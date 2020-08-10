#ifndef _SE_H
#define _SE_H

#include <vector>
#include "Singleton.h"

/********************************************************************************************
�g�p��
//�Đ�����Ƃ�
SE::Instance()->PlaySE(SE_00);
SE::Instance()->PlaySE(SE_00,DX_PLAYTYPE_LOOP);

���������w�肳��ĂȂ��Ƃ���
DX_PLAYTYPE_BACK���f�t�H���g�Ŏw�肳��Ă܂�

DX_PLAYTYPE_NORMAL�@ : ���̏������~�߂čĐ�
DX_PLAYTYPE_BACK�@�@ : ���̏����͎~�܂炸�ɍĐ�
DX_PLAYTYPE_LOOP�@�@ : ���̏����͎~�܂炸�Ƀ��[�v�Đ�

//�Đ����~�߂�Ƃ�
SE::Instance()->StopSE(SE_00);
********************************************************************************************/

// SE�i���o�[
//�ǉ�����Ƃ��͖��O�ł��肢���܂�
enum SEnum {
	SE_test,

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
	void PlaySE(SEnum,int _type= 1);      //�Đ�
	void StopSE(SEnum);                   //��~

};

#endif //SE_H_