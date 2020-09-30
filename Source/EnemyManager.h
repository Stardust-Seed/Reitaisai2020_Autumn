#ifndef _ENEMYMANAGER_H
#define _ENEMYMANAGER_H

#include "Fairy_Endurance.h"
#include "Fairy_Speed.h"
#include "Fairy_Power.h"
#include "CastleManager.h"
#include "ItemManager.h"
#include "Direction.h"


class EnemyManager {
private:
	static const int POPENEMY_EASY = 2;		//��Փx�ʉ�ʓ��̐�����

	static const int POPENEMY_NORMAL = 3;	//3�̂܂�

	static const int POPENEMY_HARD = 4;		//4�̂܂�

	static const int POPENEMY_ADD = 8;      //�ǉ��̓G�̍ő吔

	static const int MAX_ENEMY_NUM = POPENEMY_HARD + POPENEMY_ADD;			//�G�l�~�[�̍ő吶�������̗v�f��

	static const int ENEMY_TYPES = 3;		//���݂̃G�l�~�[�̎��

	/*******************************************************************
		�e�G�l�~�[�̃X�e�[�^�X

		������X�s�[�h/�̗�/�p���[�̏�
	*******************************************************************/

	const float SPEED[ENEMY_TYPES] = { 1.5f, 0.8f, 0.8f};	//�e�G�l�~�[�̑��x

	const float POWER[ENEMY_TYPES] = { 5.0f, 8.0f, 10.0f};	//�e�G�l�~�[�̃p���[

	const int DURABILITY[ENEMY_TYPES] = { 25, 125, 75};	//�e�G�l�~�[�̗̑�

	BaseEnemy* Enemys[MAX_ENEMY_NUM];			//�G�l�~�[�I�u�W�F�N�g�z��

	eDirection direction;						//�����̗񋓃N���X

	int waitCount;					//�����ҋ@�p

	int enemyType;					//�����_���Ȓl������

	int enemyNum;					//��Փx�ʐ�����������

	int addEnemyNum;				//�ǉ������G�l�~�[�̐�

	int activeCount;				//�A�N�e�B�u�ȃG�l�~�[�̐�������
	
	int _direction;					//����

public:
	EnemyManager(int);					//�R���X�g���N�^

	~EnemyManager();				//�f�X�g���N�^

	void Update(CastleManager*,BasePlayer*,BulletManager*,ItemManager*);					//�X�V����

	void Draw();									//�`�揈��

	void SpawnEnemy(CastleManager*);				//�G�l�~�[��������

	void Set_IsActive(int, bool);			//�A�N�e�B�u�t���O�̃Z�b�^�[

	void Set_IsAttack(int, bool);			//�U���t���O�̃Z�b�^�[	

	void Set_direction(int, eDirection);	//direction�̃Z�b�^�[

	void Set_x(int,float _x);				//x���W���Z�b�g

	void Set_y(int,float _y);				//y���W���Z�b�g

	void Set_width(int,float _width);		//�����Z�b�g

	void Set_height(int,float _height);		//�������Z�b�g

	int Get_enemyNum();				//��Փx�ɂ���ĕς�鐶������Ԃ�

	int Get_ActiveCount();			//�A�N�e�B�u�ȃG�l�~�[�̒l��Ԃ�

	bool Get_ActiveFlg(int);			//�A�N�e�B�u�����󂯎��

	bool Get_AttackFlg(int);			//�A�^�b�N�t���O���󂯎��

	eAttackType Get_AttackType(int);		//�A�^�b�N�^�C�v�̃Q�b�^�[

	eDirection Get_direction(int);		//direction�̃Q�b�^�[

	int Get_Power(int);				//�U���͂��󂯎��

	float Get_x(int);					//x���W���󂯎��

	float Get_y(int);					//y���W���󂯎��

	float Get_width(int);				//�����󂯎��

	float Get_height(int);			//�������󂯎��
};
#endif // !_ENEMYMANAGER_H
