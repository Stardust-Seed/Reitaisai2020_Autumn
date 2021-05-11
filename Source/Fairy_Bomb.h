#ifndef _FAIRY_BOMB_H
#define _FAIRY_BOMB_H

#include "BaseEnemy.h"

class Fairy_Bomb : public virtual BaseEnemy {
public:
	//�f�t�H���g�R���X�g���N�^
	Fairy_Bomb() = default;

	//�����X�|�[���ʒu����̐����p�R���X�g���N�^
	Fairy_Bomb(float _speed, float _power, int _durability,
		eDirection _direction, eEnemyType _enemyType = eEnemyType::Bomb);

	//��̂������_����̐����p�R���X�g���N�^
	Fairy_Bomb(float _x, float _y, float _speed, float _power, int _durability,
		eDirection _direction, eEnemyType _enemyType);

	//�X�V����
	void Update(GameResource* _gameRes);

	//�`�揈��
	void Draw(GameResource* _gameRes);
};

#endif // !_FAIRY_BOMB_H