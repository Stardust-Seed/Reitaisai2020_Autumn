#ifndef AR_GAMEMAIN_H
#define AR_GAMEMAIN_H

#include "SceneManager.h"

class GameMain {
	SceneManager sManager;	//�V�[���}�l�[�W���[

	eScene nowScene;
	int fadeCnt;
public:
	GameMain();
	~GameMain();
	void Init();
	bool GameLoop();
};

#endif // !AR_GAMEMAIN_H