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
//�����V�[�����Ƃɓǂݍ��ނ�U�蕪���Ă��������������Ǝv���̂��ȁ[�Ǝv���܂���
//Load�Ɉ�����EBaseScene�������Ă��Ă��̃V�[���ʂ�switch���œǂݍ��ނ�����s�݂�����
void SE::Load()
{
	//�t�@�C���p�X�w��
	seNum[SE_00] = LoadSE("./res/Sound/SE/OOHSYUK.wav");
	seNum[SE_01] = 0;
	seNum[SE_02] = 0;
}

//SE���Đ�
void SE::PlaySE(SEnum _SEnum, PlayBackType _PlayBackType)
{
	//DrawFormatString(10, 500, GetColor(255, 255, 255), "�T�E���h�Đ�_�ԍ�:%d",_SEnum);
	PlaySoundMem(seNum[_SEnum], _PlayBackType,TRUE);
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