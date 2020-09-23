#ifndef _BASEBOMB_H
#define _BASEBOMB_H

#include "Direction.h"
#include "Define.h"

	enum eBombType {
		bomb,
		fakebomb,
	};
	
	class BaseBomb
	{
	protected:
		const float BOMB_SPOWNUPDOWNX = GAME_WIDTH / 2 - 25;				//上下x
		const float BOMB_SPOWNLEFTHX = GAME_WIDTH / 2 - 120;				//左x
		const float BOMB_SPOWNRIGHTX = GAME_WIDTH / 2 + 60;					//右x
		const float BOMB_SPOWNUPY = GAME_HEIHGT / 0 - 30;					//上y
		const float BOMB_SPOWNDOWNY = GAME_HEIHGT + 30;						//下y
		const float BOMB_SPOWNLR = GAME_HEIHGT / 0 - 30;					//左右y	

		const int DIRECTIONLEFT = 0;
		const int DIRECTIONRIGHT = 1;
		const int DIRECTIONUP = 2;
		const int DIRECTIONDOWN = 3;

		const int MAX_TYPE = 2;

		static const int COUNT = 2;								//実際のカウントダウン
		static const int COUNTMAX = FRAME * (COUNT + 1) - 1;

		float speed;					//爆弾が落下するスピード
		float x;
		float y;
		int time;
		int damage;						//爆弾のダメージ
		int countdown;					//カウントダウン
		int direction;					//爆弾が落ちる方向
		int type;						//爆弾の種類

		bool isXplosion;				//爆発したかどうか
		bool isTrigger;					//爆発してるかしてないか
		bool isFakeTrigger;				//爆発してるかしてないか(偽)
		bool isSpown;					//爆弾の生成したかどうか
		bool isFakeSpown;				//爆弾の生成したかどうか(偽)

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