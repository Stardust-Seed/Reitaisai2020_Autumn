#include <DxLib.h>
#include "CastleManager.h"

CastleManager::CastleManager() {

	for (int i = 0; i < POPCASTLE; i++)
	{
		Castles[i] = NULL;		   //Castle�̃|�C���^��NULL
	}

	for (int i = 0; i < POPCASTLE; i++)
	{
		if (Castles[i] == NULL)    //NULL�̏ꍇ�����J�n
		{
			if (i == 0)            //���C�����_
			{
				durability = 100;
				Castles[i] = new MainCastle(durability);     //��������
			}
			else                   //�T�u���_
			{
				durability = 25;
				Castles[i] = new SubCastle(durability, i);   //��������
			}
			activeCountFlg[i] = true;
		}
	}

	occupiedNum = 0;
}

CastleManager::~CastleManager() {

	for (int num = 0; num < POPCASTLE; num++) 
	{
		delete Castles[num];       //�f���[�g����
	}
}

//�X�V����
void CastleManager::Update(EnemyManager*_enemy)
{

	for (int i = 0; i < POPCASTLE; i++)
	{
		if (Castles[i] != NULL)
		{
			Castles[i]->Update(_enemy);

			if (Castles[i]->GetIsActive() == false && i != 0)
			{
				//��񂾂��������������̂�
				if (activeCountFlg[i] == true)
				{
					SE::Instance()->PlaySE(SE_CastleBreak);
					occupiedNum++;                //�A�N�e�B�u�ȋ��_�̐������炷
					activeCountFlg[i] = false;    //���ȏ㏈�������Ȃ��p�̃t���O
				}
			}
		}
	}
}

//�`��
void CastleManager::Draw()
{
	for (int i = 0; i < POPCASTLE; i++)
	{
		if (Castles[i] != NULL)
		{
			Castles[i]->Draw();
		}
	}
}

//i�Ԗڂ̋��_�̐������Ă��邩���󂯎��
bool CastleManager::Get_IsActive(int num)
{
	if (Castles[num] != NULL)
	{
		return Castles[num]->GetIsActive();
	}
	else
	{
		return 0;
	}
}

//i�Ԗڂ̋��_�̑ϋv���󂯎��
int CastleManager::Get_Durability(int num)
{
	if (Castles[num] != NULL)
	{
		return Castles[num]->Get_Durability();
	}
	else
	{
		return 0;
	}
}

//���_�̐���Ԃ�
int CastleManager::Get_CastleNum()
{
	return POPCASTLE;
}

//��̂��ꂽ�T�u���_�̐����󂯎��
int CastleManager::Get_OccupiedNum()
{
	return occupiedNum;
}

//i�Ԗڂ̋��_��x���W���󂯎��
float CastleManager::Get_X(int _num)
{
	if (Castles[_num] != NULL)
	{
		return Castles[_num]->Get_X();
	}
	else
	{
		return 0;
	}
}

//i�Ԗڂ̋��_��y���W���󂯎��
float CastleManager::Get_Y(int _num)
{
	if (Castles[_num] != NULL) 
	{
		return Castles[_num]->Get_Y();
	}
	else
	{
		return 0;
	}
}

//i�Ԗڂ̋��_�̕����󂯎��
float CastleManager::Get_Width(int _num)
{
	if (Castles[_num] != NULL) 
	{
		return Castles[_num]->Get_Width();
	}
	else
	{
		return 0;
	}
}

//i�Ԗڂ̋��_�̍������󂯎��
float CastleManager::Get_Height(int _num)
{
	if (Castles[_num] != NULL) 
	{
		return Castles[_num]->Get_Height();
	}
	else
	{
		return 0;
	}
}

//i�Ԗڂ̋��_��\������X���W���󂯎��
float CastleManager::Get_DrawPosX(int num)
{
	if (Castles[num] != NULL) 
	{
		return Castles[num]->Get_DrawPosX();
	}
	else
	{
		return 0;
	}
}

//i�Ԗڂ̋��_��\������Y���W���󂯎��
float CastleManager::Get_DrawPosY(int num)
{
	if (Castles[num] != NULL) 
	{
		return Castles[num]->Get_DrawPosY();
	}
	else
	{
		return 0;
	}
}

//i�Ԗڂ̋��_�Ő�������G��X���W���󂯎��
float CastleManager::Get_PopPosX(int num)
{
	if (Castles[num] != NULL) 
	{
		return Castles[num]->Get_PopPosX();
	}
	else
	{
		return 0;
	}
}

//i�Ԗڂ̋��_�Ő�������G��Y���W���󂯎��
float CastleManager::Get_PopPosY(int num)
{
	if (Castles[num] != NULL) 
	{
		return Castles[num]->Get_PopPosY();
	}
	else
	{
		return 0;
	}
}

//i�Ԗڂ̋��_�̕������󂯎��
eDirection CastleManager::Get_CastleDirection(int num)
{
	if (Castles[num] != NULL)
	{
		return Castles[num]->Get_CastleDirection();
	}
	else
	{
		return eDirection::None;
	}
}