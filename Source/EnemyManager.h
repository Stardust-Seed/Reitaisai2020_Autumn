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

	static const int ENEMY_NUM = POPENEMY_EASY;

	static const int SPAWN_SPEED = 0;		//�������ʔԍ�

	static const int SPAWN_ENDURANCE = 1;	//�������ʔԍ�

	BaseEnemy* Enemys[ENEMY_NUM];			//�G�l�~�[�I�u�W�F�N�g�z��
	
	int _durability;				//�̗�
	
	int _direction;					//����
	
	float _speed;					//���x
	
	float _power;					//�p���[

public:
	EnemyManager();					//�R���X�g���N�^

	~EnemyManager();				//�f�X�g���N�^

	void SpawnEnemy();				//�G�l�~�[��������

	void Update(Castle*,BasePlayer*);					//�X�V����

	void Draw();					//�`�揈��

	void Set_x(float _x);				//x���W���Z�b�g

	void Set_y(float _y);				//y���W���Z�b�g

	void Set_width(float _width);		//�����Z�b�g

	void Set_height(float _height);	//�������Z�b�g

	int Get_ActiveFlg(int);			//�A�N�e�B�u�����󂯎��

	int Get_Power(int);				//�U���͂��󂯎��

	int Get_x(int);					//x���W���󂯎��

	int Get_y(int);					//y���W���󂯎��

	int Get_width(int);				//�����󂯎��

	int Get_height(int);			//�������󂯎��

};
#endif // !_ENEMYMANAGER_H
