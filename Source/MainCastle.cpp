#include "MainCastle.h"
#include "DxLib.h"
#include"EnemyManager.h"

//�R���X�g���N�^
MainCastle::MainCastle(int _durability)
	:BaseCastle(_durability) {

	durability = _durability;
	width = 120;
	height = 120;
	x = GAME_WIDTH / 2 - width / 2;       //452
	y = GAME_HEIHGT / 2 - height / 2;     //324

}

void MainCastle::Update(EnemyManager* enemy)
{
	for (int num = 0; num < enemy->Get_enemyNum(); num++)
	{
		if (enemy->Get_ActiveFlg(num) == true)
		{
			ClisionHit(enemy->Get_x(num), enemy->Get_y(num), enemy->Get_width(num),
				       enemy->Get_height(num), enemy->Get_Power(num),num,
				       enemy->Get_AttackFlg(num),enemy->Get_ActiveFlg(num));
		}

		if (isHit == true)
		{
			enemy->Set_IsAttack(num, false);
			enemy->Set_IsActive(num, false);
		}
	}
}

//���_�̕`��
void MainCastle::Draw()
{
	//�v���C���[�̈ړ��͈�(����UI�̕��������̂ł�)
	DrawBox(x - 60.0f, y - 60.0f, x + width + 60.0f, y + height + 60.0f, GetColor(25, 25, 25), true);

	if (isActive == true)
	{
		//���_�̉摜��ǂݍ���ŕ`�悳���܂����͎l�p��\��
		DrawBox(x, y, x + width, y + height, GetColor(255, 255, 255), true);
	}
}