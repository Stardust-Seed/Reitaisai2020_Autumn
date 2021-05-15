#include <DxLib.h>
#include "CastleManager.h"

CastleManager::CastleManager() {

	cnt = 1;
	number = 1;
	installCnt = 0;

	for (int i = 0; i < 8; i++)
	{
		numberFlg[i] = false;
	}

	for (int i = 0; i < POPCASTLE; i++)
	{
		Castles[i] = NULL;		   //CastleのポインタにNULL
	}

	for (int i = 0; i < POPCASTLE; i++)
	{
		if (Castles[i] == NULL)    //NULLの場合生成開始
		{
			if (i == 0)            //メイン拠点
			{
				durability = 100;
				Castles[i] = new MainCastle(durability);     //生成処理
				activeCountFlg[i] = true;
			}
		}
	}

	occupiedNum = 0;
}

CastleManager::~CastleManager() {

	for (int num = 0; num < POPCASTLE; num++) 
	{
		delete Castles[num];       //デリート処理
	}
}

//更新処理
void CastleManager::Update(GameResource* _gameRes)
{
	//数字キーでの番号指定時の処理
	if ((Input::Instance()->GetPressCount(KEY_INPUT_1) == 1))
	{
		number = 1;
	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_2) == 1))
	{
		number = 2;
	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_3) == 1))
	{
		number = 3;
	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_4) == 1))
	{
		number = 4;
	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_5) == 1))
	{
		number = 5;
	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_6) == 1))
	{
		number = 6;
	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_7) == 1))
	{
		number = 7;
	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_8) == 1))
	{
		number = 8;
	}


	if ((Input::Instance()->GetPressCount(KEY_INPUT_V) == 1))
	{
		number--;

		if (number < 1)
		{
			number = 8;
		}
	}

	if ((Input::Instance()->GetPressCount(KEY_INPUT_B) == 1))
	{
		number++;

		if (number > 8)
		{
			number = 1;
		}
	}

	if ((Input::Instance()->GetPressCount(KEY_INPUT_C) == 1) && numberFlg[number - 1] == false)
	{
		if (cnt < POPCASTLE)
		{
			numberFlg[number - 1] = true;
			installCnt++;
			durability = 25;
			Castles[cnt] = new SubCastle(durability, cnt, number);   //生成処理
			activeCountFlg[cnt] = true;
			cnt++;
		}
	}

	for (int i = 0; i < POPCASTLE; i++)
	{
		if (Castles[i] != NULL)
		{
			if (i == 0)
			{
				Castles[i]->Update(_gameRes->enemyManager, _gameRes->eventManager);
			}
			else
			{
				Castles[i]->Update(_gameRes->enemyManager);
			}

			if (Castles[i]->GetIsActive() == false && i != 0)
			{
				//一回だけ処理させたいので
				if (activeCountFlg[i] == true)
				{
					SE::Instance()->PlaySE(SE_CastleBreak);
					occupiedNum++;                //アクティブな拠点の数を減らす
					activeCountFlg[i] = false;    //一回以上処理させない用のフラグ
				}
			}
		}
	}
}

//描画
void CastleManager::Draw()
{
	for (int i = 0; i < POPCASTLE; i++)
	{
		if (Castles[i] != NULL)
		{
			Castles[i]->Draw();
		}
	}

	//DrawFormatString(120, 120, GetColor(255, 255, 255), "%d", cnt);
	//DrawFormatString(100, 100, GetColor(255, 255, 255), "%d", number);

	//設置できる場所の表示
	if(!numberFlg[0])DrawGraphF(SubCastle::COORDINATE_X_ONE - 4 - 48, SubCastle::COORDINATE_Y_ONE - 80 - 4, Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 2), TRUE);
	if (!numberFlg[1])DrawGraphF(SubCastle::COORDINATE_X_TWO - 4 - 48, SubCastle::COORDINATE_Y_TWO + 32 - 4, Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 2), TRUE);
	if (!numberFlg[2])DrawGraphF(SubCastle::COORDINATE_X_THREE + 32 - 4, SubCastle::COORDINATE_Y_THREE - 48 - 4, Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 2), TRUE);
	if (!numberFlg[3])DrawGraphF(SubCastle::COORDINATE_X_FOUR - 80 - 4, SubCastle::COORDINATE_Y_FOUR - 48 - 4, Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 2), TRUE);
	if (!numberFlg[4])DrawGraphF(SubCastle::COORDINATE_X_FIVE + 48 - 4, SubCastle::COORDINATE_Y_FIVE + 32 - 4, Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 2), TRUE);
	if (!numberFlg[5])DrawGraphF(SubCastle::COORDINATE_X_SIX + 48 - 4, SubCastle::COORDINATE_Y_SIX - 80 - 4, Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 2), TRUE);
	if (!numberFlg[6])DrawGraphF(SubCastle::COORDINATE_X_SEVEN - 80 - 4, SubCastle::COORDINATE_Y_SEVEN + 48 - 4, Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 2), TRUE);
	if (!numberFlg[7])DrawGraphF(SubCastle::COORDINATE_X_EIGHT + 32 - 4, SubCastle::COORDINATE_Y_EIGHT + 48 - 4, Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 2), TRUE);
	
}

