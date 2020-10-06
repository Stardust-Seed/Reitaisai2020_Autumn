#ifndef _FILE_H
#define _FILE_H

#include <vector>
#include "Singleton.h"

using namespace std;

/// <summary>
/// 開くタイプ
/// </summary>
enum class eOpenType {
	Int		//数値
};

/// <summary>
/// ファイルタイプ
/// </summary>
enum class eFileType {
	Config,		//設定
	Clear = 2	//クリア状態
};

/// <summary>
/// ファイルクラス
/// </summary>
class File final :public Singleton<File> {
private:
	const int BUF_SIZE = 256;			//バッファのサイズ
	const char* FILE_PATH[2]{			//ファイルのパス
		"./res/File/ConfigFile.txt",	//設定ファイル
		"./res/File/ClearData.txt"		//クリア状態ファイル
	};

	vector<int> datas;	//開いたデータ

	/// <summary>
	/// ファイルを読み込む
	/// </summary>
	/// <param name="_filePath">ファイルパス</param>
	/// <param name="_type">開くタイプ</param>
	void LoadFile(const char* _filePath, eOpenType _type);

	/// <summary>
	/// ファイルを書き込む
	/// </summary>
	/// <param name="_filePath">ファイルパス</param>
	/// <param name="_type">開くタイプ</param>
	/// <param name="_fileType">ファイルの種類</param>
	/// <param name="_num">数</param>
	void WriteFile(const char* _filePath, eOpenType _type, eFileType _fileType, int _num);
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	File();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~File();

	/// <summary>
	/// ロード処理
	/// </summary>
	void Load(){}

	/// <summary>
	/// データを返す
	/// </summary>
	/// <param name="_fileType">ファイルのタイプ</param>
	/// <param name="_num">数</param>
	/// <returns>指定されたファイルデータ</returns>
	int GetFileData(eFileType _fileType, int _num = 0) { 
		return datas[static_cast<int>(_fileType) + _num];
	}

	/// <summary>
	/// データを返す
	/// </summary>
	/// <param name="_fileType">ファイルのタイプ</param>
	/// <param name="_num">数</param>
	/// <param name="_data">セットするデータ</param>
	void SetFileData(eFileType _fileType, int _num, int _data) {
		datas[static_cast<int>(_fileType) + _num] = _data;
	}
};

#endif // !_FILE_H