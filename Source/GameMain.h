#ifndef AR_GAMEMAIN_H
#define AR_GAMEMAIN_H

class BasePlayer;
class BulletManager;

class GameMain {

	//自機のポインタ変数を作成
	BasePlayer* player;

	//弾管理のポインタ変数作成
	BulletManager* bulletManager;

public:
	GameMain();
	~GameMain();
	void Init();
	bool GameLoop();
};

#endif // !AR_GAMEMAIN_H