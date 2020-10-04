#ifndef _GAMEOVER_H_
#define _GAMEOVER_H_

#include "BaseScene.h"
#include "Input.h"
#include "Image.h"
#include "BGM.h"
#include "SE.h"
#include "Define.h"
#include "FontHandle.h"
#include "Cursor.h"

class GameOver :public virtual BaseScene{

private:
	const static int GAME_X;    //�R���e�B�j���[����ƕ\������e�L�X�g��Y���W
	const static int MENU_X;    //�R���e�B�j���[���Ȃ��ƕ\������e�L�X�g��Y���W

	Cursor nowCursor;           //���ݑI�𒆂̃J�[�\��
	int x;                      //�J�[�\���\���p��X���W
	int alpha;                  //�����x
	int charaType;              //�L�����^�C�v
public:
	GameOver(ISceneChanger* _sceneChanger, Parameter* _parameter);
	void Update();				//�X�V����
	void Draw();				//�`�揈��
	void Select();              //�I������
	void Move();                //�����̏���
};

#endif //GAMEOVER_H_