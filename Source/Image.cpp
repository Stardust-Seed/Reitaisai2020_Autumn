#include <DxLib.h>
#include "Image.h"

Image::Image() {
	//画像の読み込み
	MyLoadGraph("./res/Image/title_rogo.png");
	MyLoadGraph("./res/Image/darkness.png");
	MyLoadGraph("./res/Image/koumakan.png");

	//画像を分割して読み込み
	MyLoadDivGraph("./res/Image/tatie_Sakuya.png", 3, 3, 1, 486, 864);
	MyLoadDivGraph("./res/Image/tatie_Fran.png", 3, 3, 1, 486, 864);
	MyLoadDivGraph("./res/Image/player.png", 4, 2, 2, 48, 48);
	MyLoadDivGraph("./res/Image/enemy.png", 6, 2, 3, 48, 48);
	MyLoadDivGraph("./res/Image/SubCastle.png", 2, 2, 1, 55, 55);
	MyLoadDivGraph("./res/Image/sukima.png", 4, 4, 1, 48, 48);
	MyLoadDivGraph("./res/Image/ex.png", 6, 6, 1, 100, 100);
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

void Image::TransparentGraph(float _x, float _y, int _gHandle, int _pal,
	bool _isTurn, int _transFlag) {
	//描画モード αブレンドをセットする
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _pal);

	//反転描画フラグがtrueのとき反転描画をおこなう
	if (_isTurn == true) {
		DrawTurnGraphF(_x, _y, _gHandle, _transFlag);
	}
	//elseの場合通常描画をおこなう
	else {
		DrawGraphF(_x, _y, _gHandle, _transFlag);
	}

	//描画モード ノーブレンドをセットする
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

int Image::FadeOutGraph(float _x, float _y, int _gHandle, int _fadeCnt, int _fadeMaxCnt,
	bool _isTurn, int _transFlag) {

	//最大カウントより超える場合処理は行われない
	if (_fadeCnt > _fadeMaxCnt) {
		return _fadeCnt;
	}

	//フェイドカウントを加算する※1～n+1の範囲にするため
	_fadeCnt++;

	//描画モード αブレンドをセットする
	//パラメータの値の計算式 : 最大 - 現在のカウント * (最大 / 最大カウント + 1);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - _fadeCnt * (255 / (_fadeMaxCnt + 1)));

	//反転描画フラグがtrueのとき反転描画をおこなう
	if (_isTurn == true) {
		DrawTurnGraphF(_x, _y, _gHandle, _transFlag);
	}
	//elseの場合通常描画をおこなう
	else {
		DrawGraphF(_x, _y, _gHandle, _transFlag);
	}

	//描画モード ノーブレンドをセットする
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//次のカウントを返す
	return _fadeCnt;
}