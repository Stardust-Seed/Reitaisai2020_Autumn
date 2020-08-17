#include"DxLib.h"
#include"Input.h"
#include"BasePlayer.h"
#include"BaseEnemy.h"
#include"BulletManager.h"
#include"EnemyManager.h"

BasePlayer::BasePlayer()
{

	pos = VGet(PLAYER_LEFTPOS, PLAYER_LEFTRIGHTPOS, 0);
	vPos = VGet(0, 0, 0);

	width = 48;
	height = 48;

	speed = 3;
	power = 1;
	stanTime = 0;
	AttackTime = 0;

	PlayerPos = 0;	//�ŏ��͍�

	isMove = 4;   //������4
	isMoveKey = false;
	isOps = false;
	isOps_RUN = false;
	isOps_UP = false;
	isOps_DOWN = false;
	isOps_LEFT = false;
	isOps_RIGHT = false;
	isDamage = false;
	isAttack = false;
	isStan = false;

	Now_Move = 0;
}
BasePlayer::~BasePlayer()
{

}
void BasePlayer::Draw()
{
	//���@�̕`��
	DrawBox(pos.x, pos.y, pos.x + width, pos.y + height, GetColor(0, 255, 0), TRUE);

}
void BasePlayer::Update(EnemyManager* _eManager)
{
	//�X�^����ԂłȂ���
	if (isStan == false) {

		Move();    //�ړ�����
		Attack();  //�U������

		for (int i = 0; i < _eManager->Get_enemyNum(); i++) {

			//�X�^������
			Stan(_eManager->Get_x(i), _eManager->Get_y(i), _eManager->Get_width(i), _eManager->Get_height(i));
		}
	}
}
//�v���C���[�̃X�^������
void BasePlayer::Stan(float eX, float eY, float eW, float eH)
{
	//�v���C���[���G�ɓ���������isStan��true�ɂ���
	isStan = ClisionHit(Get_x(), Get_y(), Get_width(), Get_height(),
		eX, eY, eW, eH);

	//true�̎��X�^���^�C�������Z
	if (isStan == true)
	{
		DrawFormatString(0, 100, GetColor(255, 255, 255), "���т�Y��", 0);
		stanTime++;
	}
	//��莞�Ԍo�߂�����X�^�����������ăX�^���^�C�������Z�b�g
	if (stanTime >= 120)
	{
		isStan = false;
		stanTime = 0;
	}
}
//�����蔻��
bool BasePlayer::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh)
{
	if (mx < (ox + ow) && my < (oy + oh) &&
		ox < (mx + mw) && oy < (my + mh))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//�v���C���[�̍U������
void BasePlayer::Attack()
{

	if (AttackTime < 5)
	{
		AttackTime++;
	}

	//�U���Ԋu
	if ((Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1) && AttackTime >= 5)
	{
		//�U��flag��true�ɂ���
		isAttack = true;
		//�e���΂�
		bulletManager->Shot(pos, PlayerPos, isAttack);
		AttackTime = 0;
	}

}
//�v���C���[�̈ړ�����
void BasePlayer::Move()

{

	//���L�[���������Ƃ�
	if ((Input::Instance()->GetPressCount(KEY_INPUT_LEFT) == 1) && Now_Move == 0) {

		if (PlayerPos == 2) {
			isOps = true;
			isOps_RIGHT = true;
		}
		else {
			//�ړ����������ɂ���
			isMove = 0;
			//�L�[���͂̑���ł��邱�Ƃ̃t���O��on
			isMoveKey = true;
			Now_Move = 1;
		}
	}
	//���L�[���������Ƃ�
	if ((Input::Instance()->GetPressCount(KEY_INPUT_UP) == 1) && Now_Move == 0) {

		if (PlayerPos == 3) {
			isOps = true;
			isOps_DOWN = true;
		}
		else {
			//�ړ���������ɂ���
			isMove = 1;
			//�L�[���͂̑���ł��邱�Ƃ̃t���O��on
			isMoveKey = true;
			Now_Move = 1;
		}
	}
	//���L�[���������Ƃ�
	if ((Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) == 1) && Now_Move == 0) {

		if (PlayerPos == 0) {
			isOps = true;
			isOps_LEFT = true;
		}
		else {
			//�ړ��������E�ɂ���
			isMove = 2;
			//�L�[���͂̑���ł��邱�Ƃ̃t���O��on
			isMoveKey = true;
			Now_Move = 1;
		}

	}
	//���L�[���������Ƃ�
	if ((Input::Instance()->GetPressCount(KEY_INPUT_DOWN) == 1) && Now_Move == 0) {

		if (PlayerPos == 1) {
			isOps = true;
			isOps_UP = true;
		}
		else {
			//�ړ����������ɂ���
			isMove = 3;
			//�L�[���͂̑���ł��邱�Ƃ̃t���O��on
			isMoveKey = true;
			Now_Move = 1;
		}
	}
	//�ړ����������̎��A���ֈړ�������
	if (isMove == 0 && isMoveKey == true && isOps == false) {
		Move_LEFT();

	}
	//�ړ���������̎��A��ֈړ�������
	if (isMove == 1 && isMoveKey == true && isOps == false) {
		Move_UP();

	}
	//�ړ��������E�̎��A�E�ֈړ�������
	if (isMove == 2 && isMoveKey == true && isOps == false) {
		Move_RIGHT();

	}
	//�ړ����������̎��A���ֈړ�������
	if (isMove == 3 && isMoveKey == true && isOps == false) {
		Move_DOWN();

	}
	//���΃t���O��true�̎��A���Έړ��������N��������
	if (isOps == true && Now_Move == 0) {
		Move_OPS();
		Now_Move = 1;

	}
	//���Έړ����������s
	if (isOps_RUN == true) {
		Move_OPSRUN();

	}

}

