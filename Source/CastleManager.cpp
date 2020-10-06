#include <DxLib.h>
#include "CastleManager.h"

CastleManager::CastleManager() {

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
			}
			else                   //サブ拠点
			{
				durability = 25;
				Castles[i] = new SubCastle(durability, i);   //生成処理
			}
			activeCountFlg[i] = true;
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
void CastleManager::Update(EnemyManager*_enemy)
{

	for (int i = 0; i < POPCASTLE; i++)
	{
		if (Castles[i] != NULL)
		{
			Castles[i]->Update(_enemy);

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