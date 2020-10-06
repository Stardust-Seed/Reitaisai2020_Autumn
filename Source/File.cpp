#include "File.h"

/// <summary>
/// コンストラクタ
/// </summary>
File::File() {
	//ファイルを開く
	LoadFile(FILE_PATH[0], eOpenType::Int);
	LoadFile(FILE_PATH[1], eOpenType::Int);
}

/// <summary>
/// デストラクタ
/// </summary>
File::~File() {
	//ファイルを書き込む
	WriteFile(FILE_PATH[0], eOpenType::Int, eFileType::Config, 2);
	WriteFile(FILE_PATH[1], eOpenType::Int, eFileType::Clear, 3);
}

/// <summary>
/// ファイルを読み込む
/// </summary>
/// <param name="_filePath">ファイルパス</param>
/// <param name="_type">開くタイプ</param>
void File::LoadFile(const char* _filePath, eOpenType _type) {
	FILE* fp;		//ファイルポインタ
	char buf[256];	//バッファ
	int count = 0;	//カウンタ

	//ファイルを開く
	fopen_s(&fp, _filePath, "r");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}

	//ファイルを1行ごとにsavebufに格納する
	while (fgets(buf, BUF_SIZE, fp) != NULL) {
		//ファイルの開くモードがIntの場合
		if (_type == eOpenType::Int) {
			datas.push_back(atoi(buf));
		}
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
	fopen_s(&fp,_filePath, "w");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}

	//ファイルを書き込む
	for (int i = 0; i < _num; i++) {
		//ファイルの開くモードがIntの場合
		if (_type == eOpenType::Int) {
			fprintf_s(fp, "%d\n", datas[static_cast<int>(_fileType) + i]);
		}
	}

	//ファイルを閉じる
	fclose(fp);
}