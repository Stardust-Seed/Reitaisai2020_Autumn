#include <DxLib.h>
#include "EnemyManager.h"

EnemyManager::EnemyManager() {
	for (int num = 0; num < ENEMY_NUM; num++) {
		Fairy_E[num] = NULL;		//Fairy_EのポインタにNULL
	}
}

EnemyManager::~EnemyManager() {
	for (int num = 0; num < ENEMY_NUM; num++) {
		delete Fairy_E[num];		//
	}
}
void EnemyManager::SpawnEnemy() {
	for (int num = 0; num < ENEMY_NUM; num++) {
		if (Fairy_E[num] == NULL) {
			Fairy_E[num] = new Fairy_Endurance;
			break;
		}
	}
}

void EnemyManager::Update(){
	SpawnEnemy();

	for (int num = 0; num < ENEMY_NUM; num++) {
		if (Fairy_E[num] != NULL) {		//NULLでない場合
			/*
			Fairy_E[num]->Update();		//更新、引数がわからん
			
			if (Fairy_E[num]->JudgeActive() == false) {
			//BaseEnemyにアクティブ状態を返す関数が欲しい

			delete Fairy_E[num];
			Fairy_E[num] = NULL;
			}
			*/
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

void EnemyManager::Set_x(int _x) {

}

void EnemyManager::Set_y(int _y) {

}

void EnemyManager::Set_width(int _width) {

}

void EnemyManager::Set_height(int _height) {

}

int EnemyManager::Get_ActiveFlg(bool) {
	for (int num = 0; num < ENEMY_NUM; num++) {
		if (Fairy_E[num] != NULL) {
		//	return Fairy_E[num]->();
		}
	}
}

int EnemyManager::Get_Power(int) {
	for (int num = 0; num < ENEMY_NUM; num++) {
		if (Fairy_E[num] != NULL) {
			return Fairy_E[num]->GetIsAttack();
		}
	}
}

int EnemyManager::Get_x() {
	for (int num = 0; num < ENEMY_NUM; num++) {
		if (Fairy_E[num] != NULL) {
			return Fairy_E[num]->Get_X();
		}
	}
}

int EnemyManager::Get_y() {
	for (int num = 0; num < ENEMY_NUM; num++) {
		if (Fairy_E[num] != NULL) {
			return Fairy_E[num]->Get_Y();
		}
	}
}

int EnemyManager::Get_width() {
	for (int num = 0; num < ENEMY_NUM; num++) {
		if (Fairy_E[num] != NULL) {
			return Fairy_E[num]->Get_Width();
		}
	}
}

int EnemyManager::Get_height() {
	for (int num = 0; num < ENEMY_NUM; num++) {
		if (Fairy_E[num] != NULL) {
			return Fairy_E[num]->Get_Height();
		}
	}
}