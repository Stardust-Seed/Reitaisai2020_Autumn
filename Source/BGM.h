#ifndef _BGM_H
#define _BGM_H

#include <vector>
#include "Singleton.h"

/********************************************************************************************
�g�p��

//�Đ�����Ƃ�
BGM::Instance()->PlayBGM(BGM_00);
BGM::Instance()->PlayBGM(BGM_00,DX_PLAYTYPE_LOOP);
BGM::Instance()->PlayBGM(BGM_00,DX_PLAYTYPE_LOOP,FALSE);

��O�����g���Ƃ��͑������������Ǝw�肵�Ă�������

���������w�肳��ĂȂ��Ƃ���
DX_PLAYTYPE_BACK���f�t�H���g�Ŏw�肳��Ă܂�

DX_PLAYTYPE_NORMAL�@ : ���̏������~�߂čĐ�
DX_PLAYTYPE_BACK�@�@ : ���̏����͎~�܂炸�ɍĐ�
DX_PLAYTYPE_LOOP�@�@ : ���̏����͎~�܂炸�Ƀ��[�v�Đ�

��O�������w�肳��ĂȂ��Ƃ���
TRUE���f�t�H���g�Ŏw�肳��Ă܂�

TRUE    : �ŏ�����Đ�
FALSE   : ��������Đ�

//�Đ����~�߂�Ƃ�
BGM::Instance()->StopBGM(BGM_test);
********************************************************************************************/

// BGM�i���o�[
//�ǉ�����Ƃ��͖��O�ł��肢���܂�
enum BGMnum {
	BGM_test,

};


class BGM :public Singleton <BGM> {

	friend Singleton <BGM>;

private:

	std::vector<int> bgmNums;
	//�ǉ�����Ƃ��͂��̔z��̐��������₵�Ă�
	int bgmNum[3];                                              //�i�[���邽�߂̔z��
	int LoadBGM(const char* _filePath);                         //�ǂݍ��ݗp��

public:

	BGM();                                                      //�R���X�g���N�^
	~BGM();                                                     //�f�X�g���N�^
	void Load();                                                //�ǂݍ��݂������
	void PlayBGM(BGMnum,int _type = 1, bool _topflg = true);    //�Đ�
	void StopBGM(BGMnum);                                       //��~

};

#endif //BGM_H_