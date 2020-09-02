#ifndef _CASTLEMANAGER_H
#define _CASTLEMANAGER_H

#include "MainCastle.h"
#include "SubCastle.h"

class BaseCastle;
class MainCastle;
class SubCastle;

class EnemyManager;

class CastleManager {
private:
	static const int POPCASTLE = 5;

	BaseCastle* Castles[POPCASTLE];

	int durability;
	int x, y, width, heigth;
	int activeCount;

public:
	CastleManager();

	~CastleManager();

	void SpawnCastle();

	void Update(EnemyManager*);
	void Draw();

	//int Get_ActiveCount();			//�A�N�e�B�u�ȋ��_�̐���Ԃ�

	int Get_X(int);					//x���W���󂯎��
	int Get_Y(int);					//y���W���󂯎��
	int Get_Width(int);				//�����󂯎��
	int Get_Height(int);			//�������󂯎��
	int Get_IsActive(int);			//�A�N�e�B�u�t���O�̃Z�b�^�[
	int Get_Durability(int);		
	void Set_Durability(int,int);
};

#endif // !_CASTLEMANAGER_H
