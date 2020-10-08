#include <DxLib.h>
#include <cmath>
#include "Define.h"
#include "BaseEnemy.h"

#include "BasePlayer.h"
#include "BulletManager.h"
#include "CastleManager.h"
#include "Image.h"
#include "SE.h"

const float BaseEnemy::ENEMY_SPAWNXLEFT = 420;
const float BaseEnemy::ENEMY_SPAWNYLEFT = (GAME_HEIHGT / 2) - (48 / 2);
const float BaseEnemy::ENEMY_SPAWNXUP = (GAME_WIDTH / 2) - (48 / 2);
const float BaseEnemy::ENEMY_SPAWNYUP = 0 - 48;
const float BaseEnemy::ENEMY_SPAWNXRIGHT = 1500;
const float BaseEnemy::ENEMY_SPAWNYRIGHT = (GAME_HEIHGT / 2) - (48 / 2);
const float BaseEnemy::ENEMY_SPAWNXDOWN = (GAME_WIDTH / 2) - (48 / 2);
const float BaseEnemy::ENEMY_SPAWNYDOWN = GAME_HEIHGT + 48;

/// <summary>
/// 通常スポーン用のコンストラクタ
/// </summary>
/// <param name="_speed">スポーンするEnemyの速度</param>
/// <param name="_power">スポーンするEnemyの攻撃力</param>
/// <param name="_durability">スポーンするEnemyの耐久力</param>
/// <param name="_direction">スポーンするEnemyの方向</param>
/// <param name="_enemyType">スポーンするEnemyの種類</param>
BaseEnemy::BaseEnemy(float _speed, float _power, int _durability,
	eDirection _direction, eEnemyType _enemyType) {
	//各パラメータの初期化
	Init(_speed, _power, _durability, _direction, _enemyType);

	if (direction == eDirection::Left) {
		x = ENEMY_SPAWNXLEFT;
		y = ENEMY_SPAWNYLEFT;
	}

	if (direction == eDirection::Right) {
		x = ENEMY_SPAWNXRIGHT;
		y = ENEMY_SPAWNYRIGHT;
	}

	if (direction == eDirection::Up) {
		x = ENEMY_SPAWNXUP;
		y = ENEMY_SPAWNYUP;
	}

	if (direction == eDirection::Down) {
		x = ENEMY_SPAWNXDOWN;
		y = ENEMY_SPAWNYDOWN;
	}

	cx = x + (width / 2);
	cy = y + (height / 2);

}

/// <summary>
/// サブ拠点スポーン用のコンストラクタ
/// </summary>
/// <param name="_x">スポーン位置x座標</param>
/// <param name="_y">スポーン位置y座標</param>
/// <param name="_speed">スポーンするEnemyの速度</param>
/// <param name="_power">スポーンするEnemyの攻撃力</param>
/// <param name="_durability">スポーンするEnemyの耐久力</param>
/// <param name="_direction">スポーンするEnemyの方向</param>
/// <param name="_enemyType">スポーンするEnemyの種類</param>
BaseEnemy::BaseEnemy(float _x, float _y, float _speed, float _power, int _durability,
	eDirection _direction, eEnemyType _enemyType) {
	//各パラメータの初期化
	Init(_speed, _power, _durability, _direction, _enemyType);

	x = _x;
	y = _y;
	cx = x + (width / 2);
	cy = y + (height / 2);
}

