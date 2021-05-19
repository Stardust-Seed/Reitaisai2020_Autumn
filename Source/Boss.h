#ifndef _BOSS_H
#define _BOSS_H

#include "BaseEnemy.h"

//�{�X�N���X
class Boss final : public virtual BaseEnemy {
private:
	const int STOPTIME = 120;	//��~�b��
	int stopCnt;				//��~�J�E���g

	const int COOLTIME = 300;	//�U���̃N�[���^�C��
	int attackCnt;				//�U���J�E���^

	const int EFFECT_MAX_NUM = 8;	//�G�t�F�N�g�̍ő吔
	int* effectArray;				//�G�t�F�N�g�`��p�z��
	int effectIndex;				//�G�t�F�N�g�`��p�z���index�w��p
	bool isEffect;					//�G�t�F�N�g�t���O
	float effectDrawX;				//�G�t�F�N�g��`�悷��ʒu(x���W)
	float effectDrawY;				//�G�t�F�N�g��`�悷��ʒu(y���W)
public:
	//�f�t�H���g�R���X�g���N�^
	Boss() = default;

	//�f�X�g���N�^
	~Boss();

	//�����X�|�[���ʒu����̐����p�R���X�g���N�^
	Boss(float _speed, float _power, int _durability,
		eDirection _direction, eEnemyType _enemyType = eEnemyType::Boss);

	//�X�V����
	void Update(GameResource* _gameRes);
	//�`�揈��
	void Draw(GameResource* _gameRes);
};

#endif // !_BOSS_H