#include <DxLib.h>
#include "EnemyBomb.h"

#include "Image.h"
#include "EnemyManager.h"
#include "CastleManager.h"

//コンストラクタ
EnemyBomb::EnemyBomb(float _x, float _y, eExType _exType) {
	x = _x;
	y = _y;
	exAreaSize = 120.0f;
	width = exAreaSize;
	height = exAreaSize;
	cx = x + (width / 2);
	cy = y + (height / 2);
	isActive = true;
	exCnt = 0;
	effectArray = new int[EFFECT_MAX_NUM] { 0, 1, 2, 3, 4, 5, 6, 7 };
	effectIndex = 0;

	if (_exType == eExType::Immediately) {
		isExplosion = true;
	}
	else if(_exType == eExType::Installation) {
		isExplosion = false;
	}
}

void EnemyBomb::Update(Player* _player, CastleManager* _castleManager,
	EnemyManager* _enemyManager) {
	//爆破カウントが爆発までのタイムのとき
	if (exCnt == EXTIME)isExplosion = true;

	//爆破処理
	if (isExplosion) {

		if (effectIndex == 0) {
			//城と爆弾の当たり判定
			for (int i = 0; i < _castleManager->Get_CastleNum(); i++) {
				//城がアクティブな場合
				if (_castleManager->Get_IsActive(i)) {
					//当たった場合
					if (ClisionHit(cx - (exAreaSize / 2), cy - (exAreaSize / 2), width, height,
						_castleManager->Get_X(i), _castleManager->Get_Y(i),
						_castleManager->Get_Width(i), _castleManager->Get_Height(i))) {
						//ここにダメージの処理
					}
				}
			}

			//敵と爆弾の当たり判定
			for (int i = 0; i < _enemyManager->Get_enemyNum(); i++) {
				//敵がアクティブな場合
				if (_enemyManager->Get_ActiveFlg(i)) {
					//当たった場合
					if (ClisionHit(cx - (exAreaSize / 2), cy - (exAreaSize / 2), width, height,
						_enemyManager->Get_x(i), _enemyManager->Get_y(i),
						_enemyManager->Get_width(i), _enemyManager->Get_height(i))) {
						//ここにダメージの処理
					}
				}
			}
		}
		else if (effectIndex == EFFECT_MAX_NUM - 1) {
			isActive = false;
			isExplosion = false;
			effectIndex = 0;
		}
		else {
			effectIndex++;
		}
	}

	//爆破カウントを加算する
	exCnt++;
}

void EnemyBomb::Draw() {
	//爆破中の描画(爆破エフェクトの描画)
	if (isExplosion) {
		DrawGraphF(x, y, Image::Instance()->GetGraph(eImageType::Effect_Explosion2,
			effectArray[effectIndex]), TRUE);
	}
	//爆破前の描画(爆弾を表示する)
	else {
		DrawGraphF(x, y, Image::Instance()->GetGraph(eImageType::Gpicture_Bomb), TRUE);
	}
}

bool EnemyBomb::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh) {
	//当たったいる場合
	if (mx + mw >= ox && mx <= ox + ow && my + mh >= oy && my <= oy + oh) {
		return true;
	}

	return false;
}
