#ifndef _BASEBOMB_H
#define _BASEBOMB_H

enum eBombType
{
	Bomb,			//本物
	fakeBomb		//偽物
};

enum EBombType bombtype;

class BaseBomb
{
private:
	const float BOMB_SPOWNUPDOWNX = 0;				//上下x
	const float BOMB_SPOWNRIGHTX = 0;				//右x
	const float BOMB_SPOWNLEFTHX = 0;				//左x
	const float BOMB_SPOWNUPY = 0;					//上y
	const float BOMB_SPOWNDOWNY = 0;				//下y
	const float BOMB_SPOWNLR = 0;					//左右y
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
	void JudgeTrigger();							//爆発したかの判定
	void Move();									//爆弾の落下

	void Set_X(float _x) { x = _x; }				//x座標をセット
	void Set_Y(float _y) { y = _y; }				//y座標をセット

	float Get_X() { return x; }						//x座標をゲットする
	float Get_Y() { return y; }						//y座標をゲットする
	bool GetIsTrigger() { return isTrigger; };		//爆弾が爆発したか
	bool GetIsActive() { return isSpown; };
};
#endif // !_BASEBOMB_H