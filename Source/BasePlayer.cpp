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

	isMove = 4;          //������4
	isMoveKey = false;
	isOps = false;
	isOps_RUN = false;
	isOps_UP = false;
	isOps_DOWN = false;
	isOps_LEFT = false;
	isOps_RIGHT = false;
	isDamage = false;

	//�v���C���[�̏������W
	x = PLAYER_SPOWNPOSX;
	y = PLAYER_SPOWNPOSY;

	//�e�X�g�p
	x2 = 440;
	y2 = 396;
	//�e�X�g�p�̃J���[
	Color = GetColor(255, 0, 0);

}

//�v���C���[�̈ړ�����
void BasePlayer::Move()
{
	//���L�[���������Ƃ�
	if ((Input::Instance()->GetPressCount(KEY_INPUT_LEFT) == 1)) {

		if (PlayerPos == 2) {
			isOps = true;
			isOps_RIGHT = true;
		}
		else {
			//�ړ����������ɂ���
			isMove = 0;
			//�L�[���͂̑���ł��邱�Ƃ̃t���O��on
			isMoveKey = true;
		}
	}
	//���L�[���������Ƃ�
	if ((Input::Instance()->GetPressCount(KEY_INPUT_UP) == 1)) {

		if (PlayerPos == 3) {
			isOps = true;
			isOps_DOWN = true;
		}
		else {
			//�ړ���������ɂ���
			isMove = 1;
			//�L�[���͂̑���ł��邱�Ƃ̃t���O��on
			isMoveKey = true;
		}
	}
	//���L�[���������Ƃ�
	if ((Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) == 1)) {

		if (PlayerPos == 0) {
			isOps = true;
			isOps_LEFT = true;
		}
		else {
			//�ړ��������E�ɂ���
			isMove = 2;
			//�L�[���͂̑���ł��邱�Ƃ̃t���O��on
			isMoveKey = true;
		}

	}
	//���L�[���������Ƃ�
	if ((Input::Instance()->GetPressCount(KEY_INPUT_DOWN) == 1)) {

		if (PlayerPos == 1) {
			isOps = true;
			isOps_UP = true;
		}
		else {
			//�ړ����������ɂ���
			isMove = 3;
			//�L�[���͂̑���ł��邱�Ƃ̃t���O��on
			isMoveKey = true;
		}
	}
	//�ړ����������̎��A���ֈړ�������
	if (isMove == 0 && isMoveKey == true) {
		Move_LEFT();
	}
	//�ړ���������̎��A��ֈړ�������
	if (isMove == 1 && isMoveKey == true) {
		Move_UP();
	}
	//�ړ��������E�̎��A�E�ֈړ�������
	if (isMove == 2 && isMoveKey == true) {
		Move_RIGHT();
	}
	//�ړ����������̎��A���ֈړ�������
	if (isMove == 3 && isMoveKey == true) {
		Move_DOWN();
	}
	//���΃t���O��true�̎��A���Έړ��������N��������
	if (isOps == true) {
		Move_OPS();
	}
	//���Έړ����������s
	if (isOps_RUN == true) {
		Move_OPSRUN();
	}
}
void BasePlayer::Move_UP()
{
	//��������
	if (PlayerPos == 0 && isMove == 1) {
		if (y >= 264) {

			y -= speed;
			y2 -= speed;
		}
		if (y <= 264 && x <= 486) {

			x += speed;
			x2 += speed;
		}
		if (x >= 486 && y <= 264) {

			//�v���C���[�̏ꏊ����ɂ���
			PlayerPos = 1;

			//�ړ����������Z�b�g����
			isMove = 4;

			//�ړ��L�[�̃`�F�b�N�����Z�b�g
			//isMoveKey = false;
		}
		if (isOps == true && isOps_DOWN == true && x >= 485 && y <= 264) {
			isOps = false;
			isOps_DOWN = false;
			isOps_RUN = false;
		}
	}
	//�E������
	if (PlayerPos == 2 && isMove == 1) {
		if (y >= 264) {

			y -= speed;
			y2 -= speed;
		}
		if (y <= 264 && x >= 486) {

			x -= speed;
			x2 -= speed;
		}
		if (y <= 264 && x <= 486) {

			//�v���C���[�̏ꏊ����ɂ���
			PlayerPos = 1;

			//�ړ����������Z�b�g����
			isMove = 4;

			//�ړ��L�[�̃`�F�b�N�����Z�b�g
			isMoveKey = false;
		}
	}
}
//���ֈړ����鏈��
void BasePlayer::Move_DOWN()
{
	//�����牺��
	if (PlayerPos == 0 && isMove == 3) {
		if (y <= 456) {

			y += speed;
			y2 += speed;
		}
		if (y >= 456 && x <= 486) {

			x += speed;
			x2 += speed;
		}
		if (x >= 486) {

			//�v���C���[�̏ꏊ�����ɂ���
			PlayerPos = 3;

			//�ړ����������Z�b�g����
			isMove = 4;

			//�ړ��L�[�̃`�F�b�N�����Z�b�g
			isMoveKey = false;
		}
	}

	//�E���牺��
	if (PlayerPos == 2 && isMove == 3) {
		if (y <= 456) {

			y += speed;
			y2 += speed;
		}
		if (y >= 456 && x >= 486) {

			x -= speed;
			x2 -= speed;
		}
		if (x <= 486) {

			//�v���C���[�̏ꏊ�����ɂ���
			PlayerPos = 3;

			//�ړ����������Z�b�g����
			isMove = 4;

			//�ړ��L�[�̃`�F�b�N�����Z�b�g
			isMoveKey = false;
		}
		if (isOps == true && isOps_UP == true && x <= 486 && y >= 456) {
			isOps = false;
			isOps_UP = false;
			isOps_RUN = false;
		}

	}
}
//���ֈړ����鏈��
void BasePlayer::Move_LEFT()
{
	//�ォ�獶��
	if (PlayerPos == 1 && isMove == 0) {
		if (x >= 392) {

			x -= speed;
			x2 -= speed;
		}
		if (x <= 392 && y <= 348) {

			y += speed;
			y2 += speed;
		}
		if (y >= 345) {

			//�v���C���[�̏ꏊ�����ɂ���
			PlayerPos = 0;

			//�ړ����������Z�b�g����
			isMove = 4;

			//�ړ��L�[�̃`�F�b�N�����Z�b�g
			isMoveKey = false;
		}
		if (isOps == true && x <= 392 && y >= 345) {
			isOps = false;
			isOps_RIGHT = false;
			isOps_RUN = false;
		}
	}
	//�����獶��
	if (PlayerPos == 3 && isMove == 0) {
		if (x >= 392) {

			x -= speed;
			x2 -= speed;
		}
		if (x <= 392 && y >= 348) {

			y -= speed;
			y2 -= speed;
		}
		if (y <= 345) {

			//�v���C���[�̏ꏊ�����ɂ���
			PlayerPos = 0;

			//�ړ����������Z�b�g����
			isMove = 4;
		}
		if (isOps == true && isOps_RIGHT == true && x <= 392 && y <= 345) {
			isOps = false;
			isOps_RIGHT = false;
			isOps_RUN = false;
		}
	}
}
//�E�ֈړ����鏈��
void BasePlayer::Move_RIGHT()
{
	//�ォ��E��
	if (PlayerPos == 1 && isMove == 2) {
		if (x <= 584) {

			x += speed;
			x2 += speed;
		}
		if (x >= 584 && y <= 348) {

			y += speed;
			y2 += speed;
		}
		if (y >= 345) {

			//�v���C���[�̏ꏊ���E�ɂ���
			PlayerPos = 2;

			//�ړ����������Z�b�g����
			isMove = 4;

			//�ړ��L�[�̃`�F�b�N�����Z�b�g
			isMoveKey = false;
		}
		if (isOps == true && isOps_LEFT == true && x >= 584 && y >= 345) {
			isOps = false;
			isOps_LEFT = false;
			isOps_RUN = false;
		}
	}
	//������E��
	if (PlayerPos == 3 && isMove == 2) {
		if (x <= 584) {

			x += speed;
			x2 += speed;
		}
		if (x >= 584 && y >= 348) {

			y -= speed;
			y2 -= speed;
		}
		if (y <= 345) {

			//�v���C���[�̏ꏊ���E�ɂ���
			PlayerPos = 2;

			//�ړ����������Z�b�g����
			isMove = 4;

			//�ړ��L�[�̃`�F�b�N�����Z�b�g
			isMoveKey = false;
		}
	}
}

