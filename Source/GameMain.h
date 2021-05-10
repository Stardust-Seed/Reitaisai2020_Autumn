#ifndef AR_GAMEMAIN_H
#define AR_GAMEMAIN_H

#include "SceneManager.h"
#include "GameResource.h"

class GameMain {
	SceneManager* sManager;	//シーンマネージャー
	GameResource gameRes;	//ゲームリソース

	eScene nowScene;
	int fadeCnt;
public:
	GameMain();
	~GameMain();
	void Init();
	bool GameLoop();
};

#endif // !AR_GAMEMAIN_H