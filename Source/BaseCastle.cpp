#include "BaseCastle.h"
#include "EnemyManager.h"
#include "Define.h"
const int BaseCastle::MAX_DURABILITY = 100;		//Å‘å‘Ï‹v—Í	


BaseCastle::BaseCastle(int _durability){
durability = _durability;
isActive = true;
isHit = false;
width = 120;
height = 120;
x = GAME_WIDTH / 2 - width / 2;
y = GAME_HEIHGT / 2 - height / 2;

}

void BaseCastle::Set_IsActive(bool _flg)
{
	isActive = _flg;
}

void BaseCastle::Set_Durability(int _durability) 
{
	durability = _durability;
}

