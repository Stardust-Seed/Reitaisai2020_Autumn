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
	static const int POPCASTLE = 5;    //���_�̐�����

	BaseCastle* Castles[POPCASTLE];

	int durability;
	int x, y, width, heigth;
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

	//�Q�b�^�[
	//���_�֘A
	int Get_CastleNum();              //���_�̐���Ԃ�
	int Get_PopEnemyNum();			  //�ǉ��̓G�̐���Ԃ�
	int Get_X(int);
	int Get_Y(int);
	int Get_Width(int);
	int Get_Height(int);
	int Get_IsActive(int);

	//�G�p�����[�^�֘A
	int Get_Durability(int);	
	int Get_EnemyDurability(int);
	int Get_EnemyDirection(int);

	float Get_EnemySpeed(int);
	float Get_EnemyPower(int);

	//�Z�b�^�[
	void Set_Durability(int,int);
};

#endif // !_CASTLEMANAGER_H
