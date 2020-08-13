#ifndef _ENEMYMANAGER_H
#define _ENEMYMANAGER_H

#include "Fairy_Endurance.h"
#include "Fairy_Speed.h"

class Castle;

class BasePlayer;

class BaseEnemy;

class Fairy_Endurance;

class Fairy_Speed;

class EnemyManager {
private:
	static const int POPENEMY_EASY = 2;		//��Փx�ʉ�ʓ��̐�����

	static const int POPENEMY_NORMAL = 3;	//3�̂܂�

	static const int POPENEMY_HARD = 4;		//4�̂܂�

	static const int ENEMY_TYPES = 2;		//���݂̃G�l�~�[�̎��

	static const int MAX_ENEMY_NUM = 4;			//�G�l�~�[�̍ő吶�������̗v�f��

	BaseEnemy* Enemys[MAX_ENEMY_NUM];			//�G�l�~�[�I�u�W�F�N�g�z��

	int enemyType;					//�����_���Ȓl������

	int enemyNum;					//��Փx�ʐ�����������

	int _durability;				//�̗�
	
	int _direction;					//����
	
	float _speed;					//���x
	
	float _power;					//�p���[

public:
	EnemyManager(int);					//�R���X�g���N�^

	~EnemyManager();				//�f�X�g���N�^

	void SpawnEnemy();				//�G�l�~�[��������

	void Update(Castle*,BasePlayer*);					//�X�V����

	void Draw();					//�`�揈��

	void Set_x(int,float _x);				//x���W���Z�b�g

	void Set_y(int,float _y);				//y���W���Z�b�g

	void Set_width(int,float _width);		//�����Z�b�g

	void Set_height(int,float _height);	//�������Z�b�g

	int Get_ActiveFlg(int);			//�A�N�e�B�u�����󂯎��

	int Get_Power(int);				//�U���͂��󂯎��

	int Get_x(int);					//x���W���󂯎��

	int Get_y(int);					//y���W���󂯎��

	int Get_width(int);				//�����󂯎��

	int Get_height(int);			//�������󂯎��

};
#endif // !_ENEMYMANAGER_H
