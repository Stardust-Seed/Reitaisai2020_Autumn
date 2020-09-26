#include <DxLib.h>
#include "CastleManager.h"

CastleManager::CastleManager() {

	for (int i = 0; i < POPCASTLE; i++)
	{
		Castles[i] = NULL;		//CastleのポインタにNULL
	}

	for (int i = 0; i < POPCASTLE; i++)
	{
		if (Castles[i] == NULL)    //NULLの場合生成開始
		{
			if (i == 0)  //メイン拠点
			{
				durability = 100;
				Castles[i] = new MainCastle(durability);     //生成処理
			}
			else         //サブ拠点
			{
				durability = 10;
				Castles[i] = new SubCastle(durability, i);    //生成処理
			}
			activeCountFlg[i] = true;
		}
	}

	occupiedNum = 0;
}

CastleManager::~CastleManager() {

	for (int num = 0; num < POPCASTLE; num++) 
	{
		delete Castles[num];    //デリート処理
	}
}

void CastleManager::Update(EnemyManager*_enemy)
{

	for (int i = 0; i < POPCASTLE; i++)
	{
		if (Castles[i] != NULL)
		{
			Castles[i]->Update(_enemy);		      //更新処理

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

void CastleManager::Draw()
{
	for (int i = 0; i < POPCASTLE; i++)
	{
		if (Castles[i] != NULL)
		{
			Castles[i]->Draw();    //描画
		}
	}
}

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

int CastleManager::Get_Durability(int num) 
{
	if (Castles[num] != NULL) {
		return Castles[num]->Get_Durability();
	}
	else
	{
		return 0;
	}
}

eDirection CastleManager::Get_CastleDirection(int num)
{
	if (Castles[num] != NULL) {
		return Castles[num]->Get_CastleDirection();
	}
	else
	{
		return eDirection::None;
	}
}

int CastleManager::Get_CastleNum()
{
	return POPCASTLE;
}

int CastleManager::Get_OccupiedNum()
{
	return occupiedNum;
}

