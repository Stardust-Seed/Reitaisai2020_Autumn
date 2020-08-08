#include "BGM.h"
#include"DxLib.h"

//�R���X�g���N�^
BGM::BGM() {

	Load();
}

//�f�X�g���N�^
BGM::~BGM() {

	//�v�f�̐������Ȃ̂��擾����
	int size = bgmNums.size();

	//���[�h����BGM�������܂�
	for (int i = 0; i < size; i++)
	{
		DeleteSoundMem(bgmNums[i]);
	}

	//���܂Œǉ����Ă����v�f�̔���������
	bgmNums.clear();
}

//�ǂݍ���
void BGM::Load()
{
	//�t�@�C���p�X�w��
	bgmNum[BGM_test] = LoadBGM("./res/Sound/BGM/OOHSYUK.wav");

}

//BGM���Đ�
void BGM::PlayBGM(BGMnum _BGMnum, int _type, bool _topFlg)
{
	//DrawFormatString(10, 500, GetColor(255, 255, 255), "�T�E���h�Đ�_�ԍ�:%d",_BGMnum);
	if (_topFlg == true)
	{
		//DrawFormatString(50, 500, GetColor(255, 255, 255), "�ŏ�����Đ�");
		PlaySoundMem(bgmNum[_BGMnum], _type, TRUE);
	}
	else
	{
		//DrawFormatString(50, 500, GetColor(255, 255, 255), "��������Đ�");
		PlaySoundMem(bgmNum[_BGMnum], _type, FALSE);
	}
}

//BGM���~�߂�
void BGM::StopBGM(BGMnum _BGMnum)
{
	StopSoundMem(bgmNum[_BGMnum]);
}

//wav�t�@�C����ǂݍ���œǂݍ��񂾂�������o�ϐ��ɒǉ�
int BGM::LoadBGM(const char* _FilePath)
{
	//�ǂݍ���
	int newHandle = LoadSoundMem(_FilePath);

	//�v�f�̒ǉ�
	bgmNums.push_back(newHandle);

	//�ԋp
	return newHandle;
}