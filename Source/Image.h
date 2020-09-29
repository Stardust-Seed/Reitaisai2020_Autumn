#ifndef _IMAGE_H
#define _IMAGE_H

#include <vector>
#include "Singleton.h"

/// <summary>
/// 画像のタイプ
/// </summary>
enum class eImageType {
	Title_Logo				= 0,	//タイトルロゴ
	Background_Title		= 1,	//タイトル背景
	Background_Menu			= 2,	//メニュー背景
	Background_Star			= 3,	//メニュー素材
	Background_Game			= 4,	//ゲーム背景
	Event_Darkness			= 5,	//ダークネスイベントの画像
	Gpicture_MainCastle		= 6,	//ゲームの素材 紅魔館
	Gpicture_Forest			= 7,	//ゲームの素材 森
	Spicture_Sakuya			= 8,	//立ち絵 咲夜
	Spicture_Fran			= 11,	//立ち絵 フラン
	Spicture_SelectPlayer	= 14,	//立ち絵 選択されたプレイヤー
	Gpicture_Player			= 16,	//ゲームの素材 プレイヤー
	Gpicture_Enemy			= 20,	//ゲームの素材 エネミー
	Gpicture_SubCastle		= 26,	//ゲームの素材 サブ拠点
	Gpicture_Sukima			= 28,	//ゲームの素材 スキマ
	Gpicture_Explosion		= 32,	//ゲームの素材 爆破エフェクト
	Gpicture_Bomb			= 38,	//ゲームの素材 爆弾
	Gpicture_FakeBomb		= 40	//ゲームの素材 爆弾(偽物)
};

/// <summary>
/// 画像クラス
/// </summary>
class Image final :public Singleton<Image> {
private:
	std::vector<int> images;	//画像データ

	/// <summary>
	/// 画像を読み込む
	/// </summary>
	/// <param name="_filePath">読み込む画像のファイルパス</param>
	void MyLoadGraph(const char* _filePath);

	/// <summary>
	/// 画像を分割して読み込む
	/// </summary>
	/// <param name="_filePath">読み込む画像のファイルパス</param>
	/// <param name="_allNum">分割する総数</param>
	/// <param name="_xNum">横方向の分割数</param>
	/// <param name="_yNum">縦方向の分割数</param>
	/// <param name="_xSize">分割した画像の横幅</param>
	/// <param name="_ySize">分割した画像の縦幅</param>
	void MyLoadDivGraph(const char* _filePath, int _allNum, int _xNum, int _yNum,
		int _xSize, int _ySize);
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <returns></returns>
	Image();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Image() = default;

	/// <summary>
	/// 画像をロードする
	/// </summary>
	void Load() {}

	/// <summary>
	/// 画像を取得する
	/// </summary>
	/// <param name="_imageType">画像の種類</param>
	/// <param name="_num">分割した画像の番号</param>
	/// <returns>選択された画像</returns>
	int GetGraph(eImageType _imageType, int _num = 0);

	/// <summary>
	/// 画像データの開放
	/// </summary>
	void Release();

	/*------------------------------------------------------------------------------
	Beta機能
	・透過描画(LR反転機能あり)
	・フェードアウト描画(LR反転機能あり)
	------------------------------------------------------------------------------*/

	/// <summary>
	/// 透過描画
	/// </summary>
	/// <param name="_x">表示するx座標</param>
	/// <param name="_y">表示するy座標</param>
	/// <param name="_gHandle">画像ハンドル</param>
	/// <param name="_pal">透過度合いのパラメータ</param>
	/// <param name="_isTurn">LR反転フラグ true:する/false:しない(default)</param>
	/// <param name="_transFlag">透過フラグ ※基本的に入力しなくて大丈夫</param>
	void TransparentGraph(float _x, float _y, int _gHandle, int _pal = 255,
		bool _isTurn = false, int _transFlag = 1);

	/// <summary>
	/// フェードアウト描画
	/// </summary>
	/// <param name="_x">表示するx座標</param>
	/// <param name="_y">表示するy座標</param>
	/// <param name="_gHandle">画像ハンドル</param>
	/// <param name="_fadeCnt">現在のカウント</param>
	/// <param name="_fadeMaxCnt">最大カウント</param>
	/// <param name="_isTurn">LR反転フラグ true:する/false:しない(default)</param>
	/// <param name="_transFlag">透過フラグ ※基本的に入力しなくて大丈夫</param>
	/// <returns>次のカウント</returns>
	int FadeOutGraph(float _x, float _y, int _gHandle, int _fadeCnt, int _fadeMaxCnt,
		bool _isTurn = false, int _transFlag = 1);
};

#endif // !_IMAGE_H