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
	//レベルダウンフラグが有効なとき、無効状態へ
	if (isLevelDown == true) {
		isLevelDown = false;
	}

	//バフの効力を適用
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

	//バフの効力を適用
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

	//仮置きUI(UIが完成したら撤去させる)
	//DrawFormatString(0, 550, GetColor(255, 255, 255), "パワーバフレベル : %d", powerLevel);
	//DrawFormatString(0, 575, GetColor(255, 255, 255), "スピードバフレベル : %d", speedLevel);
	//DrawFormatString(0, 600, GetColor(255, 255, 255), "パワーバフ : %f", powerBuff);
	//DrawFormatString(0, 625, GetColor(255, 255, 255), "スピードバフ : %f", speedBuff);
}

void BuffManager::DownBuffLevel() {
	//パワーバフレベルが0以下の場合
	if (powerLevel <= 0) {
		powerLevel = 0;
	}
	//0より多い場合
	else {
		powerLevel--;
	}

	//パワーバフレベルがマックスだった場合
	if (isPowerLevelMax == true) {
		isPowerLevelMax = false;
	}

	//スピードバフレベルが0以下の場合
	if (speedLevel <= 0) {
		speedLevel = 0;
	}
	//0より多い場合
	else {
		speedLevel--;
	}

	//スピードバフレベルがマックスの場合
	if (isSpeedLevelMax == true) {
		isSpeedLevelMax = false;
	}

	//レベルダウンフラグをオンにする
	isLevelDown = true;
}

int BuffManager::PowerBuff_LevelUpCheck(int _powerCount) {
	//_powerCountが15以上でレベルマックスでない場合
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
	//_powerCountが15以上でレベルマックスでない場合
	if (_speedCount >= 15 && isSpeedLevelMax == false) {
		speedLevel++;

		if (speedLevel == MAX_BUFFLEVEL) {
			isSpeedLevelMax = true;
		}

		return 0;
	}

	return _speedCount;
}