/// <summary>
/// 共通の初期化項目の初期化処理
/// </summary>
/// <param name="_speed">スピードの初期値</param>
/// <param name="_power">攻撃力の初期値</param>
/// <param name="_durability">体力の初期値</param>
/// <param name="_direction">方向の初期値</param>
/// <param name="_enemyType">エネミーのタイプ情報</param>
void BaseEnemy::Init(float _speed, float _power, int _durability,
	eDirection _direction, eEnemyType _enemyType) {
	speed = _speed;
	power = _power;
	durability = _durability;
	direction = _direction;
	enemyType = _enemyType;

	animationCnt = 0;
	attackCnt = 0;
	coolDownCnt = 0;
	imageIndex = static_cast<int>(enemyType);

	isActive = true;
	isAttack = false;
	isCoolDown = false;
	isHit = false;

	if (direction == eDirection::Left) {
		isTurn = true;
	}
	else {
		isTurn = false;
	}

	addX = 0;
	addY = 0;

	distanceToPlayerX = 0;
	distanceToPlayerY = 0;

	attackType = eAttackType::None;
	inactiveType = eInactiveType::None;

	width = 48;
	height = 48;
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="_castleManager">拠点の管理クラス</param>
/// <param name="_player">プレイヤークラス</param>
/// <param name="_bulletManager">弾の管理クラス</param>
void BaseEnemy::Update(CastleManager* _castleManager, BasePlayer* _player,
	BulletManager* _bulletManager) {
/*------------------------------------------------------------------------------
センター座標の再計算
------------------------------------------------------------------------------*/
	cx = x + (width / 2);
	cy = y + (height / 2);

/*------------------------------------------------------------------------------
攻撃タイプが侵入の際攻撃フラグをfalseに
------------------------------------------------------------------------------*/
	if (isAttack == true && attackType == eAttackType::Invasion) {
		isAttack = false;
	}

/*------------------------------------------------------------------------------
ダメージ処理
------------------------------------------------------------------------------*/
	for (int i = 0; i < _bulletManager->Get_MaxBullet(); i++) {
		if (_bulletManager->Get_IsActive(i) == true) {
			if (ClisionHit(x, y, width, height, _bulletManager->Get_X(i), _bulletManager->Get_Y(i),
				_bulletManager->Get_Width(i), _bulletManager->Get_Height(i))) {
				if (attackType != eAttackType::Invasion) {
					_bulletManager->Set_isActive(i, false);
					DamageProc(_player->Get_power());
				}
			}
		}
	}
/*------------------------------------------------------------------------------
生存判定処理
------------------------------------------------------------------------------*/
	JudgeActive();

/*------------------------------------------------------------------------------
サーチ関連処理
------------------------------------------------------------------------------*/

	//クールダウンの処理
	if (isCoolDown == true) {
		SearchCoolDownTime();
	}

	//拠点のサーチ処理
	for (int i = 0; i < _castleManager->Get_CastleNum(); i++) {
		SearchCastle(_castleManager->Get_X(i), _castleManager->Get_Y(i),
			_castleManager->Get_Width(i), _castleManager->Get_Height(i), _castleManager->Get_IsActive(i));
	}

	//プレイヤーのサーチ処理
	SearchPlayer(_player->Get_x(), _player->Get_y(), _player->Get_width(), _player->Get_height(),
		_player);

/*------------------------------------------------------------------------------
攻撃処理
------------------------------------------------------------------------------*/
	if (isAttack == true) {
		AttackProc(_player->Get_cx(), _player->Get_cy());
	}

/*------------------------------------------------------------------------------
移動処理
------------------------------------------------------------------------------*/
	Move(_player->Get_isAbility(), _player->Get_AbilityType());

/*------------------------------------------------------------------------------
アニメーション処理
------------------------------------------------------------------------------*/
	Animation(_player->Get_isAbility(), _player->Get_AbilityType());
}

/// <summary>
/// 描画処理
/// </summary>
void BaseEnemy::Draw() {
/*------------------------------------------------------------------------------
通常時＆攻撃時の描画処理
------------------------------------------------------------------------------*/
	if (inactiveType == eInactiveType::None) {
		Image::Instance()->TransparentGraph(x, y, Image::Instance()->GetGraph(
			eImageType::Gpicture_Enemy, imageIndex), 255, isTurn);
	}
/*------------------------------------------------------------------------------
拠点侵入時の描画処理
------------------------------------------------------------------------------*/
	else if (inactiveType == eInactiveType::Invasion) {
		animationCnt = Image::Instance()->FadeOutGraph(x, y, Image::Instance()->GetGraph(
			eImageType::Gpicture_Enemy, imageIndex), animationCnt, 60, isTurn);
	}
}

/// <summary>
/// 移動処理
/// </summary>
/// <param name="_isAbility">プレイヤーのアビリティフラグ</param>
/// <param name="_abilityType">プレイヤーのアビリティタイプ</param>
void BaseEnemy::Move(bool _isAbility, int _abilityType) {
	/*--------------------------------------------------------------
	非アクティブの場合、攻撃中の場合、非アクティブタイプが侵入の場合
	咲夜のスキルが発動中の場合、移動処理を行わない
	--------------------------------------------------------------*/
	if (isActive == false || isAttack == true || inactiveType == eInactiveType::Invasion ||
		(_isAbility == true && _abilityType == SAKUYA)) {
		return;
	}

	//方向に対応する加算or減算処理おこなう
	switch (direction) {
	case eDirection::Left:		//左方向
		x += speed;
		break;
	case eDirection::Right:		//右方向
		x -= speed;
		break;
	case eDirection::Up:		//上方向
		y += speed;
		break;
	case eDirection::Down:		//下方向
		y -= speed;
		break;
	}
}

/// <summary>
/// 生存判定処理
/// </summary>
void BaseEnemy::JudgeActive() {
	//durabilityが0以下のとき
	if (durability <= 0) {
		//
		SE::Instance()->PlaySE(SE_EnemyDown);

		inactiveType = eInactiveType::Defeat;
		isActive = false;
	}

	//非アクティブタイプが侵入でありアニメーションカウントが最大+1のとき
	if (inactiveType == eInactiveType::Invasion && animationCnt == 60 + 1) {
		isActive = false;
	}
}

/// <summary>
/// 攻撃の処理
/// </summary>
/// <param name="_cx">プレイヤーのcx座標</param>
/// <param name="_cy">プレイヤーのcy座標</param>
void BaseEnemy::AttackProc(float _cx,float _cy) {

	//攻撃タイプが侵入の場合処理を行わない
	if (attackType == eAttackType::Invasion) {
		return;
	}

	//攻撃モーションの初回処理
	if (attackCnt == 0) {
		/*--------------------------------------------------
		1フレーム分のモーション移動距離を算出
		x = (エネミーのcx - プレイヤーのcx) / 最大フレーム数
		y = (エネミーのcy - プレイヤーのcy) / 最大フレーム数
		※abs関数によって絶対値を返す
		--------------------------------------------------*/
		distanceToPlayerX = abs(cx - _cx) / 30.0f;
		distanceToPlayerY = abs(cy - _cy) / 30.0f;

		//モーション移動に使用する座標を割り当てる
		switch (direction) {
		case eDirection::Left:						//左方向
			addX = distanceToPlayerX;
			addY = -(ATTACK_MOTION_JUNPPOWER);
			break;
		case eDirection::Right:						//右方向
			addX = -(distanceToPlayerX);
			addY = -(ATTACK_MOTION_JUNPPOWER);
			break;
		case eDirection::Up:						//上方向
			addX = ATTACK_MOTION_JUNPPOWER;
			addY = distanceToPlayerY;
			break;
		case eDirection::Down:						//下方向
			addX = -(ATTACK_MOTION_JUNPPOWER);
			addY = -(distanceToPlayerY);
			break;
		}
	}

	//モーションの終了処理
	if (attackCnt == 100) {
		isAttack = false;
		isCoolDown = true;
		attackCnt = 0;
		attackType = eAttackType::None;
		return;
	}

	if (attackCnt == 30) {
		SE::Instance()->PlaySE(SE_EnemyAttack);
	}

	//方向が左右の場合
	if (direction == eDirection::Left || direction == eDirection::Right) {
		AttackMotion(&x, &y, addX, addY);
	}
	//方向が上下の場合
	else if (direction == eDirection::Up || direction == eDirection::Down) {
		AttackMotion(&y, &x, addY, addX);
	}

	//攻撃カウントの加算処理
	attackCnt++;
}

/// <summary>
/// 攻撃モーション
/// </summary>
/// <param name="_move">移動する方向</param>
/// <param name="_jump">ジャンプする方向</param>
/// <param name="_addMove">加算させる移動値</param>
/// <param name="_addJump">加算させるジャンプ値</param>
void BaseEnemy::AttackMotion(float* _move, float* _jump, float _addMove, float _addJump) {
	//プレイヤーの方向へ向かう処理
	if (attackCnt < 30) {
		*_move += _addMove;

		if (attackCnt < 15) {
			*_jump += _addJump;
		}
		else if (attackCnt < 30) {
			*_jump -= _addJump;
		}
	}
	//元の座標に戻る処理
	else if (attackCnt >= 50 && attackCnt < 80) {
		*_move -= _addMove;

		if (attackCnt < 65) {
			*_jump += _addJump;
		}
		else if (attackCnt < 80) {
			*_jump -= _addJump;
		}
	}
}

/// <summary>
/// ダメージ処理
/// </summary>
/// <param name="_damage">ダメージ量</param>
void BaseEnemy::DamageProc(int _damage) {
	durability -= _damage;
}

/// <summary>
/// プレイヤーのサーチ処理
/// </summary>
/// <param name="_px">プレイヤーのx座標</param>
/// <param name="_py">プレイヤーのy座標</param>
/// <param name="_pw">プレイヤーの横幅</param>
/// <param name="_ph">プレイヤーの縦幅</param>
/// <param name="_player">プレイヤー</param>
void BaseEnemy::SearchPlayer(float _px, float _py, float _pw, float _ph, BasePlayer* _player) {

	if (_player->Get_isStan() || isAttack == true || isCoolDown == true ||
		(_player->Get_isAbility() == true && _player->Get_AbilityType() == SAKUYA)) {
		return;
	}

	switch (direction) {
	case eDirection::Left:
		/*******************************************************************************
		エネミーのcx座標 + エネミーの横幅 >= プレイヤーのx座標 &&
		エネミーのcx座標 <= プレイヤーのx座標 + プレイヤーの横幅の半分 &&
		エネミーのy座標 + エネミーの縦幅 >= プレイヤーのy座標
		エネミーのy座標 <= プレイヤーのy座標 + プレイヤーの横幅
		*******************************************************************************/
		if (cx + width >= _px && cx <= _px + (_pw / 2) &&
			y + height >= _py && y <= _py + _ph) {
			isAttack = true;
			attackType = eAttackType::Player;
		}
		break;
	case eDirection::Right:
		/*******************************************************************************
		エネミーのcx座標 >= プレイヤーのcx座標 &&
		エネミーのcx座標 - エネミーの横幅 <= プレイヤーのcx + プレイヤーの横幅の半分 &&
		エネミーのy座標 + エネミーの縦幅 >= プレイヤーのy座標
		エネミーのy座標 <= プレイヤーのy座標 + プレイヤーの横幅
		*******************************************************************************/
		if (cx >= (_px + (_pw / 2)) && cx - width <= (_px + (_pw / 2)) + (_pw / 2) &&
			y + height >= _py && y <= _py + _ph) {
			isAttack = true;
			attackType = eAttackType::Player;
		}
		break;
	case eDirection::Up:
		/*******************************************************************************
		エネミーのx座標 + エネミーの横幅 <= プレイヤーのx座標 &&
		エネミーのx座標 <= プレイヤーのx座標 + プレイヤーの横幅 &&
		エネミーのy座標 + エネミーの縦幅 + 参照する先の座標 >= プレイヤーのy座標 &&
		エネミーのy座標 + 参照する先の座標 <= プレイヤーのx座標 + プレイヤーの縦幅
		*******************************************************************************/
		if (x + width >= _px && x <= _px + _pw &&
			cy + height >= _py && cy <= _py + (_ph / 2)) {
			isAttack = true;
			attackType = eAttackType::Player;
		}
		break;
	case eDirection::Down:
		/*******************************************************************************
		エネミーのx座標 + エネミーの横幅 <= プレイヤーのx座標 &&
		エネミーのx座標 <= プレイヤーのx座標 + プレイヤーの横幅 &&
		エネミーのy座標 + エネミーの縦幅 + 参照する先の座標 >= プレイヤーのy座標 &&
		エネミーのy座標 + エネミーの縦幅 <= プレイヤーのx座標 - 参照する先の座標
		*******************************************************************************/
		if (x + width >= _px && x <= _px + _pw &&
			cy >= (_py + (_ph / 2)) && cy - height <= (_py + (_ph / 2)) + (_ph / 2)) {
			isAttack = true;
			attackType = eAttackType::Player;
		}
		break;
	}
}

/// <summary>
/// 拠点のサーチ処理
/// </summary>
/// <param name="_ox">拠点のx座標</param>
/// <param name="_oy">拠点のy座標</param>
/// <param name="_ow">拠点の縦幅</param>
/// <param name="_oh">拠点の縦幅</param>
/// <param name="_isActive">拠点のアクティブフラグ</param>
void BaseEnemy::SearchCastle(float _ox, float _oy, float _ow, float _oh, bool _isActive) {

	//非アクティブタイプが侵入の場合処理を行わない
	if (inactiveType == eInactiveType::Invasion || attackType == eAttackType::Player) {
		return;
	}

	//城があった場合
	if ((x + width >= _ox && x <= _ox + _ow && y + height >= _oy && y <= _oy + _oh)
		&& _isActive == true) {
		isAttack = true;
		inactiveType = eInactiveType::Invasion;
		attackType = eAttackType::Invasion;
		animationCnt = 0;
	}
}

/// <summary>
/// サーチのクールダウン
/// </summary>
void BaseEnemy::SearchCoolDownTime() {
	//180フレーム目クールダウンを終了する
	if (coolDownCnt == 180) {
		coolDownCnt = 0;
		isCoolDown = false;
	}

	//クールダウンカウントを加算する
	coolDownCnt++;
}

/// <summary>
/// あたり判定処理
/// </summary>
/// <param name="mx">エネミーのx座標</param>
/// <param name="my">エネミーのy座標</param>
/// <param name="mw">エネミーの横幅</param>
/// <param name="mh">エネミーの縦幅</param>
/// <param name="ox">相手のx座標</param>
/// <param name="oy">相手のy座標</param>
/// <param name="ow">相手の横幅</param>
/// <param name="oh">相手の縦幅</param>
/// <returns>当たった場合 true / 当たらなかった場合 false</returns>
bool BaseEnemy::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh) {

	if (mx + mw >= ox && mx <= ox + ow && my + mh >= oy && my <= oy + oh) {
		return true;
	}

	return false;
}

