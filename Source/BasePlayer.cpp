#include"DxLib.h"
#include"BasePlayer.h"
#include"Object.h"
#include"Input.h"

BasePlayer::BasePlayer()
{
	speed = 3;
	power = 0;
	stanTime = 0;
	AttackTime = 0;

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

	//プレイヤーの幅と高さ
	width = 48;
	height = 48;

	//テスト用
	x2 = 440;
	y2 = 396;

}

BasePlayer::Shot::Shot()
{
	/************
	x = BasePlayer->Get_x();       //弾のx座標
	y = BasePlayer->Get_y();       //弾のy座標
	だと処理落ちするのなんでだああああああああああ
	*****************/

	//正式な弾とか決まったら修正
	x = 392;       //弾のx座標
	y = 345;       //弾のy座標
	width = 24;    //弾の幅
	height = 24;   //弾の高さ
	cx = (x + width);
	cy = (y + height);
	shot_gh = 0;   //グラフィックハンドル
	flag = 0;      //存在フラグ

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
		if (y >= PLAYER_UPPOSY) {

			y -= speed;
			y2 -= speed;
		}
		if (y <= PLAYER_UPPOSY && x <= PLAYER_UPDOWNPOSX) {

			x += speed;
			x2 += speed;
		}
		if (x >= PLAYER_UPDOWNPOSX && y <= PLAYER_UPPOSY) {

			//プレイヤーの場所を上にする
			PlayerPos = 1;

			//移動方向をリセットする
			isMove = 4;

			//移動キーのチェックをリセット
			//isMoveKey = false;
		}
		if (isOps == true && isOps_DOWN == true && x >= PLAYER_UPDOWNPOSX && y <= PLAYER_UPPOSY) {
			isOps = false;
			isOps_DOWN = false;
			isOps_RUN = false;
		}
	}
	//右から上へ
	if (PlayerPos == 2 && isMove == 1) {
		if (y >= PLAYER_UPPOSY) {

			y -= speed;
			y2 -= speed;
		}
		if (y <= PLAYER_UPPOSY && x >= PLAYER_UPDOWNPOSX) {

			x -= speed;
			x2 -= speed;
		}
		if (y <= PLAYER_UPPOSY && x <= PLAYER_UPDOWNPOSX) {

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
		if (y <= PLAYER_DOWNPOSY) {

			y += speed;
			y2 += speed;
		}
		if (y >= PLAYER_DOWNPOSY && x <= PLAYER_UPDOWNPOSX) {

			x += speed;
			x2 += speed;
		}
		if (x >= PLAYER_UPDOWNPOSX) {

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
		if (y <= PLAYER_DOWNPOSY) {

			y += speed;
			y2 += speed;
		}
		if (y >= PLAYER_DOWNPOSY && x >= PLAYER_UPDOWNPOSX) {

			x -= speed;
			x2 -= speed;
		}
		if (x <= PLAYER_UPDOWNPOSX) {

			//プレイヤーの場所を下にする
			PlayerPos = 3;

			//移動方向をリセットする
			isMove = 4;

			//移動キーのチェックをリセット
			isMoveKey = false;
		}
		if (isOps == true && isOps_UP == true && x <= PLAYER_UPDOWNPOSX && y >= PLAYER_DOWNPOSY) {
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
		if (x >= PLAYER_LEFTPOS) {

			x -= speed;
			x2 -= speed;
		}
		if (x <= PLAYER_LEFTPOS && y <= PLAYER_LEFTRIGHTPOS) {

			y += speed;
			y2 += speed;
		}
		if (y >= PLAYER_LEFTRIGHTPOS) {

			//プレイヤーの場所を左にする
			PlayerPos = 0;

			//移動方向をリセットする
			isMove = 4;

			//移動キーのチェックをリセット
			isMoveKey = false;
		}
		if (isOps == true && x <= PLAYER_LEFTPOS && y >= PLAYER_LEFTRIGHTPOS) {
			isOps = false;
			isOps_RIGHT = false;
			isOps_RUN = false;
		}
	}
	//下から左へ
	if (PlayerPos == 3 && isMove == 0) {
		if (x >= PLAYER_LEFTPOS) {

			x -= speed;
			x2 -= speed;
		}
		if (x <= PLAYER_LEFTPOS && y >= PLAYER_LEFTRIGHTPOS) {

			y -= speed;
			y2 -= speed;
		}
		if (y <= PLAYER_LEFTRIGHTPOS) {

			//プレイヤーの場所を左にする
			PlayerPos = 0;

			//移動方向をリセットする
			isMove = 4;
		}
		if (isOps == true && isOps_RIGHT == true && x <= PLAYER_LEFTPOS && y <= PLAYER_LEFTRIGHTPOS) {
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
		if (x <= PLAYER_RIGHTPOS) {

			x += speed;
			x2 += speed;
		}
		if (x >= PLAYER_RIGHTPOS && y <= PLAYER_LEFTRIGHTPOS) {

			y += speed;
			y2 += speed;
		}
		if (y >= PLAYER_LEFTRIGHTPOS) {

			//プレイヤーの場所を右にする
			PlayerPos = 2;

			//移動方向をリセットする
			isMove = 4;

			//移動キーのチェックをリセット
			isMoveKey = false;
		}
		if (isOps == true && isOps_LEFT == true && x >= PLAYER_RIGHTPOS && y >= PLAYER_LEFTRIGHTPOS) {
			isOps = false;
			isOps_LEFT = false;
			isOps_RUN = false;
		}
	}
	//下から右へ
	if (PlayerPos == 3 && isMove == 2) {
		if (x <= PLAYER_RIGHTPOS) {

			x += speed;
			x2 += speed;
		}
		if (x >= PLAYER_RIGHTPOS && y >= PLAYER_LEFTRIGHTPOS) {

			y -= speed;
			y2 -= speed;
		}
		if (y <= PLAYER_LEFTRIGHTPOS) {

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

//***プレイヤーの攻撃処理***//
//現在はプレイヤーの中心から発射されるようにしている。
//弾を打って、まだ弾が画面上にある間に動くと弾も移動するバグがある。
//後で治す
//***************************//
void BasePlayer::Attack()
{
	//***当たり判定のテスト用***//
	float xx = 700;
	float yy = 300;

	float xx2 = 50;
	float yy2 = 100;
	//**************************//

	if (AttackTime < 5)
	{
		AttackTime++;
	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1) && AttackTime >= 5)
	{
		AttackTime = 0;
		for (int i = 0; i < MAX_SHOT; ++i)
		{
			if (shot[i].flag == 0 && PlayerPos == 0)
			{
				shot[i].x = (x + 24);  //弾のx座標
				shot[i].y = (y + 24); //弾のy座標

				shot[i].flag = 1;
				break;
			}
			if (shot[i].flag == 0 && PlayerPos == 1)
			{
				shot[i].x = (x + 24);  //弾のx座標
				shot[i].y = (y + 24);  //弾のy座標

				shot[i].flag = 1;
				break;
			}
			if (shot[i].flag == 0 && PlayerPos == 2)
			{
				shot[i].x = (x + 24);  //弾のx座標
				shot[i].y = (y + 24);  //弾のy座標

				shot[i].flag = 1;
				break;
			}
			if (shot[i].flag == 0 && PlayerPos == 3)
			{
				shot[i].x = (x + 24);  //弾のx座標
				shot[i].y = (y + 24);  //弾のy座標

				shot[i].flag = 1;
				break;
			}
		}
	}
	for (int i = 0; i < MAX_SHOT; ++i)
	{
		if (shot[i].flag == 1 && PlayerPos == 0)
		{

			shot[i].x -= 5;
			DrawCircle(shot[i].x, shot[i].y, 10, GetColor(255, 255, 255), TRUE);
		}
		if (shot[i].flag == 1 && PlayerPos == 1)
		{

			shot[i].y -= 5;
			DrawCircle(shot[i].x, shot[i].y, 10, GetColor(255, 255, 255), TRUE);
		}
		if (shot[i].flag == 1 && PlayerPos == 2)
		{

			shot[i].x += 5;
			DrawCircle(shot[i].x, shot[i].y, 10, GetColor(255, 255, 255), TRUE);
		}
		if (shot[i].flag == 1 && PlayerPos == 3)
		{

			shot[i].y += 5;
			DrawCircle(shot[i].x, shot[i].y, 10, GetColor(255, 255, 255), TRUE);
		}

		if (shot[i].x < 0)
		{
			shot[i].flag = 0;
		}
		if (shot[i].y < 0)
		{
			shot[i].flag = 0;
		}
		if (shot[i].x > 1024)
		{
			shot[i].flag = 0;
		}
		if (shot[i].y > 768)
		{
			shot[i].flag = 0;
		}
		int yyy = 50 + (i * 25);
		DrawFormatString(0, yyy, GetColor(255, 255, 255), "shot:flag:[%d]", shot[i].flag);
		DrawFormatString(200, yyy, GetColor(255, 255, 255), "shot:x:[%f]", shot[i].x);

		ClisionHit(shot[i].x, shot[i].y, shot[i].width, shot[i].height,
			xx, yy, xx2, yy2);
	}

}


bool BasePlayer::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh)
{
	if (mx < (ox + ow) && my < (oy + oh) &&
		ox < (mx + mw) && oy < (my + mh))
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
	DrawBox(x, y, x+width, y+height, GetColor(0,255,0),TRUE);

	DrawFormatString(0, 0, GetColor(255, 255, 255), "%f %f %f %f", x, x2, y, y2);
	DrawFormatString(0, 25, GetColor(255, 255, 255), "isMove:%d  PlayerPos:%d", isMove, PlayerPos);

}

//プレイヤーの更新処理
void BasePlayer::Update()
{
	//***テスト用***//
	float xx = 500;
	float yy = 400;
	//**************//
	Move();
	Attack();
	ClisionHit(x, y, width, height, xx, yy, 48, 48);

}