#include"Player_Sakuya.h"
#include"Input.h"
#include"Define.h"

Sakuya::Sakuya(){
	speed = 10;		                //�v���C���[�̈ړ����x
	power = 400;		            //�v���C���[�̍U����
	attackTime = 0;                 //�U���Ԋu

	color = GetColor(255, 0, 0);    //�F

	abilityTimer = STOPTIME;        //�X�L�����ԃ^�C�}�[
	abilityCount = 3;               //�X�L���g�p��
	countDown = FRAME;              //�X�L���^�C�}�[�����炷�̂Ɏg��

	/*************
	�L���������̏ꍇ�͍��̉摜�f�[�^������

	playerGh[] �� ��������܂�BasePlayer�̃t���[�`���[�ɂ����Ȃ��̂ō��͎g���Ȃ��B
	�@�@�@�@�@�@  ����ɍ��̉摜�𕪊��ǂݍ��݂łԂ�����

	**************/
}
Sakuya::~Sakuya()
{

}
void Sakuya::Ability()
{
	//�X�L���񐔂��܂��c���Ă��鎞
	if (Get_abilityCount() > 0 && Get_isAbility() == false) {
		//�X�y�[�X�L�[�������ƃX�L������
		if (Input::Instance()->GetPressCount(KEY_INPUT_SPACE) == 1)
		{
			isAbility = true;
			abilityCount -= 1;
		}
	}
}
void Sakuya::AbilityClock()
{
	DrawFormatString(10, 100, color, "���X�L�����ԁF%d", abilityTimer);
}
void Sakuya::Update()
{
	Ability();                             //�X�L��
	if (Get_isAbility() == true) {

		AbilityClock();                    //�X�L���^�C�}�[�̕\��

		if (abilityTimer >= 0 && countDown <= 0) {	    //�\������Ă���^�C�}�[��0�ɂ������̂ŃJ�E���g�_�E�����̂�0�ɂȂ�܂œ�����
			abilityTimer -= 1;
			countDown = FRAME;
		}
		if (abilityTimer <= 0)
		{
			isAbility = false;
		}
		countDown -= 1;
	}

}
