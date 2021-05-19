#include "DxLib.h"
#include "SubCastle.h"
#include "EnemyManager.h"

//�R���X�g���N�^
SubCastle::SubCastle(int _durability,int _type,int _num)
	:BaseCastle(_durability) {

	durability = _durability;

	width = 48;
	height = 48;
	addPosX = 0;
	addPosY = 0;
	addSize = 8;

	cnt = 0;
	bwidth = 25;
	bheight = 25;
	alpha = 255;

	bflg = false;
	discoveryFlg = false;

	//���W�ݒ�
	switch (_num)
	{
	case 1:    //�㍶��

		//���W�ݒ�
		x = COORDINATE_X_ONE;
		y = COORDINATE_Y_ONE;

		addPosX = -48;
		addPosY = -80;

		//�T�u���_�̕\���ꏊ�̍��W�ݒ�
		drawPosX = x + addPosX - addSize / 2;
		drawPosY = y + addPosY - addSize / 2;

		//��̂��ꂽ���̓G�̐������W�ݒ�
		popPosX = drawPosX;
		popPosY = (GAME_HEIHGT / 2) - (48 / 2);

		//�e�̐i�s�����̐ݒ�
		directionMove = 3;

		direction = eDirection::Left;
		break;
	case 2:    //������

        //���W�ݒ�
		x = COORDINATE_X_TWO;
		y = COORDINATE_Y_TWO;

		addPosX = -48;
		addPosY = 32;

		//�T�u���_�̕\���ꏊ�̍��W�ݒ�
		drawPosX = x + addPosX - addSize / 2;
		drawPosY = y + addPosY - addSize / 2;

		//��̂��ꂽ���̓G�̐������W�ݒ�
		popPosX = drawPosX;
		popPosY = (GAME_HEIHGT / 2) - (48 / 2);

		//�e�̐i�s�����̐ݒ�
		directionMove = 4;

		direction = eDirection::Left;
		break;

	case 3:    //��E��

		//���W�ݒ�
		x = COORDINATE_X_THREE;
		y = COORDINATE_Y_THREE;

		addPosX = 32;
		addPosY = -48;

		//�T�u���_�̕\���ꏊ�̍��W�ݒ�
		drawPosX = x + addPosX - addSize / 2;
		drawPosY = y + addPosY - addSize / 2;

		//��̂��ꂽ���̓G�̐������W�ݒ�
		popPosX = (GAME_WIDTH / 2) - (48 / 2);
		popPosY = drawPosY;

		//�e�̐i�s�����̐ݒ�
		directionMove = 4;

		direction = eDirection::Up;
		break;

	case 4:    //�㍶��

		//���W�ݒ�
		x = COORDINATE_X_FOUR;
		y = COORDINATE_Y_FOUR;

		addPosX = -80;
		addPosY = -48;

		//�T�u���_�̕\���ꏊ�̍��W�ݒ�
		drawPosX = x + addPosX - addSize / 2;
		drawPosY = y + addPosY - addSize / 2;

		//��̂��ꂽ���̓G�̐������W�ݒ�
		popPosX = (GAME_WIDTH / 2) - (48 / 2);
		popPosY = drawPosY;

		//�e�̐i�s�����̐ݒ�
		directionMove = 2;

		direction = eDirection::Up;
		break;

	case 5:    //�㍶��

		//���W�ݒ�
		x = COORDINATE_X_FIVE;
		y = COORDINATE_Y_FIVE;

		addPosX = 48;
		addPosY = 32;

		//�T�u���_�̕\���ꏊ�̍��W�ݒ�
		drawPosX = x + addPosX - addSize / 2;
		drawPosY = y + addPosY - addSize / 2;

		//��̂��ꂽ���̓G�̐������W�ݒ�
		popPosX = drawPosX;
		popPosY = (GAME_HEIHGT / 2) - (48 / 2);

		//�e�̐i�s�����̐ݒ�
		directionMove = 2;

		direction = eDirection::Right;
		break;
		
	case 6:    //������

        //���W�ݒ�
		x = COORDINATE_X_SIX;
		y = COORDINATE_Y_SIX;

		addPosX = 48;
		addPosY = -80;

		//�T�u���_�̕\���ꏊ�̍��W�ݒ�
		drawPosX = x + addPosX - addSize / 2;
		drawPosY = y + addPosY - addSize / 2;

		//��̂��ꂽ���̓G�̐������W�ݒ�
		popPosX = drawPosX;
		popPosY = (GAME_HEIHGT / 2) - (48 / 2);

		//�e�̐i�s�����̐ݒ�
		directionMove = 1;

		direction = eDirection::Right;
		break;
	case 7:    //������

        //���W�ݒ�
		x = COORDINATE_X_SEVEN;
		y = COORDINATE_Y_SEVEN;

		addPosX = -80;
		addPosY = 48;

		//�T�u���_�̕\���ꏊ�̍��W�ݒ�
		drawPosX = x + addPosX - addSize / 2;
		drawPosY = y + addPosY - addSize / 2;

		//��̂��ꂽ���̓G�̐������W�ݒ�
		popPosX = (GAME_WIDTH / 2) - (48 / 2);
		popPosY = drawPosY;

		//�e�̐i�s�����̐ݒ�
		directionMove = 1;

		direction = eDirection::Down;
		break;
	case 8:    //���E��

        //���W�ݒ�
		x = COORDINATE_X_EIGHT;
		y = COORDINATE_Y_EIGHT;

		addPosX = 32;
		addPosY = 48;

		//�T�u���_�̕\���ꏊ�̍��W�ݒ�
		drawPosX = x + addPosX - addSize / 2;
		drawPosY = y + addPosY - addSize / 2;

		//��̂��ꂽ���̓G�̐������W�ݒ�
		popPosX = (GAME_WIDTH / 2) - (48 / 2);
		popPosY = drawPosY;

		//�e�̐i�s�����̐ݒ�
		directionMove = 3;

		direction = eDirection::Down;
		break;
	default:
		break;
	}

	//�T�u���_�̕\���ꏊ�̍��W�ݒ�
	drawPosX = x + addPosX - addSize / 2;
	drawPosY = y + addPosY - addSize / 2;
}

