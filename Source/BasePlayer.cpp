#include"DxLib.h"
#include"Define.h"
#include"Input.h"
#include"BasePlayer.h"
#include"BaseEnemy.h"
#include"BulletManager.h"
#include"EnemyManager.h"

BasePlayer::BasePlayer(enum PlayerType _pType, enum AbilityType _pAbility)
{

	pos = VGet(PLAYER_LEFTPOS, PLAYER_LEFTRIGHTPOS, 0);
	vPos = VGet(0, 0, 0);

	width = 48;
	height = 48;

	speed = 3;					//�ړ����x
	power = 25;					//�U����
	abilityCount = 5;		    //�X�L����
	stanTime = 0;				//�X�^���^�C��
	stanTime_stay = 360;		//�X�^���Ĕ����܂ł̎���

	attackTime = 0;

	playerPos = 0;			//�ŏ��͍�

	isMove = 4;				//������4 ��4�͉������ĂȂ���ԁB�ڂ����̓w�b�_�[�Q��
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
	isStan_Next = false;
	isAbility = false;

	now_Move = 0;			//���݈ړ����s���Ă��邩�ǂ����̃t���O

	playerType  = _pType;
	abilityType = _pAbility; //�܂��L�����I���ł��Ȃ��̂ō��͍��
}
BasePlayer::~BasePlayer()
{

}
void BasePlayer::Draw()
{
	//���@�̕`��
	DrawBox(pos.x, pos.y, pos.x + width, pos.y + height, GetColor(0, 255, 0), TRUE);
}
void BasePlayer::Update(EnemyManager* _eManager,BuffManager* _bManager)
{
	//power *= _bManager->GetPowerBuff();   �o�t�ɂ��U���͑���
	//speed *= _bManager->GetSpeedBuff();   �o�t�ɂ��X�s�[�h����

	//�X�^����ԂłȂ���
	if (isStan == 0) {

		Move();    //�ړ�����
		Attack();  //�U������

		for (int i = 0; i < _eManager->Get_enemyNum(); i++) {

			//�v���C���[���G�ɓ���������isStan��true�ɂ���
			if (ClisionHit(Get_x(), Get_y(), Get_width(), Get_height(),
				_eManager->Get_x(i), _eManager->Get_y(i), _eManager->Get_width(i), _eManager->Get_height(i)))
			{
				isStan = true;   //�X�^���͏������Ă�����������̂�
				isHit = true;    //�o�t���x���_�E���p��isHit���g���B
			}
		}
	}
	if (isHit == true)
	{
		//_bManager->DownBuffLevel();  �o�t���x���_�E��
	}
	if (isStan == true && isStan_Next == true)
	{
		Stan();
	}
	//�X�^�����������ꂽ�玟�ɃX�^�����N���鎞�Ԃ��v���X
	if (isStan == false)
	{
		stanTime = 0;
		if (stanTime_stay < 240) {
			stanTime_stay++;
		}
	}
	if (stanTime_stay >= 360)
	{
		isStan_Next = true;

	}
	float xx = pos.x + width;
	float yy = pos.y + height;

}
//�v���C���[�̃X�^������
void BasePlayer::Stan()
{

	//�X�^���^�C�������Z
	DrawFormatString(0, 100, GetColor(255, 255, 255), "���т�Y��", 0);
	if (stanTime < 120) {
		stanTime++;
	}
	//��莞�Ԍo�߂�����X�^�����������ăX�^���^�C�������Z�b�g
	if (stanTime >= 120)
	{
		isStan = false;

	}
}
//�����蔻��
bool BasePlayer::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh)
{
	if (mx <= (ox + ow) && my <= (oy + oh) &&
		ox <= (mx + mw) && oy <= (my + mh))
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

	if (attackTime < 5)
	{
		attackTime++;
	}

	//�U���Ԋu
	if ((Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1) && attackTime >= 5 && now_Move == 0)
	{
		//�U��flag��true�ɂ���
		isAttack = true;
		//�e���΂�
		bulletManager->Shot(pos, playerPos, isAttack);
		attackTime = 0;
	}

}
//�v���C���[�̈ړ�����
void BasePlayer::Move()

