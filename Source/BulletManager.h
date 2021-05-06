#ifndef BULLET_MANAGER_H_
#define BULLET_MANAGER_H_

#include"Object.h"
#include"Direction.h"
#include"BasePlayer.h"

//�e�N���X
class Bullet;
class EnemyManager;
class BasePlayer;
class BulletManager
{
	static const int MAX_BULLET = 50;  //�e�̍ő�

	Bullet* bullet[MAX_BULLET];  //�K���ɍő�e��10��

	//�G�l�~�[�Ǘ��̃|�C���^�ϐ�
	EnemyManager* enemyManager;

	//�v���C���[�Ǘ��̃|�C���^�ϐ�
	BasePlayer* basePlayer;

private:
	int activeBullet;   //Active�Ȓe�̐�
public:
	BulletManager();    //�R���X�g���N�^
	~BulletManager();   //�f�X�g���N�^

	//�e�𔭎˂���֐�
	void Shot(VECTOR& pos,int pl_type,eDirection pl_direction, bool pl_attack,int pl_power,int shotpower);
	//�X�V
	void Update(EnemyManager* _enemyManager, BasePlayer* _basePlayer,BuffManager* _bManager);
	//�`��
	void Draw();

	bool Get_IsActive(int i); //�e���U�������ǂ����̃Q�b�^�[
	bool Get_IsHit(int i);    //�e�������������ǂ����̃Q�b�^�[

	float Get_X(int i);       //�e��x���W�Q�b�^�[
	float Get_Y(int i);       //�e��y���W�Q�b�^�[
	float Get_Width(int i);   //�e��width���W�Q�b�^�[
	float Get_Height(int i);  //�e��height���W�Q�b�^�[

	int Get_ActiveBullet();   //Active�Ȓe�̃Q�b�^�[
	int Get_MaxBullet();      //�e�̍ő吔�̃Q�b�^�[
	int Get_Power(int i);          //�e�̍U����

	void Set_isActive(int, bool);//�e��Active�̃Z�b�^�[
};

#endif // BULLET_MANAGER_H_