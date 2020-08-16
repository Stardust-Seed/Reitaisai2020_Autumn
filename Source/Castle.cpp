#include "DxLib.h"
#include "Castle.h"
#include "EnemyManager.h"

//���_�̑ϋv�͂�ݒ�
const int Castle::MAX_DURABILITY = 100;

//�R���X�g���N�^
Castle::Castle(){

	durability = MAX_DURABILITY;
	isActive = true;

	width = 120;
	height = 120;
	x = GAME_WIDTH  / 2 - width  / 2;
	y = GAME_HEIHGT / 2 - height / 2;

}


void Castle::Update(EnemyManager* enemy)
{
	for (int num = 0; num < enemy->Get_ActiveCount(); num++)
	{
		ClisionHit(enemy->Get_x(num), enemy->Get_y(num), enemy->Get_width(num), enemy->Get_height(num), enemy->Get_Power(num));
	}
}

//���_�̕`��
void Castle::Draw()
{
	/*
	DrawFormatString(10, 100, GetColor(255, 255, 255), "%d", durability);
	if (isActive == false)
	{
		DrawFormatString(10, 130, GetColor(255, 255, 255), "�N�����{���͎��񂾂�");
	}
	else
	{
		DrawFormatString(10, 130, GetColor(255, 255, 255), "�N�����{���͂����Ă�");
	}
	*/
	//�v���C���[�̈ړ��͈�
	DrawBox(x-60.0f, y-60.0f, x+width+60.0f, y+height+60.0f, GetColor(25, 25, 25), true);
	//���_�̉摜��ǂݍ���ŕ`�悳���܂����͎l�p��\��
	DrawBox(x, y, x+width, y+height, GetColor(255, 255, 255), true);
}

//���_���_���[�W���󂯂��Ƃ��̏���
bool Castle::ClisionHit(float ox, float oy, float ow, float oh,int pow)
{
	//DrawFormatString(10, 500, GetColor(255, 255, 255), "%f", ox);
	//DrawFormatString(10, 520, GetColor(255, 255, 255), "%f", oy);
	//DrawFormatString(10, 540, GetColor(255, 255, 255), "%f", ow);
	//DrawFormatString(10, 560, GetColor(255, 255, 255), "%f", oh);
	//DrawFormatString(10, 580, GetColor(255, 255, 255), "%d", pow);
	//�\�[�V�����f�B�X�^���X��ۂĂȂ�����Y��������
	//������Y�̍U���͕��A������HP�����炷���Ƃ��o����I
	if (x + width >= ox && x <= ox + ow &&
		y + height >= oy && y <= oy + oh)
	{
		durability -= pow;
	}

	//������ł��܂����̏���
	if (durability > 0)
	{
		isActive = true;
	}
	else
	{
		isActive = false;
	}

	return isActive;
}