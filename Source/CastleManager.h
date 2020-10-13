#ifndef _CASTLEMANAGER_H
#define _CASTLEMANAGER_H

#include "MainCastle.h"
#include "SubCastle.h"
#include "Direction.h"
class BaseCastle;
class MainCastle;
class SubCastle;

class EnemyManager;
class EventManager;

class CastleManager {
private:
	static const int POPCASTLE = 5;    //�������鋒�_�̐�

	BaseCastle* Castles[POPCASTLE];

	int durability;                    //�ϋv
	int occupiedNum;                   //��̐�

	bool activeCountFlg[POPCASTLE];    //�A�N�e�B�u�Ȑ��𐔂���t���O

public:
	CastleManager();

	~CastleManager();

	void Update(EnemyManager*,EventManager*);
	void Draw();

	int Get_CastleNum();                    //���_�̐���Ԃ�

	float Get_X(int);				        //i�Ԗڂ̋��_��x���W���󂯎��
	float Get_Y(int);				        //i�Ԗڂ̋��_��y���W���󂯎��
	float Get_Width(int);			        //i�Ԗڂ̋��_�̕����󂯎��
	float Get_Height(int);			        //i�Ԗڂ̋��_�̍������󂯎��
	float Get_DrawPosX(int);	            //i�Ԗڂ̋��_��\������X���W���󂯎��
	float Get_DrawPosY(int);	            //i�Ԗڂ̋��_��\������Y���W���󂯎��
	float Get_PopPosX(int);	                //i�Ԗڂ̋��_�Ő�������G��X���W���󂯎��
	float Get_PopPosY(int);	                //i�Ԗڂ̋��_�Ő�������G��Y���W���󂯎��
	bool Get_IsActive(int);			        //i�Ԗڂ̋��_�̐������Ă��邩���󂯎��
	int Get_Durability(int);	            //i�Ԗڂ̋��_�̑ϋv���󂯎��
	eDirection Get_CastleDirection(int);    //i�Ԗڂ̋��_�̕������󂯎��
	int Get_OccupiedNum();                  //��̂��ꂽ�T�u���_�̐����󂯎��
};

#endif // !_CASTLEMANAGER_H
