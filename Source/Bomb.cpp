#include <DxLib.h>
#include "Bomb.h"
#include "Image.h"

//�R���X�g���N�^
Bomb::Bomb(int _power, float _speed, eBombType _bombType)
	: BaseBomb(_power, _speed, _bombType)
{
	AnimationFlg = false;
};

//���������Ƃ��̏���
void Bomb::DamageMotion()
{
	if (isTrigger == true)		//���j���Ă���
	{
		AnimationFlg = true;
		isTrigger = false;
	}
}

//�X�V
void Bomb::Update(BasePlayer* player)
{
	pType = player->Get_AbilityType();			//�v���C���^�C�v���󂯎��

	isPAbility = player->Get_isAbility();		//���~�߂̔������Ă邩���󂯎��

	//�v���C���[�ɓ��������������
	if (isHit == true)
	{
		isSpawn = false;
		isCount = false;
		isTrigger = false;
		isXplosion = false;
		isActive = false;
	}
	//�v���C���[�ɓ������ĂȂ��Ƃ�
	else
	{
		if (type == bomb)
		{
			SpawnBomb();
		}

		if (isPAbility == false)		//�X�L�����������ĂȂ��Ƃ�
		{
			Move();
		}

		JudgeTrigger();
		SkillStop();
		DamageMotion();

		//�����蔻��
		ClisionHit(x, y, width, height,
			player->Get_x(), player->Get_y(),
			player->Get_width(), player->Get_height());
	}
}

//�`��
void Bomb::Draw()
{
	if (isSpawn == true)			//�����J�n
	{
		DrawGraphF(x, y, Image::Instance()->GetGraph(eImageType::Gpicture_Bomb, 0), TRUE);
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
		Animation();
	}
}

//�A�j���[�V����
void Bomb::Animation()
{
	m_frameIndex++;

	if (bomb_Animation[m_frameIndex] == 0)
	{
		DrawGraphF(x - 20.0f, y - 20.0f, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 0), TRUE);
	}

	if (bomb_Animation[m_frameIndex] == 1)
	{
		DrawGraphF(x - 20.0f, y - 20.0f, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 1), TRUE);
	}

	if (bomb_Animation[m_frameIndex] == 2)
	{
		DrawGraphF(x - 20.0f, y - 20.0f, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 2), TRUE);
	}

	if (bomb_Animation[m_frameIndex] == 3)
	{
		DrawGraphF(x - 20.0f, y - 20.0f, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 3), TRUE);
	}

	if (bomb_Animation[m_frameIndex] == 4)
	{
		DrawGraphF(x - 20.0f, y - 20.0f, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 4), TRUE);
	}

	if (bomb_Animation[m_frameIndex] == 5)
	{
		DrawGraphF(x - 20.0f, y - 20.0f, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 5), TRUE);
	}

	//���j�A�j���[�V�����I��
	if (bomb_Animation[m_frameIndex] == 6)
	{
		AnimationFlg = false;
		isActive = false;
		m_frameIndex--;
	}
}
