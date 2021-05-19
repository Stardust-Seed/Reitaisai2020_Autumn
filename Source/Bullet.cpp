#include"DxLib.h"
#include"Object.h"
#include"Bullet.h"
#include"Define.h"
#include"BaseEnemy.h"
#include"EnemyManager.h"

Bullet::Bullet(VECTOR& position, int pl_type,eDirection pl_direction, bool pl_attack,int pl_power,int shotpower)
{
	//弾の発生位置
	pos.x = position.x + 12;

	pos.y = position.y + 12;

	//進む方向
	bullet_Move = pl_direction;

	//発射中かどうか
	isActive = pl_attack;


	//攻撃力
	power = pl_power;

	//チャージゲージ
	shotPower = shotpower;

	//画像
	bulletGraph = pl_type;

	//画像回転
	graphAngle = 4;

	//幅
	width = 24;

	//縦
	height = 24;

	//当たり判定
	isHit = false;
}
Bullet::~Bullet()
{

}
//当たり判定
bool Bullet::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh)
{
	if (mx <= (ox + ow) && my <= (oy + oh) &&
		ox <= (mx + mw) && oy <= (my + mh))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Bullet::Draw()
{

	//弾の描画   PL * 2 = 左  PI * 2.5 上 PI* * 3.0 右 PI * 4.0 下 
	DrawRotaGraph(pos.x+12, pos.y+12, 1.0,  PI * graphAngle, Image::Instance()->GetGraph(eImageType::Gpicture_Bullet, bulletGraph), TRUE); //画像の描画

}
void Bullet::Update(EnemyManager* _eManager,BasePlayer* _basePlayer)
{

	if (isActive == true) {
		//チャージゲージがMAXなら攻撃力UP
		if (shotPower == 100)
		{
			power = 200;
		}
		else
		{
			power = _basePlayer->Get_power();
		}
		if (bullet_Move == eDirection::Left)
		{
			//弾の角度を変える
			graphAngle = 2.0;
			//左方向へ飛んでいく
			pos.x -= 3.0f;
		}
		if (bullet_Move == eDirection::Up)
		{
			//弾の角度を変える
			graphAngle = 2.5;
			//上方向へ飛んでいく
			pos.y -= 3.0f;
		}
		if (bullet_Move == eDirection::Right)
		{
			//弾の角度を変える
			graphAngle = 3.0;
			//右方向へ飛んでいく
			pos.x += 3.0f;
		}
		if (bullet_Move == eDirection::Down)
		{
			//弾の角度を変える
			graphAngle = 3.5;
			//下方向へ飛んでいく
			pos.y += 3.0f;
		}
	}

	//画面外に出たらフラグをfalseにする
	if (pos.x > GAME_WIDTH || pos.x < 0)
	{
		isActive = false;
	}
	if (pos.y > GAME_HEIHGT || pos.y < 0)
	{
		isActive= false;
	}
	for (int i = 0; i < _eManager->Get_enemyNum(); i++) {  //エネミー
		if (ClisionHit(Get_x(), Get_y(), Get_width(), Get_height(),
			_eManager->Get_x(i), _eManager->Get_y(i), _eManager->Get_width(i), _eManager->Get_height(i))) 
		{
			isHit = true;
		}
	}
	if (ClisionHit(Get_x(), Get_y(), Get_width(), Get_height(), //メイン城
		900, 480, 94, 94))
	{
		isActive = false;
	}
}
