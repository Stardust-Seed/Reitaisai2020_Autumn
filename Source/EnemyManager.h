#ifndef _ENEMYMANAGER_H
#define _ENEMYMANAGER_H

#include "Fairy_Endurance.h"
#include "Fairy_Speed.h"

class CastleManager;

class BasePlayer;

class BulletManager;

class ItemManager;

class BaseEnemy;

class Fairy_Endurance;

class Fairy_Speed;

class EnemyManager {
private:
	static const int POPENEMY_EASY = 2;		//��Փx�ʉ�ʓ��̐�����

	static const int POPENEMY_NORMAL = 3;	//3�̂܂�

	static const int POPENEMY_HARD = 4;		//4�̂܂�

	static const int POPENEMY_ADD = 8;      //�ǉ��̓G�̍ő吔

	static const int MAX_ENEMY_NUM = POPENEMY_HARD + POPENEMY_ADD;			//�G�l�~�[�̍ő吶�������̗v�f��

	static const int ENEMY_TYPES = 2;		//���݂̃G�l�~�[�̎��

	BaseEnemy* Enemys[MAX_ENEMY_NUM];			//�G�l�~�[�I�u�W�F�N�g�z��

	int waitCount;					//�����ҋ@�p

	int enemyType;					//�����_���Ȓl������

	int enemyNum;					//��Փx�ʐ�����������

	int addEnemyNum;				//�ǉ������G�l�~�[�̐�

	int activeCount;				//�A�N�e�B�u�ȃG�l�~�[�̐�������

	int _durability;				//�̗�
	
	int _direction;					//����
	
	float _speed;					//���x
	
	float _power;					//�p���[

public:
	EnemyManager(int);					//�R���X�g���N�^

	~EnemyManager();				//�f�X�g���N�^

	void Update(CastleManager*,BasePlayer*,BulletManager*,ItemManager*);					//�X�V����

	void Draw();									//�`�揈��

	void SpawnEnemy(CastleManager*);				//�G�l�~�[��������

	void Set_IsActive(int, bool);			//�A�N�e�B�u�t���O�̃Z�b�^�[

	void Set_IsAttack(int, bool);			//�U���t���O�̃Z�b�^�[	

	void Set_IsMove(int, bool);				//�ړ��t���O�̃Z�b�^�[

	void Set_x(int,float _x);				//x���W���Z�b�g

	void Set_y(int,float _y);				//y���W���Z�b�g

	void Set_width(int,float _width);		//�����Z�b�g

	void Set_height(int,float _height);		//�������Z�b�g

	int Get_enemyNum();				//��Փx�ɂ���ĕς�鐶������Ԃ�

	int Get_ActiveCount();			//�A�N�e�B�u�ȃG�l�~�[�̒l��Ԃ�

	int Get_ActiveFlg(int);			//�A�N�e�B�u�����󂯎��

	int Get_AttackFlg(int);			//�A�^�b�N�t���O���󂯎��

	int Get_Power(int);				//�U���͂��󂯎��

	int Get_x(int);					//x���W���󂯎��

	int Get_y(int);					//y���W���󂯎��

	int Get_width(int);				//�����󂯎��

	int Get_height(int);			//�������󂯎��
};
#endif // !_ENEMYMANAGER_H
