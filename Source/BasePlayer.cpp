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

	isDamage = false;

	//プレイヤーの初期座標
	x = PLAYER_SPOWNPOSX;
	y = PLAYER_SPOWNPOSY;

	//テスト用
	x2 = 348;
	y2 = 396;
	//テスト用のカラー
	Color = GetColor(255, 0, 0);

}

//プレイヤーの移動処理
void BasePlayer::Move()
{
	//←キーを押したとき
	if ((Input::Instance()->GetPressCount(KEY_INPUT_LEFT) == 1)) {

		isMove = 0;
	}
	//↑キーを押したとき
	if ((Input::Instance()->GetPressCount(KEY_INPUT_UP) == 1)) {

		isMove = 1;
	}
	//→キーを押したとき
	if ((Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) == 1)) {

		isMove = 2;
	}
	//↓キーを押したとき
	if ((Input::Instance()->GetPressCount(KEY_INPUT_DOWN) == 1)) {

		isMove = 3;
	}
	//移動方向が左の時、左へ移動させる
	if (isMove == 0) {
		Move_LEFT();
	}
	//移動方向が上の時、上へ移動させる
	if (isMove == 1) {
		Move_UP();
	}
	//移動方向が右の時、右へ移動させる
	if (isMove == 2) {
		Move_RIGHT();
	}
	//移動方向が下の時、下へ移動させる
	if (isMove == 3) {
		Move_DOWN();
	}
}
void BasePlayer::Move_UP()
{
	//左から上へ
	if (PlayerPos == 0 && isMove == 1) {
		if (y >= 180) {

			y -= speed;
			y2 -= speed;
		}
		if (y <= 180 && x <= 486) {

			x += speed;
			x2 += speed;
		}
		if (x >= 486 && y <= 180) {

			//プレイヤーの場所を上にする
			PlayerPos = 1;

			//移動方向をリセットする
			isMove = 4;
		}
	}
	//右から上へ
	if (PlayerPos == 2 && isMove == 1) {
		if (y >= 180) {

			y -= speed;
			y2 -= speed;
		}
		if (y <= 180 && x >= 486) {

			x -= speed;
			x2 -= speed;
		}
		if (y <= 180 && x <= 486) {

			//プレイヤーの場所を上にする
			PlayerPos = 1;

			//移動方向をリセットする
			isMove = 4;
		}
	}
}
//下へ移動する処理
void BasePlayer::Move_DOWN()
{
	//左から下へ
	if (PlayerPos == 0 && isMove == 3) {
		if (y <= 548) {

			y += speed;
			y2 += speed;
		}
		if (y >= 548 && x <= 486) {

			x += speed;
			x2 += speed;
		}
		if (x >= 486) {

			//プレイヤーの場所を下にする
			PlayerPos = 3;

			//移動方向をリセットする
			isMove = 4;
		}
	}
	//右から下へ
	if (PlayerPos == 2 && isMove == 3) {
		if (y <= 548) {

			y += speed;
			y2 += speed;
		}
		if (y >= 548 && x >= 486) {

			x -= speed;
			x2 -= speed;
		}
		if (x <= 486) {

			//プレイヤーの場所を下にする
			PlayerPos = 3;

			//移動方向をリセットする
			isMove = 4;
		}
	}
}
//左へ移動する処理
void BasePlayer::Move_LEFT()
{
	//上から左へ
	if (PlayerPos == 1 && isMove == 0) {
		if (x >= 300) {

			x -= speed;
			x2 -= speed;
		}
		if (x <= 300 && y <= 348) {

			y += speed;
			y2 += speed;
		}
		if (y >= 345) {

			//プレイヤーの場所を左にする
			PlayerPos = 0;

			//移動方向をリセットする
			isMove = 4;
		}
	}
	//下から左へ
	if (PlayerPos == 3 && isMove == 0) {
		if (x >= 300) {

			x -= speed;
			x2 -= speed;
		}
		if (x <= 300 && y >= 348) {

			y -= speed;
			y2 -= speed;
		}
		if (y <= 345) {

			//プレイヤーの場所を左にする
			PlayerPos = 0;

			//移動方向をリセットする
			isMove = 4;
		}
	}
}
//右へ移動する処理
void BasePlayer::Move_RIGHT()
{
	//上から右へ
	if (PlayerPos == 1 && isMove == 2) {
		if (x <= 676) {

			x += speed;
			x2 += speed;
		}
		if (x >= 676 && y <= 348) {

			y += speed;
			y2 += speed;
		}
		if (y >= 345) {

			//プレイヤーの場所を右にする
			PlayerPos = 2;

			//移動方向をリセットする
			isMove = 4;
		}
	}
	//下から右へ
	if (PlayerPos == 3 && isMove == 2) {
		if (x <= 676) {

			x += speed;
			x2 += speed;
		}
		if (x >= 676 && y >= 348) {

			y -= speed;
			y2 -= speed;
		}
		if (y <= 345) {

			//プレイヤーの場所を右にする
			PlayerPos = 2;

			//移動方向をリセットする
			isMove = 4;
		}
	}

}

//プレイヤーの攻撃処理
void BasePlayer::Attack()
{


}


bool BasePlayer::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh)
{

	return 1;
}


//プレイヤーの描画処理
void BasePlayer::Draw()
{
	//テスト用の描画
	DrawBox(x, y, x2,y2, Color, TRUE);

}

//プレイヤーの更新処理
void BasePlayer::Update()
{


}

//プレイヤーの処理まとめ
void BasePlayer::All()
{
	Draw();
	Move();
	
}