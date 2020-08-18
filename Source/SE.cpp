#include "DxLib.h"
#include "SE.h"

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
	//���g������(�������܂��������ĂȂ�)
	seNums.clear();
	//�����������
	seNums.shrink_to_fit();
}

//�ǂݍ���
void SE::Load()
{
	//�t�@�C���p�X�w��
	seNum[SE_test] = LoadSE("./res/Sound/SE/test.wav");

}

//SE���Đ�
void SE::PlaySE(SEnum _SEnum,int _type)
{
	//���̉����Đ�����������~�߂�
	if (CheckSoundMem(seNum[_SEnum]) == 1)
	{
		StopSoundMem(seNum[_SEnum]);
	}

	PlaySoundMem(seNum[_SEnum], _type, TRUE);
}

//SE���~�߂�
void SE::StopSE(SEnum _SEnum)
{
	StopSoundMem(seNum[_SEnum]);
}

//���ʂ̐ݒ�
void SE::VolumeSE(int _volume)
{
	int size = seNums.size();
	for (int i = 0; i < size; i++)
	{
		ChangeVolumeSoundMem(255 * (_volume * 10) / 100, seNum[i]);
	}
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