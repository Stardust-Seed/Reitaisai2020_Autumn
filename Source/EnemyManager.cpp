#include <DxLib.h>
#include "EnemyManager.h"

EnemyManager::EnemyManager(int level) {
	for (int num = 0; num < MAX_ENEMY_NUM; num++) {
		Enemys[num] = NULL;		//Enemys�̃|�C���^��NULL
	}

	switch (level)				//����(0�`2)�œ�Փx�ʂ̐�������ݒ�
	{
	case 0:						//EASY		2��
		enemyNum = POPENEMY_EASY;
		break;
	case 1:						//NORMAL	3��
		enemyNum = POPENEMY_NORMAL;
		break;
	case 2:						//HARD		4��
		enemyNum = POPENEMY_HARD;
		break;
	default:					//��O
		enemyNum = 4;
		break;
	}

	activeCount = 0;				//�����J�E���g������

}

EnemyManager::~EnemyManager() {
	for (int num = 0; num < MAX_ENEMY_NUM; num++) {
		delete Enemys[num];		//�f���[�g����
	}
}

void EnemyManager::SpawnEnemy() {
	if ((rand() % 100) == 0) {		//�o���m��

		for (int num = 0; num < enemyNum; num++) {	//�G�l�~�[�̐�����������
			if (Enemys[num] == NULL) {				//NULL�̏ꍇ�����J�n

				activeCount++;			//�����J�E���g���Z

				SRand;					//����������
				
				enemyType = GetRand(ENEMY_TYPES-1);	//�����_���ȓG�̎��
				_direction = GetRand(3);			//�����_���ȏo������
				
				if (enemyType == 0) {				//�X�s�[�h�^
					_speed = 1.5;
					_power = 10;
					_durability = 50;
					Enemys[num] = new Fairy_Speed(_speed,_power,_durability,_direction);		//��������
					break;								//��̐��������甲����
				}

				if (enemyType == 1) {				//�̗͌^
					_speed = 1;
					_power = 10;
					_durability = 100;
					Enemys[num] = new Fairy_Endurance(_speed, _power, _durability, _direction);	//��������
					break;								//��̐��������甲����
				}

			}
		}
	}
}

void EnemyManager::Update(Castle *_castle,BasePlayer *_player,BulletManager *_bulletManager){
	SpawnEnemy();						//�����Ăяo��

	for (int num = 0; num < enemyNum; num++) {

		if (Enemys[num] != NULL) {		//NULL�łȂ��ꍇ

			if (Enemys[num]->GetIsActive() == false) {

				delete Enemys[num];		//�A�N�e�B�u�łȂ��ꍇ�f���[�g����
				Enemys[num] = NULL;		//NULL������

				activeCount--;			//�����J�E���g���Z

			}

			Enemys[num]->Update(_castle, _player, _bulletManager);		//�X�V����
			
		}
	}
}

void EnemyManager::Draw() {
	for (int num = 0; num < enemyNum; num++) {
		if (Enemys[num] != NULL) {
			Enemys[num]->Draw();	//�`��
			
		}
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
	return enemyNum;
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