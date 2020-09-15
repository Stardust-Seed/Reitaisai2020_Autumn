#include "BuffManager.h"
#include "EnemyManager.h"
#include "ItemManager.h"
#include <DxLib.h>

BuffManager::BuffManager() {
	powerLevel = 0;
	speedLevel = 0;
	isPowerLevelMax = false;
	isSpeedLevelMax = false;

	isLevelDown = false;

	powerBuff = POWERBUFF_LV0;
	speedBuff = SPEEDBUFF_LV0;
}

void BuffManager::Update(ItemManager* _itemManager, EnemyManager* _enemyManager) {
	//���x���_�E���t���O���L���ȂƂ��A������Ԃ�
	if (isLevelDown == true) {
		isLevelDown = false;
	}

	//�o�t�̌��͂�K�p
	switch (powerLevel) {
	case 0:
		powerBuff = POWERBUFF_LV0;
		break;
	case 1:
		powerBuff = POWERBUFF_LV1;
		break;
	case 2:
		powerBuff = POWERBUFF_LV2;
		break;
	case 3:
		powerBuff = POWERBUFF_LV3;
		break;
	}

	//�o�t�̌��͂�K�p
	switch (speedLevel) {
	case 0:
		speedBuff = SPEEDBUFF_LV0;
		break;
	case 1:
		speedBuff = SPEEDBUFF_LV1;
		break;
	case 2:
		speedBuff = SPEEDBUFF_LV2;
		break;
	case 3:
		speedBuff = SPEEDBUFF_LV3;
		break;
	}

	//���u��UI(UI������������P��������)
	//DrawFormatString(0, 550, GetColor(255, 255, 255), "�p���[�o�t���x�� : %d", powerLevel);
	//DrawFormatString(0, 575, GetColor(255, 255, 255), "�X�s�[�h�o�t���x�� : %d", speedLevel);
	//DrawFormatString(0, 600, GetColor(255, 255, 255), "�p���[�o�t : %f", powerBuff);
	//DrawFormatString(0, 625, GetColor(255, 255, 255), "�X�s�[�h�o�t : %f", speedBuff);
}

void BuffManager::DownBuffLevel() {
	//�p���[�o�t���x����0�ȉ��̏ꍇ
	if (powerLevel <= 0) {
		powerLevel = 0;
	}
	//0��葽���ꍇ
	else {
		powerLevel--;
	}

	//�p���[�o�t���x�����}�b�N�X�������ꍇ
	if (isPowerLevelMax == true) {
		isPowerLevelMax = false;
	}

	//�X�s�[�h�o�t���x����0�ȉ��̏ꍇ
	if (speedLevel <= 0) {
		speedLevel = 0;
	}
	//0��葽���ꍇ
	else {
		speedLevel--;
	}

	//�X�s�[�h�o�t���x�����}�b�N�X�̏ꍇ
	if (isSpeedLevelMax == true) {
		isSpeedLevelMax = false;
	}

	//���x���_�E���t���O���I���ɂ���
	isLevelDown = true;
}

int BuffManager::PowerBuff_LevelUpCheck(int _powerCount) {
	//_powerCount��15�ȏ�Ń��x���}�b�N�X�łȂ��ꍇ
	if (_powerCount >= 15 && isPowerLevelMax == false) {
		powerLevel++;

		if (powerLevel == MAX_BUFFLEVEL) {
			isPowerLevelMax = true;
		}

		return 0;
	}

	return _powerCount;
}

int BuffManager::SpeedBuff_LevelUpCheck(int _speedCount) {
	//_powerCount��15�ȏ�Ń��x���}�b�N�X�łȂ��ꍇ
	if (_speedCount >= 15 && isSpeedLevelMax == false) {
		speedLevel++;

		if (speedLevel == MAX_BUFFLEVEL) {
			isSpeedLevelMax = true;
		}

		return 0;
	}

	return _speedCount;
}