//i番目の拠点の生存しているかを受け取る
bool CastleManager::Get_IsActive(int num)
{
	if (Castles[num] != NULL)
	{
		return Castles[num]->GetIsActive();
	}
	else
	{
		return 0;
	}
}

//i番目の拠点の耐久を受け取る
int CastleManager::Get_Durability(int num)
{
	if (Castles[num] != NULL)
	{
		return Castles[num]->Get_Durability();
	}
	else
	{
		return 0;
	}
}

//拠点の数を返す
int CastleManager::Get_CastleNum()
{
	return POPCASTLE;
}

//設置できるサブ拠点の数を返す
int CastleManager::Get_installCastle()
{
	return POPCASTLE - 1 - installCnt;
}

//設置予定のサブ拠点番号を返す
int CastleManager::Get_installNum()
{
	return number;
}

//占領されたサブ拠点の数を受け取る
int CastleManager::Get_OccupiedNum()
{
	return occupiedNum;
}

//i番目の拠点のx座標を受け取る
float CastleManager::Get_X(int _num)
{
	if (Castles[_num] != NULL)
	{
		return Castles[_num]->Get_X();
	}
	else
	{
		return 0;
	}
}

//i番目の拠点のy座標を受け取る
float CastleManager::Get_Y(int _num)
{
	if (Castles[_num] != NULL) 
	{
		return Castles[_num]->Get_Y();
	}
	else
	{
		return 0;
	}
}

//i番目の拠点の幅を受け取る
float CastleManager::Get_Width(int _num)
{
	if (Castles[_num] != NULL) 
	{
		return Castles[_num]->Get_Width();
	}
	else
	{
		return 0;
	}
}

//i番目の拠点の高さを受け取る
float CastleManager::Get_Height(int _num)
{
	if (Castles[_num] != NULL) 
	{
		return Castles[_num]->Get_Height();
	}
	else
	{
		return 0;
	}
}

//i番目の拠点を表示するX座標を受け取る
float CastleManager::Get_DrawPosX(int num)
{
	if (Castles[num] != NULL) 
	{
		return Castles[num]->Get_DrawPosX();
	}
	else
	{
		return 0;
	}
}

//i番目の拠点を表示するY座標を受け取る
float CastleManager::Get_DrawPosY(int num)
{
	if (Castles[num] != NULL) 
	{
		return Castles[num]->Get_DrawPosY();
	}
	else
	{
		return 0;
	}
}

//i番目の拠点で生成する敵のX座標を受け取る
float CastleManager::Get_PopPosX(int num)
{
	if (Castles[num] != NULL) 
	{
		return Castles[num]->Get_PopPosX();
	}
	else
	{
		return 0;
	}
}

//i番目の拠点で生成する敵のY座標を受け取る
float CastleManager::Get_PopPosY(int num)
{
	if (Castles[num] != NULL) 
	{
		return Castles[num]->Get_PopPosY();
	}
	else
	{
		return 0;
	}
}

//i番目の拠点の方向を受け取る
eDirection CastleManager::Get_CastleDirection(int num)
{
	if (Castles[num] != NULL)
	{
		return Castles[num]->Get_CastleDirection();
	}
	else
	{
		return eDirection::None;
	}
}

void CastleManager::Damage_Proc(int num, int _damage)
{
	if (Castles[num] != NULL)
	{
		Castles[num]->Damage_Proc(_damage);
	}
}