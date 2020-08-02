#ifndef _ENEMYMANAGER_H
#define _ENEMYMANAGER_H

#include "Fairy_Endurance.h"
#include "Fairy_Speed.h"

class EnemyManager {
private:
	static const int POPENEMY_EASY = 2;		//��Փx�ʉ�ʓ��̐�����

	static const int POPENEMY_NORMAL = 3;	//3�̂܂�

	static const int POPENEMY_HARD = 4;		//4�̂܂�

	static const int ENEMY_NUM = POPENEMY_EASY;

	Fairy_Endurance* Fairy_E[ENEMY_NUM];
	//�̗͌^�G�l�~�[�I�u�W�F�N�g�z��
public:
	EnemyManager();					//�R���X�g���N�^

	~EnemyManager();				//�f�X�g���N�^

	void SpawnEnemy();				//�G�l�~�[��������

	void Update();					//�X�V����

	void Draw();					//�`�揈��

	void Set_x(float _x);				//x���W���Z�b�g

	void Set_y(float _y);				//y���W���Z�b�g

	void Set_width(float _width);		//�����Z�b�g

	void Set_height(float _height);	//�������Z�b�g

	int Get_ActiveFlg(bool);			//�A�N�e�B�u�����󂯎��

	int Get_Power(int);				//�U���͂��󂯎��

	int Get_x();					//x���W���󂯎��

	int Get_y();					//y���W���󂯎��

	int Get_width();				//�����󂯎��

	int Get_height();				//�������󂯎��
};
#endif // !_ENEMYMANAGER_H
