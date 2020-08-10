#include"DxLib.h"
#include"Bullet.h"
#include"BulletManager.h"

//�R���X�g���N�^
BulletManager::BulletManager()
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		//NULL�����鎖�ŁA��Ă�delete���鎞��
		//NULL���������|�C���^�͖�������邽�߃G���[���Ȃ��Ȃ�
		bullet[i] = NULL;
	}

}
//�f�X�g���N�^
BulletManager::~BulletManager()
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		delete bullet[i];
	}

}
//�e�𔭎˂���֐�
void BulletManager::Shot(VECTOR& pos, int pl_pos, bool pl_attack)
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		//NULL�̕���T����,���I�m�ۂ���̂�
		if (bullet[i] == NULL)
		{
			bullet[i] = new Bullet(pos, pl_pos, pl_attack);
			break;
		}
	}
}
//�X�V����
void BulletManager::Update()
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		//NULL�łȂ��ꍇ,Bullet��Update�֐����s��
		if (bullet[i] != NULL)
		{
			bullet[i]->Update();

			//�e����ʊO�ɏo�Ă����ꍇ���e���G�ɓ��������ꍇ
			if (bullet[i]->Get_Flag() == false || bullet[i]->Get_Hit() == true)
			{
				//�폜����NULL�����āA�܂��g����悤�ɂ���
				delete bullet[i];
				bullet[i] = NULL;
			}
		}
	}

}
//�`�揈��
void BulletManager::Draw()
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		//NULL�łȂ��ꍇ,Bullet��Draw�֐����s��
		if (bullet[i] != NULL)
		{
			bullet[i]->Draw();

		}
	}

}