#include <DxLib.h>
#include "EnemyManager.h"

EnemyManager::EnemyManager() {

	for (int num = 0; num < ENEMY_NUM; num++) {
		Fairy_E[num] = NULL;		//Fairy_E�̃|�C���^��NULL
	}
}

EnemyManager::~EnemyManager() {
	for (int num = 0; num < ENEMY_NUM; num++) {
		delete Fairy_E[num];		//�f���[�g����
	}
}
void EnemyManager::SpawnEnemy() {
	for (int num = 0; num < ENEMY_NUM; num++) {
		if (Fairy_E[num] == NULL) {				//NULL�̏ꍇ
			Fairy_E[num] = new Fairy_Endurance;	//��������
			break;								//��̐��������甲����
		}
	}
}

void EnemyManager::Update(){
	SpawnEnemy();						//�����Ăяo��

	for (int num = 0; num < ENEMY_NUM; num++) {
		if (Fairy_E[num] != NULL) {		//NULL�łȂ��ꍇ
			Fairy_E[num]->Update(_castle, _player);		//�X�V����
			
			if (Fairy_E[num]->GetIsActive() == false) {

			delete Fairy_E[num];		//�A�N�e�B�u�łȂ��ꍇ�f���[�g����
			Fairy_E[num] = NULL;		//NULL������

			}
		}
	}
}

void EnemyManager::Draw() {
	for (int num = 0; num < ENEMY_NUM; num++) {
		if (Fairy_E[num] != NULL) {
			Fairy_E[num]->Draw();	//�`��
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