//��Ɉړ����鏈��
void BasePlayer::Move_UP()
{
	//��������
	if (PlayerPos == 0 && isMove == 1) {
		if (pos.y >= PLAYER_UPPOSY) {

			pos.y -= speed;
			//y2 -= speed;
		}
		if (pos.y <= PLAYER_UPPOSY && pos.x <= PLAYER_UPDOWNPOSX) {

			pos.x += speed;
			//x2 += speed;
		}
		if (pos.x >= PLAYER_UPDOWNPOSX && pos.y <= PLAYER_UPPOSY) {

			//�v���C���[�̏ꏊ����ɂ���
			PlayerPos = 1;

			//�ړ����������Z�b�g����
			isMove = 4;

			//���ړ���Ԃɂ���
			if (isOps == false) {
				Now_Move = 0;
			}

			//�ړ��L�[�̃`�F�b�N�����Z�b�g
			//isMoveKey = false;
		}
		if (isOps == true && isOps_DOWN == true && pos.x >= PLAYER_UPDOWNPOSX && pos.y <= PLAYER_UPPOSY) {
			isOps = false;
			isOps_DOWN = false;
			isOps_RUN = false;
			Now_Move = 0;
		}
	}
	//�E������
	if (PlayerPos == 2 && isMove == 1) {
		if (pos.y >= PLAYER_UPPOSY) {

			pos.y -= speed;
			//y2 -= speed;
		}
		if (pos.y <= PLAYER_UPPOSY && pos.x >= PLAYER_UPDOWNPOSX) {

			pos.x -= speed;
			//x2 -= speed;
		}
		if (pos.y <= PLAYER_UPPOSY && pos.x <= PLAYER_UPDOWNPOSX) {

			//�v���C���[�̏ꏊ����ɂ���
			PlayerPos = 1;

			//�ړ����������Z�b�g����
			isMove = 4;

			//�ړ��L�[�̃`�F�b�N�����Z�b�g
			isMoveKey = false;

			//���ړ���Ԃɂ���
			if (isOps == false) {
				Now_Move = 0;
			}
		}
	}
}

//���ֈړ����鏈��
void BasePlayer::Move_DOWN()
{

	//�����牺��
	if (PlayerPos == 0 && isMove == 3) {
		if (pos.y <= PLAYER_DOWNPOSY) {

			pos.y += speed;
			//y2 += speed;
		}
		if (pos.y >= PLAYER_DOWNPOSY && pos.x <= PLAYER_UPDOWNPOSX) {

			pos.x += speed;
			//x2 += speed;
		}
		if (pos.x >= PLAYER_UPDOWNPOSX) {

			//�v���C���[�̏ꏊ�����ɂ���
			PlayerPos = 3;

			//�ړ����������Z�b�g����
			isMove = 4;

			//�ړ��L�[�̃`�F�b�N�����Z�b�g
			isMoveKey = false;

			//���ړ���Ԃɂ���
			if (isOps == false) {
				Now_Move = 0;
			}
		}
	}

	//�E���牺��
	if (PlayerPos == 2 && isMove == 3) {
		if (pos.y <= PLAYER_DOWNPOSY) {

			pos.y += speed;
			//y2 += speed;
		}
		if (pos.y >= PLAYER_DOWNPOSY && pos.x >= PLAYER_UPDOWNPOSX) {

			pos.x -= speed;
			//x2 -= speed;
		}
		if (pos.x <= PLAYER_UPDOWNPOSX) {

			//�v���C���[�̏ꏊ�����ɂ���
			PlayerPos = 3;

			//�ړ����������Z�b�g����
			isMove = 4;

			//�ړ��L�[�̃`�F�b�N�����Z�b�g
			isMoveKey = false;

			//���ړ���Ԃɂ���
			if (isOps == false) {
				Now_Move = 0;
			}
		}
		if (isOps == true && isOps_UP == true && pos.x <= PLAYER_UPDOWNPOSX && pos.y >= PLAYER_DOWNPOSY) {
			isOps = false;
			isOps_UP = false;
			isOps_RUN = false;
			Now_Move = 0;
		}

	}
}

