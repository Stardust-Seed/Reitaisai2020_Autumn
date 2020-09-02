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

	bool isActive;		                    //���_�̐����t���O

public:
	BaseCastle(int);                 //�R���X�g���N�^

	virtual void Update(EnemyManager*) {} 			//�X�V����
	virtual void Draw() {}			//�`�揈��

	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh) 
	{
		return isActive;
	}
	// m = my ����   o = opnet ����	//�����蔻�菈��

	//�Q�b�^�[
	bool GetIsActive() { return isActive; }

	int Get_Durability() { return durability; }

	float Get_X() { return x; }
	float Get_Y() { return y; }
	float Get_Width() { return width; }
	float Get_Height() { return height; }

	void Set_Durability(int);
	void Set_IsActive(bool);
};

#endif //_BASECASTLE_H_