{

	//���L�[���������Ƃ�
	if ((Input::Instance()->GetPressCount(KEY_INPUT_LEFT) == 1) && now_Move == 0) {

		if (playerPos == 2) {
			isOps = true;
			isOps_RIGHT = true;
		}
		else if (playerPos != 0) {
			//�ړ����������ɂ���
			isMove = 0;
			//�L�[���͂̑���ł��邱�Ƃ̃t���O��on
			isMoveKey = true;
			now_Move = 1;
		}
	}
	//���L�[���������Ƃ�
	if ((Input::Instance()->GetPressCount(KEY_INPUT_UP) == 1) && now_Move == 0) {

		if (playerPos == 3) {
			isOps = true;
			isOps_DOWN = true;
		}
		else if (playerPos != 1) {
			//�ړ���������ɂ���
			isMove = 1;
			//�L�[���͂̑���ł��邱�Ƃ̃t���O��on
			isMoveKey = true;
			now_Move = 1;
		}
	}
	//���L�[���������Ƃ�
	if ((Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) == 1) && now_Move == 0) {

		if (playerPos == 0) {
			isOps = true;
			isOps_LEFT = true;
		}
		else if (playerPos != 2) {
			//�ړ��������E�ɂ���
			isMove = 2;
			//�L�[���͂̑���ł��邱�Ƃ̃t���O��on
			isMoveKey = true;
			now_Move = 1;
		}

	}
	//���L�[���������Ƃ�
	if ((Input::Instance()->GetPressCount(KEY_INPUT_DOWN) == 1) && now_Move == 0) {

		if (playerPos == 1) {
			isOps = true;
			isOps_UP = true;
		}
		else if (playerPos != 3) {
			//�ړ����������ɂ���
			isMove = 3;
			//�L�[���͂̑���ł��邱�Ƃ̃t���O��on
			isMoveKey = true;
			now_Move = 1;
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
	if (isOps == true && now_Move == 0) {
		Move_OPS();
		now_Move = 1;

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
	if (playerPos == 0 && isMove == 1) {
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
			playerPos = 1;

			//�ړ����������Z�b�g����
			isMove = 4;

			//���ړ���Ԃɂ���
			if (isOps == false) {
				now_Move = 0;
			}

			//�ړ��L�[�̃`�F�b�N�����Z�b�g
			//isMoveKey = false;
		}
		if (isOps == true && isOps_DOWN == true && pos.x >= PLAYER_UPDOWNPOSX && pos.y <= PLAYER_UPPOSY) {
			isOps = false;
			isOps_DOWN = false;
			isOps_RUN = false;
			now_Move = 0;
		}
	}
	//�E������
	if (playerPos == 2 && isMove == 1) {
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
			playerPos = 1;

			//�ړ����������Z�b�g����
			isMove = 4;

			//�ړ��L�[�̃`�F�b�N�����Z�b�g
			isMoveKey = false;

			//���ړ���Ԃɂ���
			if (isOps == false) {
				now_Move = 0;
			}
		}
	}
}

//���ֈړ����鏈��
void BasePlayer::Move_DOWN()
{

	//�����牺��
	if (playerPos == 0 && isMove == 3) {
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
			playerPos = 3;

			//�ړ����������Z�b�g����
			isMove = 4;

			//�ړ��L�[�̃`�F�b�N�����Z�b�g
			isMoveKey = false;

			//���ړ���Ԃɂ���
			if (isOps == false) {
				now_Move = 0;
			}
		}
	}

	//�E���牺��
	if (playerPos == 2 && isMove == 3) {
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
			playerPos = 3;

			//�ړ����������Z�b�g����
			isMove = 4;

			//�ړ��L�[�̃`�F�b�N�����Z�b�g
			isMoveKey = false;

			//���ړ���Ԃɂ���
			if (isOps == false) {
				now_Move = 0;
			}
		}
		if (isOps == true && isOps_UP == true && pos.x <= PLAYER_UPDOWNPOSX && pos.y >= PLAYER_DOWNPOSY) {
			isOps = false;
			isOps_UP = false;
			isOps_RUN = false;
			now_Move = 0;
		}

	}
}

