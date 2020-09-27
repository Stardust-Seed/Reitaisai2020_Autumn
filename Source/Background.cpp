#include <DxLib.h>
#include "Image.h"
#include "Background.h"
#include "Define.h"

Background::Background() {
	extCnt = 0;

	//初期化
	for (int i = 0; i < MAX_STAR; i++) {
		stars[i] = nullptr;
	}

	for (int i = 0; i < starsExtData.max_size(); i++) {
		starsExtData[i] = 0;
	}
}

void Background::Update() {
	bool isSpawn = false;				//スポーンフラグ
	bool spawnPercent = GetRand(100);	//スポーンする確率用変数

	//拡大率のカウンタと被り防止データをリセットする

	if (extCnt >= starsExtData.max_size()) {
		extCnt = 0;
		for (int i = 0; i < starsExtData.max_size(); i++) {
			starsExtData[i] = 0;
		}
	}

	//生成率が5以下の場合
	if (spawnPercent % 10 <= 5) {
		isSpawn = true;
	}

	//星を削除する処理
	for (int i = 0; i < MAX_STAR; i++) {
		//星クラスが空でない場合
		if (stars[i] != nullptr) {
			/*--------------------------------------------------
			画面外に星クラスが出た場合
			(星の座標(x) > gameWidth(1920)+(画像のwidth / 2)) ||
			(星の座標(y) > gameWidth(1080)+(画像のheight / 2))
			--------------------------------------------------*/
			if (stars[i]->GetX() > (GAME_WIDTH + (900 / 2)) ||
				stars[i]->GetY() > (GAME_HEIHGT + (900 / 2))) {
				delete stars[i];
				stars[i] = nullptr;
			}
		}
	}

	//生成処理用のループ
	for (int i = 0; i < MAX_STAR; i++) {
		if (stars[i] == nullptr) {
			//isSpawnがtrueの場合生成を行う
			if (isSpawn == true) {

				bool isExt = true;
				double ext;

				while (isExt == true) {
					ext = (GetRand(6) + 1.0) * 0.1;

					for (int j = 0; j < starsExtData.max_size(); j++) {
						if (ext == starsExtData[j]) {
							break;
						}
						else if (j < starsExtData.max_size() - 1) {
							continue;
						}
						starsExtData[extCnt] = ext;
						isExt = false;
						extCnt++;
					}
				}


				float x = -(GAME_WIDTH / 2) + (GetRand(6) * 100);
				float y = -(GAME_HEIHGT) + (GetRand(20) * 100);
				float angle = GetRand(359);

				//星を生成
				stars[i] = new Star(x, y, ext, ext, angle);
				return;
			}
		}
	}

	for (int i = 0; i < MAX_STAR; i++) {
		if (stars[i] != nullptr) {
			stars[i]->Update();
		}
	}
}

void Background::Draw(eBackgroundType _backgroundType) {
	switch (_backgroundType)
	{
	case eBackgroundType::Title:
		break;
	case eBackgroundType::Menu:
		DrawGraph(0, 0, Image::Instance()->GetGraph(eImageType::Background_Menu), TRUE);
		for (int i = 0; i < MAX_STAR; i++) {
			if (stars[i] != nullptr) {
				stars[i]->Draw();
			}
		}
		DrawFormatString(0, 0, GetColor(0, 0, 0), "%d",starsExtData.max_size());
		//DrawRotaGraph3F(315,315, 900/2, 900/2, 0.7, 0.7,
		//	(0 * PAI) / 180,
		//	Image::Instance()->GetGraph(eImageType::Background_Star), TRUE);
		break;
	case eBackgroundType::Game:
		break;
	}
}