#ifndef _DARKNESSEVENT_H
#define _DARKNESSEVENT_H

#include <DxLib.h>
#include "BaseEvent.h"
#include "Define.h"


class DarknessEvent : public virtual BaseEvent {
private:

	static const int MAX_DARKNESSTIME = 15 * FRAME;	//�ÈŎ��ԁ@�b * �t���[����

	static const int MAX_OPACITY = 255;		//�ő�s�����x

	enum PHASE {
		PHASE_START,	//�J�n�t�F�[�Y�@�s�����x��������
		PHASE_DARK,		//�ێ��t�F�[�Y�@�s�����x���ێ�
		PHASE_END		//�I���t�F�[�Y�@�s�����x��������
	};

	PHASE nowPhase;		//���݂̃t�F�[�Y

	int darkCount;		//�o�ߎ���

	int opacity;		//�s�����x

public:
	DarknessEvent();	//�R���X�g���N�^

	~DarknessEvent();	//�f�X�g���N�^

	void Update();		//�X�V

	void Draw();		//�`��
};


#endif // !_DARKNESSEVENT_H