/// <summary>
/// 移動処理
/// </summary>
/// <param name="_isAbility">プレイヤーのアビリティフラグ</param>
/// <param name="_abilityType">プレイヤーのアビリティタイプ</param>
void BaseEnemy::Animation(bool _isAbility, int _abilityType) {
	//非アクティブタイプがNoneの場合
	if (inactiveType == eInactiveType::None) {
		//カウントが60の時リセットする
		if (animationCnt == (ANIMATION_SWITCHING * 2)) {
			animationCnt = 0;
		}

		//0～29カウントはimageIndexに1枚目の要素番号を代入する
		if (animationCnt < ANIMATION_SWITCHING) {
			imageIndex = static_cast<int>(enemyType);
		}
		//30～59カウントはimageIndexに2枚目の要素番号を代入する
		else if (animationCnt < (ANIMATION_SWITCHING * 2)) {
			imageIndex = static_cast<int>(enemyType) + 1;
		}

		//エネミーが非アクティブまたは攻撃中の際、animationCutを加算しない
		if (isActive == false || isAttack == true ||
			(_isAbility == true && _abilityType == SAKUYA)) {
			return;
		}

		animationCnt++;
	}
}

/// <summary>
/// directionを設定する
/// </summary>
/// <param name="_direction">設定する方向</param>
void BaseEnemy::SetDirection(eDirection _direction) {
	//方向を設定する
	direction = _direction;

	//LR反転フラグも再設定する
	if (direction == eDirection::Left) {
		isTurn = true;
	}
	else {
		isTurn = false;
	}
}