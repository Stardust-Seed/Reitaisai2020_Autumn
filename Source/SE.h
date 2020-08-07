#ifndef _SE_H
#define _SE_H

#include <vector>
#include "Singleton.h"

/********************************************************************************************
�g�p��
//�Đ�����Ƃ�
SE::Instance()->PlaySE(SE_00,Back);
//�Đ����~�߂�Ƃ�
SE::Instance()->StopSE(SE_00);
********************************************************************************************/

// SE�i���o�[
//�ԍ��ɂ��邩�A���O�ŕ\�����邩�Ŗ����Ă܂�(���͔ԍ�)
//PlaySE(SE_00);  PlaySE(SE_Hit); 
enum SEnum {
	SE_00,
	SE_01,
	SE_02,
};

//�Đ��^�C�v
/***************************************************************
Back��Loop�̊ԂɕςȂ̂�����̂�PlaySoundMem�̑�������

DX_PLAYTYPE_NORMAL�@ : �m�[�}���Đ�
DX_PLAYTYPE_BACK�@�@ : �o�b�N�O���E���h�Đ�
DX_PLAYTYPE_LOOP�@�@ : ���[�v�Đ�

�������ł����ǐ��l�Ō����
DX_PLAYTYPE_NORMAL�@ : 0
DX_PLAYTYPE_BACK�@�@ : 1
DX_PLAYTYPE_LOOP�@�@ : 3

�ɂȂ��ĂĂ�������킹�邽�߂ɒǉ����Ă܂�
�Ԃ����Ⴏ�g���Ƃ��̈�����
DX_PLAYTYPE_NORMAL
DX_PLAYTYPE_BACK
DX_PLAYTYPE_LOOP

���ē����΂�����ł����ǂ��ꂾ�ƒ������Ȃ��Ďv����
���������Ă���܂��B����Ȃ��Ȃ畁�ʂɏ����܂���
****************************************************************/
enum PlayBackType {
	Normal,    //���̏����͎~�߂��A�Đ�����܂�
	Back,      //���̏����͎~�܂炸�A�Đ�����܂�
	No,        //�g��Ȃ��ł��������B�g�p���̋�����Back�Ɠ���
	Loop,      //���̏����͎~�܂炸�A���[�v�Đ�����܂�
};

class SE:public Singleton <SE> {

	friend Singleton <SE>;

private:

	std::vector<int> seNums;
	int seNum[3];                         //�i�[���邽�߂̔z��
	int LoadSE(const char* _filePath);    //�ǂݍ��ݗp��

public:

	SE();                                 //�R���X�g���N�^
	~SE();                                //�f�X�g���N�^
	void Load();                          //�ǂݍ��݂������
	void PlaySE(SEnum,PlayBackType);      //�Đ�
	void StopSE(SEnum);                   //��~

};

#endif //SE_H_