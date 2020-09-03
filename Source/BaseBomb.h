#ifndef _BASEBOMB_H
#define _BASEBOMB_H

enum eBombType
{
	Bomb,			//�{��
	fakeBomb		//�U��
};

enum EBombType bombtype;

class BaseBomb
{
private:
	const float BOMB_SPOWNUPDOWNX = 0;				//�㉺x
	const float BOMB_SPOWNRIGHTX = 0;				//�Ex
	const float BOMB_SPOWNLEFTHX = 0;				//��x
	const float BOMB_SPOWNUPY = 0;					//��y
	const float BOMB_SPOWNDOWNY = 0;				//��y
	const float BOMB_SPOWNLR = 0;					//���Ey
	const int DIRECTIONLEFT = 0;
	const int DIRECTIONRIGHT = 1;
	const int DIRECTIONUP = 2;
	const int DIRECTIONDOWN = 3;
	const int MAX_TIME = 10;

	float speed;
	int damage;
	int countdown;
	int direction;
	int BombType;
	int x;
	int y;

	bool isTrigger;
	bool isSpown;

public:
	BaseBomb() {}
	~BaseBomb() {}
	BaseBomb(float _speed, int _damage, int _direction, int _countdown);

	void SpawnBomb();
	void JudgeTrigger();							//�����������̔���
	void Move();									//���e�̗���

	void Set_X(float _x) { x = _x; }				//x���W���Z�b�g
	void Set_Y(float _y) { y = _y; }				//y���W���Z�b�g

	float Get_X() { return x; }						//x���W���Q�b�g����
	float Get_Y() { return y; }						//y���W���Q�b�g����
	bool GetIsTrigger() { return isTrigger; };		//���e������������
	bool GetIsActive() { return isSpown; };
};
#endif // !_BASEBOMB_H