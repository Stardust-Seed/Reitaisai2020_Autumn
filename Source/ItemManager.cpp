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

		//items[i]が空でない場合
		if (items[i] != nullptr) {

			//items[i]が非アクティブの場合、items[i]を空にして次のループへ
			if (items[i]->Get_IsActive() == false) {
				delete items[i];
				items[i] = nullptr;
				continue;
			}

			//items[i]の更新処理
			items[i]->Update(_player);

			//items[i]がプレイヤーと当たってた場合
			if (items[i]->Get_IsHit() == true) {

				//items[i]のアイテム情報を取得し、対応した処理をおこなう
				switch (items[i]->Get_ItemType()) {
				case eItem::Power:
					//パワーバフレベルが最大でないとき
					if (_buffManger->GetIsPowerLevelMax() == false) {
						p_Count++;
					}
					break;
				case eItem::Speed:
					//スピードバフレベルが最大でないとき
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

	//バフレベルが下がったとき
	if (_buffManger->GetIsLevelDown() == true) {
		p_Count = 0;
		s_Count = 0;
	}

	//バフマネージャーにてレベルが上昇するか処理をおこなう
	p_Count = _buffManger->PowerBuff_LevelUpCheck(p_Count);
	s_Count = _buffManger->SpeedBuff_LevelUpCheck(s_Count);
}

void ItemManager::Draw() {
	for (int i = 0; i < MAX_ITEM_NUM; i++) {
		//items[i]が空ではない場合
		if (items[i] != nullptr) {
			//items[i]の描画処理
			items[i]->Draw();
		}
	}

	//仮置きUI(UIが完成したら撤去させる)
	//DrawFormatString(0, 500, GetColor(255, 255, 255), "アイテムP取得個数 : %d", p_Count);
	//DrawFormatString(0, 525, GetColor(255, 255, 255), "アイテムS取得個数 : %d", s_Count);
}

void ItemManager::SpawnItem(float _ex,float _ey) {
	bool isSpawn = false;	//生成判定フラグ

	for (int i = 0; i < MAX_ITEM_NUM; i++) {
		//items[i]が空の場合
		if (items[i] == nullptr) {
			int spawnPercent = GetRand(ITEM_GENERATION_RANDMAX);	//生成確率

			//50未満の場合生成判定フラグをtrueにする
			if (spawnPercent < ITEM_GENERATION_RATE) {
				isSpawn = true;
			}

			//生成判定フラグがtrueの場合
			if (isSpawn == true) {
				int spawnType = GetRand(ITEM_TYPE_NUM - 1);	//生成するアイテムのタイプを決める

				//spawnTypeがeItem::Powerのとき
				if (spawnType == static_cast<int>(eItem::Power)) {
					items[i] = new Item_P(_ex, _ey, 16, 16, eItem::Power);
				}

				//spawnTypeがeItem::Powerのとき
				if (spawnType == static_cast<int>(eItem::Speed)) {
					items[i] = new Item_S(_ex, _ey, 16, 16, eItem::Speed);
				}
			}

			break;
		}
	}
}