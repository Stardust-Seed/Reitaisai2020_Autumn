#include "FontHandle.h"
#include "DxLib.h"
//コンストラクタ
FontHandle::FontHandle() {
	//コンストラクタにInitの処理内容を直接入れるとなんか実行されなく、
	//Initに処理を入れてコンストラクタに入れるとなんか実行されます
	Init();

	natumemozi = "./res/Font/natumemozi.ttf";              //読み込むフォントファイルのパス
	weakForce = "./res/Font/851CHIKARA-YOWAKU_002.ttf";    //読み込むフォントファイルのパス

	AddFontResourceEx(natumemozi, FR_PRIVATE, NULL);       //フォントを読み込む
	AddFontResourceEx(weakForce, FR_PRIVATE, NULL);        //フォントを読み込む

}

//デストラクタ
FontHandle::~FontHandle() {
	RemoveFontResource(natumemozi);                        //読み込んだフォントを削除
	RemoveFontResource(weakForce);                         //読み込んだフォントを削除

	//作成したフォントハンドルを消してくれる便利な奴
	InitFontToHandle();
}

//初期化
void FontHandle::Init()
{
	//CreateFontToHandle("指定するフォント名", 文字のサイズ, 文字の太さ);
	//指定のフォントデータが見つからないときはデフォルトのフォントにされます
	//フォント名をNULLにすればデフォルトフォントになる

	//登録
	natumemozi_38_8  = CreateFontToHandle("なつめもじ", 38, 8, DX_FONTTYPE_ANTIALIASING);
	natumemozi_48_8  = CreateFontToHandle("なつめもじ", 48, 8, DX_FONTTYPE_ANTIALIASING);
	natumemozi_64_8  = CreateFontToHandle("なつめもじ", 64, 8, DX_FONTTYPE_ANTIALIASING);
	natumemozi_100_3 = CreateFontToHandle("なつめもじ", 100, 3, DX_FONTTYPE_ANTIALIASING);
	weakForce_222_16 = CreateFontToHandle("851チカラヨワク", 222, 16, DX_FONTTYPE_ANTIALIASING);
}

