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
			/*
			Fairy_E[num]->Update();		//�X�V�����A�������킩���
			
			if (Fairy_E[num]->JudgeActive() == false) {
			//BaseEnemy�ɃA�N�e�B�u��Ԃ�Ԃ��֐����~����

			delete Fairy_E[num];		//�A�N�e�B�u�łȂ��ꍇ�f���[�g����
			Fairy_E[num] = NULL;		//NULL������
			}
			*/
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
		//	return Fairy_E[num]->();	//�Ԃ��֐����~����
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