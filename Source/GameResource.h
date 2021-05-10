#ifndef _GAMERESOURCE_H
#define _GAMERESOURCE_H

class BasePlayer;
class BuffManager;
class BulletManager;
class CastleManager;
class EnemyManager;
class EventManager;
class ItemManager;
class TimeLimit;

//�Q�[�����\�[�X�\����
typedef struct {
	BasePlayer*			player;			//�v���C���[
	BuffManager*		buffManager;	//�o�t�Ǘ��N���X
	BulletManager*		bulletManager;	//�e�Ǘ��N���X
	CastleManager*		castleManager;	//��Ǘ��N���X
	EnemyManager*		enemyManager;	//�G�Ǘ��N���X
	EventManager*		eventManager;	//�C�x���g�Ǘ��N���X
	ItemManager*		itemManager;	//�A�C�e���Ǘ��N���X
	TimeLimit*			timeLimit;		//�������ԃN���X
}GameResource;

#endif // !_GAMERESOURCE_H