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
	int popEnemyNum;

	bool spawnFlg;
	bool activeCountFlg[POPCASTLE];

public:
	CastleManager();

	~CastleManager();

	void SpawnCastle();

	void Update(EnemyManager*);
	void Draw();

	int Get_CastleNum();
	int Get_PopEnemyNum();			//�A�N�e�B�u�ȋ��_�̐���Ԃ�

	float Get_X(int);				//x���W���󂯎��
	float Get_Y(int);				//y���W���󂯎��
	float Get_Width(int);			//�����󂯎��
	float Get_Height(int);			//�������󂯎��
	bool Get_IsActive(int);			//�A�N�e�B�u�t���O�̃Z�b�^�[
	int Get_Durability(int);	
	float Get_EnemySpeed(int);
	float Get_EnemyPower(int);
	int Get_EnemyDurability(int);
	int Get_EnemyDirection(int);
	void Set_Durability(int,int);
};

#endif // !_CASTLEMANAGER_H
