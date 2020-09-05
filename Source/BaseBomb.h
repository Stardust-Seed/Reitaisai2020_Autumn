#ifndef _BASEBOMB_H
#define _BASEBOMB_H

//#include "Castle.h"

enum eBombType
{
	Bomb,			//�{��
	fakeBomb		//�U��
};

//enum EBombType bombtype;

class BaseBomb
{
protected:
	const float BOMB_SPOWNUPDOWNX = 488;				//�㉺x
	const float BOMB_SPOWNRIGHTX = 584;				//�Ex
	const float BOMB_SPOWNLEFTHX = 392;				//��x
	const float BOMB_SPOWNUPY = 0;					//��y
	const float BOMB_SPOWNDOWNY = 768;				//��y
	const float BOMB_SPOWNLR = 0;					//���Ey
	
	const int DIRECTIONLEFT = 0;
	const int DIRECTIONRIGHT = 1;
	const int DIRECTIONUP = 2;
	const int DIRECTIONDOWN = 3;

	static const int FRAME = 60;							//�t���[�����[�g

	static const int TIME = 1;								//���ۂ̐�������
	static const int TIMELIMIT = FRAME * (TIME + 1) - 1;

	float speed;
	int damage;
	int countdown;
	int direction;
	int BombType;
	float x;
	float y;

	bool finishxplosion;
	bool isTrigger;
	bool isSpown;

public:
	BaseBomb();
	~BaseBomb();

	void Update();
	void Draw();

	void SpawnBomb();
	void Damage(int _damage);
	void JudgeTrigger();							//�����������̔���
	void Move();									//���e�̗���
	void Delete();

	void Set_X(float _x) { x = _x; }				//x���W���Z�b�g
	void Set_Y(float _y) { y = _y; }				//y���W���Z�b�g

	float Get_X() { return x; }						//x���W���Q�b�g����
	float Get_Y() { return y; }						//y���W���Q�b�g����
	bool GetIsTrigger() { return isTrigger; };		//���e������������
	bool GetIsActive() { return isSpown; };
};
#endif // !_BASEBOMB_H