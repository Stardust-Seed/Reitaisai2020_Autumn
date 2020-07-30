#ifndef _ENEMYMANAGER_H
#define _ENEMYMANAGER_H

class EnemyManager {
private:
	static const int POPENEMY_EASY = 2;		//難易度別画面内の生成数

	static const int POPENEMY_NORMAL = 3;	//3体まで

	static const int POPENEMY_HARD = 4;		//4体まで

public:
	EnemyManager();					//コンストラクタ

	~EnemyManager();				//デストラクタ

	void SpawnEnemy();				//エネミー生成処理

	void Update();					//更新処理

	void Draw();					//描画処理

	int Get_ActiveFlg(int);			//アクティブかを受け取る

	int Get_Power(int);				//攻撃力を受け取る

	int Get_x();					//x座標を受け取る

	int Get_y();					//y座標を受け取る

	int Get_width();				//幅を受け取る

	int Get_height();				//高さを受け取る

	int Set_x(int _x);				//x座標をセット

	int Set_y(int _y);				//y座標をセット

	int Set_width(int _width);		//幅をセット

	int Set_height(int _height);	//高さをセット
};
#endif // !_ENEMYMANAGER_H
