#include "Castle.h"
#include "DxLib.h"
#include "Fairy_Speed.h"
//���_�̑ϋv�͂�ݒ�
const int Castle::MAX_DURABILITY = 100;

//�R���X�g���N�^
Castle::Castle(){

	durability = MAX_DURABILITY;
	isActive = true;
	//�e�X�g�p�ɏ������炵�Ă���
	x = 1024 / 2 - 60+80;
	y = 768 / 2 - 60+80;
	width = 120;
	height = 120;
}

//void Castle::Update(Enemy& enemy)const�ɂȂ�\��
//���̓X�s�[�h�^�̓z�Q�Ƃ��ăe�X�g���Ă܂�
void Castle::Update(Fairy_Speed* enemy)
{
	Draw();
	ClisionHit(enemy->Get_X(), enemy->Get_Y(), enemy->Get_Width(), enemy->Get_Height(),enemy->GetPower());
}
//���_�̕`��
void Castle::Draw()
{
	DrawFormatString(10, 100, GetColor(255, 255, 255), "%d", durability);
	if (isActive == false)
	{
		DrawFormatString(10, 130, GetColor(255, 255, 255), "�N�����{���͎��񂾂�");
	}
	else
	{
		DrawFormatString(10, 130, GetColor(255, 255, 255), "�N�����{���͂����Ă�");
	}
	//�v���C���[�̈ړ��͈�
	DrawBox(x-60, y-60, x+width+60, y+height+60, GetColor(25, 25, 25), true);
	//���_�̉摜��ǂݍ���ŕ`�悳���܂����͎l�p��\��
	DrawBox(x, y, x+width, y+height, GetColor(255, 255, 255), true);
}
/*
//ClisionHit���g����Ȃ�K�v�Ȃ��H
//���_�����݂��Ă��邩���肷�鏈��
void Castle::JudgeActive()
{
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
*/

//���_���_���[�W���󂯂��Ƃ��̏���
bool Castle::ClisionHit(float ox, float oy, float ow, float oh,int pow)
{
	DrawFormatString(10, 500, GetColor(255, 255, 255), "%f", ox);
	DrawFormatString(10, 520, GetColor(255, 255, 255), "%f", oy);
	DrawFormatString(10, 540, GetColor(255, 255, 255), "%f", ow);
	DrawFormatString(10, 560, GetColor(255, 255, 255), "%f", oh);
	DrawFormatString(10, 580, GetColor(255, 255, 255), "%d", pow);

	if (x + width >= ox && x <= ox + ow &&
		y + height >= oy && y <= oy + oh)
	{
		//durability -= 10;    //�Ƃ肠�����̋L�q
		durability -= pow;
	}

	if (durability >= 0)
	{
		isActive = true;
	}
	else
	{
		isActive = false;
	}

	return isActive;
}