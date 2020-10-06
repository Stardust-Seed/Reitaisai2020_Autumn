#include"DxLib.h"
#include"Define.h"
#include"Input.h"
#include"BasePlayer.h"
#include"BaseEnemy.h"
#include"BulletManager.h"
#include"BuffManager.h"
#include"EnemyManager.h"
#include "Direction.h"
#include"Image.h"

BasePlayer::BasePlayer(int _pType)
{
	pos = VGet(PLAYER_LEFTPOS, PLAYER_LEFTRIGHTPOS, 0);
	vPos = VGet(0, 0, 0);

	width = 48;
	height = 48;

	playerType = _pType;       //使用してるキャラクタータイプ

	if (playerType == SAKUYA)
	{
		speed = 8;					//移動速度
		power = 40;					//攻撃力
		abilityCount = 3;		    //スキル回数
		graphNo = 2;
		animNo = 2;
		attackTime = 10;
		//咲夜用
		abilityTimer = STOPTIME;        //スキル時間タイマー
	}
	if (playerType == FRAN)
	{
		speed = 3;					//移動速度
		power = 80;			    //攻撃力
		abilityCount = 2;		    //スキル回数
		graphNo = 0;
		animNo = 0;
		attackTime = 5;
		abilityTimer = 0;
	}

	bulletCount = 0;            //弾のカウント

	stanTime = 0;				//スタンタイム
	stanTime_stay = 360;		//スタン再発動までの時間

	playerDirection = 0;			    //プレイヤーの向き。最初は左

	isMove = false;				//移動している：true  移動していない：false
	isAttack = false;           //攻撃してるかどうか
	isStan = false;             //スタンしてるかどうか
	isStan_Next = false;        //次のスタンが起きるかどうか
	isAbility = false;          //スキルが発動しているかどうか

	animWait = ANIMETION_SPEED; //アニメーション速度

	animLR = true;              //最初は左向き

	countDown = FRAME;          //スキルタイマーを減らすのに使う

}
BasePlayer::~BasePlayer()
{

}
void BasePlayer::Draw()
{
	if (animLR == true)
	{
		Image::Instance()->TransparentGraph(pos.x, pos.y, Image::Instance()->GetGraph(eImageType::Gpicture_Player, graphNo));
	}
	else
	{
		Image::Instance()->TransparentGraph(pos.x, pos.y, Image::Instance()->GetGraph(eImageType::Gpicture_Player, graphNo), 255, true);
	}

	Draw_Arow();  //矢印描画

}
void BasePlayer::Draw_Arow()
{
	if (playerDirection == 0)
	{
		//左向き矢印
		DrawTriangle(pos.x - 30, pos.y + 24, pos.x - 5, pos.y + 32, pos.x - 5, pos.y + 16, GetColor(255, 255, 255), TRUE);
	}
	if (playerDirection == 1)
	{
		//上向き矢印
		DrawTriangle(pos.x + 24, pos.y - 30, pos.x + 16, pos.y - 5, pos.x + 32, pos.y - 5, GetColor(255, 255, 255), TRUE);
	}
	if (playerDirection == 2)
	{
		//右向き矢印
		DrawTriangle(pos.x + 78, pos.y + 24, pos.x + 53, pos.y + 16, pos.x + 53, pos.y + 32, GetColor(255, 255, 255), TRUE);
	}
	if (playerDirection == 3)
	{
		//下向き矢印
		DrawTriangle(pos.x + 24, pos.y + 78, pos.x + 16, pos.y + 53, pos.x + 32, pos.y + 53, GetColor(255, 255, 255), TRUE);
	}
}
void BasePlayer::Update(EnemyManager* _eManager, BuffManager* _bManager)
{

	if (playerType == SAKUYA)
	{
		power = 40 * _bManager->GetPowerBuff();   //バフによる攻撃力増加
		speed = 5 * _bManager->GetSpeedBuff();   //バフによるスピード増加
	}
	if (playerType == FRAN)
	{
		power = 80 * _bManager->GetPowerBuff();   //バフによる攻撃力増加
		speed = 3 * _bManager->GetSpeedBuff();   //バフによるスピード増加
	}
	//スタン状態でない時
	if (isStan == 0) {

		Move();        //移動処理
		Attack();      //攻撃処理
		Ability();     //スキル

		/***咲夜のスキル処理***/
		if (Get_isAbility() == true && playerType == SAKUYA) {

			//SEを鳴らす
			SE::Instance()->PlaySE(SE_SakuyaAbility, DX_PLAYTYPE_BACK);
			if (abilityTimer >= 0 && countDown <= 0) {	    //表示されているタイマーを0にしたいのでカウントダウン自体は0になるまで動かす
				abilityTimer -= 1;
				countDown = FRAME;
			}
			if (abilityTimer <= 0)
			{
				isAbility = false;
				abilityTimer = STOPTIME;
				//再生を止めるとき
				SE::Instance()->StopSE(SE_SakuyaAbility);
			}
			countDown -= 1;
		}
		/**********************/

		/***フランスキル処理***/
		if (Get_isAbility() == true && playerType == FRAN) {

			//SEを鳴らす
			SE::Instance()->PlaySE(SE_FranAbility, DX_PLAYTYPE_BACK);
			if (abilityTimer == 1) {    //フランのスキルは発動したらすぐ終了する
				isAbility = false;
				abilityTimer = 0;
			}
			if (Get_isAbility() == true && abilityTimer < 1)
			{
				abilityTimer += 1;
			}
		}
		/***********************/

		for (int i = 0; i < _eManager->Get_enemyNum(); i++) {

			//プレイヤーが敵に当たったらisStanをtrueにする
			if (ClisionHit(Get_x() + 6, Get_y(), Get_width() - 6, Get_height(),
				_eManager->Get_x(i), _eManager->Get_y(i), _eManager->Get_width(i), _eManager->Get_height(i)))
			{
				if (_eManager->Get_AttackType(i) != eAttackType::Invasion)
				{
					isStan = true;   //スタンは少ししてから解除されるので
				}
			}
		}
	}
	if (isStan == true && isStan_Next == true)
	{
		Stan();
		_bManager->DownBuffLevel();  //バフレベルダウン
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

	if (attackTime < 20)   //攻撃間隔
	{
		attackTime++;
	}
	if (isMove == false) {
		if ((Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1) && attackTime >= 20)
		{
			//攻撃flagをtrueにする
			isAttack = true;
			//弾を飛ばす
			bulletManager->Shot(pos, playerDirection, isAttack);
			if (playerType == SAKUYA)
			{
				//SEを鳴らす
				SE::Instance()->PlaySE(SE_SakuyaAttack, DX_PLAYTYPE_BACK);
			}
			else
			{
				//SEを鳴らす
				SE::Instance()->PlaySE(SE_FranAttack, DX_PLAYTYPE_BACK);
			}
			if (playerType == FRAN)
			{
				attackTime = 5;
			}
			else
			{
				attackTime = 10;
			}

		}
	}

}
//アニメーション処理
void BasePlayer::Animation()
{
	if (--animWait <= 0) {

		animNo++;

		animWait = ANIMETION_SPEED;  //待ち時間を戻す

		/*************
		アニメーション番号が、最大より大きければ
		ANIMETION_MAX分を引いてそれ以下の値にする
		*************/
		animNo %= ANIMETION_MAX;
	}
	//画像番号に、アニメーションの番号を入れる
	if (playerType == SAKUYA)
	{
		graphNo = sakuyaAnim[animNo];
	}
	if (playerType == FRAN)
	{
		graphNo = franAnim[animNo];
	}
}
void BasePlayer::Ability()
{
	//スキル回数がまだ残っている時
	if (abilityCount > 0 && Get_isAbility() == false) {
		//スペースキーを押すとスキル発動
		if (Input::Instance()->GetPressCount(KEY_INPUT_X) == 1)
		{
			isAbility = true;
			abilityCount -= 1;
		}
	}
}
//プレイヤーの移動処理
void BasePlayer::Move()
{
	//←キーを押したとき
	if ((Input::Instance()->GetPressCount(KEY_INPUT_LEFT) >= 1)) {

		Move_LEFT();    //←移動
		isMove = true;
		playerDirection = 0;  //←向き状態
		animLR = true;

	}
	//↑キーを押したとき
	if ((Input::Instance()->GetPressCount(KEY_INPUT_UP) >= 1)) {

		Move_UP();      //↑移動
		isMove = true;
		playerDirection = 1;  //↑向き状態

	}
	//→キーを押したとき
	if ((Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) >= 1)) {

		Move_RIGHT();   //→移動
		isMove = true;
		playerDirection = 2;  //→向き状態
		animLR = false;

	}
	//↓キーを押したとき
	if ((Input::Instance()->GetPressCount(KEY_INPUT_DOWN) >= 1)) {

		Move_DOWN();    //↓移動
		isMove = true;
		playerDirection = 3;  //↓向き状態

	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_DOWN) <= 0) && (Input::Instance()->GetPressCount(KEY_INPUT_UP) <= 0) &&
		(Input::Instance()->GetPressCount(KEY_INPUT_LEFT) <= 0) && (Input::Instance()->GetPressCount(KEY_INPUT_DOWN) <= 0))
	{
		isMove = false; //移動してないときはフラグをfalseにする
	}

}

//上に移動する処理
void BasePlayer::Move_UP()
{
	if (pos.y >= 426 && (pos.x <= 846 || pos.x >= 1026))
	{
		pos.y -= speed;
		Animation();
	}
}

//下へ移動する処理
void BasePlayer::Move_DOWN()
{
	if (pos.y <= 606 && (pos.x <= 846 || pos.x >= 1026))
	{
		pos.y += speed;
		Animation();
	}
}

//左へ移動する処理
void BasePlayer::Move_LEFT()
{
	if (pos.x >= 846 && (pos.y <= 426 || pos.y >= 606))
	{
		pos.x -= speed;
		Animation();
	}
}
//右へ移動する処理
void BasePlayer::Move_RIGHT()
{
	if (pos.x <= 1026 && (pos.y <= 426 || pos.y >= 606))
	{
		pos.x += speed;
		Animation();
	}
}
