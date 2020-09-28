#include <DxLib.h>
#include "Input.h"
#include "Charaselect.h"

/*コンストラクタ*/
CharaSelect::CharaSelect(ISceneChanger* _sceneChanger, Parameter* _parameter):BaseScene(_sceneChanger,parameter) {

	//最初は咲夜が選択されている状態
	charaSelect = select_SAKUYA;

	//色
	color = GetColor(0, 0, 255);

}

/*更新処理*/
void CharaSelect::Update()
{
	/****選択****/
	/************/
	if ((Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) == 1))
	{
		//選択項目を一つずらす(右に)
		charaSelect = (charaSelect + 1) % select_NUM;
		SE::Instance()->PlaySE(SE_cursor, DX_PLAYTYPE_NORMAL);
	}
	if (charaSelect != select_SAKUYA) {
		if ((Input::Instance()->GetPressCount(KEY_INPUT_LEFT) == 1))
		{
			//選択項目を一つ上げる(左に)
			charaSelect = (charaSelect - 1) % select_NUM;
			SE::Instance()->PlaySE(SE_cursor, DX_PLAYTYPE_NORMAL);
		}
	}

	/****決定****/
	/************/
	if ((Input::Instance()->GetPressCount(KEY_INPUT_RETURN) == 1))
	{
		switch (charaSelect) {
		case select_SAKUYA:   //咲夜を選択
			sceneChanger->SceneChange(eScene_LEVELSELECT, parameter, false, true);
			SE::Instance()->PlaySE(SE_cursor, DX_PLAYTYPE_NORMAL);
			break;
		case select_FRAN:     //フランを選択
			sceneChanger->SceneChange(eScene_LEVELSELECT, parameter,false, true);
			SE::Instance()->PlaySE(SE_cursor, DX_PLAYTYPE_NORMAL);
			break;
		case select_BACK:
			//前のシーン(画面)に戻る
			sceneChanger->SceneChange(eScene_MENU, parameter, false, true); //新
			SE::Instance()->PlaySE(SE_cursor, DX_PLAYTYPE_NORMAL);
			break;
		}
	}

}

/*描画処理*/
void CharaSelect::Draw()
{

	Draw_waku();
	Draw_Charagraph();
	Draw_Charaname();

}
void CharaSelect::Draw_Charagraph()
{
	/**描画 中**/
	//キャラクター画像の表示
	DrawGraph(555, 200, Image::Instance()->GetGraph(eImageType::Spicture_SelectPlayer, 0), true);
	DrawGraph(1105, 200, Image::Instance()->GetGraph(eImageType::Spicture_SelectPlayer, 1), true);
}
void CharaSelect::Draw_waku()
{
	/**描画 奥**/
	//キャラクター画像の枠組み
	DrawBox(535, 180, 850, 620, GetColor(0, 0, 255), true);      //青色
	DrawBox(1085, 180, 1400, 620, GetColor(255, 0, 0), true);    //赤色

	DrawBox(555, 200, 830, 599, GetColor(0, 255, 255), true);    //水色
	DrawBox(1105, 200, 1380, 599, GetColor(255, 255, 0), true);  //黄色

	//選択してる項目の枠
	DrawOvalAA(selectMenu[charaSelect].x, selectMenu[charaSelect].y,
		selectMenu[charaSelect].rx, selectMenu[charaSelect].ry, 100, color, false, 5.0f);
}
void CharaSelect::Draw_Charaname()
{

	/**描画 前**/
	//キャラクター名の表示
	DrawStringToHandle(560, 700, "十六夜 咲夜", GetColor(255, 255, 255), FontHandle::Instance()->Get_NatumeMozi_16_3());
	DrawStringToHandle(1100, 700, "フランドール・Ｓ", GetColor(255, 255, 255), FontHandle::Instance()->Get_NatumeMozi_16_3());
	DrawStringToHandle(830, 900, "メニューに戻る", GetColor(255, 255, 255), FontHandle::Instance()->Get_NatumeMozi_16_3());
}