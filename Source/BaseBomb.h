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
		const float BOMB_SPOWNUPX = GAME_WIDTH / 2 - 176;     			    //��x
		const float BOMB_SPOWNDOWNX = GAME_WIDTH / 2 + 200;   			    //��x
		const float BOMB_SPOWNLEFTHX = GAME_WIDTH / 2 - 1050;				//��x
		const float BOMB_SPOWNRIGHTX = GAME_WIDTH / 2 + 1050;				//�Ex
		const float BOMB_SPOWNUPY = GAME_HEIHGT / 0 - 30;					//��y
		const float BOMB_SPOWNDOWNY = GAME_HEIHGT + 200;					//��y
		const float BOMB_SPOWNRIGHTY = GAME_HEIHGT / 0 + 867;				//�Ey	
		const float BOMB_SPOWNLEFTY = GAME_HEIHGT / 0 + 202;				//��y	

		//����(�΂߂�����ł���㉺���E)
		const int DIRECTIONLEFT = 0;
		const int DIRECTIONRIGHT = 1;
		const int DIRECTIONUP = 2;
		const int DIRECTIONDOWN = 3;

		static const int COUNT = 3;									//���ۂ̃J�E���g�_�E��
		static const int COUNTMAX = FRAME * (COUNT + 1) - 1;		//�t���[��

		float speed = 0;					//���e����������X�s�[�h
		float x;
		float y;
		float cx;						//���Sx
		float cy;						//���Sy
		float width;					//��
		float height;					//����

		int tX = 0;						//�^�C�}�[��x
		int tY = 0;						//�^�C�}�[��y
		int time = 0;					//��������܂ł̃^�C��
		int power = 0;					//���e�̃_���[�W								
		int countDown = 0;				//�J�E���g�_�E��
		int direction = 0;				//���e�����������
		int pType = 0;					//��邳�񂩂ǂ���
		int sTime  = 0;					//���~�ߎ��̃X�g�b�v�^�C��
		int m_frameIndex = 0;			//�A�j���V�����̃t���[��
		eBombType type;					//���e�̎��

		bool isXplosion;				//�����������ǂ���
		bool isTrigger;					//�������Ă邩���ĂȂ���
		bool isSpawn;					//���e�̐����������ǂ���
		bool isCount;					//�J�E���g�_�E����\�������邽��
		bool isStopCount;				//�J�E���g���X�g�b�v�����邽�߂̔���
		bool AnimationFlg;				//�A�j���V�����̊J�n�����锻��
		bool isPAbility;				//�v���C���[�̃X�L������������������
		bool isHit;						//�v���C���[�����e�ɓ����������̔���

	public:
		BaseBomb() {}
		~BaseBomb();
		BaseBomb(int _power, float _speed, eBombType _bombType);

		void SpawnBomb();								//���e�̐���
		void JudgeTrigger();							//�����������̔���
		void Move();									//���e�̗���
		void SkillStop();								//���~�ߎ�

		bool ClisionHit(float mx, float my, float mw, float mh,
			float ox, float oy, float ow, float oh);

		int GetPower() { return power; }				//���e�̃_���[�W���󂯎��
		bool GetIsTriggerFlg() { return isTrigger; }	//�������������󂯎��
		virtual void Update(BasePlayer*) {}
		virtual void Draw() {}
	};
#endif // !_BASEBOMB_H