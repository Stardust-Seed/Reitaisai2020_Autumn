#ifndef _DARKNESSEVENT_H
#define _DARKNESSEVENT_H

#include <DxLib.h>
#include "BaseEvent.h"

class DarknessEvent : public virtual BaseEvent {
private:
	static const int FREAM = 60; //�t���[����

	static const int MAX_DARKNESSTIME = 15 * FREAM;	//�ÈŎ��ԁ@�b * �t���[����

	static const int MAX_OPACITY = 255;		//�ő�s�����x

	static const int PHASE_START = 0;		//�J�n�t�F�[�Y�@�s�����x��������

	static const int PHASE_DARK = 1;		//�ێ��t�F�[�Y�@�s�����x���ێ�

	static const int PHASE_END = 2;			//�I���t�F�[�Y�@�s�����x��������

	int darkCount;		//�o�ߎ���

	int phase;			//���݂̃t�F�[�Y

	int opacity;		//�s�����x

	int darkImage;		//�摜�i�[�p

public:
		DarknessEvent();	//�R���X�g���N�^

		~DarknessEvent();	//�f�X�g���N�^

		void Update();		//�X�V

		void Draw();		//�`��
};


#endif // !_DARKNESSEVENT_H
