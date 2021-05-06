#include "Fairy_Bomb.h"

#include "BasePlayer.h"
#include "BulletManager.h"
#include "CastleManager.h"

//初期スポーン位置からの生成用コンストラクタ
Fairy_Bomb::Fairy_Bomb(float _speed, float _power, int _durability,
	eDirection _direction, eEnemyType _enemyType)
	:BaseEnemy(_speed, _power, _durability, _direction, _enemyType) {

}

//占領した拠点からの生成用コンストラクタ
Fairy_Bomb::Fairy_Bomb(float _x, float _y, float _speed, float _power, int _durability,
	eDirection _direction, eEnemyType _enemyType)
	: BaseEnemy(_x, _y, _speed, _power, _durability, _direction, _enemyType) {

}

//更新処理
void Fairy_Bomb::Update(CastleManager* _castleManager, BasePlayer* _player,
	BulletManager* _bulletManager){

	//更新処理
	BaseEnemy::Update(_castleManager, _player, _bulletManager);

	//城発見時
	if (isHitCastle) {
		isAttack = true;
		inactiveType = eInactiveType::Invasion;
		attackType = eAttackType::Invasion;
		animationCnt = 0;
	}

	//非アクティブになった場合
	if (!isActive && inactiveType == eInactiveType::Defeat) {
		//ここに爆弾を生成する処理を加える
	}
	else if (!isActive && inactiveType == eInactiveType::Invasion) {
		//ここに爆弾を生成する処理を加える
	}

	//移動処理
	Move(_player->Get_isAbility(), _player->Get_AbilityType());

	//アニメーション処理
	Animation(_player->Get_isAbility(), _player->Get_AbilityType());

	//攻撃処理
	if (isAttack) {
		AttackProc(_player->Get_cx(), _player->Get_cy());
	}
}

//描画処理
void Fairy_Bomb::Draw() {
	BaseEnemy::Draw();
}