//���ֈړ����鏈��
void BasePlayer::Move_LEFT()
{
	//�ォ�獶��
	if (playerPos == 1 && isMove == 0) {
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
			playerPos = 0;

			//�ړ����������Z�b�g����
			isMove = 4;

			//�ړ��L�[�̃`�F�b�N�����Z�b�g
			isMoveKey = false;

			//���ړ���Ԃɂ���
			if (isOps == false) {
				now_Move = 0;
			}
		}
		if (isOps == true && pos.x <= PLAYER_LEFTPOS && pos.y >= PLAYER_LEFTRIGHTPOS) {
			isOps = false;
			isOps_RIGHT = false;
			isOps_RUN = false;
			now_Move = 0;
		}
	}
	//�����獶��
	if (playerPos == 3 && isMove == 0) {
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
			playerPos = 0;

			//�ړ����������Z�b�g����
			isMove = 4;

			//���ړ���Ԃɂ���
			if (isOps == false) {
				now_Move = 0;
			}
		}
		if (isOps == true && isOps_RIGHT == true && pos.x <= PLAYER_LEFTPOS && pos.y <= PLAYER_LEFTRIGHTPOS) {
			isOps = false;
			isOps_RIGHT = false;
			isOps_RUN = false;
			now_Move = 0;
		}
	}
}
//�E�ֈړ����鏈��
void BasePlayer::Move_RIGHT()
{
	//�ォ��E��
	if (playerPos == 1 && isMove == 2) {
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
			playerPos = 2;

			//�ړ����������Z�b�g����
			isMove = 4;

			//�ړ��L�[�̃`�F�b�N�����Z�b�g
			isMoveKey = false;

			//���ړ���Ԃɂ���
			if (isOps == false) {
				now_Move = 0;
			}
		}
		if (isOps == true && isOps_LEFT == true && pos.x >= PLAYER_RIGHTPOS && pos.y >= PLAYER_LEFTRIGHTPOS) {
			isOps = false;
			isOps_LEFT = false;
			isOps_RUN = false;
			now_Move = 0;
		}
	}
	//������E��
	if (playerPos == 3 && isMove == 2) {
		if (pos.x <= PLAYER_RIGHTPOS) {

			pos.x += speed;

		}
		if (pos.x >= PLAYER_RIGHTPOS && pos.y >= PLAYER_LEFTRIGHTPOS) {

			pos.y -= speed;

		}
		if (pos.y <= PLAYER_LEFTRIGHTPOS && pos.x >= PLAYER_RIGHTPOS) {

			//�v���C���[�̏ꏊ���E�ɂ���
			playerPos = 2;

			//�ړ����������Z�b�g����
			isMove = 4;

			//�ړ��L�[�̃`�F�b�N�����Z�b�g
			isMoveKey = false;

			//���ړ���Ԃɂ���
			if (isOps == false) {
				now_Move = 0;
			}
		}
	}

}

//���΂ֈړ����鏈��
void BasePlayer::Move_OPS()
{

	//������E�ֈړ�
	if (playerPos == 0 && isOps_LEFT == true) {

		isOps_RUN = true;
	}
	//�E���獶�ֈړ�
	if (playerPos == 2 && isOps_RIGHT == true) {

		isOps_RUN = true;
	}
	//�ォ�牺�ֈړ�
	if (playerPos == 1 && isOps_UP == true) {

		isOps_RUN = true;
	}
	//�������ֈړ�
	if (playerPos == 3 && isOps_DOWN == true) {

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