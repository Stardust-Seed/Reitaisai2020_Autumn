#ifndef _BASEBOMB_H
#define _BASEBOMB_H

#include "Define.h"

	enum eBombType
	{
		bomb,
		fakebomb,
	};
	
	class BaseBomb
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
		int countdown;					//�J�E���g�_�E��
		int put;
		int direction;					//���e�����������
		int type;						//���e�̎��

		bool isXplosion;				//�����������ǂ���
		bool isTrigger;					//�������Ă邩���ĂȂ���
		bool isFakeTrigger;				//�������Ă邩���ĂȂ���(�U)
		bool isSpown;					//���e�̐����������ǂ���
		bool isFakeSpown;				//���e�̐����������ǂ���(�U)

	public:
		BaseBomb() {}
		~BaseBomb();
		BaseBomb(int _power, eBombType _btype);

		void SpawnBomb();								//���e�̐���
		void JudgeTrigger();							//�����������̔���
		void Move();									//���e�̗���
		void SetIsTrigger(bool _isTrigger) { isTrigger = _isTrigger; }

		int GetPower() { return power; }							
		bool GetIsTrigger() { return isTrigger; }
		virtual void Update() = 0;
		virtual void Draw() = 0;

	};
#endif // !_BASEBOMB_H