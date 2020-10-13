#ifndef _SUKIMAEVENT_H
#define _SUKIMAEVENT_H

#include "BaseEvent.h"
#include "Define.h"
#include "Direction.h"
#include "Image.h"
#include "SE.h"

class EnemyManager;
class BasePlayer;

class SukimaEvent : public virtual BaseEvent {
private:
	static const int UP_X = GAME_WIDTH  / 2;		     //�X�L�}�̔����ꏊ��
	static const int UP_Y = GAME_HEIHGT / 2 - 460;		 //�X�L�}�̔����ꏊ��

	static const int DOWN_X = GAME_WIDTH  / 2;	         //�X�L�}�̔����ꏊ��
	static const int DOWN_Y = GAME_HEIHGT / 2 + 460;	 //�X�L�}�̔����ꏊ��

	static const int LEFT_X = GAME_WIDTH  / 2 - 460;	 //�X�L�}�̔����ꏊ��
	static const int LEFT_Y = GAME_HEIHGT / 2;           //�X�L�}�̔����ꏊ��

	static const int RIGHT_X = GAME_WIDTH  / 2 + 460;    //�X�L�}�̔����ꏊ�E
	static const int RIGHT_Y = GAME_HEIHGT / 2;          //�X�L�}�̔����ꏊ�E

	//object�p�����ĂȂ��̂�
	float x;
	float y;
	float width;
	float height;
	float addSize;

	//���[�v��̏ꏊ
	float warpPosX;
	float warpPosY;

	//�����蔻��
	bool isHit;
	int hitNum;

	//�X�L�}�̏ꏊ
	int type;

	//���R���ŗp�J�E���g
	int deleteCnt;

	//���~�ߎ��p�̃t���O

	bool sakuyaSkill;

	//�A�j���[�V�����Đ��p
	bool popFlg;
	bool deleteFlg;
	bool animationFlg;
	int warpAnimationCnt;
	int popAnimationCnt;
	int animation[62] = { 4,0,0,0,0,0,1,1,1,1,1,
						  2,2,2,2,2,3,3,3,3,3,
		                  3,3,3,3,3,3,3,3,3,3,
		                  3,3,3,3,3,3,3,3,3,3,
				       	  3,3,3,3,3,2,2,2,2,2,
		                  1,1,1,1,1,0,0,0,0,0,4 };
public:
	SukimaEvent();
	~SukimaEvent();
	void Update(EnemyManager*,BasePlayer*);		//�X�V
	void Draw();	            	//�`��
	void Animation();               //�A�j���[�V����
	//�����蔻��
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);
};

#endif // !_SUKIMAEVENT_H
