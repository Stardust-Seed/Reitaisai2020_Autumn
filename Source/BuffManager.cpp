#include "BuffManager.h"
#include "EnemyManager.h"
#include "ItemManager.h"
#include <DxLib.h>

BuffManager::BuffManager() {
	powerLevel = 0;
	speedLevel = 0;
	powerBuff = 0.0f;
	speedBuff = 0.0f;
}

void BuffManager::Update(ItemManager* _itemManager, EnemyManager* _enemyManager) {

	//���u��UI(UI������������P��������)
	//DrawFormatString(0, 550, GetColor(255, 255, 255), "�p���[�o�t���x�� : %d", powerLevel);
	//DrawFormatString(0, 575, GetColor(255, 255, 255), "�X�s�[�h�o�t���x�� : %d", speedLevel);
	//DrawFormatString(0, 600, GetColor(255, 255, 255), "�p���[�o�t : %f", powerBuff);
	//DrawFormatString(0, 625, GetColor(255, 255, 255), "�X�s�[�h�o�t : %f", speedBuff);
}