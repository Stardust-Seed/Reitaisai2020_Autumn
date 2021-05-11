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
	Endurance	= 4,	//体力型
	Bomb		= 6,	//爆破兵
	Boss		= 8		//ボス
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

	const int ANIMATION_SWITCHING = 30;		//アニメーションの切り替えフラグ

	const float ATTACK_MOTION_JUNPPOWER		= 15.0f / 15.0f;	//上方向へのジャンプ力

	float speed;			//エネミーの移動速度
	float power;			//エネミーの攻撃力
	int durability;			//エネミーの体力
	eDirection direction;	//エネミーの進行方向
	eEnemyType enemyType;	//エネミーの種類

	int animationCnt;	//アニメーションカウンタ
	int attackCnt;		//攻撃中のカウンタ
	int coolDownCnt;	//クールダウンカウンタ

	int imageIndex;		//描画指定変数
	bool isTurn;		//LR反転フラグ

	bool isActive;		//エネミーの生存フラグ
	bool isAttack;		//エネミーの攻撃フラグ
	bool isHitCastle;	//城発見フラグ
	bool isCoolDown;	//クールダウンフラグ

	float addX;			//攻撃モーション用の加算x
	float addY;			//攻撃モーション用の加算y

	float distanceToPlayerX;	//プレイヤーとエネミーの中心座標間の距離x
	float distanceToPlayerY;	//プレイヤーとエネミーの中心座標間の距離y

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
	/// <param name="_isAbility">プレイヤーのアビリティフラグ</param>
	/// <param name="_abilityType">プレイヤーのアビリティタイプ</param>
	void Move(bool _isAbility, int _abilityType);

	/// <summary>
	/// 生存判定処理
	/// </summary>
	void JudgeActive();

	/// <summary>
	/// 攻撃の処理
	/// </summary>
	/// <param name="_cx">プレイヤーのcx座標</param>
	/// <param name="_cy">プレイヤーのcy座標</param>
	void AttackProc(float _cx, float _cy);

	/// <summary>
	/// 攻撃モーション
	/// </summary>
	/// <param name="_move">移動する方向</param>
	/// <param name="_jump">ジャンプする方向</param>
	/// <param name="_addMove">加算させる移動値</param>
	/// <param name="_addJump">加算させるジャンプ値</param>
	void AttackMotion(float* _move, float* _jump, float _addMove, float _addJump);

	/// <summary>
	/// 移動処理
	/// </summary>
	/// <param name="_isAbility">プレイヤーのアビリティフラグ</param>
	/// <param name="_abilityType">プレイヤーのアビリティタイプ</param>
	void Animation(bool _isAbility, int _abilityType);

	/// <summary>
	/// プレイヤーのサーチ処理
	/// </summary>
	/// <param name="_px">プレイヤーのx座標</param>
	/// <param name="_py">プレイヤーのy座標</param>
	/// <param name="_pw">プレイヤーの横幅</param>
	/// <param name="_ph">プレイヤーの縦幅</param>
	/// <param name="_player">プレイヤー</param>
	void SearchPlayer(float _px, float _py, float _pw, float _ph, BasePlayer* _player);

	/// <summary>
	/// サーチのクールダウン
	/// </summary>
	void SearchCoolDownTime();

	/// <summary>
	/// 拠点のサーチ処理
	/// </summary>
	/// <param name="_ox">拠点のx座標</param>
	/// <param name="_oy">拠点のy座標</param>
	/// <param name="_ow">拠点の縦幅</param>
	/// <param name="_oh">拠点の縦幅</param>
	/// <param name="_isActive">拠点のアクティブフラグ</param>
	bool SearchCastle(float _ox, float _oy, float _ow, float _oh, bool _isActive);
