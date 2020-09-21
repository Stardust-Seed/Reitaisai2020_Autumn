#include <DxLib.h>
#include "Image.h"

Image::Image() {
	//画像の読み込み
	MyLoadGraph("./res/Image/title_rogo.png");
	MyLoadGraph("./res/Image/darkness.png");

	//画像を分割して読み込み
	MyLoadDivGraph("./res/Image/tatie_Sakuya.png", 3, 3, 1, 486, 864);
	MyLoadDivGraph("./res/Image/tatie_Fran.png", 3, 3, 1, 486, 864);
	MyLoadDivGraph("./res/Image/player.png", 4, 2, 2, 48, 48);
	MyLoadDivGraph("./res/Image/enemy.png", 6, 2, 3, 48, 48);
	MyLoadDivGraph("./res/Image/sukima.png", 4, 4, 1, 48, 48);
}

void Image::Release() {
	//読み込んだ画像をクリアする
	for (auto release : images) {
		DeleteGraph(release);
	}
	images.clear();
}

int Image::GetGraph(eImageType _imageType, int _num) {
	//指定された画像を呼び出す
	return images[static_cast<int>(_imageType) + _num];
}

void Image::MyLoadGraph(const char* _filePath) {
	//DXライブラリの機能で画像を読み込む
	int tmp = LoadGraph(_filePath);

	//画像をimagesに加える
	images.push_back(tmp);
}

void Image::MyLoadDivGraph(const char* _filePath, int _allNum, int _xNum, int _yNum,
	int _xSize, int _ySize) {
	int tmp[100];	//画像バッファ

	//バッファを初期化
	memset(tmp, 0, sizeof(tmp) / sizeof(int));

	//DXライブラリの機能で画像を分割してバッファに読み込む
	LoadDivGraph(_filePath, _allNum, _xNum, _yNum, _xSize, _ySize, tmp);

	//画像をimagesに加える
	for (int i = 0; i < _allNum; i++) {
		images.push_back(tmp[i]);
	}
}