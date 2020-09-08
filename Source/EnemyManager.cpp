#include <DxLib.h>
#include "EnemyManager.h"

EnemyManager::EnemyManager(int level) {
	for (int num = 0; num < MAX_ENEMY_NUM; num++) {
		Enemys[num] = NULL;		//EnemysのポインタにNULL
	}

	switch (level)				//引数(0～2)で難易度別の生成数を設定
	{
	case 0:						//EASY		2体
		enemyNum = POPENEMY_EASY;
		break;
	case 1:						//NORMAL	3体
		enemyNum = POPENEMY_NORMAL;
		break;
	case 2:						//HARD		4体
		enemyNum = POPENEMY_HARD;
		break;
	default:					//例外
		enemyNum = 4;
		break;
	}

	addEnemyNum = 0;				//最初なので追加分はなし
	activeCount = 0;				//生成カウント初期化
	waitCount = 0;					//待機カウント初期化

}

EnemyManager::~EnemyManager() {
	for (int num = 0; num < MAX_ENEMY_NUM; num++) {
		delete Enemys[num];		//デリート処理
	}
}

void EnemyManager::Update(CastleManager *_castle,BasePlayer *_player,BulletManager *_bulletManager,ItemManager *_itemManager){
	SpawnEnemy(_castle);						//生成呼び出し

	for (int num = 0; num < enemyNum + addEnemyNum; num++) {

		if (Enemys[num] != NULL) {		//NULLでない場合

			Enemys[num]->Update(_castle, _player, _bulletManager);		//更新処理

			if (Enemys[num]->GetInactiveType() == eInactiveType::Defeat) {

				_itemManager->SpawnItem(Enemys[num]->Get_X(), Enemys[num]->Get_Y());	//アイテム生成
			}

			if (Enemys[num]->GetIsActive() == false) {

				delete Enemys[num];		//アクティブでない場合デリートして
				Enemys[num] = NULL;		//NULLを入れる

				activeCount--;			//生成カウント減算

			}
		}
	}
}

void EnemyManager::Draw() {
	for (int num = 0; num < enemyNum + addEnemyNum; num++) {
		if (Enemys[num] != NULL) {
			Enemys[num]->Draw();	//描画
			
		}
	}
}

void EnemyManager::SpawnEnemy(CastleManager* _castle) {

	addEnemyNum = _castle->Get_PopEnemyNum();//追加分を取得

	waitCount++;				//カウント加算

	if (waitCount >= 30) {		//0.5秒間は待機

		if ((rand() % 100) == 0) {	//出現確率

			SRand;					//乱数初期化

			int i = 0;				//direction初期化

			enemyType = GetRand(ENEMY_TYPES - 1);	//ランダムな敵の種類

			for (int num = 0; num < enemyNum; num++) {	//エネミーの数だけ動かす

				if (Enemys[num] == NULL) {				//NULLの場合生成開始

					activeCount++;			//生成カウント加算

					i = GetRand(3);			//ランダムな出現方向

					_direction = i;			

					if (enemyType == 0) {				//スピード型

						_speed = 1.5;
						_power = 10;
						_durability = 50;

						Enemys[num] = new Fairy_Speed(_speed,_power,_durability,_direction);        //生成処理

						waitCount = 0;
						break;								//一体生成したら抜ける
					}

					if (enemyType == 1) {				//体力型

						_speed = 1;
						_power =10;
						_durability = 100;

						Enemys[num] = new Fairy_Endurance(_speed, _power, _durability, _direction);        //生成処理

						waitCount = 0;
						break;								//一体生成したら抜ける
					}
				}
			}


			for (int num = enemyNum; num < enemyNum + addEnemyNum; num++) {    //追加分動かす

				if (_castle->Get_IsActive(i) == false){

					if (Enemys[num] == NULL) {      //NULLの場合生成開始

						activeCount++;				//生成カウント加算

						i = GetRand(4);				//ランダムな出現方向

						if (enemyType == 0) {            //スピード型

							Enemys[num] = new Fairy_Speed(_castle->Get_EnemySpeed(i), _castle->Get_EnemyPower(i),
								_castle->Get_EnemyDurability(i), _castle->Get_EnemyDirection(i),
								_castle->Get_X(i), _castle->Get_Y(i));        //生成処理

							waitCount = 0;
							break;      //一体生成したら抜ける
						}

						if (enemyType == 1) {            //耐久型

							Enemys[num] = new Fairy_Endurance(_castle->Get_EnemySpeed(i), _castle->Get_EnemyPower(i),
								_castle->Get_EnemyDurability(i), _castle->Get_EnemyDirection(i),
								_castle->Get_X(i), _castle->Get_Y(i));        //生成処理

							waitCount = 0;
							break;      //一体生成したら抜ける
						}
					}
				}
			}


		}
	}
}

void EnemyManager::Set_IsActive(int num, bool _isActive) {
	if (Enemys[num] != NULL) {
		Enemys[num]->SetIsActive(_isActive);
	}
}

void EnemyManager::Set_IsAttack(int num, bool _isAttack) {
	if (Enemys[num] != NULL) {
		Enemys[num]->SetIsAttack(_isAttack);
	}
}

void EnemyManager::Set_IsMove(int num, bool _isMove) {
	if (Enemys[num] != NULL) {
		Enemys[num]->SetIsMove(_isMove);
	}
}

void EnemyManager::Set_x(int num,float _x) {
		if (Enemys[num] != NULL) {
			Enemys[num]->Set_X(_x);			
		}
}

void EnemyManager::Set_y(int num,float _y) {
		if (Enemys[num] != NULL) {
			Enemys[num]->Set_Y(_y);			
		}
}

void EnemyManager::Set_width(int num,float _width) {
		if (Enemys[num] != NULL) {
			Enemys[num]->Set_Width(_width);	
		}
}

void EnemyManager::Set_height(int num,float _height) {
		if (Enemys[num] != NULL) {
			Enemys[num]->Set_Height(_height);	
		}
}

int EnemyManager::Get_enemyNum() {
	return enemyNum + addEnemyNum;
}

int EnemyManager::Get_ActiveCount() {
	return activeCount;
}

int EnemyManager::Get_ActiveFlg(int num) {
	if (Enemys[num] != NULL) {
		return Enemys[num]->GetIsActive();	
	}
}

int EnemyManager::Get_AttackFlg(int num) {
	if (Enemys[num] != NULL) {
		return Enemys[num]->GetIsAttack();
	}
}

int EnemyManager::Get_Power(int num) {
	if (Enemys[num] != NULL) {
		return Enemys[num]->GetPower();
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