#include "DxLib.h"
#include "MainCastle.h"
#include "EnemyManager.h"

//コンストラクタ
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

    //一回だけ処理する用のフラグ処理
    if (isHit == true)
    {
        isHit = false;
    }

    //耐久の処理
    if (durability <= 0)
    {
        isActive = false;
    }
}

//拠点の描画
void MainCastle::Draw()
{
    //拠点の描画
	if (isActive == true)
	{
		DrawGraph(x, y, Image::Instance()->GetGraph(eImageType::Gpicture_MainCastle), TRUE);
	}
}
