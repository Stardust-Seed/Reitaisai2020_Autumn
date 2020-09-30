#ifndef _SE_H
#define _SE_H

#include <vector>
#include "Singleton.h"

/********************************************************************************************
�o�^�̎d��
SE.h��
SEnum�ɍ��ڒǉ�
int seNum[]; �̔��𑝂₷���A������傫������

,SE_urabe
int seNum[2];

SE.cpp��
Load()�ɍ��ڒǉ�

seNum[SE_urabe] = LoadSE("./res/Sound/SE/urabe.wav");

�g�p��
//�Đ�����Ƃ�
SE::Instance()->PlaySE(SE_test);
SE::Instance()->PlaySE(SE_test,DX_PLAYTYPE_LOOP);

���������w�肳��ĂȂ��Ƃ���
DX_PLAYTYPE_BACK���f�t�H���g�Ŏw�肳��Ă܂�

DX_PLAYTYPE_NORMAL�@ : ���̏������~�߂čĐ�
DX_PLAYTYPE_BACK�@�@ : ���̏����͎~�܂炸�ɍĐ�
DX_PLAYTYPE_LOOP�@�@ : ���̏����͎~�܂炸�Ƀ��[�v�Đ�

//�Đ����~�߂�Ƃ�
SE::Instance()->StopSE(SE_test);
********************************************************************************************/

// SE�i���o�[
//�ǉ�����Ƃ��͖��O�ł��肢���܂�
enum SEnum {
	SE_bomb,
	SE_cursor,
	SE_sukimaWarp,
	SE_CastleBreak,
	SE_CastleDamage,
	SE_warning,
	SE_DarknessStart,
	SE_DarknessEnd,
	SE_SakuyaAttack,
	SE_SakuyaAbility,
	SE_FranAttack,
	SE_FranAbility
};

class SE :public Singleton <SE> {

	friend Singleton <SE>;

private:

	std::vector<int> seNums;
	//�ǉ�����Ƃ��͂��̔z��̐��������₵�Ă�
	int seNum[12];                        //�i�[���邽�߂̔z��
	int LoadSE(const char* _filePath);    //�ǂݍ��ݗp��

public:

	SE();                                 //�R���X�g���N�^
	~SE();                                //�f�X�g���N�^
	void Load();                          //�ǂݍ��݂������
	void PlaySE(SEnum, int _type = 1);    //�Đ�
	void StopSE(SEnum);                   //��~
	void VolumeSE(int);                   //���ʐݒ�

};

#endif //SE_H_