//���΂ֈړ����鏈��
void BasePlayer::Move_OPS()
{

	//������E�ֈړ�
	if (PlayerPos == 0 && isOps_LEFT == true) {

		isOps_RUN = true;
	}
	//�E���獶�ֈړ�
	if (PlayerPos == 2 && isOps_RIGHT == true) {

		isOps_RUN = true;
	}
	//�ォ�牺�ֈړ�
	if (PlayerPos == 1 && isOps_UP == true) {

		isOps_RUN = true;
	}
	//�������ֈړ�
	if (PlayerPos == 3 && isOps_DOWN == true) {

		isOps_RUN = true;
	}
}
//���Έړ�����:����
void BasePlayer::Move_OPSRUN()
{
	//�ォ�牺�ֈړ����鏈��
	if (isOps_RUN == true && isOps_UP == true)
	{
		isMove = 2;
		Move_RIGHT();
		isMove = 3;
		Move_DOWN();

	}
	//�������ֈړ����鏈��
	if (isOps_RUN == true && isOps_DOWN == true)
	{
		isMove = 0;
		Move_LEFT();
		isMove = 1;
		Move_UP();

	}
	//������E�ֈړ����鏈��
	if (isOps_RUN == true && isOps_LEFT == true)
	{
		isMove = 1;
		Move_UP();
		isMove = 2;
		Move_RIGHT();

	}
	//�E���獶�ֈړ����鏈��
	if (isOps_RUN == true && isOps_RIGHT == true)
	{
		isMove = 3;
		Move_DOWN();
		isMove = 0;
		Move_LEFT();

	}

}
//�v���C���[�̍U������
void BasePlayer::Attack()
{


}


