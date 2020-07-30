#include"DxLib.h"
#include"BasePlayer.h"
#include"Object.h"
#include"Input.h"

BasePlayer::BasePlayer()
{
	speed = 3;
	power = 0;
	stanTime = 0;
	attackTime = 0;

	PlayerPos = 0;                  
	// 0 = 左         1 = 上        2 = 右         3 = 下

	isMove = 4;
	// 0 = 左へ移動   1 =上へ移動   2 = 右へ移動   3 = 下へ移動   4 = なし

	isMove = 4;          //初期は4
	isMoveKey = false;
	isOps = false;
	isOps_RUN = false;
	isOps_UP = false;
	isOps_DOWN = false;
	isOps_LEFT = false;
	isOps_RIGHT = false;
	isDamage = false;

	//プレイヤーの初期座標
	x = PLAYER_SPOWNPOSX;
	y = PLAYER_SPOWNPOSY;

	//テスト用
	x2 = 440;
	y2 = 396;
	//テスト用のカラー
	Color = GetColor(255, 0, 0);

}

//プレイヤーの移動処理
void BasePlayer::Move()
{
	//←キーを押したとき
	if ((Input::Instance()->GetPressCount(KEY_INPUT_LEFT) == 1)) {

		if (PlayerPos == 2) {
			isOps = true;
			isOps_RIGHT = true;
		}
		else {
			//移動方向を左にする
			isMove = 0;
			//キー入力の操作であることのフラグをon
			isMoveKey = true;
		}
	}
	//↑キーを押したとき
	if ((Input::Instance()->GetPressCount(KEY_INPUT_UP) == 1)) {

		if (PlayerPos == 3) {
			isOps = true;
			isOps_DOWN = true;
		}
		else {
			//移動方向を上にする
			isMove = 1;
			//キー入力の操作であることのフラグをon
			isMoveKey = true;
		}
	}
	//→キーを押したとき
	if ((Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) == 1)) {

		if (PlayerPos == 0) {
			isOps = true;
			isOps_LEFT = true;
		}
		else {
			//移動方向を右にする
			isMove = 2;
			//キー入力の操作であることのフラグをon
			isMoveKey = true;
		}

	}
	//↓キーを押したとき
	if ((Input::Instance()->GetPressCount(KEY_INPUT_DOWN) == 1)) {

		if (PlayerPos == 1) {
			isOps = true;
			isOps_UP = true;
		}
		else {
			//移動方向を下にする
			isMove = 3;
			//キー入力の操作であることのフラグをon
			isMoveKey = true;
		}
	}
	//移動方向が左の時、左へ移動させる
	if (isMove == 0 && isMoveKey == true) {
		Move_LEFT();
	}
	//移動方向が上の時、上へ移動させる
	if (isMove == 1 && isMoveKey == true) {
		Move_UP();
	}
	//移動方向が右の時、右へ移動させる
	if (isMove == 2 && isMoveKey == true) {
		Move_RIGHT();
	}
	//移動方向が下の時、下へ移動させる
	if (isMove == 3 && isMoveKey == true) {
		Move_DOWN();
	}
	//反対フラグがtrueの時、反対移動処理を起動させる
	if (isOps == true) {
		Move_OPS();
	}
	//反対移動処理を実行
	if (isOps_RUN == true) {
		Move_OPSRUN();
	}
}
void BasePlayer::Move_UP()
{
	//左から上へ
	if (PlayerPos == 0 && isMove == 1) {
		if (y >= 264) {

			y -= speed;
			y2 -= speed;
		}
		if (y <= 264 && x <= 486) {

			x += speed;
			x2 += speed;
		}
		if (x >= 486 && y <= 264) {

			//プレイヤーの場所を上にする
			PlayerPos = 1;

			//移動方向をリセットする
			isMove = 4;

			//移動キーのチェックをリセット
			//isMoveKey = false;
		}
		if (isOps == true && isOps_DOWN == true && x >= 485 && y <= 264) {
			isOps = false;
			isOps_DOWN = false;
			isOps_RUN = false;
		}
	}
	//右から上へ
	if (PlayerPos == 2 && isMove == 1) {
		if (y >= 264) {

			y -= speed;
			y2 -= speed;
		}
		if (y <= 264 && x >= 486) {

			x -= speed;
			x2 -= speed;
		}
		if (y <= 264 && x <= 486) {

			//プレイヤーの場所を上にする
			PlayerPos = 1;

			//移動方向をリセットする
			isMove = 4;

			//移動キーのチェックをリセット
			isMoveKey = false;
		}
	}
}
//下へ移動する処理
void BasePlayer::Move_DOWN()
{
	//左から下へ
	if (PlayerPos == 0 && isMove == 3) {
		if (y <= 456) {

			y += speed;
			y2 += speed;
		}
		if (y >= 456 && x <= 486) {

			x += speed;
			x2 += speed;
		}
		if (x >= 486) {

			//プレイヤーの場所を下にする
			PlayerPos = 3;

			//移動方向をリセットする
			isMove = 4;

			//移動キーのチェックをリセット
			isMoveKey = false;
		}
	}

	//右から下へ
	if (PlayerPos == 2 && isMove == 3) {
		if (y <= 456) {

			y += speed;
			y2 += speed;
		}
		if (y >= 456 && x >= 486) {

			x -= speed;
			x2 -= speed;
		}
		if (x <= 486) {

			//プレイヤーの場所を下にする
			PlayerPos = 3;

			//移動方向をリセットする
			isMove = 4;

			//移動キーのチェックをリセット
			isMoveKey = false;
		}
		if (isOps == true && isOps_UP == true && x <= 486 && y >= 456) {
			isOps = false;
			isOps_UP = false;
			isOps_RUN = false;
		}

	}
}
//左へ移動する処理
void BasePlayer::Move_LEFT()
{
	//上から左へ
	if (PlayerPos == 1 && isMove == 0) {
		if (x >= 392) {

			x -= speed;
			x2 -= speed;
		}
		if (x <= 392 && y <= 348) {

			y += speed;
			y2 += speed;
		}
		if (y >= 345) {

			//プレイヤーの場所を左にする
			PlayerPos = 0;

			//移動方向をリセットする
			isMove = 4;

			//移動キーのチェックをリセット
			isMoveKey = false;
		}
		if (isOps == true && x <= 392 && y >= 345) {
			isOps = false;
			isOps_RIGHT = false;
			isOps_RUN = false;
		}
	}
	//下から左へ
	if (PlayerPos == 3 && isMove == 0) {
		if (x >= 392) {

			x -= speed;
			x2 -= speed;
		}
		if (x <= 392 && y >= 348) {

			y -= speed;
			y2 -= speed;
		}
		if (y <= 345) {

			//プレイヤーの場所を左にする
			PlayerPos = 0;

			//移動方向をリセットする
			isMove = 4;
		}
		if (isOps == true && isOps_RIGHT == true && x <= 392 && y <= 345) {
			isOps = false;
			isOps_RIGHT = false;
			isOps_RUN = false;
		}
	}
}
//右へ移動する処理
void BasePlayer::Move_RIGHT()
{
	//上から右へ
	if (PlayerPos == 1 && isMove == 2) {
		if (x <= 584) {

			x += speed;
			x2 += speed;
		}
		if (x >= 584 && y <= 348) {

			y += speed;
			y2 += speed;
		}
		if (y >= 345) {

			//プレイヤーの場所を右にする
			PlayerPos = 2;

			//移動方向をリセットする
			isMove = 4;

			//移動キーのチェックをリセット
			isMoveKey = false;
		}
		if (isOps == true && isOps_LEFT == true && x >= 584 && y >= 345) {
			isOps = false;
			isOps_LEFT = false;
			isOps_RUN = false;
		}
	}
	//下から右へ
	if (PlayerPos == 3 && isMove == 2) {
		if (x <= 584) {

			x += speed;
			x2 += speed;
		}
		if (x >= 584 && y >= 348) {

			y -= speed;
			y2 -= speed;
		}
		if (y <= 345) {

			//プレイヤーの場所を右にする
			PlayerPos = 2;

			//移動方向をリセットする
			isMove = 4;

			//移動キーのチェックをリセット
			isMoveKey = false;
		}
	}
}

