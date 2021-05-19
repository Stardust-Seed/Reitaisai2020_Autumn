#ifndef BULLET_H_
#define BULLET_H_

#include "Object.h"
#include "DxLib.h"
#include "Image.h"
#include "Direction.h"
#include "BasePlayer.h"

class BaseEnemy;
class EnemyManager;

//�e�̊Ǘ�
class Bullet :public virtual Object
{
private:

	const float PI = 3.141592654;

	//�G�l�~�[�̃|�C���^�ϐ�
	BaseEnemy* baseEnemy;

	//�G�l�~�[�Ǘ��̃|�C���^�ϐ�
	EnemyManager* enemyManager;

	//DX���C�u�����Œ�`����Ă���\���́i���g��float�^��x,y,z�j
	//�e�̈ʒu
	VECTOR pos;

	//�e�̐i�ޕ���
	eDirection bullet_Move;

	//���˂���Ă邩�ǂ���
	bool isActive;

	//�U����
	int power;

	//�`���[�W�Q�[�W
	int shotPower;

	//�摜
	int bulletGraph;

	//�摜��]
	float graphAngle;

public:
	//�����蔻��
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);

	//�R���X�g���N�^���ɒe�̔����ʒu�ƁA�i�ޕ����������Ŏ�������
	Bullet(VECTOR& position, int pl_type,eDirection pl_direction, bool pl_attack,int pl_power,int shotpower);        //�R���X�g���N�^
	~Bullet();       //�f�X�g���N�^
	void Draw();     //�`��
	void Update(EnemyManager* _eManager,BasePlayer* _basePlayer);   //�X�V

	float Get_x() { return pos.x; }           //x���W�Q�b�^�[
	float Get_y() { return pos.y; }			  //y���W�Q�b�^�[
	float Get_width() { return width; }       //width�Q�b�^�[
	float Get_height() { return height; }     //height�Q�b�^�[
	int Get_power() { return power; }         //power�Q�b�^�[

	bool Get_isActive() { return isActive; } //�e���U�������ǂ����̃Q�b�^�[
	bool Get_isHit() { return isHit; }       //�e�̓����蔻��̃Q�b�^�[

	void Set_isActive(bool _Active) { isActive = _Active; } //�e�̃A�N�e�B�u�̃Z�b�^�[

};

#endif // BULLET_H_