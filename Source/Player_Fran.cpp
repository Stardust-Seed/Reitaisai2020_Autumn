#include"Player_Fran.h"
#include"Input.h"
#include"Define.h"

Fran::Fran()
{
	speed = 10;		                //�v���C���[�̈ړ����x
	power = 400;		            //�v���C���[�̍U����
	attackTime = 0;                 //�U���Ԋu

	color = GetColor(255, 0, 0);    //�F

	abilityCount = 2;               //�X�L���g�p��

	countDown = FRAME;              //�X�L���^�C�}�[�����炷�̂Ɏg��

}
Fran::~Fran()
{

}
void Fran::Ability()
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
void Fran::Update()
{
	Ability();    //�X�L��

	if (Get_isAbility() == true) {

		if (abilityTimer == 1) {    //�t�����̃X�L���͔��������炷���I������
			isAbility = false;
			abilityTimer = 0;
		}
		if (Get_isAbility() == true && abilityTimer < 1)
		{
			abilityTimer += 1;
		}
	}

}
