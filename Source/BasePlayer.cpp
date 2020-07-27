#include"DxLib.h"
#include"BasePlayer.h"
#include"Object.h"
#include"Input.h"

BasePlayer::BasePlayer()
{
	speed = 3;
	power = 0;
	stanTime = 0;
	attackTime = 0;

	PlayerPos = 0;                  
	// 0 = ��         1 = ��        2 = �E         3 = ��

	isMove = 4;
	// 0 = ���ֈړ�   1 =��ֈړ�   2 = �E�ֈړ�   3 = ���ֈړ�   4 = �Ȃ�

	isDamage = false;

	//�v���C���[�̏������W
	x = PLAYER_SPOWNPOSX;
	y = PLAYER_SPOWNPOSY;

	//�e�X�g�p
	x2 = 348;
	y2 = 396;
	//�e�X�g�p�̃J���[
	Color = GetColor(255, 0, 0);

}

//�v���C���[�̈ړ�����
void BasePlayer::Move()
{
	//���L�[���������Ƃ�
	if ((Input::Instance()->GetPressCount(KEY_INPUT_LEFT) == 1)) {

		isMove = 0;
	}
	//���L�[���������Ƃ�
	if ((Input::Instance()->GetPressCount(KEY_INPUT_UP) == 1)) {

		isMove = 1;
	}
	//���L�[���������Ƃ�
	if ((Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) == 1)) {

		isMove = 2;
	}
	//���L�[���������Ƃ�
	if ((Input::Instance()->GetPressCount(KEY_INPUT_DOWN) == 1)) {

		isMove = 3;
	}
	//�ړ����������̎��A���ֈړ�������
	if (isMove == 0) {
		Move_LEFT();
	}
	//�ړ���������̎��A��ֈړ�������
	if (isMove == 1) {
		Move_UP();
	}
	//�ړ��������E�̎��A�E�ֈړ�������
	if (isMove == 2) {
		Move_RIGHT();
	}
	//�ړ����������̎��A���ֈړ�������
	if (isMove == 3) {
		Move_DOWN();
	}
}
void BasePlayer::Move_UP()
{
	//��������
	if (PlayerPos == 0 && isMove == 1) {
		if (y >= 180) {

			y -= speed;
			y2 -= speed;
		}
		if (y <= 180 && x <= 486) {

			x += speed;
			x2 += speed;
		}
		if (x >= 486 && y <= 180) {

			//�v���C���[�̏ꏊ����ɂ���
			PlayerPos = 1;

			//�ړ����������Z�b�g����
			isMove = 4;
		}
	}
	//�E������
	if (PlayerPos == 2 && isMove == 1) {
		if (y >= 180) {

			y -= speed;
			y2 -= speed;
		}
		if (y <= 180 && x >= 486) {

			x -= speed;
			x2 -= speed;
		}
		if (y <= 180 && x <= 486) {

			//�v���C���[�̏ꏊ����ɂ���
			PlayerPos = 1;

			//�ړ����������Z�b�g����
			isMove = 4;
		}
	}
}
//���ֈړ����鏈��
void BasePlayer::Move_DOWN()
{
	//�����牺��
	if (PlayerPos == 0 && isMove == 3) {
		if (y <= 548) {

			y += speed;
			y2 += speed;
		}
		if (y >= 548 && x <= 486) {

			x += speed;
			x2 += speed;
		}
		if (x >= 486) {

			//�v���C���[�̏ꏊ�����ɂ���
			PlayerPos = 3;

			//�ړ����������Z�b�g����
			isMove = 4;
		}
	}
	//�E���牺��
	if (PlayerPos == 2 && isMove == 3) {
		if (y <= 548) {

			y += speed;
			y2 += speed;
		}
		if (y >= 548 && x >= 486) {

			x -= speed;
			x2 -= speed;
		}
		if (x <= 486) {

			//�v���C���[�̏ꏊ�����ɂ���
			PlayerPos = 3;

			//�ړ����������Z�b�g����
			isMove = 4;
		}
	}
}
//���ֈړ����鏈��
void BasePlayer::Move_LEFT()
{
	//�ォ�獶��
	if (PlayerPos == 1 && isMove == 0) {
		if (x >= 300) {

			x -= speed;
			x2 -= speed;
		}
		if (x <= 300 && y <= 348) {

			y += speed;
			y2 += speed;
		}
		if (y >= 345) {

			//�v���C���[�̏ꏊ�����ɂ���
			PlayerPos = 0;

			//�ړ����������Z�b�g����
			isMove = 4;
		}
	}
	//�����獶��
	if (PlayerPos == 3 && isMove == 0) {
		if (x >= 300) {

			x -= speed;
			x2 -= speed;
		}
		if (x <= 300 && y >= 348) {

			y -= speed;
			y2 -= speed;
		}
		if (y <= 345) {

			//�v���C���[�̏ꏊ�����ɂ���
			PlayerPos = 0;

			//�ړ����������Z�b�g����
			isMove = 4;
		}
	}
}
//�E�ֈړ����鏈��
void BasePlayer::Move_RIGHT()
{
	//�ォ��E��
	if (PlayerPos == 1 && isMove == 2) {
		if (x <= 676) {

			x += speed;
			x2 += speed;
		}
		if (x >= 676 && y <= 348) {

			y += speed;
			y2 += speed;
		}
		if (y >= 345) {

			//�v���C���[�̏ꏊ���E�ɂ���
			PlayerPos = 2;

			//�ړ����������Z�b�g����
			isMove = 4;
		}
	}
	//������E��
	if (PlayerPos == 3 && isMove == 2) {
		if (x <= 676) {

			x += speed;
			x2 += speed;
		}
		if (x >= 676 && y >= 348) {

			y -= speed;
			y2 -= speed;
		}
		if (y <= 345) {

			//�v���C���[�̏ꏊ���E�ɂ���
			PlayerPos = 2;

			//�ړ����������Z�b�g����
			isMove = 4;
		}
	}

}

//�v���C���[�̍U������
void BasePlayer::Attack()
{


}


bool BasePlayer::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh)
{

	return 1;
}


//�v���C���[�̕`�揈��
void BasePlayer::Draw()
{
	//�e�X�g�p�̕`��
	DrawBox(x, y, x2,y2, Color, TRUE);

}

//�v���C���[�̍X�V����
void BasePlayer::Update()
{


}

//�v���C���[�̏����܂Ƃ�
void BasePlayer::All()
{
	Draw();
	Move();
	
}