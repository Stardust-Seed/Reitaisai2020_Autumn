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
		BP_speed = 8;					//移動速度
		BP_power = 30;					//攻撃力
		BP_abilityCount = 3;		    //スキル回数
		BP_graphNo = 2;                //画像ナンバー
		BP_animNo = 2;                 //アニメーションナンバー
		BP_attackTime = 10;            //攻撃間隔
		BP_abilityTimer = BP_STOPTIME;    //咲夜用スキル時間タイマー
		maxCharge = MAX_CHAGE_SAKUYA; //チャージゲージの最大値
	}
	/***フランステータス***/
	if (playerType == FRAN)
	{
		BP_speed = 3;					//移動速度
		BP_power = 50;			        //攻撃力
		BP_abilityCount = 2;		    //スキル回数
		BP_graphNo = 0;                //画像ナンバー
		
		BP_animNo = 0;                 //アニメーションナンバー
		BP_attackTime = 5;             //攻撃間隔
		BP_abilityTimer = BP_FRANTIME;    //フランスキル発動までの待機時間
		BP_franAbility = false;        //フランスキルの発動フラグ
		BP_franTimer = 0;              //スキル発動までのカウント
		maxCharge = MAX_CHAGE_FRAN; //チャージゲージ最大値
	}

	BP_star01X = pos.x - 5;             //スタン時の☆のx座標
	BP_star01Y = pos.y - 10;            //スタン時の☆のy座標
	BP_star02X = pos.x + 35;            //スタン時の☆のx座標
	BP_star02Y = pos.y - 10;            //スタン時の☆のy座標
	BP_stanTime = 0;					 //スタンタイム
	BP_stanTime_stay = 0;			     //スタン再発動までの時間

	direction = eDirection::Left;	 //プレイヤーの向き。最初は左

	BP_isDraw = true;              //true:描画ON false:描画OFF
	BP_isMove = false;				//移動している：true  移動していない：false
	BP_isAttack = false;           //攻撃してるかどうか
	BP_isStan = false;             //スタンしてるかどうか
	BP_isStan_Next = true;         //次のスタンが起きるかどうか
	BP_isAbility = false;          //スキルが発動しているかどうか

	BP_animWait = ANIMETION_SPEED; //アニメーション速度

	BP_animLR = true;              //最初は左向き

	BP_countDown = FRAME;          //スキルタイマーを減らすのに使う

	BP_drawAngle = 0;              //描画の角度
	BP_drawZoom = 1.0;             //描画の拡大率

	BP_shotPower = 0;              //チャージゲージ
	BP_fadeCount = 0;              //カットインカウント

	BP_catX = 400;                 //スキルカットイン_X
	BP_catY = 850;                 //スキルカットイン_Y
}

