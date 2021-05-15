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
#include"SE.h"

BasePlayer::BasePlayer(int _pType)
{
	pos = VGet(PLAYER_LEFTPOS, PLAYER_LEFTRIGHTPOS, 0);
	vPos = VGet(0, 0, 0);

	width = 48;				      //プレイヤー横幅
	height = 48;                  //プレイヤー縦幅

	playerType = _pType;          //使用してるキャラクタータイプ


	/***咲夜ステータス***/
	if (playerType == SAKUYA)
	{
		speed = 8;					//移動速度
		power = 30;					//攻撃力
		abilityCount = 3;		    //スキル回数
		graphNo = 2;                //画像ナンバー
		animNo = 2;                 //アニメーションナンバー
		attackTime = 10;            //攻撃間隔
		abilityTimer = STOPTIME;    //咲夜用スキル時間タイマー
		maxCharge = MAX_CHAGE_SAKUYA; //チャージゲージの最大値
	}
	/***フランステータス***/
	if (playerType == FRAN)
	{
		speed = 3;					//移動速度
		power = 50;			        //攻撃力
		abilityCount = 2;		    //スキル回数
		graphNo = 0;                //画像ナンバー
		animNo = 0;                 //アニメーションナンバー
		attackTime = 5;             //攻撃間隔
		abilityTimer = FRANTIME;    //フランスキル発動までの待機時間
		franAbility = false;        //フランスキルの発動フラグ
		franTimer = 0;              //スキル発動までのカウント
		maxCharge = MAX_CHAGE_FRAN; //チャージゲージ最大値
	}

	star01X = pos.x - 5;             //スタン時の☆のx座標
	star01Y = pos.y - 10;            //スタン時の☆のy座標
	star02X = pos.x + 35;            //スタン時の☆のx座標
	star02Y = pos.y - 10;            //スタン時の☆のy座標
	stanTime = 0;					 //スタンタイム
	stanTime_stay = 0;			     //スタン再発動までの時間

	direction = eDirection::Left;	 //プレイヤーの向き。最初は左

	isDraw = true;              //true:描画ON false:描画OFF
	isMove = false;				//移動している：true  移動していない：false
	isAttack = false;           //攻撃してるかどうか
	isStan = false;             //スタンしてるかどうか
	isStan_Next = true;         //次のスタンが起きるかどうか
	isAbility = false;          //スキルが発動しているかどうか

	animWait = ANIMETION_SPEED; //アニメーション速度

	animLR = true;              //最初は左向き

	countDown = FRAME;          //スキルタイマーを減らすのに使う

	drawAngle = 0;              //描画の角度
	drawZoom = 1.0;             //描画の拡大率

	shotPower = 0;              //チャージゲージ
	fadeCount = 0;              //カットインカウント

	catX = 400;                 //スキルカットイン_X
	catY = 850;                 //スキルカットイン_Y
}

