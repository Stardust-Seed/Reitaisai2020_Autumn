#include"DxLib.h"
#include"Define.h"
#include"Input.h"
#include"BasePlayer.h"
#include"BaseEnemy.h"
#include"BulletManager.h"
#include"EnemyManager.h"

BasePlayer::BasePlayer(enum PlayerType _pType, enum AbilityType _pAbility)
{

	pos = VGet(PLAYER_LEFTPOS, PLAYER_LEFTRIGHTPOS, 0);
	vPos = VGet(0, 0, 0);

	width = 48;
	height = 48;

	speed = 3;					//移動速度
	power = 25;					//攻撃力
	abilityCount = 5;		    //スキル回数
	stanTime = 0;				//スタンタイム
	stanTime_stay = 360;		//スタン再発動までの時間

	attackTime = 0;

	playerPos = 0;			//最初は左

	isMove = 4;				//初期は4 ※4は何もしてない状態。詳しくはヘッダー参照
	isMoveKey = false;
	isOps = false;
	isOps_RUN = false;
	isOps_UP = false;
	isOps_DOWN = false;
	isOps_LEFT = false;
	isOps_RIGHT = false;
	isDamage = false;
	isAttack = false;
	isStan = false;
	isStan_Next = false;
	isAbility = false;

	now_Move = 0;			//現在移動を行っているかどうかのフラグ

	playerType  = _pType;
	abilityType = _pAbility; //まだキャラ選択できないので今は咲夜
}
BasePlayer::~BasePlayer()
{

}
void BasePlayer::Draw()
{
	//自機の描画
	DrawBox(pos.x, pos.y, pos.x + width, pos.y + height, GetColor(0, 255, 0), TRUE);
}
void BasePlayer::Update(EnemyManager* _eManager,BuffManager* _bManager)
{
	//power *= _bManager->GetPowerBuff();   バフによる攻撃力増加
	//speed *= _bManager->GetSpeedBuff();   バフによるスピード増加

	//スタン状態でない時
	if (isStan == 0) {

		Move();    //移動処理
		Attack();  //攻撃処理

		for (int i = 0; i < _eManager->Get_enemyNum(); i++) {

			//プレイヤーが敵に当たったらisStanをtrueにする
			if (ClisionHit(Get_x(), Get_y(), Get_width(), Get_height(),
				_eManager->Get_x(i), _eManager->Get_y(i), _eManager->Get_width(i), _eManager->Get_height(i)))
			{
				isStan = true;   //スタンは少ししてから解除されるので
				isHit = true;    //バフレベルダウン用にisHitを使う。
			}
		}
	}
	if (isHit == true)
	{
		//_bManager->DownBuffLevel();  バフレベルダウン
	}
	if (isStan == true && isStan_Next == true)
	{
		Stan();
	}
	//スタンが解除されたら次にスタンが起こる時間をプラス
	if (isStan == false)
	{
		stanTime = 0;
		if (stanTime_stay < 240) {
			stanTime_stay++;
		}
	}
	if (stanTime_stay >= 360)
	{
		isStan_Next = true;

	}
	float xx = pos.x + width;
	float yy = pos.y + height;

}
//プレイヤーのスタン処理
void BasePlayer::Stan()
{

	//スタンタイムを加算
	DrawFormatString(0, 100, GetColor(255, 255, 255), "しびれ浦部", 0);
	if (stanTime < 120) {
		stanTime++;
	}
	//一定時間経過したらスタンを解除してスタンタイムをリセット
	if (stanTime >= 120)
	{
		isStan = false;

	}
}
//当たり判定
bool BasePlayer::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh)
{
	if (mx <= (ox + ow) && my <= (oy + oh) &&
		ox <= (mx + mw) && oy <= (my + mh))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//プレイヤーの攻撃処理
void BasePlayer::Attack()
{

	if (attackTime < 5)
	{
		attackTime++;
	}

	//攻撃間隔
	if ((Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1) && attackTime >= 5 && now_Move == 0)
	{
		//攻撃flagをtrueにする
		isAttack = true;
		//弾を飛ばす
		bulletManager->Shot(pos, playerPos, isAttack);
		attackTime = 0;
	}

}
//プレイヤーの移動処理
void BasePlayer::Move()

{

	//←キーを押したとき
	if ((Input::Instance()->GetPressCount(KEY_INPUT_LEFT) == 1) && now_Move == 0) {

		if (playerPos == 2) {
			isOps = true;
			isOps_RIGHT = true;
		}
		else if (playerPos != 0) {
			//移動方向を左にする
			isMove = 0;
			//キー入力の操作であることのフラグをon
			isMoveKey = true;
			now_Move = 1;
		}
	}
	//↑キーを押したとき
	if ((Input::Instance()->GetPressCount(KEY_INPUT_UP) == 1) && now_Move == 0) {

		if (playerPos == 3) {
			isOps = true;
			isOps_DOWN = true;
		}
		else if (playerPos != 1) {
			//移動方向を上にする
			isMove = 1;
			//キー入力の操作であることのフラグをon
			isMoveKey = true;
			now_Move = 1;
		}
	}
	//→キーを押したとき
	if ((Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) == 1) && now_Move == 0) {

		if (playerPos == 0) {
			isOps = true;
			isOps_LEFT = true;
		}
		else if (playerPos != 2) {
			//移動方向を右にする
			isMove = 2;
			//キー入力の操作であることのフラグをon
			isMoveKey = true;
			now_Move = 1;
		}

	}
	//↓キーを押したとき
	if ((Input::Instance()->GetPressCount(KEY_INPUT_DOWN) == 1) && now_Move == 0) {

		if (playerPos == 1) {
			isOps = true;
			isOps_UP = true;
		}
		else if (playerPos != 3) {
			//移動方向を下にする
			isMove = 3;
			//キー入力の操作であることのフラグをon
			isMoveKey = true;
			now_Move = 1;
		}
	}
	//移動方向が左の時、左へ移動させる
	if (isMove == 0 && isMoveKey == true && isOps == false) {
		Move_LEFT();

	}
	//移動方向が上の時、上へ移動させる
	if (isMove == 1 && isMoveKey == true && isOps == false) {
		Move_UP();

	}
	//移動方向が右の時、右へ移動させる
	if (isMove == 2 && isMoveKey == true && isOps == false) {
		Move_RIGHT();

	}
	//移動方向が下の時、下へ移動させる
	if (isMove == 3 && isMoveKey == true && isOps == false) {
		Move_DOWN();

	}
	//反対フラグがtrueの時、反対移動処理を起動させる
	if (isOps == true && now_Move == 0) {
		Move_OPS();
		now_Move = 1;

	}
	//反対移動処理を実行
	if (isOps_RUN == true) {
		Move_OPSRUN();

	}

}

