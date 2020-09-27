#include <DxLib.h>
#include "CastleManager.h"

CastleManager::CastleManager() {

	for (int i = 0; i < POPCASTLE; i++)
	{
		Castles[i] = NULL;		//Castle�̃|�C���^��NULL
	}

	for (int i = 0; i < POPCASTLE; i++)
	{
		if (Castles[i] == NULL)    //NULL�̏ꍇ�����J�n
		{
			if (i == 0)  //���C�����_
			{
				durability = 100;
				Castles[i] = new MainCastle(durability);     //��������
			}
			else         //�T�u���_
			{
				durability = 10;
				Castles[i] = new SubCastle(durability, i);    //��������
			}
			activeCountFlg[i] = true;
		}
	}

	occupiedNum = 0;
}

CastleManager::~CastleManager() {

	for (int num = 0; num < POPCASTLE; num++) 
	{
		delete Castles[num];    //�f���[�g����
	}
}

void CastleManager::Update(EnemyManager*_enemy)
{

	for (int i = 0; i < POPCASTLE; i++)
	{
		if (Castles[i] != NULL)
		{
			Castles[i]->Update(_enemy);		      //�X�V����

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

void CastleManager::Draw()
{
	for (int i = 0; i < POPCASTLE; i++)
	{
		if (Castles[i] != NULL)
		{
			Castles[i]->Draw();    //�`��
		}
	}
}

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

int CastleManager::Get_Durability(int num) 
{
	if (Castles[num] != NULL) {
		return Castles[num]->Get_Durability();
	}
	else
	{
		return 0;
	}
}

eDirection CastleManager::Get_CastleDirection(int num)
{
	if (Castles[num] != NULL) {
		return Castles[num]->Get_CastleDirection();
	}
	else
	{
		return eDirection::None;
	}
}

int CastleManager::Get_CastleNum()
{
	return POPCASTLE;
}

int CastleManager::Get_OccupiedNum()
{
	return occupiedNum;
}