void SubCastle::Update(EnemyManager* enemy)
{
	//�z�u�ꏊ�ɂ���Đi��ł������������߂�
	switch (directionMove)
	{
	//�E������
	case 1:
		bx++;
		by++;
		break;
	//�E�����
	case 2:
		bx++;
		by--;
		break;
	//��������
	case 3:
		bx--;
		by++;
		break;
	//�������
	case 4:
		bx--;
		by--;
		break;
	default:
		break;
	}

	//�����t�F�[�h�A�E�g
	if (bx > drawPosX + 100 ||
		bx < drawPosX - 100 ||
		by > drawPosY + 100 ||
		by < drawPosY - 100   )
	{
		alpha -= 5;
	}

	//��񂾂���������p�̃t���O����
	if (isHit == true)
	{
		isHit = false;
	}

	//�ϋv�̏���
	if (durability <= 0)
	{
		isActive = false;
	}

	//�G�𔭌�������
	if (discoveryFlg)
	{
		cnt++;
	}

	//�t�F�[�h�A�E�g�������x�����t���O���I�t�ɂ���
	if (alpha <= 0)
	{
		discoveryFlg = false;
	}

	//�����ĂȂ��Ȃ炱�̐�̏����͂��Ȃ�
	if (isActive == false)return;

	//�����蔻��
	for (int num = 0; num < enemy->Get_enemyNum(); num++)
	{
		//�T�u���_�ƓG�̓����蔻��
		if (enemy->Get_ActiveFlg(num) == true && enemy->Get_AttackFlg(num) == true &&
			enemy->Get_AttackType(num) != eAttackType::Player)
		{
			ClisionHit(enemy->Get_x(num), enemy->Get_y(num), enemy->Get_width(num),
				enemy->Get_height(num), enemy->Get_Power(num), num,
				enemy->Get_AttackFlg(num), enemy->Get_ActiveFlg(num));
		}

		//���������̍��G�͈͂ɓG�𔭌�������
		if (x - enemy->Get_x(num) >= -250 && x - enemy->Get_x(num) <= 250 &&
			y - enemy->Get_y(num) >= -250 && y - enemy->Get_y(num) <= 250 &&
			direction == enemy->Get_direction(num))
		{
			discoveryFlg = true;
		}

		//�J�E���g������e����
		if (cnt > 70)
		{
			bflg = true;
			cnt = 0;
			alpha = 255;
			bx = drawPosX + width / 2;
			by = drawPosY + height / 2;
			discoveryFlg = false;
		}

		//�e�ƓG�̓����蔻��
		if (bflg == true && ClisionHit(bx, by, bheight, bwidth, enemy->Get_x(num), enemy->Get_y(num), enemy->Get_width(num),
			enemy->Get_height(num)) == true)
		{
			enemy->DamageSend(num, 25);
			bflg = false;
			discoveryFlg = false;
			bx = drawPosX + width / 2;
			by = drawPosY + height / 2;
		}
	}
}

void SubCastle::Draw()
{
	//�K���ɕ\��
	if (isActive == true)
	{
		DrawGraphF(drawPosX,drawPosY,Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 0), TRUE);
	}
	else
	{
		DrawGraphF(drawPosX, drawPosY, Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 1), TRUE);
	}

	//�e�\��
	if (bflg==true)
	{
		//�u�����h���[�h����Z�ς݃��p�̃��u�����h�ɂ���
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);

		//�e�\��
		DrawGraphF(bx,  by, Image::Instance()->GetGraph(eImageType::Gpicture_Bullet, 1), TRUE);

		//�u�����h���[�h��ʏ�ɖ߂�
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, alpha);

		//�ʏ�t�F�[�h�A�E�g
		if (cnt > 50)
		{
			alpha -= 5;
		}
	}
}