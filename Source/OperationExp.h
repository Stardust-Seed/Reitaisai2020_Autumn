#ifndef _OPERATIONEXP_H
#define _OPERATIONEXP_H

#include "Scene.h"

class OperationExp final :public Scene {
private:
	const char* text[12]{			//表示するテキスト
		"◆操作説明◆",
		"・移動 / カーソル移動",
		"上:↑キー",
		"下:↓キー",
		"左:←キー",
		"右:→キー",
		"・攻撃 / 決定",
		"　:Ｚキー",
		"・キャラスキル / 戻る",
		"　:Ｘキー",
		"・ポーズメニュー(ゲーム中)",
		"　:ＥＳＣキー"
	};
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_sceneChanger">シーン切り替えクラス</param>
	/// <param name="_parameter">パラメータ</param>
	OperationExp();

	~OperationExp() = default;

	//更新処理
	void Update(GameResource* _gameRes);

	//描画処理
	void Draw(GameResource* _gameRes);
};

#endif // !_OPERATIONEXP_H