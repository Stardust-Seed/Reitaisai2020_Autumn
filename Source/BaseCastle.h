#ifndef _BASECASTLE_H
#define _BASECASTLE_H

#include "Object.h"
#include "Direction.h"
#include "Define.h"
#include "Image.h"
#include "SE.h"
/*-------------------------------------------------------------
�I�u�W�F�N�g��    BaseCastle
�T�v    ���_�̌��ɂȂ�I�u�W�F�N�g
�A�N�Z�X
�p���N���X    Object(�I�u�W�F�N�g)
�Ă΂��
�ڍא���    Object����p�������A���_�̌�
--------------------------------------------------------------*/

class EnemyManager;
class EventManager;

class BaseCastle :public Object {
protected:
	int maxDurabiliy;		                //�ő�ϋv��			

	int durability;		                    //���_�̗̑�
	eDirection direction;
	bool isActive;		                    //���_�̐����t���O
	bool dyingFlg;                          //�m���t���O

	int addSize;                            //�ǉ��̃T�C�Y
	float addPosX;                          //�ǉ���X���W
	float addPosY;                          //�ǉ���Y���W

	float popPosX;                          //�T�u���_����o��G�l�~�[�̍��WX
	float popPosY;                          //�T�u���_����o��G�l�~�[�̍��WY

	float drawPosX;                         //�\�������̍��WX
	float drawPosY;                         //�\�������̍��WY
public:
	BaseCastle(int);                        //�R���X�g���N�^

	virtual void Update(EnemyManager*) {} 	//�X�V����
	virtual void Update(EnemyManager*,EventManager*) {} 	//�X�V����(���C���L���b�X��)
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
	int   Get_Durability() { return durability; }             //���_��HP�̃Q�b�^�[

	bool  GetIsActive()    { return isActive; }               //���_���������Ă��邩�̃Q�b�^�[

	float Get_X() { return x; }                               //���_�̃Q�b�^�[X
	float Get_Y() { return y; }                               //���_�̃Q�b�^�[Y
	float Get_Width() { return width; }                       //�����̃Q�b�^�[
	float Get_Height() { return height; }                     //�c���̃Q�b�^�[

	float Get_PopPosX() { return popPosX; }                   //�G�̐����ꏊ�̃Q�b�^�[X
	float Get_PopPosY() { return popPosY; }                   //�G�̐����ꏊ�̃Q�b�^�[Y

	float Get_DrawPosX() { return drawPosX; }                 //�\���ꏊ�̃Q�b�^�[X
	float Get_DrawPosY() { return drawPosY; }                 //�\���ꏊ�̃Q�b�^�[Y

	eDirection Get_CastleDirection() { return direction; }    //�����̃Q�b�^�[
};

#endif //_BASECASTLE_H_