#include"Player_Sakuya.h"
#include"Input.h"

Sakuya::Sakuya()
{
	speed = 10;		                //�v���C���[�̈ړ����x
	power = 400;		            //�v���C���[�̍U����
	AttackTime = 0;                 //�U���Ԋu

	SkilTimer = STOPTIME;               //�X�L�����ԃ^�C�}�[

	Color = GetColor(255, 0, 0);		//�F

	CountDown = FRAME;              //�X�L���^�C�}�[�����炷�̂Ɏg��
}
Sakuya::~Sakuya()
{

}
void Sakuya::Skil()
{
	//�X�L���񐔂��܂��c���Ă��鎞
	if (Get_SkilCount() > 0 && Get_isAbility() == false) {
		//�X�y�[�X�L�[�������ƃX�L������
		if (Input::Instance()->GetPressCount(KEY_INPUT_SPACE) == 1)
		{
			Set_isAbility(true);
			Set_SkilCount(Get_SkilCount() - 1);
		}
	}
}
void Sakuya::SkilClock()
{
	DrawFormatString(10, 100, Color, "���X�L�����ԁF%d", SkilTimer);
}
void Sakuya::Update()
{
	if (Get_isAbility() == true) {

		Skil();                         //�X�L��
		SkilClock();                    //�X�L���^�C�}�[�̕\��

		if (SkilTimer >= 0 && CountDown <= 0) {	    //�\������Ă���^�C�}�[��0�ɂ������̂ŃJ�E���g�_�E�����̂�0�ɂȂ�܂œ�����
			SkilTimer -= 1;
			CountDown = FRAME;
		}
		if (SkilTimer <= 0)
		{
			Set_isAbility(false);
		}
		CountDown -= 1;
	}

}
