#ifndef BULLET_MANAGER_H_
#define BULLET_MANAGER_H_

#include"Object.h"

//�e�N���X
class Bullet;
class EnemyManager;

#define MAX_BULLET 10   //�e�̍ő�

class BulletManager
{
	Bullet* bullet[MAX_BULLET];  //�K���ɍő�e��10��

	//�G�l�~�[�Ǘ��̃|�C���^�ϐ�
	EnemyManager* enemyManager;

private:
	int activeBullet;   //Active�Ȓe�̐�
public:
	BulletManager();    //�R���X�g���N�^
	~BulletManager();   //�f�X�g���N�^

	//�e�𔭎˂���֐�
	void Shot(VECTOR& pos, int pl_pos, bool pl_attack);
	//�X�V
	void Update(EnemyManager* _enemyManager);
	//�`��
	void Draw();

	bool Get_IsActive(int i); //�e���U�������ǂ����̃Q�b�^�[
	bool Get_IsHit(int i);    //�e�������������ǂ����̃Q�b�^�[

	float Get_X(int i);       //�e��x���W�Q�b�^�[
	float Get_Y(int i);       //�e��y���W�Q�b�^�[
	float Get_Width(int i);   //�e��width���W�Q�b�^�[
	float Get_Height(int i);  //�e��height���W�Q�b�^�[

	int Get_ActiveBullet();   //Active�Ȓe�̃Q�b�^�[

	int Get_ispower(int i);        //�e�̍U����
};

#endif // BULLET_MANAGER_H_