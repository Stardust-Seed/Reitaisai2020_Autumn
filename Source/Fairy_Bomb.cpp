#include "Fairy_Bomb.h"

#include "BasePlayer.h"
#include "BulletManager.h"
#include "CastleManager.h"
#include "EnemyManager.h"

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
void Fairy_Bomb::Update(GameResource* _gameRes){

	//�X�V����
	BaseEnemy::Update(_gameRes);

	//�锭����
	if (isHitCastle) {
		isAttack = true;
		inactiveType = eInactiveType::Invasion;
		attackType = eAttackType::Invasion;
		animationCnt = 0;
	}

	//��A�N�e�B�u�ɂȂ����ꍇ
	if (!isActive && inactiveType == eInactiveType::Defeat) {
		_gameRes->enemyManager->SpawnBomb(x, y, eExType::Immediately);
	}
	else if (inactiveType == eInactiveType::Invasion) {
		_gameRes->enemyManager->SpawnBomb(x, y, eExType::Installation);
	}

	bool pIsAbility = _gameRes->player->Get_isAbility();
	int pAbilityType = _gameRes->player->Get_AbilityType();

	//�ړ�����
	Move(pIsAbility, pAbilityType);

	//�A�j���[�V��������
	Animation(pIsAbility, pAbilityType);

	//�U������
	if (isAttack == true) {
		AttackProc(_gameRes->player->Get_cx(), _gameRes->player->Get_cy());
	}
}

//�`�揈��
void Fairy_Bomb::Draw(GameResource* _gameRes) {
	BaseEnemy::Draw(_gameRes);
}