void BasePlayer::Draw(GameResource* _gameRes)
{

	Draw_Ability(); //スキル演出
	Draw_Arow();    //矢印描画

	/***プレイヤー描画処理***/
	if (BP_isDraw == true)
	{
		//左向き
		if (BP_animLR == true)
		{
			Image::Instance()->TransparentGraph(pos.x, pos.y, Image::Instance()->GetGraph(eImageType::Gpicture_Player, BP_graphNo));
		}
		//右向き
		else
		{
			Image::Instance()->TransparentGraph(pos.x, pos.y, Image::Instance()->GetGraph(eImageType::Gpicture_Player, BP_graphNo), 255, true);
		}
	}

	//スタン中の演出
	if (BP_isStan == true) {
		//☆がピカピカさせます
		Image::Instance()->TransparentGraph(BP_star01X, BP_star01Y, Image::Instance()->GetGraph(eImageType::Gpicture_Star), 255, true);
		Image::Instance()->TransparentGraph(BP_star02X, BP_star02Y, Image::Instance()->GetGraph(eImageType::Gpicture_Star), 255, true);
	}
}
void BasePlayer::Draw_Ability()
{

	//スキル時の演出
	if ((Get_isAbility() == true && playerType == SAKUYA) || Get_FranAbility() == true)
	{
		//魔法陣ブワァァァ
		DrawRotaGraph(pos.x + 24, pos.y + 24, BP_drawZoom, PI * BP_drawAngle, Image::Instance()->GetGraph(eImageType::Gpicture_Magic), TRUE);
		
		if (playerType == SAKUYA) {
			//カットイン(白目)
			//クソ地味だからカットインの左側にセリフでも入れようかな。後効果音
			BP_fadeCount = Image::Instance()->FadeInGraph(BP_catX, BP_catY, Image::Instance()->GetGraph(eImageType::Spicture_SelectPlayer, 0), BP_fadeCount, 50);

			//時計
			Image::Instance()->FadeInGraph(550, 150, Image::Instance()->GetGraph(eImageType::Skil_Sakuya), BP_fadeCount, 250);
		}
		else
		{
			//カットイン(白目)
			BP_fadeCount = Image::Instance()->FadeInGraph(BP_catX, BP_catY, Image::Instance()->GetGraph(eImageType::Spicture_SelectPlayer, 1), BP_fadeCount, 50);

			//目
			Image::Instance()->FadeInGraph(550, 200, Image::Instance()->GetGraph(eImageType::Skil_Fran), BP_fadeCount, 250);
		}

		if (BP_catY >= 700)
		{
			//下からカットイン
			BP_catY -= 10;
		}
		
	}
	else
	{
		BP_catY = 850; //カットインを初期位置に
		BP_fadeCount = 0;
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
		BP_power = BP_power * _gameRes->buffManager->GetPowerBuff();   //バフによる攻撃力増加
		BP_speed = 5 * _gameRes->buffManager->GetSpeedBuff();   //バフによるスピード増加

	}
	if (playerType == FRAN)
	{
		BP_power = BP_power * _gameRes->buffManager->GetPowerBuff();   //バフによる攻撃力増加
		BP_speed = 3 * _gameRes->buffManager->GetSpeedBuff();   //バフによるスピード増加

	}
	//スタン状態でない時
	if (BP_isStan == false) {

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
					if (BP_isStan_Next == true) {
						BP_isStan = true;   //スタンは少ししてから解除されるので
					}
				}
			}
		}
	}
	//スタン処理
	if (BP_isStan == true)
	{
		Stan(_gameRes->buffManager);
	}
	if (BP_isStan_Next == true)
	{
		BP_isDraw = true;
	}
	//スタンが解除されたら次にスタンが起こる時間をプラス
	if (BP_isStan_Next == false)
	{
		if (BP_stanTime_stay < 240) {
			BP_stanTime_stay++;
		}
		if (BP_stanTime_stay >= 240)
		{
			BP_isStan_Next = true;
			BP_stanTime_stay = 0;

		}

		//無敵時の点滅処理
		if (BP_stanTime_stay % 15 == 0)
		{
			BP_isDraw = false;
		}
		else
		{
			BP_isDraw = true;
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
	if (BP_stanTime == 0)
	{
		SE::Instance()->PlaySE(SE_Stan, DX_PLAYTYPE_BACK);
		_bManager->DownBuffLevel();  //バフレベルダウン
		BP_star01X = pos.x - 3;         //星の位置を設定
		BP_star01Y = pos.y - 10;        //星の位置を設定
		BP_star02X = pos.x + 35;        //星の位置を設定
		BP_star02Y = pos.y - 10;        //星の位置を設定
	}

	if (BP_stanTime < 20)
	{
		BP_star01X++; //右
		BP_star01Y--; //上
		BP_star02X--; //左
		BP_star02Y++; //下
	}
	else if (BP_stanTime >= 20 && BP_stanTime < 40)
	{
		BP_star01X++; //右
		BP_star01Y++; //下
		BP_star02X--; //左
		BP_star02Y--; //上
	}
	else if (BP_stanTime >= 40 && BP_stanTime < 60)
	{
		BP_star01X--; //左
		BP_star01Y++; //下
		BP_star02X++; //右
		BP_star02Y--; //上
	}
	else if (BP_stanTime >= 60 && BP_stanTime < 80)
	{
		BP_star01X--; //左
		BP_star01Y--; //上
		BP_star02X++; //右
		BP_star02Y++; //下
	}

	//スタンタイムを加算
	if (BP_stanTime < 100) {
		BP_stanTime++;
	}
	//一定時間経過したらスタンを解除してスタンタイムをリセット
	if (BP_stanTime >= 100)
	{
		BP_stanTime = 0;
		BP_stanTime_stay = 0;
		BP_isStan_Next = false;
		BP_isStan = false;
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

	if (BP_attackTime < 20)   //攻撃間隔
	{
		BP_attackTime++;
	}
	if (BP_isMove == false) {
		if ((Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1) && BP_attackTime >= 20)
		{
			//攻撃flagをtrueにする
			BP_isAttack = true;
			//弾を飛ばす
			bulletManager->Shot(pos, playerType, direction, BP_isAttack, BP_power,BP_shotPower);
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
				BP_attackTime = 5;
			}
			else
			{
				//攻撃間隔 咲夜は早い
				BP_attackTime = 10;
			}

		}

		//チャージショット
		if (BP_shotPower == maxCharge) {
			if ((Input::Instance()->GetPressCount(KEY_INPUT_Z) == 0))
			{
				//弾を飛ばす
				bulletManager->Shot(pos, playerType, direction, BP_isAttack,BP_power,BP_shotPower);
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

	//チャージショツトBP_powerチャージ
	if ((Input::Instance()->GetPressCount(KEY_INPUT_Z) >= 1) && BP_shotPower < maxCharge)
	{
		//押してる間パワーチャージ
		BP_shotPower += 1;
	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_Z) <= 0) && BP_shotPower > LOW_CHAGE)
	{
		//押してない間パワーダウン
		BP_shotPower -= 1;
	}


}
//アニメーション処理
void BasePlayer::Animation()
{
	if (--BP_animWait <= 0) {

		BP_animNo++;

		BP_animWait = ANIMETION_SPEED;  //待ち時間を戻す

		/*************
		アニメーション番号が、最大より大きければ
		ANIMETION_MAX分を引いてそれ以下の値にする
		*************/
		BP_animNo %= ANIMETION_MAX;
	}
	//画像番号に、アニメーションの番号を入れる
	if (playerType == SAKUYA)
	{
		BP_graphNo = BP_sakuyaAnim[BP_animNo];
	}
	if (playerType == FRAN)
	{
		BP_graphNo = BP_franAnim[BP_animNo];
	}
}
void BasePlayer::onAbility()
{
	//スキル回数がまだ残っている時
	if (BP_abilityCount > 0 && Get_isAbility() == false) {
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
				BP_isAbility = true;
				BP_abilityCount -= 1;
			}
			if (playerType == FRAN && BP_franAbility == false)
			{
				//心臓の音
				SE::Instance()->PlaySE(SE_Hart, DX_PLAYTYPE_BACK);

				//スキル処理の為のフラグを切り替える
				BP_franAbility = true;
				BP_abilityCount -= 1;
			}
		}
	}
	if (BP_franAbility == true)
	{

		if (BP_drawZoom <= 3)
		{
			BP_drawZoom += 0.02;
		}
		BP_drawAngle += 0.02;
		if (BP_abilityTimer >= 0 && BP_countDown <= 0) {	    //表示されているタイマーを0にしたいのでカウントダウン自体は0になるまで動かす

			BP_abilityTimer -= 1;
			BP_countDown = FRAME;
		}
		if (BP_abilityTimer <= 0)
		{
			BP_isAbility = true;
			BP_franAbility = false;
			BP_abilityTimer = BP_FRANTIME;
			//SEを止める 心臓
			SE::Instance()->StopSE(SE_Hart);
			//SEを鳴らす 爆発
			SE::Instance()->PlaySE(SE_FranAbility, DX_PLAYTYPE_BACK);

		}
		BP_countDown -= 1;
	}
}
void BasePlayer::CharaAbility()
{
	/***咲夜のスキル処理***/
	if (Get_isAbility() == true && playerType == SAKUYA) {

		if (BP_drawZoom <= 3)
		{
			BP_drawZoom += 0.02; //スキル発動中の魔法陣をズームさせる
		}
		BP_drawAngle += 0.02;
		if (BP_abilityTimer >= 0 && BP_countDown <= 0) {	    //表示されているタイマーを0にしたいのでカウントダウン自体は0になるまで動かす
			BP_abilityTimer -= 1;
			BP_countDown = FRAME;
		}
		if (BP_abilityTimer <= 0)
		{
			
			BP_abilityTimer = BP_STOPTIME;    //時止めスキルの時間を代入
			BP_drawAngle = 0;              //描画の角度
			BP_drawZoom = 1.0;             //描画の拡大率
			//再生を止めるとき
			SE::Instance()->StopSE(SE_SakuyaAbility);
			BP_isAbility = false;
		}
		BP_countDown -= 1;
	}
	/**********************/

	/***フランスキル処理***/
	if (Get_isAbility() == true && playerType == FRAN) {

		BP_franTimer += 1;

		if (Get_isAbility() == true && BP_franTimer >= 3) {    //フランのスキルは発動したらすぐ終了する

			BP_franTimer = 0;
			BP_drawAngle = 0;
			BP_drawZoom = 1.0;
			BP_isAbility = false;

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
		BP_isMove = true;
		direction = eDirection::Left;  //←向き状態
		BP_animLR = true;

	}
	//↑キーを押したとき
	if ((Input::Instance()->GetPressCount(KEY_INPUT_UP) >= 1)) {

		Move_UP();      //↑移動
		BP_isMove = true;
		direction = eDirection::Up;  //↑向き状態

	}
	//→キーを押したとき
	if ((Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) >= 1)) {

		Move_RIGHT();   //→移動
		BP_isMove = true;
		direction = eDirection::Right;  //→向き状態
		BP_animLR = false;

	}
	//↓キーを押したとき
	if ((Input::Instance()->GetPressCount(KEY_INPUT_DOWN) >= 1)) {

		Move_DOWN();    //↓移動
		BP_isMove = true;
		direction = eDirection::Down;  //↓向き状態

	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_DOWN) <= 0) && (Input::Instance()->GetPressCount(KEY_INPUT_UP) <= 0) &&
		(Input::Instance()->GetPressCount(KEY_INPUT_LEFT) <= 0) && (Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) <= 0))
	{
		BP_isMove = false; //移動してないときはフラグをfalseにする
	}

}

//上に移動する処理
void BasePlayer::Move_UP()
{
	if (pos.y >= 426 && (pos.x <= 846 || pos.x >= 1020))
	{
		pos.y -= BP_speed;
		Animation();
	}
}

//下へ移動する処理
void BasePlayer::Move_DOWN()
{
	if (pos.y <= 606 && (pos.x <= 846 || pos.x >= 1020))
	{
		pos.y += BP_speed;
		Animation();
	}
}

//左へ移動する処理
void BasePlayer::Move_LEFT()
{
	if (pos.x >= 846 && (pos.y <= 426 || pos.y >= 606))
	{
		pos.x -= BP_speed;
		Animation();
	}
}
//右へ移動する処理
void BasePlayer::Move_RIGHT()
{
	if (pos.x <= 1020 && (pos.y <= 426 || pos.y >= 606))
	{
		pos.x += BP_speed;
		Animation();
	}
}
//攻撃力のセッター
void BasePlayer::Set_power(int _BP_power, BuffManager* _bManager)
{
	BP_power = _BP_power * _bManager->GetPowerBuff();
}

