#include "BaseCastle.h"

const int BaseCastle::MAX_DURABILITY = 100;		//�ő�ϋv��	

//�R���X�g���N�^
BaseCastle::BaseCastle(int _durability){

	durability = _durability;
	isActive = true;
	isHit = false;
	enemySpeed = 0;
	enemyPower = 0;
	enemyDurability = 0;
	enemyDirection = 0;

}