#include <DxLib.h>
#include "Boss.h"

#include "BasePlayer.h"
#include "BulletManager.h"
#include "CastleManager.h"

//初期スポーン位置からの生成用コンストラクタ
Boss::Boss(float _speed, float _power, int _durability,
	eDirection _direction, eEnemyType _enemyType)
	:BaseEnemy(_speed, _power, _durability, _direction, _enemyType) {
	stopCnt = 0;
	attackCnt = 0;
	effectArray = new int[EFFECT_MAX_NUM] { 0, 1, 2, 3, 4, 5, 6, 7 };
	effectIndex = 0;
	effectDrawX = 0;
	effectDrawY = 0;
	isEffect = false;
}

//デストラクタ
Boss::~Boss() {
	//動的に確保した配列を解放する
	delete effectArray;
}

//更新処理
void Boss::Update(GameResource* _gameRes) {
	//BaseEnemyの更新処理
	BaseEnemy::Update(_gameRes);

	if (isHitCastle) {
		isAttack = true;
	}

	//エフェクトフラグがオンの場合
	if (isEffect) {
		if (effectIndex == EFFECT_MAX_NUM - 1) {
			isEffect = false;
			effectIndex = 0;


		}
		else {
			effectIndex++;
		}
	}
	
	//カウントリセット
	if (stopCnt == STOPTIME)stopCnt = 0;

	//カウントが0の場合
	if (stopCnt == 0 && !isHitCastle) {
		//移動処理
		Move(_gameRes->player->Get_isAbility(), _gameRes->player->Get_AbilityType());

		//移動する際に画像を切り替える
		if (imageIndex == static_cast<int>(eEnemyType::Boss)) {
			imageIndex = static_cast<int>(eEnemyType::Boss) + 1;
		}
		else {
			imageIndex = static_cast<int>(eEnemyType::Boss);
		}
	}

	//攻撃処理
	if (isAttack) {
		//攻撃カウンタが60の時攻撃フラグをオフにする
		if (attackCnt == 300) {
			isAttack = false;
			attackCnt = 0;

			for (int i = 0; i < _gameRes->castleManager->Get_CastleNum(); i++) {
				if (direction == _gameRes->castleManager->Get_CastleDirection(i) &&
					_gameRes->castleManager->Get_IsActive(i)) {
					//ここにダメージ処理を入れられると助かる

					effectDrawX = _gameRes->castleManager->Get_DrawPosX(i);
					effectDrawY = _gameRes->castleManager->Get_DrawPosY(i);

					isEffect = true;
					break;
				}
			}
		}

		//攻撃カウンタを加算する
		attackCnt++;
	}

	//カウンタを加算する
	if (!isAttack)stopCnt++;
}

//描画処理
void Boss::Draw(GameResource* _gameRes) {
	//描画処理
	Image::Instance()->TransparentGraph(x, y,
		Image::Instance()->GetGraph(eImageType::Gpicture_Enemy,imageIndex),
		255, isTurn);

	//攻撃エフェクトを描画
	if (isEffect) {
		DrawExtendGraphF(effectDrawX, effectDrawY,
			effectDrawX + 120 * 0.45833f, effectDrawY + 120 * 0.45833f,
			Image::Instance()->GetGraph(eImageType::Effect_Slashing, effectArray[effectIndex]), TRUE);
	}
}