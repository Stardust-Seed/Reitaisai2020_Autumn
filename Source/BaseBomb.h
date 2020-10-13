#ifndef _BASEBOMB_H
#define _BASEBOMB_H

#include "Define.h"
#include "BaseEvent.h"
#include "BasePlayer.h"
#include "FontHandle.h"
#include "SE.h"

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

		//方向(斜めから飛んでくる上下左右)
		const int DIRECTIONLEFT = 0;
		const int DIRECTIONRIGHT = 1;
		const int DIRECTIONUP = 2;
		const int DIRECTIONDOWN = 3;

		static const int COUNT = 3;									//実際のカウントダウン
		static const int COUNTMAX = FRAME * (COUNT + 1) - 1;		//フレーム

		float speed = 0;					//爆弾が落下するスピード
		float x;
		float y;
		float cx;						//中心x
		float cy;						//中心y
		float width;					//幅
		float height;					//高さ

		int tX = 0;						//タイマーのx
		int tY = 0;						//タイマーのy
		int time = 0;					//爆発するまでのタイム
		int power = 0;					//爆弾のダメージ								
		int countDown = 0;				//カウントダウン
		int direction = 0;				//爆弾が落ちる方向
		int pType = 0;					//咲夜さんかどうか
		int sTime  = 0;					//時止め時のストップタイム
		int m_frameIndex = 0;			//アニメションのフレーム
		eBombType type;					//爆弾の種類

		bool isXplosion;				//爆発したかどうか
		bool isTrigger;					//爆発してるかしてないか
		bool isSpawn;					//爆弾の生成したかどうか
		bool isCount;					//カウントダウンを表示させるため
		bool isStopCount;				//カウントをストップさせるための判定
		bool AnimationFlg;				//アニメションの開始させる判定
		bool isPAbility;				//プレイヤーのスキルが発動したか判定
		bool isHit;						//プレイヤーが爆弾に当たったかの判定

	public:
		BaseBomb() {}
		~BaseBomb();
		BaseBomb(int _power, float _speed, eBombType _bombType);

		void SpawnBomb();								//爆弾の生成
		void JudgeTrigger();							//爆発したかの判定
		void Move();									//爆弾の落下
		void SkillStop();								//時止め時

		bool ClisionHit(float mx, float my, float mw, float mh,
			float ox, float oy, float ow, float oh);

		int GetPower() { return power; }				//爆弾のダメージを受け取る
		bool GetIsTriggerFlg() { return isTrigger; }	//爆発したかを受け取る
		virtual void Update(BasePlayer*) {}
		virtual void Draw() {}
	};
#endif // !_BASEBOMB_H