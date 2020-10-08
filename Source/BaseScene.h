#ifndef _BASESCENE_H
#define _BASESCENE_H

#include "ISceneChanger.h"
#include "Parameter.h"

class ISceneChanger;

enum eScene
{
	eScene_TITLE,			//タイトル画面
	eScene_MENU,			//メニュー画面
	eScene_GAME,			//ゲーム画面
	eScene_CLAER,			//クリア画面
	eScene_GAMEOVER,		//ゲームオブジェクト
	eScene_OPTION,			//オプション
	eScene_PAUSEMENU,		//ポーズメニュー
	eScene_CHARASELECT,		//キャラ選択画面
	eScene_LEVELSELECT,		//難易度選択画面
	eScene_OPERATIONEXP		//操作説明画面
};

class BaseScene {
protected:
	const static string LevelSelectTag;	//レベル選択タグ
	const static string CharaSelectTag;	//キャラ選択タグ

	ISceneChanger* sceneChanger;	//シーン切り替えのインターフェイスクラス
	Parameter* parameter;
public:
	BaseScene(ISceneChanger* _sceneChanger, Parameter* _parameter);
	virtual ~BaseScene() = default;
	void Init();
	virtual void Draw() = 0;		//描画処理
	virtual void Update() = 0;		//更新処理
};


#endif // !_BASESCENE_H