#include <DxLib.h>
#include "BaseBomb.h"

//�R���X�g���N�^
BaseBomb::BaseBomb(float _speed, int _damage, int _direction, int _countdown)
{
	speed = _speed;
	damage = _damage;
	direction = _direction;
	countdown = _countdown;

	isSpown = true;
	isTrigger = false;

	if (direction == DIRECTIONLEFT)			//��
	{
		x = BOMB_SPOWNLEFTHX;
		y = BOMB_SPOWNLR;
	}

	if (direction == DIRECTIONRIGHT)		//�E
	{
		x = BOMB_SPOWNRIGHTX;
		y = BOMB_SPOWNLR;
	}

	if (direction == DIRECTIONUP)			//��
	{
		x = BOMB_SPOWNUPDOWNX;
		y = BOMB_SPOWNUPY;
	}

	if (direction == DIRECTIONDOWN)			//��
	{
		x = BOMB_SPOWNUPDOWNX;
		y = BOMB_SPOWNDOWNY;
	}
}

/*void BaseBomb::SpawnBomb() 
{
	bool isSpawn = false;    //��������t���O

	for (int i = 0; i < 1; i++) {
		//items[i]����̏ꍇ
		if (bombs[i] == null) {
			int spawnPercent = GetRand(100);    //�����m��

			//50�ȉ��̏ꍇ��������t���O��true�ɂ���
			if (spawnPercent > 50) {
				isSpawn = true;
			}

			//��������t���O��true�̏ꍇ
			if (isSpawn == true) {
				int spawnType = GetRand(1); 


				if (spawnType == static_cast<int>(eBombType::Bomb)) {
					bombs[i] = new Bomb(_ex, _ey, 48, 48, eBombType::Bomb);
				}

				
				if (spawnType == static_cast<int>(eBombType::fakeBomb)) {
					bombs[i] = new fakeBomb(_ex, _ey, 48, 48, eBombType::fakeBomb);
				}
			}

			break;
		}
	}
}*/

void BaseBomb::JudgeTrigger()
{

}

void BaseBomb::Move()
{
	if (isSpown == false) {
		return;
	}

	if (direction == DIRECTIONLEFT)			//��
	{		
		y += speed;
	}

	if (direction == DIRECTIONRIGHT)		//�E
	{
		y += speed;
	}

	if (direction == DIRECTIONUP)			//��
	{
		y += speed;
	}

	if (direction == DIRECTIONDOWN)			//��
	{
		y += speed;
	}
}

