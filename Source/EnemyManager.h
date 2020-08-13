#ifndef _ENEMYMANAGER_H
#define _ENEMYMANAGER_H

#include "Fairy_Endurance.h"
#include "Fairy_Speed.h"

class Castle;

class BasePlayer;

class BaseEnemy;

class Fairy_Endurance;

class Fairy_Speed;

class EnemyManager {
private:
	static const int POPENEMY_EASY = 2;		//難易度別画面内の生成数

	static const int POPENEMY_NORMAL = 3;	//3体まで

	static const int POPENEMY_HARD = 4;		//4体まで

	static const int ENEMY_TYPES = 2;		//現在のエネミーの種類

	static const int MAX_ENEMY_NUM = 4;			//エネミーの最大生成数分の要素数

	BaseEnemy* Enemys[MAX_ENEMY_NUM];			//エネミーオブジェクト配列

	int enemyType;					//ランダムな値を入れる

	int enemyNum;					//難易度別生成数を入れる

	int _durability;				//体力
	
	int _direction;					//方向
	
	float _speed;					//速度
	
	float _power;					//パワー

public:
	EnemyManager(int);					//コンストラクタ

	~EnemyManager();				//デストラクタ

	void SpawnEnemy();				//エネミー生成処理

	void Update(Castle*,BasePlayer*);					//更新処理

	void Draw();					//描画処理

	void Set_x(int,float _x);				//x座標をセット

	void Set_y(int,float _y);				//y座標をセット

	void Set_width(int,float _width);		//幅をセット

	void Set_height(int,float _height);	//高さをセット

	int Get_ActiveFlg(int);			//アクティブかを受け取る

	int Get_Power(int);				//攻撃力を受け取る

	int Get_x(int);					//x座標を受け取る

	int Get_y(int);					//y座標を受け取る

	int Get_width(int);				//幅を受け取る

	int Get_height(int);			//高さを受け取る

};
#endif // !_ENEMYMANAGER_H
