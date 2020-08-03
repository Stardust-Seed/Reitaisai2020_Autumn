#ifndef _ENEMYMANAGER_H
#define _ENEMYMANAGER_H

#include "Fairy_Endurance.h"
#include "Fairy_Speed.h"

class Castle;
class BasePlayer;

Castle* _castle;
BasePlayer* _player;

class EnemyManager {
private:
	static const int POPENEMY_EASY = 2;		//難易度別画面内の生成数

	static const int POPENEMY_NORMAL = 3;	//3体まで

	static const int POPENEMY_HARD = 4;		//4体まで

	static const int ENEMY_NUM = POPENEMY_EASY;

	Fairy_Endurance* Fairy_E[ENEMY_NUM];
	//体力型エネミーオブジェクト配列
public:
	EnemyManager();					//コンストラクタ

	~EnemyManager();				//デストラクタ

	void SpawnEnemy();				//エネミー生成処理

	void Update();					//更新処理

	void Draw();					//描画処理

	void Set_x(float _x);				//x座標をセット

	void Set_y(float _y);				//y座標をセット

	void Set_width(float _width);		//幅をセット

	void Set_height(float _height);	//高さをセット

	int Get_ActiveFlg(int);			//アクティブかを受け取る

	int Get_Power(int);				//攻撃力を受け取る

	int Get_x(int);					//x座標を受け取る

	int Get_y(int);					//y座標を受け取る

	int Get_width(int);				//幅を受け取る

	int Get_height(int);				//高さを受け取る
};
#endif // !_ENEMYMANAGER_H
