#include <DxLib.h>
#include "EnemyManager.h"

EnemyManager::EnemyManager() {

	for (int num = 0; num < ENEMY_NUM; num++) {
		Fairy_E[num] = NULL;		//Fairy_EのポインタにNULL
	}
}

EnemyManager::~EnemyManager() {
	for (int num = 0; num < ENEMY_NUM; num++) {
		delete Fairy_E[num];		//デリート処理
	}
}
void EnemyManager::SpawnEnemy() {
	for (int num = 0; num < ENEMY_NUM; num++) {
		if (Fairy_E[num] == NULL) {				//NULLの場合
			Fairy_E[num] = new Fairy_Endurance;	//生成処理
			break;								//一体生成したら抜ける
		}
	}
}

void EnemyManager::Update(){
	SpawnEnemy();						//生成呼び出し

	for (int num = 0; num < ENEMY_NUM; num++) {
		if (Fairy_E[num] != NULL) {		//NULLでない場合
			Fairy_E[num]->Update(_castle, _player);		//更新処理
			
			if (Fairy_E[num]->GetIsActive() == false) {

			delete Fairy_E[num];		//アクティブでない場合デリートして
			Fairy_E[num] = NULL;		//NULLを入れる

			}
		}
	}
}

void EnemyManager::Draw() {
	for (int num = 0; num < ENEMY_NUM; num++) {
		if (Fairy_E[num] != NULL) {
			Fairy_E[num]->Draw();	//描画
		}
	}
}

void EnemyManager::Set_x(float _x) {
	for (int num = 0; num < ENEMY_NUM; num++) {
		if (Fairy_E[num] != NULL) {
			Fairy_E[num]->Set_X(_x);			
		}
	}
}

void EnemyManager::Set_y(float _y) {
	for (int num = 0; num < ENEMY_NUM; num++) {
		if (Fairy_E[num] != NULL) {
			Fairy_E[num]->Set_Y(_y);			
		}
	}
}

void EnemyManager::Set_width(float _width) {
	for (int num = 0; num < ENEMY_NUM; num++) {
		if (Fairy_E[num] != NULL) {
			Fairy_E[num]->Set_Width(_width);	
		}
	}
}

void EnemyManager::Set_height(float _height) {
	for (int num = 0; num < ENEMY_NUM; num++) {
		if (Fairy_E[num] != NULL) {
			Fairy_E[num]->Set_Height(_height);	
		}
	}
}

int EnemyManager::Get_ActiveFlg(int num) {
		if (Fairy_E[num] != NULL) {
			return Fairy_E[num]->GetIsActive();	
		}
}

int EnemyManager::Get_Power(int num) {
		if (Fairy_E[num] != NULL) {
			return Fairy_E[num]->GetIsAttack();
		}
}

int EnemyManager::Get_x(int num) {
		if (Fairy_E[num] != NULL) {
			return Fairy_E[num]->Get_X();
		}
}

int EnemyManager::Get_y(int num) {
		if (Fairy_E[num] != NULL) {
			return Fairy_E[num]->Get_Y();
		}
}

int EnemyManager::Get_width(int num) {
		if (Fairy_E[num] != NULL) {
			return Fairy_E[num]->Get_Width();
		}
}

int EnemyManager::Get_height(int num) {
		if (Fairy_E[num] != NULL) {
			return Fairy_E[num]->Get_Height();
		}
}