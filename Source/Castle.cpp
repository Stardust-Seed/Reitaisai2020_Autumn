#include "Castle.h"
#include "DxLib.h"

//���_�̑ϋv�͂�ݒ�
const int Castle::MAX_DURABILITY = 100;

//�R���X�g���N�^
Castle::Castle(){

	durability = MAX_DURABILITY;
	isActive = true;

}
//void Castle::Update(Enemy& enemy)const�ɂȂ�\��
void Castle::Update()
{
	Draw();
	JudgeActive();
	HitDamage();
	//��X����Ȋ����̋L�q�ɂȂ�H
	//ClisionHit(x,y,width,height, enemy.x, enemy.y, enemy.width, enemy.height);
}
//���_�̕`��
void Castle::Draw()
{
	//���_�̉摜��ǂݍ���ŕ`�悳���܂����͎l�p��\��
	DrawBox(1024/2-120, 768/2-120, 1024/2+120, 768/2+120, GetColor(255, 255, 255), true);
}

//ClisionHit���g����Ȃ�K�v�Ȃ��H
//���_�����݂��Ă��邩���肷�鏈��
void Castle::JudgeActive()
{
	DrawFormatString(10, 100, GetColor(255, 255, 255), "%d",durability);
	if (durability <= 0)
	{
		isActive = false;
	}
	else
	{
		isActive = true;
	}
}

//ClisionHit���g����Ȃ�K�v�Ȃ��H
//���_���_���[�W���󂯂��Ƃ��̏���
void Castle::HitDamage()
{
	durability -= 1;
	//�G�l�~�[���҂��Ȃ̂ŉ��̏���
	//Durability -= Enemy->GetPower();
}

//���_���_���[�W���󂯂��Ƃ��̏���
bool Castle::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh)
{
	if (mx + mw >= ox && mx <= ox + ow &&
		my + mh >= oy && my <= oy + oh)
	{
		durability -= 10;    //�Ƃ肠�����̋L�q
		//Durability -= Enemy.GetPower();
	}

	if (durability <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}