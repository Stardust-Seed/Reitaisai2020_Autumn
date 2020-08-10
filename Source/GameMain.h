#ifndef AR_GAMEMAIN_H
#define AR_GAMEMAIN_H

class BasePlayer;
class BulletManager;

class GameMain {

	//���@�̃|�C���^�ϐ����쐬
	BasePlayer* player;

	//�e�Ǘ��̃|�C���^�ϐ��쐬
	BulletManager* bulletManager;

public:
	GameMain();
	~GameMain();
	void Init();
	bool GameLoop();
};

#endif // !AR_GAMEMAIN_H