#ifndef _SUKIMAEVENT_H
#define _SUKIMAEVENT_H

#include <DxLib.h>
#include "BaseEvent.h"

class EnemyManager;

class SukimaEvent : public virtual BaseEvent {
private:
	static const int UP_X = 450;		//�X�L�}�̔����ꏊ��
	static const int UP_Y = 150;		//�X�L�}�̔����ꏊ��
	static const int DOWN_X = 450;	    //�X�L�}�̔����ꏊ��
	static const int DOWN_Y = 650;	    //�X�L�}�̔����ꏊ��
	static const int LEFT_X = 150;	    //�X�L�}�̔����ꏊ��
	static const int LEFT_Y = 350;      //�X�L�}�̔����ꏊ��
	static const int RIGHT_X = 750;	    //�X�L�}�̔����ꏊ�E
	static const int RIGHT_Y = 350;     //�X�L�}�̔����ꏊ�E

	//object�p�����ĂȂ��̂�
	float x;
	float y;
	float width;
	float height;

	//���[�v��̏ꏊ
	float warpPosX;
	float warpPosY;

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
