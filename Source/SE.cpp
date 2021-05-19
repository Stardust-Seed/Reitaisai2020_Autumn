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
	seNum[SE_SakuyaAttack] = LoadSE("./res/Sound/SE/sakuya.wav");
	seNum[SE_SakuyaAbility] = LoadSE("./res/Sound/SE/sakuya_ab.wav");
	seNum[SE_FranAttack] = LoadSE("./res/Sound/SE/fran.wav");
	seNum[SE_FranAbility] = LoadSE("./res/Sound/SE/furan_ab.wav");
	seNum[SE_ItemGet] = LoadSE("./res/Sound/SE/pa1.wav");
	seNum[SE_EnemyAttack] = LoadSE("./res/Sound/SE/punch-middle2.wav");
	seNum[SE_EnemyDown] = LoadSE("./res/Sound/SE/down1.wav");
	seNum[SE_EventAlarm] = LoadSE("./res/Sound/SE/afa7ca1aa9e16917.wav");
	seNum[SE_LevelUP] = LoadSE("./res/Sound/SE/magic-charge1.wav");
	seNum[SE_Cancel] = LoadSE("./res/Sound/SE/cancel2.wav");
	seNum[SE_Enter] = LoadSE("./res/Sound/SE/decision48.wav");
	seNum[SE_Stan] = LoadSE("./res/Sound/SE/piyopiyo.wav");
	seNum[SE_Fake] = LoadSE("./res/Sound/SE/train-steam1.wav");
	seNum[SE_Skil] = LoadSE("./res/Sound/SE/skil.wav");
	seNum[SE_Hart] = LoadSE("./res/Sound/SE/sinzou.wav");
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