//上に移動する処理
void BasePlayer::Move_UP()
{
	//左から上へ
	if (playerPos == 0 && isMove == 1) {
		if (pos.y >= PLAYER_UPPOSY) {

			pos.y -= speed;
			//y2 -= speed;
		}
		if (pos.y <= PLAYER_UPPOSY && pos.x <= PLAYER_UPDOWNPOSX) {

			pos.x += speed;
			//x2 += speed;
		}
		if (pos.x >= PLAYER_UPDOWNPOSX && pos.y <= PLAYER_UPPOSY) {

			//プレイヤーの場所を上にする
			playerPos = 1;

			//移動方向をリセットする
			isMove = 4;

			//無移動状態にする
			if (isOps == false) {
				now_Move = 0;
			}

			//移動キーのチェックをリセット
			//isMoveKey = false;
		}
		if (isOps == true && isOps_DOWN == true && pos.x >= PLAYER_UPDOWNPOSX && pos.y <= PLAYER_UPPOSY) {
			isOps = false;
			isOps_DOWN = false;
			isOps_RUN = false;
			now_Move = 0;
		}
	}
	//右から上へ
	if (playerPos == 2 && isMove == 1) {
		if (pos.y >= PLAYER_UPPOSY) {

			pos.y -= speed;
			//y2 -= speed;
		}
		if (pos.y <= PLAYER_UPPOSY && pos.x >= PLAYER_UPDOWNPOSX) {

			pos.x -= speed;
			//x2 -= speed;
		}
		if (pos.y <= PLAYER_UPPOSY && pos.x <= PLAYER_UPDOWNPOSX) {

			//プレイヤーの場所を上にする
			playerPos = 1;

			//移動方向をリセットする
			isMove = 4;

			//移動キーのチェックをリセット
			isMoveKey = false;

			//無移動状態にする
			if (isOps == false) {
				now_Move = 0;
			}
		}
	}
}

