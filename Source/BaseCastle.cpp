#include "BaseCastle.h"

const int BaseCastle::MAX_DURABILITY = 100;		//�ő�ϋv��	

//�R���X�g���N�^
BaseCastle::BaseCastle(int _durability){
	direction = 0;
	durability = _durability;
	isActive = true;
	isHit = false;

}

//���_���_���[�W���󂯂��Ƃ��̏���
bool BaseCastle::ClisionHit(float ox, float oy, float ow, float oh,
	int pow, int num, bool attackFlg, bool activeFlg)
{
	if (x + width >= ox && x <= ox + ow &&
		y + height >= oy && y <= oy + oh &&
		attackFlg == true && activeFlg == true)
	{
		//��񂾂�����
		if (isHit == false)
		{
			durability -= pow;
			isHit = true;
			return isHit;
		}

	}

	//��񂾂���������p�̃t���O����
	if (isHit == true)
	{
		isHit = false;
	}

	//�ϋv�̏���
	if (durability <= 0)
	{
		isActive = false;
	}

	return isHit;
}

