#ifndef AR_GAMEMAIN_H
#define AR_GAMEMAIN_H

#include "SceneManager.h"
#include "GameResource.h"
#include "Parameter.h"

#include "Title.h"
#include "Menu.h"
#include "CharaSelect.h"
#include "Option.h"
#include "OperationExp.h"
#include "LevelSelect.h"
#include "GameScene.h"
#include "GameClear.h"
#include "GameOver.h"
#include "Pausemenu.h"

class GameMain {
	Parameter* parameter;	//パラメータ
	SceneManager* sManager;	//シーンマネージャー
	GameResource gameRes;	//ゲームリソース

	Title title;				//タイトルシーン
	Menu menu;					//メニューシーン
	CharaSelect cSelect;		//キャラ選択シーン
	Option option;				//設定シーン
	OperationExp opExp;			//操作説明シーン
	LevelSelect levelSelect;	//難易度選択シーン
	GameScene inGame;			//ゲームシーン
	GameClear gameClear;		//ゲームクリアシーン
	GameOver gameOver;			//ゲームオーバーシーン
	Pausemenu pauseMenu;		//ポーズメニューシーン

	int fadeCnt;
public:
	GameMain();
	~GameMain();
	void Init();
	bool GameLoop();
};

#endif // !AR_GAMEMAIN_H