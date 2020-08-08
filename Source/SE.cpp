#include "SE.h"
#include"DxLib.h"
//�R���X�g���N�^
SE::SE(){

	Load();
}

//�f�X�g���N�^
SE::~SE() {

	//�v�f�̐������Ȃ̂��擾����
	int size = seNums.size();

	//���[�h����SE�������܂�
	for (int i = 0; i < size; i++)
	{
		DeleteSoundMem(seNums[i]);
	}

	//���܂Œǉ����Ă����v�f�̔���������
	seNums.clear();
}

//�ǂݍ���
void SE::Load()
{
	//�t�@�C���p�X�w��
	seNum[SE_test] = LoadSE("./res/Sound/SE/OOHSYUK.wav");

}

//SE���Đ�
void SE::PlaySE(SEnum _SEnum,int _type)
{
	//DrawFormatString(10, 500, GetColor(255, 255, 255), "�T�E���h�Đ�_�ԍ�:%d",_SEnum);
	PlaySoundMem(seNum[_SEnum],_type,TRUE);
}

//SE���~�߂�
void SE::StopSE(SEnum _SEnum)
{
	StopSoundMem(seNum[_SEnum]);
}

//wav�t�@�C����ǂݍ���œǂݍ��񂾂�������o�ϐ��ɒǉ�
int SE::LoadSE(const char* _FilePath)
{
	//�ǂݍ���
	int newHandle = LoadSoundMem(_FilePath);

	//�v�f�̒ǉ�
	seNums.push_back(newHandle);

	//�ԋp
	return newHandle;
}