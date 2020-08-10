#ifndef BULLET_H_
#define BULLET_H_

#include "Object.h"

class BaseEnemy;

//�e�̊Ǘ�
class Bullet :public virtual Object
{
private:

	//�G�l�~�[�̃|�C���^�ϐ�
	BaseEnemy* baseEnemy;

	//DX���C�u�����Œ�`����Ă���\���́i���g��float�^��x,y,z�j
	//�e�̈ʒu
	VECTOR pos;

	//�e�̐i�ޕ���
	int Bullet_Move;

	//���˂���Ă邩�ǂ���
	bool Bullet_Attack;

	//�摜
	int gh;

	//�e�X�g�p�J���[
	int Cr;
public:
	//�����蔻��
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);

	//�R���X�g���N�^���ɒe�̔����ʒu�ƁA�i�ޕ����������Ŏ�������
	Bullet(VECTOR& position, int pl_pos, bool pl_attack);        //�R���X�g���N�^
	~Bullet();       //�f�X�g���N�^
	void Draw();     //�`��
	void Update();   //�X�V

	float Get_x() { return pos.x; }           //x���W�Q�b�^�[
	float Get_y() { return pos.y; }			  //y���W�Q�b�^�[
	float Get_width() { return width; }       //width�Q�b�^�[
	float Get_height() { return height; }     //height�Q�b�^�[

	bool Get_Flag() { return Bullet_Attack; } //�e���U�������ǂ����̃Q�b�^�[
	bool Get_Hit() { return isHit; }          //�e�������������ǂ����̃Q�b�^�[
};

#endif // BULLET_H_