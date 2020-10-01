#ifndef KURONEKO_KURONEKOLIB_H
#define KURONEKO_KURONEKOLIB_H

#include <string>
#include "Cursor.h"

using namespace std;

//描画タイプ
enum class eDrawType {
	Front,	//左
	Center,	//中央
	Back	//右
};

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
	float _angle, int _pal, unsigned int _color, int _cursor,eDrawType _drawType,
	int _font, int _fontSize, string _text);

#endif // !KURONEKO_KURONEKOLIB_H