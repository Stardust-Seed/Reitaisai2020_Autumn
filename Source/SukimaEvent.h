#ifndef _SUKIMAEVENT_H
#define _SUKIMAEVENT_H

#include "BaseEvent.h"
#include "Define.h"
#include "Direction.h"

class EnemyManager;

class SukimaEvent : public virtual BaseEvent {
private:
	static const int UP_X = GAME_WIDTH  / 2;		     //�X�L�}�̔����ꏊ��
	static const int UP_Y = GAME_HEIHGT / 2 - 300;		 //�X�L�}�̔����ꏊ��

	static const int DOWN_X = GAME_WIDTH  / 2;	         //�X�L�}�̔����ꏊ��
	static const int DOWN_Y = GAME_HEIHGT / 2 + 300;	 //�X�L�}�̔����ꏊ��

	static const int LEFT_X = GAME_WIDTH  / 2 - 300;	 //�X�L�}�̔����ꏊ��
	static const int LEFT_Y = GAME_HEIHGT / 2;           //�X�L�}�̔����ꏊ��

	static const int RIGHT_X = GAME_WIDTH  / 2 + 300;    //�X�L�}�̔����ꏊ�E
	static const int RIGHT_Y = GAME_HEIHGT / 2;          //�X�L�}�̔����ꏊ�E

	//object�p�����ĂȂ��̂�
	float x;
	float y;
	float width;
	float height;

	//���[�v��̏ꏊ
	float warpPosX;
	float warpPosY;

	int cnt;
	bool isHit;
public:
	SukimaEvent();
	~SukimaEvent();
	void Update(EnemyManager*);		//�X�V
	void Draw();	            	//�`��
	void Animation();               //�A�j���[�V����
	//�����蔻��
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);
};

#endif // !_SUKIMAEVENT_H
