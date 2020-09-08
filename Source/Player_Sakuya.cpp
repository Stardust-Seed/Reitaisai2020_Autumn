#include"Player_Sakuya.h"
#include"Input.h"

Sakuya::Sakuya()
{
	speed = 10;		                //�v���C���[�̈ړ����x
	power = 400;		            //�v���C���[�̍U����
	AttackTime = 0;                 //�U���Ԋu

	SkilTimer = STOPTIME;               //�X�L�����ԃ^�C�}�[

	Color = GetColor(255, 0, 0);		//�F
}
Sakuya::~Sakuya()
{

}
void Sakuya::Draw()
{
	//���@�̕`��
	DrawGraph(pos.x, pos.y,handle[SAKUYA_GRAPH1],true);
}
void Sakuya::Skil()
{
	//�X�L���񐔂��܂��c���Ă��鎞
	if (SkilCount > 0 && Skil_isActive == false) {
		//�X�y�[�X�L�[�������ƃX�L������
		if (Input::Instance()->GetPressCount(KEY_INPUT_SPACE) == 1)
		{
			Skil_isActive = true;
			SkilCount -= 1;
		}
	}
}
void Sakuya::SkilClock()
{
	if (Skil_isActive == true) {
		DrawFormatString(10, 100, Color, "���X�L�����ԁF%d", SkilTimer / FRAME);
	}
}
void Sakuya::Update(EnemyManager* _eManager)
{
	Sakuya::Draw();						    //�`��
	BasePlayer::Update(_eManager);          //�X�V
	SkilClock();
	Skil();                     //�X�L��
	if (SkilTimer >= 0) {	    //�\������Ă���^�C�}�[��0�ɂ������̂ŃJ�E���g�_�E�����̂�0�ɂȂ�܂œ�����
		SkilTimer -= 1;
	}

	//�X�L���������̓G�l�~�[�̈ړ����~�߂�
	if (Skil_isActive == true)
	{
		for (int i = 0; i < _eManager->Get_enemyNum(); i++)
		{
			_eManager->Set_IsMove(i, false);
		}
	}
	if (Skil_isActive == false)
	{
		for (int i = 0; i < _eManager->Get_enemyNum(); i++)
		{
			_eManager->Set_IsMove(i, true);
		}
	}
}
