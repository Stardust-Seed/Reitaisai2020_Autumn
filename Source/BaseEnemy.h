#ifndef _BASEENEMY_H
#define _BASEENEMY_H

#include "Direction.h"
#include "Object.h"

class CastleManager;
class BasePlayer;
class BulletManager;

/// <summary>
/// 非アクティブのタイプ
/// </summary>
enum class eInactiveType {
	Defeat,		//撃破
	Invasion,	//侵入
	None		//初期化用
};

/// <summary>
/// BaseEnemy class
/// </summary>
class BaseEnemy :public virtual Object {
protected:
	static const float ENEMY_SPAWNXLEFT;	//エネミーの初期位置X左
	static const float ENEMY_SPAWNYLEFT;	//エネミーの初期位置Y左
	static const float ENEMY_SPAWNXUP;		//エネミーの初期位置X上
	static const float ENEMY_SPAWNYUP;		//エネミーの初期位置Y上
	static const float ENEMY_SPAWNXRIGHT;	//エネミーの初期位置X右
	static const float ENEMY_SPAWNYRIGHT;	//エネミーの初期位置Y右
	static const float ENEMY_SPAWNXDOWN;	//エネミーの初期位置X下
	static const float ENEMY_SPAWNYDOWN;	//エネミーの初期位置Y下

	float speed;			//エネミーの移動速度
	float power;			//エネミーの攻撃力
	int durability;			//エネミーの体力
	eDirection direction;	//エネミーの進行方向

	bool isCoolDown;	//クールダウンフラグ

	bool isAttack;		//エネミーの攻撃フラグ
	bool isActive;		//エネミーの生存フラグ

	eInactiveType inactiveType;	//非アクティブのタイプ
public:
	BaseEnemy(){}
	virtual ~BaseEnemy(){}
	BaseEnemy(float _speed, float _power, int _durability, eDirection _direction);
	BaseEnemy(float _speed, float _power, int _durability, eDirection _direction, float _x, float _y);

	virtual void Update(CastleManager* _castleManager, BasePlayer* _player,
		BulletManager* _bulletManager) {}							//更新処理
	virtual void Draw() {}											//描画処理

	void Move();	//移動処理

	void SearchCastle(float _ox, float _oy, float _ow, float _oh, bool _isActive);	//城の範囲内かサーチ
	void SearchPlayer(float _px, float _py, float _pw, float _ph,
		BasePlayer* _player);										//プレイヤーが攻撃範囲内かサーチ
	void SearchCoolDownTime();		//サーチのクールダウン
	void JudgeActive();				//アクティブかを判断する
	void AttackProc();				//攻撃中の時間処理
	void DamageProc(int _damage);	//ダメージ処理

	void Set_X(float _x) { x = _x; }							//x座標を設定する
	void Set_Y(float _y) { y = _y; }							//y座標を設定する
	void Set_Width(float _width) { width = _width; }			//widthを設定する
	void Set_Height(float _height) { height = _height; }		//heightを設定する
	void SetIsAttack(bool _isAttack) { isAttack = _isAttack; }	//isAttackを設定する
	void SetIsActive(bool _isActive) { isActive = _isActive; }	//isActiveを設定する
	void SetDirection(eDirection _direction) { direction = _direction; }

	float Get_X() { return x; }									//x座標を取得する
	float Get_Y() { return y; }									//y座標を取得する
	float Get_Width() { return width; }							//widthを取得する
	float Get_Height() { return height; }						//heightを取得する
	float GetPower() { return power; }							//エネミーの攻撃力を取得する
	bool GetIsActive() { return isActive; }						//生存フラグを取得する
	bool GetIsAttack() { return isAttack; }						//アタックフラグを取得する
	//bool GetTset() { return isCoolDown; }
	eDirection GetDirection() { return direction; }				//方向を取得する
	eInactiveType GetInactiveType() { return inactiveType; }	//非アクティブのタイプを取得する
	
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);			// m = my 自分   o = opnet 相手	//当たり判定処理
};

#endif _BASEENEMY_H