//���ֈړ����鏈��
void BasePlayer::Move_LEFT()
{
	//�ォ�獶��
	if (PlayerPos == 1 && isMove == 0) {
		if (pos.x >= PLAYER_LEFTPOS) {

			pos.x -= speed;
			//x2 -= speed;
		}
		if (pos.x <= PLAYER_LEFTPOS && pos.y <= PLAYER_LEFTRIGHTPOS) {

			pos.y += speed;
			//y2 += speed;
		}
		if (pos.y >= PLAYER_LEFTRIGHTPOS && pos.x <= PLAYER_LEFTPOS) {

			//�v���C���[�̏ꏊ�����ɂ���
			PlayerPos = 0;

			//�ړ����������Z�b�g����
			isMove = 4;

			//�ړ��L�[�̃`�F�b�N�����Z�b�g
			isMoveKey = false;

			//���ړ���Ԃɂ���
			if (isOps == false) {
				Now_Move = 0;
			}
		}
		if (isOps == true && pos.x <= PLAYER_LEFTPOS && pos.y >= PLAYER_LEFTRIGHTPOS) {
			isOps = false;
			isOps_RIGHT = false;
			isOps_RUN = false;
			Now_Move = 0;
		}
	}
	//�����獶��
	if (PlayerPos == 3 && isMove == 0) {
		if (pos.x >= PLAYER_LEFTPOS) {

			pos.x -= speed;
			//x2 -= speed;
		}
		if (pos.x <= PLAYER_LEFTPOS && pos.y >= PLAYER_LEFTRIGHTPOS) {

			pos.y -= speed;
			//y2 -= speed;
		}
		if (pos.y <= PLAYER_LEFTRIGHTPOS && pos.x <= PLAYER_LEFTPOS) {

			//�v���C���[�̏ꏊ�����ɂ���
			PlayerPos = 0;

			//�ړ����������Z�b�g����
			isMove = 4;

			//���ړ���Ԃɂ���
			if (isOps == false) {
				Now_Move = 0;
			}
		}
		if (isOps == true && isOps_RIGHT == true && pos.x <= PLAYER_LEFTPOS && pos.y <= PLAYER_LEFTRIGHTPOS) {
			isOps = false;
			isOps_RIGHT = false;
			isOps_RUN = false;
			Now_Move = 0;
		}
	}
}
//�E�ֈړ����鏈��
void BasePlayer::Move_RIGHT()
{
	//�ォ��E��
	if (PlayerPos == 1 && isMove == 2) {
		if (pos.x <= PLAYER_RIGHTPOS) {

			pos.x += speed;
			//x2 += speed;
		}
		if (pos.x >= PLAYER_RIGHTPOS && pos.y <= PLAYER_LEFTRIGHTPOS) {

			pos.y += speed;
			//y2 += speed;
		}
		if (pos.y >= PLAYER_LEFTRIGHTPOS && pos.x >= PLAYER_RIGHTPOS) {

			//�v���C���[�̏ꏊ���E�ɂ���
			PlayerPos = 2;

			//�ړ����������Z�b�g����
			isMove = 4;

			//�ړ��L�[�̃`�F�b�N�����Z�b�g
			isMoveKey = false;

			//���ړ���Ԃɂ���
			if (isOps == false) {
				Now_Move = 0;
			}
		}
		if (isOps == true && isOps_LEFT == true && pos.x >= PLAYER_RIGHTPOS && pos.y >= PLAYER_LEFTRIGHTPOS) {
			isOps = false;
			isOps_LEFT = false;
			isOps_RUN = false;
			Now_Move = 0;
		}
	}
	//������E��
	if (PlayerPos == 3 && isMove == 2) {
		if (pos.x <= PLAYER_RIGHTPOS) {

			pos.x += speed;
			//x2 += speed;
		}
		if (pos.x >= PLAYER_RIGHTPOS && pos.y >= PLAYER_LEFTRIGHTPOS) {

			pos.y -= speed;
			//y2 -= speed;
		}
		if (pos.y <= PLAYER_LEFTRIGHTPOS && pos.x >= PLAYER_RIGHTPOS) {

			//�v���C���[�̏ꏊ���E�ɂ���
			PlayerPos = 2;

			//�ړ����������Z�b�g����
			isMove = 4;

			//�ړ��L�[�̃`�F�b�N�����Z�b�g
			isMoveKey = false;

			//���ړ���Ԃɂ���
			if (isOps == false) {
				Now_Move = 0;
			}
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