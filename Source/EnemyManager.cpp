#include <DxLib.h>
#include "EnemyManager.h"

EnemyManager::EnemyManager() {
	const int ENEMY_NUM = POPENEMY_EASY;
	//��Փx�ɂ���ĕς��G�̐�����
	Fairy_Endurance* Fairy_E[ENEMY_NUM];
	//�̗͌^�G�l�~�[�I�u�W�F�N�g�z��

	for (int num = 0; num < ENEMY_NUM; num++) {
		Fairy_E[num] = NULL;
	}
}

EnemyManager::~EnemyManager() {

}
void EnemyManager::SpawnEnemy() {

}

void EnemyManager::Update(){

}

void EnemyManager::Draw() {

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
	return ;
}

int EnemyManager::Get_Power(int) {
	return ;
}

int EnemyManager::Get_x() {
	return ;
}

int EnemyManager::Get_y() {
	return ;
}

int EnemyManager::Get_width() {
	return ;
}

int EnemyManager::Get_height() {
	return ;
}