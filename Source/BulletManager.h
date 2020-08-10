#ifndef BULLET_MANAGER_H_
#define BULLET_MANAGER_H_

#include"Object.h"

//�e�N���X
class Bullet;

#define MAX_BULLET 10   //�e�̍ő�

class BulletManager
{
	Bullet* bullet[MAX_BULLET];  //�K���ɍő�e��10��

public:
	BulletManager();    //�R���X�g���N�^
	~BulletManager();   //�f�X�g���N�^

	//�e�𔭎˂���֐�
	void Shot(VECTOR& pos, int pl_pos, bool pl_attack);
	//�X�V
	void Update();
	//�`��
	void Draw();
};

#endif // BULLET_MANAGER_H_