void BasePlayer::Draw(GameResource* _gameRes)
{

	Draw_Ability(); //スキル演出
	Draw_Arow();    //矢印描画

	/***プレイヤー描画処理***/
	if (isDraw == true)
	{
		//左向き
		if (animLR == true)
		{
			Image::Instance()->TransparentGraph(pos.x, pos.y, Image::Instance()->GetGraph(eImageType::Gpicture_Player, graphNo));
		}
		//右向き
		else
		{
			Image::Instance()->TransparentGraph(pos.x, pos.y, Image::Instance()->GetGraph(eImageType::Gpicture_Player, graphNo), 255, true);
		}
	}

	//スタン中の演出
	if (isStan == true) {
		//☆がピカピカさせます
		Image::Instance()->TransparentGraph(star01X, star01Y, Image::Instance()->GetGraph(eImageType::Gpicture_Star), 255, true);
		Image::Instance()->TransparentGraph(star02X, star02Y, Image::Instance()->GetGraph(eImageType::Gpicture_Star), 255, true);
	}
}
void BasePlayer::Draw_Ability()
{

	//スキル時の演出
	if ((Get_isAbility() == true && playerType == SAKUYA) || Get_FranAbility() == true)
	{
		//魔法陣ブワァァァ
		DrawRotaGraph(pos.x + 24, pos.y + 24, drawZoom, PI * drawAngle, Image::Instance()->GetGraph(eImageType::Gpicture_Magic), TRUE);
		
		if (playerType == SAKUYA) {
			//カットイン(白目)
			//クソ地味だからカットインの左側にセリフでも入れようかな。後効果音
			fadeCount = Image::Instance()->FadeInGraph(catX, catY, Image::Instance()->GetGraph(eImageType::Spicture_SelectPlayer, 0), fadeCount, 50);

			//時計
			Image::Instance()->FadeInGraph(550, 150, Image::Instance()->GetGraph(eImageType::Skil_Sakuya), fadeCount, 250);
		}
		else
		{
			//カットイン(白目)
			fadeCount = Image::Instance()->FadeInGraph(catX, catY, Image::Instance()->GetGraph(eImageType::Spicture_SelectPlayer, 1), fadeCount, 50);

			//目
			Image::Instance()->FadeInGraph(550, 200, Image::Instance()->GetGraph(eImageType::Skil_Fran), fadeCount, 250);
		}

		if (catY >= 700)
		{
			//下からカットイン
			catY -= 10;
		}
		
	}
	else
	{
		catY = 850; //カットインを初期位置に
		fadeCount = 0;
	}

}
void BasePlayer::Draw_Arow()
{

	if (direction == eDirection::Left)
	{
		//左向き矢印
		DrawTriangle(pos.x - 30, pos.y + 24, pos.x - 5, pos.y + 32, pos.x - 5, pos.y + 16, GetColor(255, 255, 255), TRUE);
	}
	if (direction == eDirection::Up)
	{
		//上向き矢印
		DrawTriangle(pos.x + 24, pos.y - 30, pos.x + 16, pos.y - 5, pos.x + 32, pos.y - 5, GetColor(255, 255, 255), TRUE);
	}
	if (direction == eDirection::Right)
	{
		//右向き矢印
		DrawTriangle(pos.x + 78, pos.y + 24, pos.x + 53, pos.y + 16, pos.x + 53, pos.y + 32, GetColor(255, 255, 255), TRUE);
	}
	if (direction == eDirection::Down)
	{
		//下向き矢印
		DrawTriangle(pos.x + 24, pos.y + 78, pos.x + 16, pos.y + 53, pos.x + 32, pos.y + 53, GetColor(255, 255, 255), TRUE);
	}
}
void BasePlayer::Update(GameResource* _gameRes)
{

	
	if (playerType == SAKUYA)
	{
		power = power * _gameRes->buffManager->GetPowerBuff();   //バフによる攻撃力増加
		speed = 5 * _gameRes->buffManager->GetSpeedBuff();   //バフによるスピード増加

	}
	if (playerType == FRAN)
	{
		power = power * _gameRes->buffManager->GetPowerBuff();   //バフによる攻撃力増加
		speed = 3 * _gameRes->buffManager->GetSpeedBuff();   //バフによるスピード増加

	}
	//スタン状態でない時
	if (isStan == false) {

		Move();        //移動処理
		Attack();      //攻撃処理
		onAbility();   //スキル発動処理
		CharaAbility();//スキル処理

		for (int i = 0; i < _gameRes->enemyManager->Get_enemyNum(); i++) {

			//プレイヤーが敵に当たったらisStanをtrueにする
			if (ClisionHit(Get_x() + 6, Get_y(), Get_width() - 6, Get_height(),
				_gameRes->enemyManager->Get_x(i), _gameRes->enemyManager->Get_y(i),
				_gameRes->enemyManager->Get_width(i), _gameRes->enemyManager->Get_height(i)))
			{
				if (_gameRes->enemyManager->Get_AttackType(i) != eAttackType::Invasion &&
					_gameRes->enemyManager->Get_InactiveType(i) != eInactiveType::Invasion )
				{
					if (isStan_Next == true) {
						isStan = true;   //スタンは少ししてから解除されるので
					}
				}
			}
		}
	}
	//スタン処理
	if (isStan == true)
	{
		Stan(_gameRes->buffManager);
	}
	if (isStan_Next == true)
	{
		isDraw = true;
	}
	//スタンが解除されたら次にスタンが起こる時間をプラス
	if (isStan_Next == false)
	{
		if (stanTime_stay < 240) {
			stanTime_stay++;
		}
		if (stanTime_stay >= 240)
		{
			isStan_Next = true;
			stanTime_stay = 0;

		}

		//無敵時の点滅処理
		if (stanTime_stay % 15 == 0)
		{
			isDraw = false;
		}
		else
		{
			isDraw = true;
		}

	}


	if (Input::Instance()->GetPressCount(KEY_INPUT_ESCAPE) == 1)
	{
		SE::Instance()->StopSE(SE_Stan);
		SE::Instance()->StopSE(SE_SakuyaAbility);
		SE::Instance()->StopSE(SE_FranAbility);
		SE::Instance()->StopSE(SE_Skil);

	}
}
//プレイヤーのスタン処理
void BasePlayer::Stan(BuffManager* _bManager)
{

	//バフダウン
	if (stanTime == 0)
	{
		SE::Instance()->PlaySE(SE_Stan, DX_PLAYTYPE_BACK);
		_bManager->DownBuffLevel();  //バフレベルダウン
		star01X = pos.x - 3;         //星の位置を設定
		star01Y = pos.y - 10;        //星の位置を設定
		star02X = pos.x + 35;        //星の位置を設定
		star02Y = pos.y - 10;        //星の位置を設定
	}

	if (stanTime < 20)
	{
		star01X++; //右
		star01Y--; //上
		star02X--; //左
		star02Y++; //下
	}
	else if (stanTime >= 20 && stanTime < 40)
	{
		star01X++; //右
		star01Y++; //下
		star02X--; //左
		star02Y--; //上
	}
	else if (stanTime >= 40 && stanTime < 60)
	{
		star01X--; //左
		star01Y++; //下
		star02X++; //右
		star02Y--; //上
	}
	else if (stanTime >= 60 && stanTime < 80)
	{
		star01X--; //左
		star01Y--; //上
		star02X++; //右
		star02Y++; //下
	}

	//スタンタイムを加算
	if (stanTime < 100) {
		stanTime++;
	}
	//一定時間経過したらスタンを解除してスタンタイムをリセット
	if (stanTime >= 100)
	{
		stanTime = 0;
		stanTime_stay = 0;
		isStan_Next = false;
		isStan = false;
		SE::Instance()->StopSE(SE_Stan);
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
			bulletManager->Shot(pos, playerType, direction, isAttack, power,shotPower);
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
				//攻撃感覚 フランは遅い
				attackTime = 5;
			}
			else
			{
				//攻撃間隔 咲夜は早い
				attackTime = 10;
			}

		}

		//チャージショット
		if (shotPower == maxCharge) {
			if ((Input::Instance()->GetPressCount(KEY_INPUT_Z) == 0))
			{
				//弾を飛ばす
				bulletManager->Shot(pos, playerType, direction, isAttack,power,shotPower);
				//チャージゲージリセット
				Set_chageGauge(0);
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
			}
		}
	}

	//チャージショツトpowerチャージ
	if ((Input::Instance()->GetPressCount(KEY_INPUT_Z) >= 1) && shotPower < maxCharge)
	{
		//押してる間パワーチャージ
		shotPower += 1;
	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_Z) <= 0) && shotPower > LOW_CHAGE)
	{
		//押してない間パワーダウン
		shotPower -= 1;
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
void BasePlayer::onAbility()
{
	//スキル回数がまだ残っている時
	if (abilityCount > 0 && Get_isAbility() == false) {
		//Xキーを押すとスキル発動
		if (Input::Instance()->GetPressCount(KEY_INPUT_X) == 1)
		{
			//SEを鳴らす
			SE::Instance()->PlaySE(SE_Skil, DX_PLAYTYPE_BACK);
			if (playerType == SAKUYA)
			{
				//SEを鳴らす
				SE::Instance()->PlaySE(SE_SakuyaAbility, DX_PLAYTYPE_BACK);
				
				//スキル処理の為のフラグを切り替える
				isAbility = true;
				abilityCount -= 1;
			}
			if (playerType == FRAN && franAbility == false)
			{
				//心臓の音
				SE::Instance()->PlaySE(SE_Hart, DX_PLAYTYPE_BACK);

				//スキル処理の為のフラグを切り替える
				franAbility = true;
				abilityCount -= 1;
			}
		}
	}
	if (franAbility == true)
	{

		if (drawZoom <= 3)
		{
			drawZoom += 0.02;
		}
		drawAngle += 0.02;
		if (abilityTimer >= 0 && countDown <= 0) {	    //表示されているタイマーを0にしたいのでカウントダウン自体は0になるまで動かす

			abilityTimer -= 1;
			countDown = FRAME;
		}
		if (abilityTimer <= 0)
		{
			isAbility = true;
			franAbility = false;
			abilityTimer = FRANTIME;
			//SEを止める 心臓
			SE::Instance()->StopSE(SE_Hart);
			//SEを鳴らす 爆発
			SE::Instance()->PlaySE(SE_FranAbility, DX_PLAYTYPE_BACK);

		}
		countDown -= 1;
	}
}
void BasePlayer::CharaAbility()
{
	/***咲夜のスキル処理***/
	if (Get_isAbility() == true && playerType == SAKUYA) {

		if (drawZoom <= 3)
		{
			drawZoom += 0.02; //スキル発動中の魔法陣をズームさせる
		}
		drawAngle += 0.02;
		if (abilityTimer >= 0 && countDown <= 0) {	    //表示されているタイマーを0にしたいのでカウントダウン自体は0になるまで動かす
			abilityTimer -= 1;
			countDown = FRAME;
		}
		if (abilityTimer <= 0)
		{
			
			abilityTimer = STOPTIME;    //時止めスキルの時間を代入
			drawAngle = 0;              //描画の角度
			drawZoom = 1.0;             //描画の拡大率
			//再生を止めるとき
			SE::Instance()->StopSE(SE_SakuyaAbility);
			isAbility = false;
		}
		countDown -= 1;
	}
	/**********************/

	/***フランスキル処理***/
	if (Get_isAbility() == true && playerType == FRAN) {

		franTimer += 1;

		if (Get_isAbility() == true && franTimer >= 3) {    //フランのスキルは発動したらすぐ終了する

			franTimer = 0;
			drawAngle = 0;
			drawZoom = 1.0;
			isAbility = false;

		}
	}
	/***********************/
}
//プレイヤーの移動処理
void BasePlayer::Move()
{
	//←キーを押したとき
	if ((Input::Instance()->GetPressCount(KEY_INPUT_LEFT) >= 1)) {

		Move_LEFT();    //←移動
		isMove = true;
		direction = eDirection::Left;  //←向き状態
		animLR = true;

	}
	//↑キーを押したとき
	if ((Input::Instance()->GetPressCount(KEY_INPUT_UP) >= 1)) {

		Move_UP();      //↑移動
		isMove = true;
		direction = eDirection::Up;  //↑向き状態

	}
	//→キーを押したとき
	if ((Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) >= 1)) {

		Move_RIGHT();   //→移動
		isMove = true;
		direction = eDirection::Right;  //→向き状態
		animLR = false;

	}
	//↓キーを押したとき
	if ((Input::Instance()->GetPressCount(KEY_INPUT_DOWN) >= 1)) {

		Move_DOWN();    //↓移動
		isMove = true;
		direction = eDirection::Down;  //↓向き状態

	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_DOWN) <= 0) && (Input::Instance()->GetPressCount(KEY_INPUT_UP) <= 0) &&
		(Input::Instance()->GetPressCount(KEY_INPUT_LEFT) <= 0) && (Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) <= 0))
	{
		isMove = false; //移動してないときはフラグをfalseにする
	}

}

//上に移動する処理
void BasePlayer::Move_UP()
{
	if (pos.y >= 426 && (pos.x <= 846 || pos.x >= 1020))
	{
		pos.y -= speed;
		Animation();
	}
}

//下へ移動する処理
void BasePlayer::Move_DOWN()
{
	if (pos.y <= 606 && (pos.x <= 846 || pos.x >= 1020))
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
	if (pos.x <= 1020 && (pos.y <= 426 || pos.y >= 606))
	{
		pos.x += speed;
		Animation();
	}
}
//攻撃力のセッター
void BasePlayer::Set_power(int _power, BuffManager* _bManager)
{
	power = _power * _bManager->GetPowerBuff();
}

