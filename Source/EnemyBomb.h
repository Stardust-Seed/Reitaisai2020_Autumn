#ifndef _ENEMYBOMB_H
#define _ENEMYBOMB_H

#include "Object.h"

class Player;
class EnemyManager;
class CastleManager;

//���j�^�C�v
enum class eExType {
	Immediately,		//�����j
	Installation		//�ݒu
};

//�G�l�~�[�̔��e�N���X
class EnemyBomb : public Object {
private:
	bool isActive;			//�A�N�e�B�u�t���O

	const int EXTIME = 180;	//���j�܂ł̃^�C��
	int exCnt;				//���j�J�E���g
	float exAreaSize;		//���j�͈͂̃T�C�Y
	bool isExplosion;		//���j�t���O

	const int EFFECT_MAX_NUM = 8;	//�G�t�F�N�g�̍ő吔
	int* effectArray;				//�G�t�F�N�g�`��p�z��
	int effectIndex;				//�G�t�F�N�g�`��p�z���index�w��p

	//�����蔻�菈��
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);
public:
	//�R���X�g���N�^
	EnemyBomb(float _x, float _y, eExType _exType);

	void Update(Player* _player, CastleManager* _castleManager,
		EnemyManager* _enemyManager);

	//�`�揈��
	void Draw();

	//�A�N�e�B�u�t���O���擾����
	bool Get_IsActive() { return isActive; }
};

#endif // !_ENEMYBOMB_H
