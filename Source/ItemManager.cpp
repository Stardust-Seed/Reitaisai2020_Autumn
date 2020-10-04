#include <DxLib.h>
#include "ItemManager.h"
#include "BuffManager.h"
#include "Item_P.h"
#include "Item_S.h"
#include "Input.h"

ItemManager::ItemManager() {
	//各パラメータの初期化
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
}

void ItemManager::SpawnItem(float _ex,float _ey) {
	bool isSpawn = false;									//生成判定フラグ
	int spawnPercent = GetRand(ITEM_GENERATION_RANDMAX);	//生成確率
	int maxSpawnNum = 0;									//生成する最大数
	int spawnCnt = 0;										//生成数カウント

	//50未満の場合生成判定フラグをtrueにする
	if (spawnPercent % ITEM_RATEDATA <= ITEM_GENERATION_RATE) {
		isSpawn = true;
		maxSpawnNum = GetRand(4);
	}

	for (int i = 0; i < MAX_ITEM_NUM; i++) {
		//items[i]が空の場合
		if (items[i] == nullptr) {

			//生成判定フラグがtrueの場合
			if (isSpawn == true) {
				int spawnType = GetRand(ITEM_TYPE_NUM - 1);	//生成するアイテムのタイプを決める

				//ちりばめる方向用変数
				int sTypeX = GetRand(1);
				int sTypeY = GetRand(1);

				//加算する値を取得
				float addX = GetRand(24) * 1.0f;
				float addY = GetRand(24) * 1.0f;

				//1だった場合
				if (sTypeX == 1) {
					addX = -(addX);
				}
				if (sTypeY == 1) {
					addY = -(addY);
				}

				//spawnTypeがeItem::Powerのとき
				if (spawnType == static_cast<int>(eItem::Power)) {
					items[i] = new Item_P(_ex + addX, _ey + addY, 16, 16, eItem::Power);
				}

				//spawnTypeがeItem::Powerのとき
				if (spawnType == static_cast<int>(eItem::Speed)) {
					items[i] = new Item_S(_ex + addX, _ey + addY, 16, 16, eItem::Speed);
				}

				if (spawnCnt == maxSpawnNum) {
					return;
				}
			}

			spawnCnt++;
		}
	}
}