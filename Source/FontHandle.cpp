#include "FontHandle.h"
#include "DxLib.h"
//コンストラクタ
FontHandle::FontHandle(){
	//コンストラクタにInitの処理内容を直接入れるとなんか実行されなく、
	//Initに処理を入れてコンストラクタに入れるとなんか実行されます
	Init();
	snoutCrayon = "./res/Font/crayon_1-1.ttf";        //読み込むフォントファイルのパス
	natumemozi = "./res/Font/natumemozi.ttf";        //読み込むフォントファイルのパス
	AddFontResourceEx(snoutCrayon, FR_PRIVATE, NULL);     //フォントを読み込む
	AddFontResourceEx(natumemozi, FR_PRIVATE, NULL);     //フォントを読み込む
}

//デストラクタ
FontHandle::~FontHandle() {

	RemoveFontResource(snoutCrayon);                      //読み込んだフォントを削除

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
	snoutCrayon_48_3 = CreateFontToHandle("殴り書きクレヨン", 48, 3);
	natumemozi_48_3 = CreateFontToHandle("なつめもじ", 48, 3);
}

