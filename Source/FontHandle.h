#ifndef _FONTHANDLE_H
#define _FONTHANDLE_H

#include "Singleton.h"

/*********************************************************************************************************************

CreateFontToHandle("指定するフォント名", 文字のサイズ, 文字の太さ);
指定のフォントデータが見つからないときはデフォルトのフォントにされます
フォント名をNULLにすればデフォルトフォントになる

あっこれ登録できるの40個らしいです(確認はしてない)

*注意*
今まではDrawString、DrawFormatStringを使って文字を表示してると思います。
このハンドルを使用するには
DrawStringToHandle(x,y,"文字",GetColor(255,255,255),FontHandleの変数名);
DrawFormatStringToHandle(x,y,GetColor(255,255,255),FontHandleの変数名,"%d",%dで使うint型の変数名);
上記のDrawStringToHandle、DrawFormatStringToHandleによる記述で使用できます。

登録例)
FontHandle.hで
int urabeFont;
int Get_urabe(){ return urabeFont; }

FontHandle.cppで
urabeFont = CreateFontToHandle("ＭＳ ゴシック",32,3);

使用例)
	文字表示
	DrawStringToHandle(0,0,"新世界の浦部君", GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_16_3());

	変数表示
	int test = 1919;
	DrawFormatStringToHandle(0,0,GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_16_3(),"%d",test);
*********************************************************************************************************************/

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

	FontHandle();     //コンストラクタ
	~FontHandle();    //デストラクタ

	void Init();      //初期化

	//ゲッター
	int Get_MS_GOTHIC_112_3() { return MS_GOTHIC_112_3; }
	int Get_MS_GOTHIC_64_3() { return MS_GOTHIC_64_3; }
	int Get_MS_GOTHIC_32_3() { return MS_GOTHIC_32_3; }
	int Get_MS_GOTHIC_16_3() { return MS_GOTHIC_16_3; }

	int Get_MS_MINCHO_64_3() { return MS_MINCHO_64_3; }
	int Get_MS_MINCHO_32_3() { return MS_MINCHO_32_3; }
	int Get_MS_MINCHO_16_3() { return MS_MINCHO_16_3; }
};

#endif //FONTHANDLE_H_