#include "DxLib.h"
#include "MainCastle.h"
#include "EnemyManager.h"

//�R���X�g���N�^
MainCastle::MainCastle(int _durability)
	:BaseCastle(_durability) {

	durability = _durability;
	width = 120;
	height = 120;
	x = GAME_WIDTH / 2 - width / 2;       //1920 / 2 - 120 / 2 = 900
	y = GAME_HEIHGT / 2 - height / 2;     //1080 / 2 - 120 / 2 = 480

}

void MainCastle::Update(EnemyManager* enemy)
{
    for (int num = 0; num < enemy->Get_enemyNum(); num++)
    {
        if (enemy->Get_ActiveFlg(num) == true && enemy->Get_AttackFlg(num) == true &&
            enemy->Get_AttackType(num) != eAttackType::Player)
        {
            ClisionHit(enemy->Get_x(num)        , enemy->Get_y(num)         , enemy->Get_width(num),
                       enemy->Get_height(num)   , enemy->Get_Power(num)     , num,
                       enemy->Get_AttackFlg(num), enemy->Get_ActiveFlg(num) );
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
}

//���_�̕`��
void MainCastle::Draw()
{
    //���_�̕`��
	if (isActive == true)
	{
		DrawGraph(x, y, Image::Instance()->GetGraph(eImageType::Gpicture_MainCastle), TRUE);
	}
}
