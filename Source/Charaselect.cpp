#include <DxLib.h>
#include "Input.h"
#include "Charaselect.h"

/*コンストラクタ*/
Charaselect::Charaselect(ISceneChanger* _sceneChanger) :BaseScene(_sceneChanger) {


	//最初は咲夜が選択されている状態
	charaSelect = select_SAKUYA;
}

/*更新処理*/
void Charaselect::Update() 
{
	/****選択****/
	/************/
	if ((Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) == 1))
	{
		//選択項目を一つ下げる
		charaSelect = (charaSelect + 1) % select_NUM;
	}
	if (charaSelect != select_SAKUYA) {
		if ((Input::Instance()->GetPressCount(KEY_INPUT_LEFT) == 1))
		{
			//選択項目を一つ上げる
			charaSelect = (charaSelect - 1) % select_NUM;
		}
	}

	/****決定****/
	/************/
	if ((Input::Instance()->GetPressCount(KEY_INPUT_RETURN) == 1))
	{
		switch (charaSelect){
		case select_SAKUYA:   //咲夜を選択
			//確か次難易度選択画面だったっけ？
			//sceneChanger->SceneChange(難易度画面, parameter, true, false);
			break;
		case select_FRAN:
			//確か次難易度選択画面だったっけ？
			//sceneChanger->SceneChange(難易度画面, false, false);
			//sceneChanger->SceneChange(eScene_MENU, parameter, true, false);
			break;
		case select_BACK:
			//前のシーン(画面)に戻る
			sceneChanger->SceneChange(eScene_MENU, false, false);
			//sceneChanger->SceneChange(eScene_MENU, parameter, true, false); //新
			break;
		}
	}

}

/*描画処理*/
void Charaselect::Draw()
{
	DrawFormatString(200, 200, GetColor(255, 255, 255),"選択項目:%d",charaSelect );

	/***テスト用***/
	static int select_Sakuya = LoadGraph("res/Image/select_Sakuya.png");
	static int select_Fran = LoadGraph("res/Image/select_Fran.png");

	DrawGraph(575, 200, select_Sakuya, true);
	DrawGraph(1125, 200, select_Fran, true);

	DrawBox(575, 200, 850, 600, GetColor(255, 255, 255), false);
	//275*400

	DrawBox(1125, 200, 1400, 600, GetColor(255, 255, 255), false);
	//275*400

	//キャラクター項目の描画
	for (int i = 0; i < 2; i++)
	{
		DrawFormatString(selectMenu[i].x, selectMenu[i].y, GetColor(255, 255, 255), selectMenu[i].isMenu);
	}
}