bool BasePlayer::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh)
{
	if (mx < (ox + 100) && my < (oy + 100) &&
		ox < (mx + 48) && oy < (my + 48))
	{
		return DrawFormatString(0, 100, GetColor(255, 0, 0), "���˂̉Y��");
	}
	else
	{
		return 1;
	}
}


//�v���C���[�̕`�揈��
void BasePlayer::Draw()
{
	//�e�X�g�p�̕`��

	//���̈ʒu
	DrawBox(x, y, x2, y2, Color, TRUE);

	DrawFormatString(0, 0, GetColor(255, 255, 255), "%f %f %f %f", x, x2, y, y2);
	DrawFormatString(0, 25, GetColor(255, 255, 255), "isMove:%d  PlayerPos:%d", isMove, PlayerPos);

}

//�v���C���[�̍X�V����
void BasePlayer::Update()
{


}

//�v���C���[�̏����܂Ƃ�
void BasePlayer::All()
{

	//***�e�X�g�p***//
	float xx = 500;
	float yy = 400;

	float xx2 = 600;
	float yy2 = 500;
	//**************//

	//***�e�X�g�Ɏg���Ă����***
	/***�v���C���[�̈ړ��͈�***
	DrawBox(632, 504, 392, 264, GetColor(255, 255, 0), TRUE);
	//���_
	DrawBox(482, 342, 542, 402, GetColor(255, 0, 0), TRUE);
	//�G
	DrawBox(xx, yy, xx2, yy2, GetColor(100, 100, 100), TRUE);
	****************************/

	Draw();
	Move();
	ClisionHit(x, y, x2, y2, xx, yy, xx2, yy2);
}