//下へ移動する処理
void BasePlayer::Move_DOWN()
{

	//左から下へ
	if (playerPos == 0 && isMove == 3) {
		if (pos.y <= PLAYER_DOWNPOSY) {

			pos.y += speed;
			//y2 += speed;
		}
		if (pos.y >= PLAYER_DOWNPOSY && pos.x <= PLAYER_UPDOWNPOSX) {

			pos.x += speed;
			//x2 += speed;
		}
		if (pos.x >= PLAYER_UPDOWNPOSX) {

			//プレイヤーの場所を下にする
			playerPos = 3;

			//移動方向をリセットする
			isMove = 4;

			//移動キーのチェックをリセット
			isMoveKey = false;

			//無移動状態にする
			if (isOps == false) {
				now_Move = 0;
			}
		}
	}

	//右から下へ
	if (playerPos == 2 && isMove == 3) {
		if (pos.y <= PLAYER_DOWNPOSY) {

			pos.y += speed;
			//y2 += speed;
		}
		if (pos.y >= PLAYER_DOWNPOSY && pos.x >= PLAYER_UPDOWNPOSX) {

			pos.x -= speed;
			//x2 -= speed;
		}
		if (pos.x <= PLAYER_UPDOWNPOSX) {

			//プレイヤーの場所を下にする
			playerPos = 3;

			//移動方向をリセットする
			isMove = 4;

			//移動キーのチェックをリセット
			isMoveKey = false;

			//無移動状態にする
			if (isOps == false) {
				now_Move = 0;
			}
		}
		if (isOps == true && isOps_UP == true && pos.x <= PLAYER_UPDOWNPOSX && pos.y >= PLAYER_DOWNPOSY) {
			isOps = false;
			isOps_UP = false;
			isOps_RUN = false;
			now_Move = 0;
		}

	}
}

