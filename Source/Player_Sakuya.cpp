#include"Player_Sakuya.h"
#include"Input.h"

Sakuya::Sakuya()
{
	speed = 10;		                //�v���C���[�̈ړ����x
	power = 400;		            //�v���C���[�̍U����
	attackTime = 0;                 //�U���Ԋu

	abilityTimer = STOPTIME;               //�X�L�����ԃ^�C�}�[

	color = GetColor(255, 0, 0);		//�F

	countDown = FRAME;              //�X�L���^�C�}�[�����炷�̂Ɏg��
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
void Sakuya::SkilClock()
{
	DrawFormatString(10, 100, color, "���X�L�����ԁF%d", abilityTimer);
}
void Sakuya::Update()
{
	if (Get_isAbility() == true) {

		Ability();                         //�X�L��
		SkilClock();                    //�X�L���^�C�}�[�̕\��

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
