#ifndef _BASEBOMB_H
#define _BASEBOMB_H

//#include "Castle.h"

enum eBombType
{
	Bomb,			//本物
	fakeBomb		//偽物
};

//enum EBombType bombtype;

class BaseBomb
{
protected:
	const float BOMB_SPOWNUPDOWNX = 488;				//上下x
	const float BOMB_SPOWNRIGHTX = 584;				//右x
	const float BOMB_SPOWNLEFTHX = 392;				//左x
	const float BOMB_SPOWNUPY = 0;					//上y
	const float BOMB_SPOWNDOWNY = 768;				//下y
	const float BOMB_SPOWNLR = 0;					//左右y
	
	const int DIRECTIONLEFT = 0;
	const int DIRECTIONRIGHT = 1;
	const int DIRECTIONUP = 2;
	const int DIRECTIONDOWN = 3;

	static const int FRAME = 60;							//フレームレート

	static const int TIME = 1;								//実際の制限時間
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
	void JudgeTrigger();							//爆発したかの判定
	void Move();									//爆弾の落下
	void Delete();

	void Set_X(float _x) { x = _x; }				//x座標をセット
	void Set_Y(float _y) { y = _y; }				//y座標をセット

	float Get_X() { return x; }						//x座標をゲットする
	float Get_Y() { return y; }						//y座標をゲットする
	bool GetIsTrigger() { return isTrigger; };		//爆弾が爆発したか
	bool GetIsActive() { return isSpown; };
};
#endif // !_BASEBOMB_H