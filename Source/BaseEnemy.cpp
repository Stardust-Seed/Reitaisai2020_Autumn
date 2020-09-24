#include <DxLib.h>
#include "Define.h"
#include "BaseEnemy.h"

#include "BasePlayer.h"
#include "BulletManager.h"
#include "Image.h"

const float BaseEnemy::ENEMY_SPAWNXLEFT = 420;
const float BaseEnemy::ENEMY_SPAWNYLEFT = (GAME_HEIHGT / 2) - (48 / 2);
const float BaseEnemy::ENEMY_SPAWNXUP = (GAME_WIDTH / 2) - (48 / 2);
const float BaseEnemy::ENEMY_SPAWNYUP = 0 - 48;
const float BaseEnemy::ENEMY_SPAWNXRIGHT = 1500;
const float BaseEnemy::ENEMY_SPAWNYRIGHT = (GAME_HEIHGT / 2) - (48 / 2);
const float BaseEnemy::ENEMY_SPAWNXDOWN = (GAME_WIDTH / 2) - (48 / 2);
const float BaseEnemy::ENEMY_SPAWNYDOWN = GAME_HEIHGT + 48;

//通常スポーン用のコンストラクタ
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

//サブ拠点用のコンストラクタ
BaseEnemy::BaseEnemy(float _x, float _y, float _speed, float _power, int _durability,
	eDirection _direction, eEnemyType _enemyType) {
	//各パラメータの初期化
	Init(_speed, _power, _durability, _direction, _enemyType);

	x = _x;
	y = _y;
	cx = x + (width / 2);
	cy = y + (height / 2);
}

void BaseEnemy::Init(float _speed, float _power, int _durability,
	eDirection _direction, eEnemyType _enemyType) {
	speed = _speed;
	power = _power;
	durability = _durability;
	direction = _direction;
	enemyType = _enemyType;

	animationCnt = 0;

	isCoolDown = false;

	isActive = true;
	isAttack = false;
	isHit = false;

	inactiveType = eInactiveType::None;

	width = 48;
	height = 48;
}

//移動処理
void BaseEnemy::Move() {

	if (isActive == false || isAttack == true || inactiveType == eInactiveType::Invasion) {
		return;
	}

	if (direction == eDirection::Left) {
		x += speed;
	}

	if (direction == eDirection::Right) {
		x -= speed;
	}

	if (direction == eDirection::Up) {
		y += speed;
	}

	if (direction == eDirection::Down) {
		y -= speed;
	}

}

//生存判定処理
void BaseEnemy::JudgeActive() {
	//durabilityが0以下のとき
	if (durability <= 0) {
		inactiveType = eInactiveType::Defeat;
		isActive = false;
	}

	//非アクティブタイプが侵入でありアニメーションカウントが最大+1のとき
	if (inactiveType == eInactiveType::Invasion && animationCnt == 60 + 1) {
		isActive = false;
	}
}

void BaseEnemy::AttackProc() {
	static int attackCnt = 0;	//攻撃のカウント
	float addX = 0;
	float addY = 0;

	switch (direction) {
	case eDirection::Left:
		addX = (48.0f / 30.0f);
		addY = -(20.0f / 15.0f);
		break;
	case eDirection::Right:
		addX = -(48.0f / 30.0f);
		addY = -(20.0f / 15.0f);
		break;
	case eDirection::Up:
		addX = (48.0f / 30.0f);
		addY = (20.0f / 15.0f);
		break;
	case eDirection::Down:
		addX = -(48.0f / 30.0f);
		addY = -(20.0f / 15.0f);
		break;
	}

	if (attackCnt == 120) {
		isAttack = false;
		isCoolDown = true;
		attackCnt = 0;
		return;
	}

	if (attackCnt < 30) {
		x += addX;

		if (attackCnt < 15) {
			y += addY;
		}
		else if (attackCnt < 30) {
			y -= addY;
		}

	}
	else if (attackCnt >= 50 && attackCnt < 80) {

		x -= addX;

		if (attackCnt < 65) {
			y += addY;
		}
		else if (attackCnt < 80) {
			y -= addY;
		}
	}

	attackCnt++;
}

void BaseEnemy::DamageProc(int _damage) {
	durability -= _damage;
}

