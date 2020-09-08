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
	int activeCount;

	bool activeCountFlg[POPCASTLE];

public:
	CastleManager();

	~CastleManager();

	void Update(EnemyManager*);
	void Draw();

	int Get_CastleNum();    //���_�̐���Ԃ�

	float Get_X(int);				//x���W���󂯎��
	float Get_Y(int);				//y���W���󂯎��
	float Get_Width(int);			//�����󂯎��
	float Get_Height(int);			//�������󂯎��
	bool Get_IsActive(int);			//�A�N�e�B�u�t���O�̃Z�b�^�[
	int Get_Durability(int);	
	int Get_CastleDirection(int);
};

#endif // !_CASTLEMANAGER_H
