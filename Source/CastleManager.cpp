#include <DxLib.h>
#include "CastleManager.h"

CastleManager::CastleManager() {

	for (int i = 0; i < POPCASTLE; i++)
	{
		Castles[i] = NULL;		//Castle�̃|�C���^��NULL
	}

	popEnemyNum = 0;
	activeCount = 0;
	spawnFlg = true;
}

CastleManager::~CastleManager() {

	for (int num = 0; num < POPCASTLE; num++) 
	{
		delete Castles[num];    //�f���[�g����
	}
}

void CastleManager::SpawnCastle()
{
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
				Castles[i] = new SubCastle(durability,i);    //��������
			}
			activeCountFlg[i] = true;
			activeCount++;
		}
	}
	spawnFlg = false;
}

void CastleManager::Update(EnemyManager*_enemy)
{
	if (spawnFlg == true)
	{
		SpawnCastle();    //����
	}

	for (int i = 0; i < POPCASTLE; i++)
	{
		if (Castles[i] != NULL)
		{
			Castles[i]->Update(_enemy);		      //�X�V����

			if (Castles[i]->GetIsActive() == false)
			{
				//��񂾂��������������̂�
				if (activeCountFlg[i] == true)
				{
					popEnemyNum += 2;             //�ǉ����Ő�������G��ݒ肷��
					activeCount--;                //�A�N�e�B�u�ȋ��_�̐������炷
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

int CastleManager::Get_X(int _num)
{
	if (Castles[_num] != NULL)
	{
		return Castles[_num]->Get_X();
	}
}

int CastleManager::Get_Y(int _num)
{
	if (Castles[_num] != NULL) 
	{
		return Castles[_num]->Get_Y();
	}
}

int CastleManager::Get_Width(int _num)
{
	if (Castles[_num] != NULL) 
	{
		return Castles[_num]->Get_Width();
	}
}

int CastleManager::Get_Height(int _num)
{
	if (Castles[_num] != NULL) 
	{
		return Castles[_num]->Get_Height();
	}
}

int CastleManager::Get_IsActive(int num) 
{
	if (Castles[num] != NULL) 
	{
		return Castles[num]->GetIsActive();
	}
}

int CastleManager::Get_Durability(int num) 
{
	if (Castles[num] != NULL) {
		return Castles[num]->Get_Durability();
	}
}

int CastleManager::Get_CastleNum()
{
	return POPCASTLE;
}

float CastleManager::Get_EnemySpeed(int num)
{
	if (Castles[num] != NULL) {
		return Castles[num]->Get_EnemySpeed();
	}
}

float CastleManager::Get_EnemyPower(int num)
{
	if (Castles[num] != NULL) {
		return Castles[num]->Get_EnemyPower();
	}
}

int CastleManager::Get_EnemyDurability(int num)
{
	if (Castles[num] != NULL) {
		return Castles[num]->Get_EnemyDurability();
	}
}

int CastleManager::Get_EnemyDirection(int num)
{
	if (Castles[num] != NULL) {
		return Castles[num]->Get_EnemyDirection();
	}
}

int CastleManager::Get_PopEnemyNum()
{
	return popEnemyNum;
}

void CastleManager::Set_Durability(int num,int _durability) 
{
	if (Castles[num] != NULL) 
	{
		Castles[num]->Set_Durability(_durability);
	}
}
