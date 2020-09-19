#ifndef _IMAGE_H
#define _IMAGE_H

#include <vector>
#include "Singleton.h"

/// <summary>
/// 画像のタイプ
/// </summary>
enum class eImageType {
	Title_Logo,			//タイトルロゴ
	Event_Darkness,		//ダークネスイベントの画像
	Spicture_Sakuya01,	//立ち絵 咲夜(通常)
	Spicture_Sakuya02,	//立ち絵 咲夜(笑顔)
	Spicture_Sakuya03,	//立ち絵 咲夜(焦り)
	Spicture_Fran01,	//立ち絵 フラン(通常)
	Spicture_Fran02,	//立ち絵 フラン(笑顔)
	Spicture_Fran03,	//立ち絵 フラン(焦り？)
	Gpicture_Sakuya01,	//ゲームの素材 昨夜01
	Gpicture_Sakuya02,	//ゲームの素材 昨夜02
	Gpicture_Fran01,	//ゲームの素材 フラン01
	Gpicture_Fran02,	//ゲームの素材 フラン02
	Gpicture_Enemy01,	//ゲームの素材 敵01
	Gpicture_Enemy02	//ゲームの素材 敵02
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