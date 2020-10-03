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
		const float BOMB_SPOWNUPX = GAME_WIDTH / 2 - 176;     			    //��x
		const float BOMB_SPOWNDOWNX = GAME_WIDTH / 2 + 200;   			    //��x
		const float BOMB_SPOWNLEFTHX = GAME_WIDTH / 2 - 1050;				//��x
		const float BOMB_SPOWNRIGHTX = GAME_WIDTH / 2 + 1050;				//�Ex
		const float BOMB_SPOWNUPY = GAME_HEIHGT / 0 - 30;					//��y
		const float BOMB_SPOWNDOWNY = GAME_HEIHGT + 200;					//��y
		const float BOMB_SPOWNRIGHTY = GAME_HEIHGT / 0 + 867;				//�Ey	
		const float BOMB_SPOWNLEFTY = GAME_HEIHGT / 0 + 202;				//��y	

		const int DIRECTIONLEFT = 0;
		const int DIRECTIONRIGHT = 1;
		const int DIRECTIONUP = 2;
		const int DIRECTIONDOWN = 3;

		const int MAX_TYPE_NUM = 2;

		static const int COUNT = 10;								//���ۂ̃J�E���g�_�E��
		static const int COUNTMAX = FRAME * (COUNT + 1) - 1;

		float speed;					//���e����������X�s�[�h
		float x;
		float y;
		float cx;
		float cy;
		float width;
		float height;
		int sx;
		int sy;
		int time;
		int power;						//���e�̃_���[�W
		int damage;
		int countDown;					//�J�E���g�_�E��
		int direction;					//���e�����������
		int type;						//���e�̎��
		int pType;
		int sTime;
		int m_frameIndex = 0;

		bool isXplosion;				//�����������ǂ���
		bool isTrigger;					//�������Ă邩���ĂȂ���
		bool isSpown;					//���e�̐����������ǂ���
		bool isCount;					//�J�E���g�_�E����\�������邽��
		bool isStopCount;
		bool AnimationFlg;
		bool isPAbility;
		bool isHit;

	public:
		BaseBomb() {}
		~BaseBomb();
		BaseBomb(int _power, int _speed, eBombType _bombType);

		void SpawnBomb();								//���e�̐���
		void JudgeTrigger();							//�����������̔���
		void Move();									//���e�̗���
		void SkillStop();

		bool ClisionHit(float mx, float my, float mw, float mh,
			float ox, float oy, float ow, float oh);

		int GetPower() { return power; }							
		bool GetIsTriggerFlg() { return isActive; }
		virtual void Update(BasePlayer*) {}
		virtual void Draw() {}
	};
#endif // !_BASEBOMB_H