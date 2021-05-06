#ifndef _ENEMYBOMB_H
#define _ENEMYBOMB_H

#include "Object.h"

class Player;
class EnemyManager;
class CastleManager;

//爆破タイプ
enum class eExType {
	Immediately,		//即爆破
	Installation		//設置
};

//エネミーの爆弾クラス
class EnemyBomb : public Object {
private:
	bool isActive;			//アクティブフラグ

	const int EXTIME = 180;	//爆破までのタイム
	int exCnt;				//爆破カウント
	float exAreaSize;		//爆破範囲のサイズ
	bool isExplosion;		//爆破フラグ

	const int EFFECT_MAX_NUM = 8;	//エフェクトの最大数
	int* effectArray;				//エフェクト描画用配列
	int effectIndex;				//エフェクト描画用配列のindex指定用

	//当たり判定処理
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);
public:
	//コンストラクタ
	EnemyBomb(float _x, float _y, eExType _exType);

	void Update(Player* _player, CastleManager* _castleManager,
		EnemyManager* _enemyManager);

	//描画処理
	void Draw();

	//アクティブフラグを取得する
	bool Get_IsActive() { return isActive; }
};

#endif // !_ENEMYBOMB_H
