#ifndef _BASEBOMB_H
#define _BASEBOMB_H

class BaseBomb
{
protected:
	const float BOMB_SPOWNUPDOWNX = 488;			//上下x
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

	static const int COUNT = 1;								//実際のカウントダウン
	static const int COUNTMAX = FRAME * (COUNT + 1) - 1;	

	float speed;		//爆弾が落下するスピード
	float x;
	float y;
	int damage;			//爆弾のダメージ
	int countdown;		//カウントダウン
	int direction;		//爆弾が落ちる方向

	bool isXplosion;    //爆発したかどうか
	bool isTrigger;     //爆発してるかしてないか
	bool isSpown;		//爆弾の生成したかどうか

public:
	BaseBomb();
	~BaseBomb();

	void SpawnBomb();								//爆弾の生成
	void JudgeTrigger();							//爆発したかの判定
	void Move();									//爆弾の落下
	virtual void Update() = 0;
	virtual void Draw() = 0;

};
#endif // !_BASEBOMB_H