#ifndef _FONTHANDLE_H
#define _FONTHANDLE_H

#include "Singleton.h"

/********************************************************************************************

CreateFontToHandle("指定するフォント名", 文字のサイズ, 文字の太さ);
指定のフォントデータが見つからないときはデフォルトのフォントにされます
フォント名をNULLにすればデフォルトフォントになる

コンストラクタにCreateFontToHandleの生成処理を書いても反応しないリューロウハンヤンなので
わざわざわざわざわざわざわざわざわざわざわざわざわざ
Init処理があります
コンストラクタなんか必要ねぇんだよ！ハゲ！！！！！！！！！！！！！
あっこれ登録できるの40個らしいです(確認はしてない)

*注意*
今まではDrawString、DrawFormatStringを使って文字を表示してると思います。
このハンドルを使用するには上記の奴ではなく
DrawStringToHandle(x,y,"文字",GetColor(255,255,255),FontHandleの変数名);
のような記述になります。

例)
int urabe;
urabe = CreateFontToHandle("ＭＳ ゴシック",32,3);
DrawStringToHandle(0,0,"狩場町第二公園",GetColor(255,255,255),urabe);

********************************************************************************************/

class FontHandle :public Singleton <FontHandle> {

	friend Singleton < FontHandle >;

private:

	//変数名小文字だとなんか気持ち悪かったから大文字アンダーバーオンリー
	/*-MS ゴシック フォント定義場-*/
	int MS_GOTHIC_112_3;
	int MS_GOTHIC_64_3;
	int MS_GOTHIC_32_3;
	int MS_GOTHIC_16_3;
	/*----------------------------*/

	/*-MS 明朝 フォント定義場-----*/
	int MS_MINCHO_64_3;
	int MS_MINCHO_32_3;
	int MS_MINCHO_16_3;
	/*----------------------------*/
public:

	//コンストラクタちゃんが使えないので
	//Init君を宣言しております
	void Init();

	int Get_MS_GOTHIC_112_3() { return MS_GOTHIC_112_3; }
	int Get_MS_GOTHIC_64_3() { return MS_GOTHIC_64_3; }
	int Get_MS_GOTHIC_32_3() { return MS_GOTHIC_32_3; }
	int Get_MS_GOTHIC_16_3() { return MS_GOTHIC_16_3; }

	int Get_MS_MINCHO_64_3() { return MS_MINCHO_64_3; }
	int Get_MS_MINCHO_32_3() { return MS_MINCHO_32_3; }
	int Get_MS_MINCHO_16_3() { return MS_MINCHO_16_3; }
};

#endif //FONTHANDLE_H_