#ifndef _IMAGE_H
#define _IMAGE_H

#include <vector>
#include "Singleton.h"

/// <summary>
/// 画像のタイプ
/// </summary>
enum class eImageType {
	Title_Logo		= 0,	//タイトルロゴ
	Event_Darkness	= 1,	//ダークネスイベントの画像
	Spicture_Sakuya = 2,	//立ち絵 昨夜
	Spicture_Fran	= 5,	//立ち絵 フラン
	Gpicture_Player = 8,	//ゲームの素材 プレイヤー
	Gpicture_Enemy	= 12,	//ゲームの素材 エネミー
	Gpicture_Sukima = 18,	//ゲームの素材 スキマ
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
	void Load(){}

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
};

#endif // !_IMAGE_H