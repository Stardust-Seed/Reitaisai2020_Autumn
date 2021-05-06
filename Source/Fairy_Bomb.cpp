#include "Fairy_Bomb.h"

#include "BasePlayer.h"
#include "BulletManager.h"
#include "CastleManager.h"

//�����X�|�[���ʒu����̐����p�R���X�g���N�^
Fairy_Bomb::Fairy_Bomb(float _speed, float _power, int _durability,
	eDirection _direction, eEnemyType _enemyType)
	:BaseEnemy(_speed, _power, _durability, _direction, _enemyType) {

}

//��̂������_����̐����p�R���X�g���N�^
Fairy_Bomb::Fairy_Bomb(float _x, float _y, float _speed, float _power, int _durability,
	eDirection _direction, eEnemyType _enemyType)
	: BaseEnemy(_x, _y, _speed, _power, _durability, _direction, _enemyType) {

}

//�X�V����
void Fairy_Bomb::Update(CastleManager* _castleManager, BasePlayer* _player,
	BulletManager* _bulletManager){

	//�X�V����
	BaseEnemy::Update(_castleManager, _player, _bulletManager);

	//�锭����
	if (isHitCastle) {
		isAttack = true;
		inactiveType = eInactiveType::Invasion;
		attackType = eAttackType::Invasion;
		animationCnt = 0;
	}

	//��A�N�e�B�u�ɂȂ����ꍇ
	if (!isActive && inactiveType == eInactiveType::Defeat) {
		//�����ɔ��e�𐶐����鏈����������
	}
	else if (!isActive && inactiveType == eInactiveType::Invasion) {
		//�����ɔ��e�𐶐����鏈����������
	}

	//�ړ�����
	Move(_player->Get_isAbility(), _player->Get_AbilityType());

	//�A�j���[�V��������
	Animation(_player->Get_isAbility(), _player->Get_AbilityType());

	//�U������
	if (isAttack) {
		AttackProc(_player->Get_cx(), _player->Get_cy());
	}
}

//�`�揈��
void Fairy_Bomb::Draw() {
	BaseEnemy::Draw();
}
