#ifndef _FONTHANDLE_H
#define _FONTHANDLE_H

#include "Singleton.h"
#include <Windows.h>
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
LPCSTR urabe;
int urabeFont;
int Get_urabe(){ return urabeFont; }
上記のようなやつをの追加をしてもらい、

FontHandle.cppで
urabeFont = CreateFontToHandle("urabeフォントの名前(MS ゴシックとか)",32(フォントサイズ),3(フォントの太さ));
と入れれば追加出来ます。

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
	LPCSTR natumemozi;       //読み込むフォント変数
	LPCSTR weakForce;        //読み込むフォント変数

	int natumemozi_38_8;     //なつめもじフォント
	int natumemozi_48_8;     //なつめもじフォント
	int natumemozi_64_8;     //なつめもじフォント
	int natumemozi_100_3;    //なつめもじフォント
	int weakForce_222_16;    //851チカラヨワク

public:

	FontHandle();     //コンストラクタ
	~FontHandle();    //デストラクタ

	void Init();      //初期化

	//ゲッター

	int Get_natumemozi_38_8() { return natumemozi_38_8; }
	int Get_natumemozi_48_8() { return natumemozi_48_8; }
	int Get_natumemozi_64_8() { return natumemozi_64_8; }
	int Get_natumemozi_100_3() { return natumemozi_100_3; }

	int Get_weakForce_222_16() { return weakForce_222_16; }


};

#endif //FONTHANDLE_H_