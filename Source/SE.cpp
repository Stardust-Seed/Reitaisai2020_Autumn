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
	seNum[SE_bomb] = LoadSE("./res/Sound/SE/bomb1.wav");
	seNum[SE_cursor] = LoadSE("./res/Sound/SE/cursor2.wav");
	seNum[SE_sukimaWarp] = LoadSE("./res/Sound/SE/magic-worp1.wav");
	seNum[SE_CastleDamage] = LoadSE("./res/Sound/SE/stone-break1.wav");
	seNum[SE_CastleBreak] = LoadSE("./res/Sound/SE/glass-break4.wav");
	seNum[SE_warning] = LoadSE("./res/Sound/SE/warning1.wav");
	seNum[SE_DarknessStart] = LoadSE("./res/Sound/SE/buun1.wav");
	seNum[SE_DarknessEnd] = LoadSE("./res/Sound/SE/buun1_reverse.wav");
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