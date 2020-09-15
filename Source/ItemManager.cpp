#include <DxLib.h>
#include "ItemManager.h"
#include "BuffManager.h"
#include "Item_P.h"
#include "Item_S.h"
#include "Input.h"

ItemManager::ItemManager() {
	p_Count = 0;
	s_Count = 0;

	for (int i = 0; i < MAX_ITEM_NUM; i++) {
		items[i] = nullptr;
	}
}

ItemManager::~ItemManager() {
	for (int i = 0; i < MAX_ITEM_NUM; i++) {
		delete items[i];
	}
}

void ItemManager::Update(BasePlayer* _player, BuffManager* _buffManger) {
	for (int i = 0; i < MAX_ITEM_NUM; i++) {

		//items[i]����łȂ��ꍇ
		if (items[i] != nullptr) {

			//items[i]����A�N�e�B�u�̏ꍇ�Aitems[i]����ɂ��Ď��̃��[�v��
			if (items[i]->Get_IsActive() == false) {
				delete items[i];
				items[i] = nullptr;
				continue;
			}

			//items[i]�̍X�V����
			items[i]->Update(_player);

			//items[i]���v���C���[�Ɠ������Ă��ꍇ
			if (items[i]->Get_IsHit() == true) {

				//items[i]�̃A�C�e�������擾���A�Ή����������������Ȃ�
				switch (items[i]->Get_ItemType()) {
				case eItem::Power:
					//�p���[�o�t���x�����ő�łȂ��Ƃ�
					if (_buffManger->GetIsPowerLevelMax() == false) {
						p_Count++;
					}
					break;
				case eItem::Speed:
					//�X�s�[�h�o�t���x�����ő�łȂ��Ƃ�
					if (_buffManger->GetIsSpeedLevelMax() == false) {
						s_Count++;
					}
					break;
				}
			}
		}
	}

	//if (Input::Instance()->GetPressCount(KEY_INPUT_R) == 1 && _buffManger->GetIsPowerLevelMax() == false) {
	//	p_Count += 5;
	//}
	//if (Input::Instance()->GetPressCount(KEY_INPUT_T) == 1 && _buffManger->GetIsSpeedLevelMax() == false) {
	//	s_Count += 5;
	//}

	//if (Input::Instance()->GetPressCount(KEY_INPUT_Y) == 1) {
	//	_buffManger->DownBuffLevel();
	//}

	//�o�t���x�������������Ƃ�
	if (_buffManger->GetIsLevelDown() == true) {
		p_Count = 0;
		s_Count = 0;
	}

	//�o�t�}�l�[�W���[�ɂă��x�����㏸���邩�����������Ȃ�
	p_Count = _buffManger->PowerBuff_LevelUpCheck(p_Count);
	s_Count = _buffManger->SpeedBuff_LevelUpCheck(s_Count);
}

void ItemManager::Draw() {
	for (int i = 0; i < MAX_ITEM_NUM; i++) {
		//items[i]����ł͂Ȃ��ꍇ
		if (items[i] != nullptr) {
			//items[i]�̕`�揈��
			items[i]->Draw();
		}
	}

	//���u��UI(UI������������P��������)
	//DrawFormatString(0, 500, GetColor(255, 255, 255), "�A�C�e��P�擾�� : %d", p_Count);
	//DrawFormatString(0, 525, GetColor(255, 255, 255), "�A�C�e��S�擾�� : %d", s_Count);
}

void ItemManager::SpawnItem(float _ex,float _ey) {
	bool isSpawn = false;	//��������t���O

	for (int i = 0; i < MAX_ITEM_NUM; i++) {
		//items[i]����̏ꍇ
		if (items[i] == nullptr) {
			int spawnPercent = GetRand(ITEM_GENERATION_RANDMAX);	//�����m��

			//50�����̏ꍇ��������t���O��true�ɂ���
			if (spawnPercent < ITEM_GENERATION_RATE) {
				isSpawn = true;
			}

			//��������t���O��true�̏ꍇ
			if (isSpawn == true) {
				int spawnType = GetRand(ITEM_TYPE_NUM - 1);	//��������A�C�e���̃^�C�v�����߂�

				//spawnType��eItem::Power�̂Ƃ�
				if (spawnType == static_cast<int>(eItem::Power)) {
					items[i] = new Item_P(_ex, _ey, 16, 16, eItem::Power);
				}

				//spawnType��eItem::Power�̂Ƃ�
				if (spawnType == static_cast<int>(eItem::Speed)) {
					items[i] = new Item_S(_ex, _ey, 16, 16, eItem::Speed);
				}
			}

			break;
		}
	}
}