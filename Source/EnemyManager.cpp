#include <DxLib.h>
#include "EnemyManager.h"

EnemyManager::EnemyManager() {
	for (int num = 0; num < ENEMY_NUM; num++) {
		Enemys[num] = NULL;		//EnemysのポインタにNULL
	}
}

EnemyManager::~EnemyManager() {
	for (int num = 0; num < ENEMY_NUM; num++) {
		delete Enemys[num];		//デリート処理
	}
}
void EnemyManager::SpawnEnemy() {
	if ((rand() % 100) == 0) {		//出現確率

		for (int num = 0; num < ENEMY_NUM; num++) {	//エネミーの数だけ動かす
			if (Enemys[num] == NULL) {				//NULLの場合生成開始

				SRand;					//乱数初期化
				
				_direction = GetRand(3);			//ランダムな出現方向
				enemyType = GetRand(1);				//ランダムな敵の種類
				
				if (enemyType == 0) {				//スピード型
					Enemys[num] = new Fairy_Speed(1, 10, 100, _direction);		//生成処理
					break;								//一体生成したら抜ける
				}

				if (enemyType == 1) {				//体力型
					Enemys[num] = new Fairy_Endurance(1, 10, 100, _direction);	//生成処理
					break;								//一体生成したら抜ける
				}
			}
		}
	}
}

void EnemyManager::Update(Castle *_castle,BasePlayer *_player){
	SpawnEnemy();						//生成呼び出し
	
	for (int num = 0; num < ENEMY_NUM; num++) {

		if (Enemys[num] != NULL) {		//NULLでない場合
			Enemys[num]->Update(_castle, _player);		//更新処理
			
			if (Enemys[num]->GetIsActive() == false) {

			delete Enemys[num];		//アクティブでない場合デリートして
			Enemys[num] = NULL;		//NULLを入れる

			}
		}
	}
}

void EnemyManager::Draw() {
	for (int num = 0; num < ENEMY_NUM; num++) {
		if (Enemys[num] != NULL) {
			Enemys[num]->Draw();	//描画
			
		}
	}
}

void EnemyManager::Set_x(float _x) {
	for (int num = 0; num < ENEMY_NUM; num++) {
		if (Enemys[num] != NULL) {
			Enemys[num]->Set_X(_x);			
		}
	}
}

void EnemyManager::Set_y(float _y) {
	for (int num = 0; num < ENEMY_NUM; num++) {
		if (Enemys[num] != NULL) {
			Enemys[num]->Set_Y(_y);			
		}
	}
}

void EnemyManager::Set_width(float _width) {
	for (int num = 0; num < ENEMY_NUM; num++) {
		if (Enemys[num] != NULL) {
			Enemys[num]->Set_Width(_width);	
		}
	}
}

void EnemyManager::Set_height(float _height) {
	for (int num = 0; num < ENEMY_NUM; num++) {
		if (Enemys[num] != NULL) {
			Enemys[num]->Set_Height(_height);	
		}
	}
}

int EnemyManager::Get_ActiveFlg(int num) {
		if (Enemys[num] != NULL) {
			return Enemys[num]->GetIsActive();	
		}
}

int EnemyManager::Get_Power(int num) {
		if (Enemys[num] != NULL) {
			return Enemys[num]->GetIsAttack();
		}
}

int EnemyManager::Get_x(int num) {
		if (Enemys[num] != NULL) {
			return Enemys[num]->Get_X();
		}
}

int EnemyManager::Get_y(int num) {
		if (Enemys[num] != NULL) {
			return Enemys[num]->Get_Y();
		}
}

int EnemyManager::Get_width(int num) {
		if (Enemys[num] != NULL) {
			return Enemys[num]->Get_Width();
		}
}

int EnemyManager::Get_height(int num) {
		if (Enemys[num] != NULL) {
			return Enemys[num]->Get_Height();
		}
}