//反対へ移動する処理
void BasePlayer::Move_OPS()
{

	//左から右へ移動
	if (PlayerPos == 0 && isOps_LEFT == true) {

		isOps_RUN = true;
	}
	//右から左へ移動
	if (PlayerPos == 2 && isOps_RIGHT == true) {

		isOps_RUN = true;
	}
	//上から下へ移動
	if (PlayerPos == 1 && isOps_UP == true) {

		isOps_RUN = true;
	}
	//下から上へ移動
	if (PlayerPos == 3 && isOps_DOWN == true) {

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
//プレイヤーの攻撃処理
void BasePlayer::Attack()
{


}


bool BasePlayer::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh)
{
	if (mx < (ox + 100) && my < (oy + 100) &&
		ox < (mx + 48) && oy < (my + 48))
	{
		return DrawFormatString(0, 100, GetColor(255, 0, 0), "激突の浦部");
	}
	else
	{
		return 1;
	}
}


//プレイヤーの描画処理
void BasePlayer::Draw()
{
	//テスト用の描画

	//左の位置
	DrawBox(x, y, x2, y2, Color, TRUE);

	DrawFormatString(0, 0, GetColor(255, 255, 255), "%f %f %f %f", x, x2, y, y2);
	DrawFormatString(0, 25, GetColor(255, 255, 255), "isMove:%d  PlayerPos:%d", isMove, PlayerPos);

}

//プレイヤーの更新処理
void BasePlayer::Update()
{


}

//プレイヤーの処理まとめ
void BasePlayer::All()
{

	//***テスト用***//
	float xx = 500;
	float yy = 400;

	float xx2 = 600;
	float yy2 = 500;
	//**************//

	//***テストに使ってたやつ***
	/***プレイヤーの移動範囲***
	DrawBox(632, 504, 392, 264, GetColor(255, 255, 0), TRUE);
	//拠点
	DrawBox(482, 342, 542, 402, GetColor(255, 0, 0), TRUE);
	//敵
	DrawBox(xx, yy, xx2, yy2, GetColor(100, 100, 100), TRUE);
	****************************/

	Draw();
	Move();
	ClisionHit(x, y, x2, y2, xx, yy, xx2, yy2);
}