#include <DxLib.h>
#include "KuronekoLib.h"

#include "Define.h"
#include "Image.h"

/// <summary>
/// UI画像を描画する
/// </summary>
/// <param name="_x">x座標</param>
/// <param name="_y">y座標</param>
/// <param name="_width">横幅</param>
/// <param name="_height">高さ</param>
/// <param name="_extX">拡大率x</param>
/// <param name="_extY">拡大率y</param>
/// <param name="_angle">回転(°)</param>
/// <param name="_pal">ブレンドモードのパラメータ</param>
/// <param name="_color">色</param>
/// <param name="_cursor">カーソル</param>
/// <param name="_drawType">描画タイプ</param>
/// <param name="_font">フォント</param>
/// <param name="_fontSize">フォントのサイズ</param>
/// <param name="_text">表示するテキスト</param>
/// <returns></returns>
int DrawUIGraph(float _x, float _y, float _width, float _height, double _extX, double _extY,
	float _angle, int _pal, unsigned int _color, int _cursor, eDrawType _drawType,
	int _font, int _fontSize, string _text) {
	//テキストサイズを取得する
	int textSize = _text.size();

	//座標を補正
	if (_drawType == eDrawType::Front) {
		_x += ((_width / 2) * _extX);
		_y += ((_height / 2) * _extY);
	}

	//ブレンドモードをアルファブレンドにする
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _pal);

	//UIフレームの描画
	DrawRotaGraph3F(_x, _y, _width / 2, _height / 2, _extX, _extY, (_angle * PAI) / 180,
		Image::Instance()->GetGraph(eImageType::UI_CursorFrame, _cursor), TRUE);

	//影の描画
	DrawStringToHandle(_x - ((_fontSize / 2) * (textSize / 2))+2, _y - (_fontSize / 2)+2,
		_text.c_str(), GetColor(0, 0, 0), _font);

	//文字の描画
	DrawStringToHandle(_x - ((_fontSize / 2) * (textSize / 2)), _y - (_fontSize / 2),
		_text.c_str(), _color, _font);

	//ブレンドモードをノーブレンドにする
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	return 0;
}