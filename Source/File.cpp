#include "File.h"

/// <summary>
/// コンストラクタ
/// </summary>
File::File() {
	//ファイルを開く
	LoadFile("./res/File/ConfigFile.bin", eOpenType::Int);
	LoadFile("./res/File/ClearData.bin", eOpenType::Int);
}

/// <summary>
/// デストラクタ
/// </summary>
File::~File() {
	//ファイルを書き込む
	WriteFile("./res/File/ConfigFile.bin", eOpenType::Int, eFileType::Config, 2);
	WriteFile("./res/File/ClearData.bin", eOpenType::Int, eFileType::Clear, 3);
}

/// <summary>
/// ファイルを読み込む
/// </summary>
/// <param name="_filePath">ファイルパス</param>
/// <param name="_type">開くタイプ</param>
void File::LoadFile(const char* _filePath, eOpenType _type) {
	FILE* fp;		//ファイルポインタ
	int count = 0;	//カウンタ
	int buf[100];

	//ファイルを開く
	fopen_s(&fp, _filePath, "rb");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}

	//ファイルを読み込む
	while (!feof(fp)) {
		//読み込みタイプがint型のとき
		if (_type == eOpenType::Int) {
			fread(&buf[count], sizeof(int), 1, fp);
		}
		count++;
	}

	for (int i = 0; i < count - 1; i++) {
		datas.push_back(buf[i]);
	}

	//ファイルを閉じる
	fclose(fp);
}

/// <summary>
/// ファイルを書き込む
/// </summary>
/// <param name="_filePath">ファイルパス</param>
/// <param name="_type">開くタイプ</param>
/// <param name="_fileType">ファイルの種類</param>
/// <param name="_num">数</param>
void File::WriteFile(const char* _filePath, eOpenType _type, eFileType _fileType, int _num) {
	FILE* fp;	//ファイルポインタ

	//ファイルを開く
	fopen_s(&fp,_filePath, "wb");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}

	//ファイルを書き込む
	for (int i = 0; i < _num; i++) {
		//ファイルの開くモードがIntの場合
		if (_type == eOpenType::Int) {
			fwrite(&datas[static_cast<int>(_fileType) + i], sizeof(int), 1, fp);
		}
	}

	//ファイルを閉じる
	fclose(fp);
}