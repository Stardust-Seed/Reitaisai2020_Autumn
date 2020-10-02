#ifndef _BASEENEMY_H
#define _BASEENEMY_H

#include "Direction.h"
#include "Object.h"

class CastleManager;
class BasePlayer;
class BulletManager;

/// <summary>
/// エネミーのタイプ
/// </summary>
enum class eEnemyType {
	Speed		= 0,	//速度型
	Power		= 2,	//パワー型
	Endurance	= 4		//体力型
};

/// <summary>
/// 非アクティブのタイプ
/// </summary>
enum class eInactiveType {
	Defeat,		//撃破
	Invasion,	//侵入
	None		//初期化用
};

/// <summary>
/// 攻撃のタイプ
/// </summary>
enum class eAttackType {
	Invasion,	//侵入時の攻撃
	Player,		//プレイヤーへの攻撃
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

	const int ANIMATION_SWITCHING = 30;

	const float ATTACK_ANIMATION_MOVEAMOUNT	= 48.0f / 30.0f;
	const float ATTACK_ANIMATION_JUNPPOWER	= 15.0f / 15.0f;

	float speed;			//エネミーの移動速度
	float power;			//エネミーの攻撃力
	int durability;			//エネミーの体力
	eDirection direction;	//エネミーの進行方向
	eEnemyType enemyType;	//エネミーの種類

	int animationCnt;	//アニメーションカウンタ
	int attackCnt;		//攻撃中のカウンタ
	int coolDownCnt;	//クールダウンカウンタ

	bool isActive;		//エネミーの生存フラグ
	bool isAttack;		//エネミーの攻撃フラグ
	bool isCoolDown;	//クールダウンフラグ

	float addX;
	float addY;

	float distanceToPlayerX;
	float distanceToPlayerY;

	eAttackType attackType;		//攻撃のタイプ
	eInactiveType inactiveType;	//非アクティブのタイプ

	/// <summary>
	/// 共通の初期化項目の初期化処理
	/// </summary>
	/// <param name="_speed">スピードの初期値</param>
	/// <param name="_power">攻撃力の初期値</param>
	/// <param name="_durability">体力の初期値</param>
	/// <param name="_direction">方向の初期値</param>
	/// <param name="_enemyType">エネミーのタイプ情報</param>
	void Init(float _speed, float _power, int _durability,
		eDirection _direction, eEnemyType _enemyType);

	/// <summary>
	/// 移動処理
	/// </summary>
	void Move();

	/// <summary>
	/// アニメーション
	/// </summary>
	void Animation();
public:
	BaseEnemy(){}
	virtual ~BaseEnemy(){}
	BaseEnemy(float _speed, float _power, int _durability,
		eDirection _direction, eEnemyType _enemyType);
	BaseEnemy(float _x, float _y, float _speed, float _power, int _durability,
		eDirection _direction, eEnemyType _enemyType);

	virtual void Update(CastleManager* _castleManager, BasePlayer* _player,
		BulletManager* _bulletManager) {}							//更新処理
	virtual void Draw() {}											//描画処理

	void SearchCastle(float _ox, float _oy, float _ow, float _oh, bool _isActive);	//城の範囲内かサーチ
	void SearchPlayer(float _px, float _py, float _pw, float _ph,
		BasePlayer* _player);										//プレイヤーが攻撃範囲内かサーチ
	void SearchCoolDownTime();				//サーチのクールダウン
	void JudgeActive();						//アクティブかを判断する
	void AttackProc(float _cx, float _cy);	//攻撃中の時間処理
	void DamageProc(int _damage);			//ダメージ処理

	void Set_X(float _x) { x = _x; }										//x座標を設定する
	void Set_Y(float _y) { y = _y; }										//y座標を設定する
	void Set_Width(float _width) { width = _width; }						//widthを設定する
	void Set_Height(float _height) { height = _height; }					//heightを設定する
	void SetIsAttack(bool _isAttack) { isAttack = _isAttack; }				//isAttackを設定する
	void SetIsActive(bool _isActive) { isActive = _isActive; }				//isActiveを設定する
	void SetDirection(eDirection _direction) { direction = _direction; }	//directionを設定する

	float Get_X() { return x; }									//x座標を取得する
	float Get_Y() { return y; }									//y座標を取得する
	float Get_CX() { return cx; }								//cx座標を取得する
	float Get_CY() { return cy; }								//cy座標を取得する
	float Get_Width() { return width; }							//widthを取得する
	float Get_Height() { return height; }						//heightを取得する
	float GetPower() { return power; }							//エネミーの攻撃力を取得する
	bool GetIsActive() { return isActive; }						//生存フラグを取得する
	bool GetIsAttack() { return isAttack; }						//アタックフラグを取得する
	eDirection GetDirection() { return direction; }				//方向を取得する
	eInactiveType GetInactiveType() { return inactiveType; }	//非アクティブのタイプを取得する
	eAttackType GetAttackType() { return attackType; }			//攻撃タイプを取得する
	
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);			// m = my 自分   o = opnet 相手	//当たり判定処理
};

#endif _BASEENEMY_H