//左へ移動する処理
void BasePlayer::Move_LEFT()
{
	//上から左へ
	if (playerPos == 1 && isMove == 0) {
		if (pos.x >= PLAYER_LEFTPOS) {

			pos.x -= speed;
			//x2 -= speed;
		}
		if (pos.x <= PLAYER_LEFTPOS && pos.y <= PLAYER_LEFTRIGHTPOS) {

			pos.y += speed;
			//y2 += speed;
		}
		if (pos.y >= PLAYER_LEFTRIGHTPOS && pos.x <= PLAYER_LEFTPOS) {

			//プレイヤーの場所を左にする
			playerPos = 0;

			//移動方向をリセットする
			isMove = 4;

			//移動キーのチェックをリセット
			isMoveKey = false;

			//無移動状態にする
			if (isOps == false) {
				now_Move = 0;
			}
		}
		if (isOps == true && pos.x <= PLAYER_LEFTPOS && pos.y >= PLAYER_LEFTRIGHTPOS) {
			isOps = false;
			isOps_RIGHT = false;
			isOps_RUN = false;
			now_Move = 0;
		}
	}
	//下から左へ
	if (playerPos == 3 && isMove == 0) {
		if (pos.x >= PLAYER_LEFTPOS) {

			pos.x -= speed;
			//x2 -= speed;
		}
		if (pos.x <= PLAYER_LEFTPOS && pos.y >= PLAYER_LEFTRIGHTPOS) {

			pos.y -= speed;
			//y2 -= speed;
		}
		if (pos.y <= PLAYER_LEFTRIGHTPOS && pos.x <= PLAYER_LEFTPOS) {

			//プレイヤーの場所を左にする
			playerPos = 0;

			//移動方向をリセットする
			isMove = 4;

			//無移動状態にする
			if (isOps == false) {
				now_Move = 0;
			}
		}
		if (isOps == true && isOps_RIGHT == true && pos.x <= PLAYER_LEFTPOS && pos.y <= PLAYER_LEFTRIGHTPOS) {
			isOps = false;
			isOps_RIGHT = false;
			isOps_RUN = false;
			now_Move = 0;
		}
	}
}
//右へ移動する処理
void BasePlayer::Move_RIGHT()
{
	//上から右へ
	if (playerPos == 1 && isMove == 2) {
		if (pos.x <= PLAYER_RIGHTPOS) {

			pos.x += speed;
			//x2 += speed;
		}
		if (pos.x >= PLAYER_RIGHTPOS && pos.y <= PLAYER_LEFTRIGHTPOS) {

			pos.y += speed;
			//y2 += speed;
		}
		if (pos.y >= PLAYER_LEFTRIGHTPOS && pos.x >= PLAYER_RIGHTPOS) {

			//プレイヤーの場所を右にする
			playerPos = 2;

			//移動方向をリセットする
			isMove = 4;

			//移動キーのチェックをリセット
			isMoveKey = false;

			//無移動状態にする
			if (isOps == false) {
				now_Move = 0;
			}
		}
		if (isOps == true && isOps_LEFT == true && pos.x >= PLAYER_RIGHTPOS && pos.y >= PLAYER_LEFTRIGHTPOS) {
			isOps = false;
			isOps_LEFT = false;
			isOps_RUN = false;
			now_Move = 0;
		}
	}
	//下から右へ
	if (playerPos == 3 && isMove == 2) {
		if (pos.x <= PLAYER_RIGHTPOS) {

			pos.x += speed;

		}
		if (pos.x >= PLAYER_RIGHTPOS && pos.y >= PLAYER_LEFTRIGHTPOS) {

			pos.y -= speed;

		}
		if (pos.y <= PLAYER_LEFTRIGHTPOS && pos.x >= PLAYER_RIGHTPOS) {

			//プレイヤーの場所を右にする
			playerPos = 2;

			//移動方向をリセットする
			isMove = 4;

			//移動キーのチェックをリセット
			isMoveKey = false;

			//無移動状態にする
			if (isOps == false) {
				now_Move = 0;
			}
		}
	}

}

//反対へ移動する処理
void BasePlayer::Move_OPS()
{

	//左から右へ移動
	if (playerPos == 0 && isOps_LEFT == true) {

		isOps_RUN = true;
	}
	//右から左へ移動
	if (playerPos == 2 && isOps_RIGHT == true) {

		isOps_RUN = true;
	}
	//上から下へ移動
	if (playerPos == 1 && isOps_UP == true) {

		isOps_RUN = true;
	}
	//下から上へ移動
	if (playerPos == 3 && isOps_DOWN == true) {

		isOps_RUN = true;
	}
}

//反対移動処理:処理
void BasePlayer::Move_OPSRUN()
{
	//上から下へ移動する処理
	if (isOps_RUN == true && isOps_UP == true)
	{
		isMove = 2;
		Move_RIGHT();
		isMove = 3;
		Move_DOWN();

	}
	//下から上へ移動する処理
	if (isOps_RUN == true && isOps_DOWN == true)
	{
		isMove = 0;
		Move_LEFT();
		isMove = 1;
		Move_UP();

	}
	//左から右へ移動する処理
	if (isOps_RUN == true && isOps_LEFT == true)
	{
		isMove = 1;
		Move_UP();
		isMove = 2;
		Move_RIGHT();

	}
	//右から左へ移動する処理
	if (isOps_RUN == true && isOps_RIGHT == true)
	{
		isMove = 3;
		Move_DOWN();
		isMove = 0;
		Move_LEFT();

	}

}