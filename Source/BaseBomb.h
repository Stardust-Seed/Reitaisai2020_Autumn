#ifndef _BASEBOMB_H
#define _BASEBOMB_H

#include "Define.h"
#include "BaseEvent.h"
#include "CastleManager.h"
#include "BasePlayer.h"
#include "FontHandle.h"
#include "SE.h"

class castleManager;
class BasePlayer;

	enum eBombType
	{
		bomb = 1,
		fakebomb = 2,
	};
	
	class BaseBomb : public virtual BaseEvent
	{
	protected:
		const float BOMB_SPOWNUPX = GAME_WIDTH / 2 - 176;     			    //上x
		const float BOMB_SPOWNDOWNX = GAME_WIDTH / 2 + 200;   			    //下x
		const float BOMB_SPOWNLEFTHX = GAME_WIDTH / 2 - 1050;				//左x
		const float BOMB_SPOWNRIGHTX = GAME_WIDTH / 2 + 1050;				//右x
		const float BOMB_SPOWNUPY = GAME_HEIHGT / 0 - 30;					//上y
		const float BOMB_SPOWNDOWNY = GAME_HEIHGT + 200;					//下y
		const float BOMB_SPOWNRIGHTY = GAME_HEIHGT / 0 + 867;				//右y	
		const float BOMB_SPOWNLEFTY = GAME_HEIHGT / 0 + 202;				//左y	

		const int DIRECTIONLEFT = 0;
		const int DIRECTIONRIGHT = 1;
		const int DIRECTIONUP = 2;
		const int DIRECTIONDOWN = 3;

		const int MAX_TYPE_NUM = 2;

		static const int COUNT = 10;								//実際のカウントダウン
		static const int COUNTMAX = FRAME * (COUNT + 1) - 1;

		float speed;					//爆弾が落下するスピード
		float x;
		float y;
		float cx;
		float cy;
		float width;
		float height;
		int sx;
		int sy;
		int time;
		int power;						//爆弾のダメージ
		int damage;
		int countDown;					//カウントダウン
		int direction;					//爆弾が落ちる方向
		int type;						//爆弾の種類
		int pType;
		int sTime;
		int m_frameIndex = 0;

		bool isXplosion;				//爆発したかどうか
		bool isTrigger;					//爆発してるかしてないか
		bool isSpown;					//爆弾の生成したかどうか
		bool isCount;					//カウントダウンを表示させるため
		bool isStopCount;
		bool AnimationFlg;
		bool isPAbility;
		bool isHit;

	public:
		BaseBomb() {}
		~BaseBomb();
		BaseBomb(int _power, int _speed, eBombType _bombType);

		void SpawnBomb();								//爆弾の生成
		void JudgeTrigger();							//爆発したかの判定
		void Move();									//爆弾の落下
		void SkillStop();

		bool ClisionHit(float mx, float my, float mw, float mh,
			float ox, float oy, float ow, float oh);

		int GetPower() { return power; }							
		bool GetIsTriggerFlg() { return isActive; }
		virtual void Update(BasePlayer*) {}
		virtual void Draw() {}
	};
#endif // !_BASEBOMB_H