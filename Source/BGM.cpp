#include "DxLib.h"
#include "BGM.h"

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
	//���g������(�������܂��������ĂȂ�)
	bgmNums.clear();
	//�����������
	bgmNums.shrink_to_fit();
}

//�ǂݍ���
void BGM::Load()
{
	//�t�@�C���p�X�w��
	bgmNum[BGM_title] = LoadBGM("./res/Sound/BGM/gensoukyounohatuaki.wav");
	bgmNum[BGM_menu] = LoadBGM("./res/Sound/BGM/engawakaranagameru.wav");
	bgmNum[BGM_gameScene] = LoadBGM("./res/Sound/BGM/youseinoakudoi.wav");
	bgmNum[BGM_result] = LoadBGM("./res/Sound/BGM/asobiniikuhinoasa_2.wav");
}

//BGM���Đ�
void BGM::PlayBGM(BGMnum _BGMnum, int _type, bool _topFlg)
{
	DrawFormatString(10, 500, GetColor(255, 255, 255), "�T�E���h�Đ�_�ԍ�:%d", PlaySoundMem(bgmNum[_BGMnum], _type, TRUE));
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

//���ʂ̐ݒ�
void BGM::VolumeBGM(int _volume)
{
	int size = bgmNums.size();
	for (int i = 0; i < size; i++)
	{
		ChangeVolumeSoundMem(255 * (_volume * 10) / 100, bgmNum[i]);
	}
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