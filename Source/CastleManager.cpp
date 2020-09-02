#include <DxLib.h>
#include "CastleManager.h"

CastleManager::CastleManager() {
	for (int i = 0; i < POPCASTLE; i++)
	{
		Castles[i] = NULL;		//CastleのポインタにNULL
	}

	activeCount = 0;				//生成カウント初期化
}

CastleManager::~CastleManager() {
	for (int num = 0; num < POPCASTLE; num++) 
	{
		delete Castles[num];		//デリート処理
	}
}

void CastleManager::SpawnCastle()
{
	for (int i = 0; i < POPCASTLE; i++) 
	{
		if (Castles[i] == NULL)    //NULLの場合生成開始
		{
			if (i == 0)
			{
				durability = 100;
				Castles[i] = new MainCastle(durability);    //生成処理
			}
			else
			{
				durability = 50;
				Castles[i] = new SubCastle(durability,i);		//生成処理
			}
		}
	}
}

void CastleManager::Update(EnemyManager*_enemy)
{
	SpawnCastle();    //生成

	for (int i = 0; i < POPCASTLE; i++)
	{
		if (Castles[i] != NULL)
		{
			Castles[i]->Update(_enemy);		//更新処理

			if (Castles[i]->GetIsActive() == false)
			{

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

int CastleManager::Get_X(int _num)
{
	if (Castles[_num] != NULL) {
		return Castles[_num]->Get_X();
	}
}

int CastleManager::Get_Y(int _num)
{
	if (Castles[_num] != NULL) {
		return Castles[_num]->Get_Y();
	}
}

int CastleManager::Get_Width(int _num)
{
	if (Castles[_num] != NULL) {
		return Castles[_num]->Get_Width();
	}
}

int CastleManager::Get_Height(int _num)
{
	if (Castles[_num] != NULL) {
		return Castles[_num]->Get_Height();
	}
}

int CastleManager::Get_IsActive(int num) {
	if (Castles[num] != NULL) {
		return Castles[num]->GetIsActive();
	}
}

int CastleManager::Get_Durability(int num) {
	if (Castles[num] != NULL) {
		return Castles[num]->Get_Durability();
	}
}

void CastleManager::Set_Durability(int num,int _durability) {
	if (Castles[num] != NULL) {
		Castles[num]->Set_Durability(_durability);
	}
}

