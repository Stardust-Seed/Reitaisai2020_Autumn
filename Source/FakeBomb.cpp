#include <DxLib.h>
#include "FakeBomb.h"
#include "Image.h"

//�R���X�g���N�^
FakeBomb::FakeBomb(int _power, float _speed, eBombType _bombType)
	: BaseBomb(_power, _speed, _bombType)
{
	isFakeAction = false;
	AnimationFlg = false;
};

//�U���������Ƃ��̏���
void FakeBomb::FakeMotion()
{
	//�U���e���N��
	if (isTrigger == true)
	{
		isFakeAction = true;
		if (isFakeAction == true)
		{
			isTrigger = false;
			AnimationFlg = true;
		}
	}
}

//�X�V
void FakeBomb::Update(BasePlayer* player)
{
	pType = player->Get_AbilityType();		//�v���C���^�C�v���󂯎��

	isPAbility = player->Get_isAbility();	//���~�߂̔������Ă邩���󂯎��

	if (isHit == true)						//�v���C���[�Ɠ���������
	{
		isSpawn = false;
		isCount = false;
		isTrigger = false;
		isXplosion = false;
		isActive = false;
	}
	else
	{
		if (type == fakebomb)
		{
			SpawnBomb();
		}

		if (isPAbility == false)		//��邳��̃X�L�����������ĂȂ������瓮��
		{
			Move();
		}

		JudgeTrigger();
		SkillStop();
		FakeMotion();

		//�����蔻��
		ClisionHit(x, y, width, height,
			player->Get_x(), player->Get_y(),
			player->Get_width(), player->Get_height());
	}
}

//�`��
void FakeBomb::Draw()
{

	if (isSpawn == true)			//�����J�n
	{
		DrawGraphF(x, y, Image::Instance()->GetGraph(eImageType::Gpicture_Bomb, 1), TRUE);
	}

	if (isCount == true)			//�ʏ�J�E���g
	{
		JudgeTrigger();
	}

	if (isStopCount == true)		//���~�߃J�E���g
	{
		SkillStop();
	}

	if (AnimationFlg == true)		//�A�j���[�V�����J�n
	{
		isFakeAction = false;
		Animation();
	}
}

//�A�j���[�V����
void FakeBomb::Animation()
{
	m_frameIndex++;

	if (fake_Animation[m_frameIndex] == 0)
	{
		DrawGraphF(x, y, Image::Instance()->GetGraph(eImageType::Gpicture_FakeBomb, 0), TRUE);
	}

	if (fake_Animation[m_frameIndex] == 1)
	{
		DrawGraphF(x, y - 10.0f, Image::Instance()->GetGraph(eImageType::Gpicture_FakeBomb, 1), TRUE);
	}
	if (fake_Animation[m_frameIndex] == 2)
	{
		DrawGraphF(x, y - 30.0f, Image::Instance()->GetGraph(eImageType::Gpicture_FakeBomb, 2), TRUE);
	}

	//�A�j���[�V�����I��
	if (fake_Animation[m_frameIndex] == 3)
	{
		AnimationFlg = false;
		isActive = false;
		m_frameIndex--;
	}
}