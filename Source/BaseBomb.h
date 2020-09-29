#ifndef _BASEBOMB_H
#define _BASEBOMB_H

#include "Define.h"
#include "BaseEvent.h"
#include "CastleManager.h"
#include "FontHandle.h"
#include "SE.h"

class castleManager;

	enum eBombType
	{
		bomb = 1,
		fakebomb = 2,
	};
	
	class BaseBomb : public virtual BaseEvent
	{
	protected:
		const float BOMB_SPOWNUPDOWNX = GAME_WIDTH / 2 - 25;				//�㉺x
		const float BOMB_SPOWNLEFTHX = GAME_WIDTH / 2 - 120;				//��x
		const float BOMB_SPOWNRIGHTX = GAME_WIDTH / 2 + 60;					//�Ex
		const float BOMB_SPOWNUPY = GAME_HEIHGT / 0 - 30;					//��y
		const float BOMB_SPOWNDOWNY = GAME_HEIHGT + 30;						//��y
		const float BOMB_SPOWNLR = GAME_HEIHGT / 0 - 30;					//���Ey	

		const int DIRECTIONLEFT = 0;
		const int DIRECTIONRIGHT = 1;
		const int DIRECTIONUP = 2;
		const int DIRECTIONDOWN = 3;

		const int MAX_TYPE_NUM = 2;

		static const int COUNT = 2;								//���ۂ̃J�E���g�_�E��
		static const int COUNTMAX = FRAME * (COUNT + 1) - 1;

		float speed;					//���e����������X�s�[�h
		float x;
		float y;
		int time;
		int power;						//���e�̃_���[�W
		int damage;
		int countdown;					//�J�E���g�_�E��
		int put;
		int direction;					//���e�����������
		int type;						//���e�̎��

		int alpha;
		int rad;

		bool isXplosion;				//�����������ǂ���
		bool isTrigger;					//�������Ă邩���ĂȂ���
		bool isSpown;					//���e�̐����������ǂ���
		bool isCount;					//�J�E���g�_�E����\�������邽��

	public:
		BaseBomb() {}
		~BaseBomb();
		BaseBomb(int _power, int _speed, eBombType _bombType);

		void SpawnBomb();								//���e�̐���
		void JudgeTrigger();							//�����������̔���
		void Move();									//���e�̗���

		int GetPower() { return power; }							
		bool GetIsTriggerFlg() { return isTrigger; }
		virtual void Update() {}
		virtual void Draw() {}

	};
#endif // !_BASEBOMB_H