//プレイヤーサーチ処理
/*
現状敵側は遠距離攻撃を想定してない判定式となってるので
敵が遠距離攻撃を行うようにする際は判定式を変更する必要性がある
*/
void BaseEnemy::SearchPlayer(float _px, float _py, float _pw, float _ph, BasePlayer* _player) {

	if (_player->Get_isStan() || isAttack == true || isCoolDown == true) {
		return;
	}

	switch (direction) {
	case eDirection::Left:
		/*******************************************************************************
		エネミーのx座標 + エネミーの横幅 + 参照する先の座標 <= プレイヤーのx座標 &&
		エネミーのx座標 + 参照する先の座標 <= プレイヤーのx座標 + プレイヤーの横幅 &&
		エネミーのy座標 + エネミーの縦幅 >= プレイヤーのy座標 &&
		エネミーのy座標 <= プレイヤーのx座標 + プレイヤーの縦幅
		*******************************************************************************/
		if (x + (width * 2) >= _px && x + width <= _px + _pw &&
			y + height >= _py && y <= _py + _ph) {
			isAttack = true;
		}
		break;
	case eDirection::Right:
		/*******************************************************************************
		エネミーのx座標 + エネミーの横幅 <= プレイヤーのx座標 &&
		エネミーのx座標 - 参照する先の座標 <= プレイヤーのx座標 + プレイヤーの横幅 &&
		エネミーのy座標 + エネミーの縦幅 >= プレイヤーのy座標 &&
		エネミーのy座標 <= プレイヤーのx座標 + プレイヤーの縦幅
		*******************************************************************************/
		if (x + width >= _px && x - width <= _px + _pw &&
			y + height >= _py && y <= _py + _ph) {
			isAttack = true;
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
			y + (height * 2) >= _py && y + height <= _py + _ph) {
			isAttack = true;
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
			y + height >= _py && y - height <= _py + _ph) {
			isAttack = true;
		}
		break;
	}
}

//城サーチ処理
void BaseEnemy::SearchCastle(float _ox, float _oy, float _ow, float _oh, bool _isActive) {

	//非アクティブタイプが侵入の場合処理を行わない
	if (inactiveType == eInactiveType::Invasion) {
		return;
	}

	//城があった場合
	if ((x + width >= _ox && x <= _ox + _ow && y + height >= _oy && y <= _oy + _oh)
		&& _isActive == true) {
		isAttack = true;
		inactiveType = eInactiveType::Invasion;
		animationCnt = 0;
	}
}

//クールダウン処理
void BaseEnemy::SearchCoolDownTime() {
	static int coolDownCount = 0;	//クールダウンカウンタ

	//180フレーム目クールダウンを終了する
	if (coolDownCount == 180) {
		coolDownCount = 0;
		isCoolDown = false;
	}

	//クールダウンカウントを加算する
	coolDownCount++;
}

//当たり判定処理
bool BaseEnemy::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh) {

	if (mx + mw >= ox && mx <= ox + ow && my + mh >= oy && my <= oy + oh) {
		return true;
	}

	return false;
}

void BaseEnemy::Animation() {
	static int imageIndex = 0;		//どの画像を呼び出すかの変数
	bool isTurn = false;	//LR反転フラグ

	if (direction == eDirection::Left && isTurn != true) {
		isTurn = true;
	}

	//非アクティブタイプがNoneの場合
	if (inactiveType == eInactiveType::None) {
		//カウントが60の時リセットする
		if (animationCnt == (ANIMATION_SWITCHING * 2)) {
			animationCnt = 0;
		}

		//0〜29カウントはimageIndexに1枚目の要素番号を代入する
		if (animationCnt < ANIMATION_SWITCHING) {
			imageIndex = static_cast<int>(enemyType);
		}
		//30〜59カウントはimageIndexに2枚目の要素番号を代入する
		else if (animationCnt < (ANIMATION_SWITCHING * 2)) {
			imageIndex = static_cast<int>(enemyType) + 1;
		}

		Image::Instance()->TransparentGraph(x, y, Image::Instance()->GetGraph(
			eImageType::Gpicture_Enemy, imageIndex), 255, isTurn);
	}
	else if (inactiveType == eInactiveType::Invasion) {
		animationCnt = Image::Instance()->FadeOutGraph(x, y, Image::Instance()->GetGraph(
			eImageType::Gpicture_Enemy, imageIndex), animationCnt, 60, isTurn);
	}

	//エネミーが非アクティブまたは攻撃中の際、animationCutを加算しない
	if (isActive == false || isAttack == true) {
		return;
	}

	animationCnt++;
}