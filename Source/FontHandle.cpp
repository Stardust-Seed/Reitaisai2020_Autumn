#include "FontHandle.h"
#include "DxLib.h"

void FontHandle::Init()
{
	//CreateFontToHandle("指定するフォント名", 文字のサイズ, 文字の太さ);
	//指定のフォントデータが見つからないときはデフォルトのフォントにされます
	//フォント名をNULLにすればデフォルトフォントになる

	//登録してくよ～
	MS_GOTHIC_112_3 = CreateFontToHandle("ＭＳ ゴシック", 112, 3);
	MS_GOTHIC_64_3 = CreateFontToHandle("ＭＳ ゴシック", 64, 3);
	MS_GOTHIC_32_3 = CreateFontToHandle("ＭＳ ゴシック", 32, 3);
	MS_GOTHIC_16_3 = CreateFontToHandle("ＭＳ ゴシック", 16, 3);

	MS_MINCHO_64_3 = CreateFontToHandle("ＭＳ 明朝", 64, 3);
	MS_MINCHO_32_3 = CreateFontToHandle("ＭＳ 明朝", 32, 3);
	MS_MINCHO_16_3 = CreateFontToHandle("ＭＳ 明朝", 16, 3);
}

