#include "FontHandle.h"
#include "DxLib.h"

//コンストラクタ
FontHandle::FontHandle(){
	//コンストラクタにInitの処理内容を直接入れるとなんか実行されなく、
	//Initに処理を入れてコンストラクタに入れるとなんか実行されます
	Init();
}

//デストラクタ
FontHandle::~FontHandle() {
	//作成したフォントハンドルを消してくれる便利な奴
	InitFontToHandle();
}

//初期化
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