public:
	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	BaseEnemy(){}

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~BaseEnemy(){}

	/// <summary>
	/// 通常スポーン用のコンストラクタ
	/// </summary>
	/// <param name="_speed">スポーンするEnemyの速度</param>
	/// <param name="_power">スポーンするEnemyの攻撃力</param>
	/// <param name="_durability">スポーンするEnemyの耐久力</param>
	/// <param name="_direction">スポーンするEnemyの方向</param>
	/// <param name="_enemyType">スポーンするEnemyの種類</param>
	BaseEnemy(float _speed, float _power, int _durability,
		eDirection _direction, eEnemyType _enemyType);

	/// <summary>
	/// サブ拠点スポーン用のコンストラクタ
	/// </summary>
	/// <param name="_x">スポーン位置x座標</param>
	/// <param name="_y">スポーン位置y座標</param>
	/// <param name="_speed">スポーンするEnemyの速度</param>
	/// <param name="_power">スポーンするEnemyの攻撃力</param>
	/// <param name="_durability">スポーンするEnemyの耐久力</param>
	/// <param name="_direction">スポーンするEnemyの方向</param>
	/// <param name="_enemyType">スポーンするEnemyの種類</param>
	BaseEnemy(float _x, float _y, float _speed, float _power, int _durability,
		eDirection _direction, eEnemyType _enemyType);

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="_castleManager">拠点の管理クラス</param>
	/// <param name="_player">プレイヤークラス</param>
	/// <param name="_bulletManager">弾の管理クラス</param>
	virtual void Update(GameResource* _gameRes);

	/// <summary>
	/// ダメージ処理
	/// </summary>
	/// <param name="_damage">ダメージ量</param>
	void DamageProc(int _damage);

	/// <summary>
	/// 描画処理
	/// </summary>
	virtual void Draw(GameResource* _gameRes);

	/// <summary>
	/// x座標を設定する
	/// </summary>
	/// <param name="_x">設定するx座標</param>
	void Set_X(float _x) { x = _x; }

	/// <summary>
	/// y座標を設定する
	/// </summary>
	/// <param name="_y">設定するy座標</param>
	void Set_Y(float _y) { y = _y; }

	/// <summary>
	/// widthを設定する
	/// </summary>
	/// <param name="_width">設定する横幅</param>
	void Set_Width(float _width) { width = _width; }

	/// <summary>
	/// heightを設定する
	/// </summary>
	/// <param name="_height">設定する縦幅</param>
	void Set_Height(float _height) { height = _height; }

	/// <summary>
	/// isAttackを設定する
	/// </summary>
	/// <param name="_isAttack">設定する攻撃フラグ</param>
	void SetIsAttack(bool _isAttack) { isAttack = _isAttack; }

	/// <summary>
	/// isActiveを設定する
	/// </summary>
	/// <param name="_isActive">設定するアクティブフラグ</param>
	void SetIsActive(bool _isActive) { isActive = _isActive; }

	/// <summary>
	/// directionを設定する
	/// </summary>
	/// <param name="_direction">設定する方向</param>
	void SetDirection(eDirection _direction);

	/// <summary>
	/// x座標を取得する
	/// </summary>
	/// <returns>x座標</returns>
	float Get_X() { return x; }

	/// <summary>
	/// y座標を取得する
	/// </summary>
	/// <returns>y座標</returns>
	float Get_Y() { return y; }

	/// <summary>
	/// cx座標を取得する
	/// </summary>
	/// <returns>cx座標</returns>
	float Get_CX() { return cx; }

	/// <summary>
	/// cy座標を取得する
	/// </summary>
	/// <returns>cy座標</returns>
	float Get_CY() { return cy; }

	/// <summary>
	/// widthを取得する
	/// </summary>
	/// <returns>width</returns>
	float Get_Width() { return width; }

	/// <summary>
	/// heightを取得する
	/// </summary>
	/// <returns>height</returns>
	float Get_Height() { return height; }

	/// <summary>
	/// エネミーの攻撃力を取得する
	/// </summary>
	/// <returns>エネミーの攻撃力</returns>
	float GetPower() { return power; }

	/// <summary>
	/// 生存フラグを取得する
	/// </summary>
	/// <returns>生存フラグ</returns>
	bool GetIsActive() { return isActive; }

	/// <summary>
	/// アタックフラグを取得する
	/// </summary>
	/// <returns>アタックフラグ</returns>
	bool GetIsAttack() { return isAttack; }

	/// <summary>
	/// 方向を取得する
	/// </summary>
	/// <returns>方向</returns>
	eDirection GetDirection() { return direction; }

	/// <summary>
	/// 非アクティブのタイプを取得する
	/// </summary>
	/// <returns>非アクティブのタイプ</returns>
	eInactiveType GetInactiveType() { return inactiveType; }

	/// <summary>
	/// 攻撃タイプを取得する
	/// </summary>
	/// <returns>攻撃タイプ</returns>
	eAttackType GetAttackType() { return attackType; }
	
	/// <summary>
	/// あたり判定処理
	/// </summary>
	/// <param name="mx">エネミーのx座標</param>
	/// <param name="my">エネミーのy座標</param>
	/// <param name="mw">エネミーの横幅</param>
	/// <param name="mh">エネミーの縦幅</param>
	/// <param name="ox">相手のx座標</param>
	/// <param name="oy">相手のy座標</param>
	/// <param name="ow">相手の横幅</param>
	/// <param name="oh">相手の縦幅</param>
	/// <returns>当たった場合 true / 当たらなかった場合 false</returns>
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);
};

#endif _BASEENEMY_H