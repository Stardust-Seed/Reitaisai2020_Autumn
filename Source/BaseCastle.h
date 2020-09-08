#ifndef _BASECASTLE_H
#define _BASECASTLE_H

#include "Object.h"

/*-------------------------------------------------------------
�I�u�W�F�N�g��    BaseCastle
�T�v    ���_�̌��ɂȂ�I�u�W�F�N�g
�A�N�Z�X
�p���N���X    Object(�I�u�W�F�N�g)
�Ă΂��
�ڍא���    Object����p�������A���_�̌�
--------------------------------------------------------------*/

class EnemyManager;

class BaseCastle :public Object {
protected:
	static const int MAX_DURABILITY;		//�ő�ϋv��			

	int durability;		                    //���_�̗̑�
	int direction;
	bool isActive;		                    //���_�̐����t���O

public:
	BaseCastle(int);                        //�R���X�g���N�^

	virtual void Update(EnemyManager*) {} 	//�X�V����
	virtual void Draw() {}		        	//�`�揈��

	//�������͎g��Ȃ�
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh) {
		return false;
	}
	// m = my ����   o = opnet ����	//�����蔻�菈��

	//�������g��
	bool ClisionHit(float ox, float oy, float ow, float oh,
		int pow, int num, bool attackFlg, bool activeFlg);

	//�Q�b�^�[
	//���_�֘A
	int   Get_Durability() { return durability; }

	bool  GetIsActive()    { return isActive; }

	float Get_X() { return x; }
	float Get_Y() { return y; }
	float Get_Width() { return width; }
	float Get_Height() { return height; }

	int Get_CastleDirection() { return direction; }
};

#endif //_BASECASTLE_H_