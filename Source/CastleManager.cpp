#include <DxLib.h>
#include "CastleManager.h"

CastleManager::CastleManager() {

	cnt = 1;
	number = 1;
	installCnt = 0;

	for (int i = 0; i < 8; i++)
	{
		numberFlg[i] = false;
	}

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
				activeCountFlg[i] = true;
			}
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
void CastleManager::Update(GameResource* _gameRes)
{
	//�����L�[�ł̔ԍ��w�莞�̏���
	if ((Input::Instance()->GetPressCount(KEY_INPUT_1) == 1))
	{
		number = 1;
	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_2) == 1))
	{
		number = 2;
	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_3) == 1))
	{
		number = 3;
	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_4) == 1))
	{
		number = 4;
	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_5) == 1))
	{
		number = 5;
	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_6) == 1))
	{
		number = 6;
	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_7) == 1))
	{
		number = 7;
	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_8) == 1))
	{
		number = 8;
	}


	if ((Input::Instance()->GetPressCount(KEY_INPUT_V) == 1))
	{
		number--;

		if (number < 1)
		{
			number = 8;
		}
	}

	if ((Input::Instance()->GetPressCount(KEY_INPUT_B) == 1))
	{
		number++;

		if (number > 8)
		{
			number = 1;
		}
	}

	if ((Input::Instance()->GetPressCount(KEY_INPUT_C) == 1) && numberFlg[number - 1] == false)
	{
		if (cnt < POPCASTLE)
		{
			numberFlg[number - 1] = true;
			installCnt++;
			durability = 25;
			Castles[cnt] = new SubCastle(durability, cnt, number);   //��������
			activeCountFlg[cnt] = true;
			cnt++;
		}
	}

	for (int i = 0; i < POPCASTLE; i++)
	{
		if (Castles[i] != NULL)
		{
			if (i == 0)
			{
				Castles[i]->Update(_gameRes->enemyManager, _gameRes->eventManager);
			}
			else
			{
				Castles[i]->Update(_gameRes->enemyManager);
			}

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

	//DrawFormatString(120, 120, GetColor(255, 255, 255), "%d", cnt);
	//DrawFormatString(100, 100, GetColor(255, 255, 255), "%d", number);

	//�ݒu�ł���ꏊ�̕\��
	if(!numberFlg[0])DrawGraphF(SubCastle::COORDINATE_X_ONE - 4 - 48, SubCastle::COORDINATE_Y_ONE - 80 - 4, Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 2), TRUE);
	if (!numberFlg[1])DrawGraphF(SubCastle::COORDINATE_X_TWO - 4 - 48, SubCastle::COORDINATE_Y_TWO + 32 - 4, Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 2), TRUE);
	if (!numberFlg[2])DrawGraphF(SubCastle::COORDINATE_X_THREE + 32 - 4, SubCastle::COORDINATE_Y_THREE - 48 - 4, Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 2), TRUE);
	if (!numberFlg[3])DrawGraphF(SubCastle::COORDINATE_X_FOUR - 80 - 4, SubCastle::COORDINATE_Y_FOUR - 48 - 4, Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 2), TRUE);
	if (!numberFlg[4])DrawGraphF(SubCastle::COORDINATE_X_FIVE + 48 - 4, SubCastle::COORDINATE_Y_FIVE + 32 - 4, Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 2), TRUE);
	if (!numberFlg[5])DrawGraphF(SubCastle::COORDINATE_X_SIX + 48 - 4, SubCastle::COORDINATE_Y_SIX - 80 - 4, Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 2), TRUE);
	if (!numberFlg[6])DrawGraphF(SubCastle::COORDINATE_X_SEVEN - 80 - 4, SubCastle::COORDINATE_Y_SEVEN + 48 - 4, Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 2), TRUE);
	if (!numberFlg[7])DrawGraphF(SubCastle::COORDINATE_X_EIGHT + 32 - 4, SubCastle::COORDINATE_Y_EIGHT + 48 - 4, Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 2), TRUE);
	
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

//�ݒu�ł���T�u���_�̐���Ԃ�
int CastleManager::Get_installCastle()
{
	return POPCASTLE - 1 - installCnt;
}

//�ݒu�\��̃T�u���_�ԍ���Ԃ�
int CastleManager::Get_installNum()
{
	return number;
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

void CastleManager::Damage_Proc(int num, int _damage)
{
	if (Castles[num] != NULL)
	{
		Castles[num]->Damage_Proc(_damage);
	}
}