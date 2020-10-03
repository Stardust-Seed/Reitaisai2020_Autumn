#include <DxLib.h>
#include "Input.h"
#include "Charaselect.h"

/*コンストラクタ*/
CharaSelect::CharaSelect(ISceneChanger* _sceneChanger, Parameter* _parameter) :BaseScene(_sceneChanger, _parameter) {

	//最初は咲夜が選択されている状態
	charaSelect = select_SAKUYA;

	//最初は咲夜が選択されている状態
	select_Sakuya= 0;
	select_Fran = 0;

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
	if ((Input::Instance()->GetPressCount(KEY_INPUT_LEFT) == 1))
	{
		//選択項目を一つ上げる(左に)
		charaSelect = (charaSelect - 1) % select_NUM;
		SE::Instance()->PlaySE(SE_cursor, DX_PLAYTYPE_NORMAL);
	}


	/****決定****/
	/************/
	if ((Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1))
	{
		switch (charaSelect) {
		case select_SAKUYA:   //咲夜を選択
			SE::Instance()->PlaySE(SE_cursor, DX_PLAYTYPE_NORMAL);
			parameter->Set(BaseScene::CharaSelectTag, charaSelect);
			sceneChanger->SceneChange(eScene_LEVELSELECT, parameter, true, false);
			break;
		case select_FRAN:     //フランを選択
			SE::Instance()->PlaySE(SE_cursor, DX_PLAYTYPE_NORMAL);
			parameter->Set(BaseScene::CharaSelectTag, charaSelect);
			sceneChanger->SceneChange(eScene_LEVELSELECT, parameter, true, false);
			break;
		}
	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_X) == 1))
	{
		BGM::Instance()->StopBGM(BGM_menu);
		sceneChanger->SceneChange(eScene_MENU, parameter, true, false);
	}

	if (charaSelect == select_SAKUYA)
	{
		select_Sakuya = 3;
		select_Fran = 0;
	}
	else if (charaSelect == select_FRAN)
	{
		select_Fran = 1;
		select_Sakuya = 0;
	}
	else
	{
		select_Sakuya = 0;
		select_Fran = 0;
	}

}


/*描画処理*/
void CharaSelect::Draw()
{
	Draw_CharaBack();    //背景
	Draw_CharaWaku();    //キャラ画像の枠
	Draw_CharaGraph();   //キャラ画像
	Draw_CharaName();    //キャラネームとネームの枠
	Draw_CharaAbility(); //キャラクターのスキル説明

}
void CharaSelect::Draw_CharaBack()
{
	DrawGraph(0, 0, Image::Instance()->GetGraph(eImageType::Background_Title, 0), true);   //背景
	DrawGraph(0, 0, Image::Instance()->GetGraph(eImageType::Background_Filter, 0), true); //フィルター
}
void CharaSelect::Draw_CharaWaku()
{
	/**描画 奥**/
	//キャラクター画像の枠組み
	DrawBox(535, 180, 850, 620, GetColor(0, 0, 255), true);      //青色
	DrawBox(1085, 180, 1400, 620, GetColor(255, 0, 0), true);    //赤色

	DrawBox(555, 200, 830, 599, GetColor(0, 255, 255), true);    //水色
	DrawBox(1105, 200, 1380, 599, GetColor(255, 255, 0), true);  //黄色

}
void CharaSelect::Draw_CharaGraph()
{
	/**描画 中**/
	//キャラクター画像の表示
	DrawGraph(555, 200, Image::Instance()->GetGraph(eImageType::Spicture_SelectPlayer, 0), true);
	DrawGraph(1105, 200, Image::Instance()->GetGraph(eImageType::Spicture_SelectPlayer, 1), true);
}
void CharaSelect::Draw_CharaName()
{
	//咲夜枠
	DrawRotaGraph(690,725,0.6,0.0,Image::Instance()->GetGraph(eImageType::UI_CursorFrame, select_Sakuya),TRUE);
	//スキル枠
	DrawBox(95, 200, 450, 700, GetColor(0, 0, 0), TRUE);
	//DrawExtendGraph(125, 200, 500, 600, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 0), TRUE);

	//フラン枠
	DrawRotaGraph(1250, 725, 0.6, 0.0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, select_Fran), TRUE);
	//スキル枠
	DrawBox(1490,200,1845, 700, GetColor(0, 0, 0), TRUE);
	//DrawExtendGraph(1440, 200, 1800, 600, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 0), TRUE);

	/**描画 前**/
	//キャラクター名の表示
	DrawStringToHandle(560, 700, "十六夜 咲夜", GetColor(0, 0,0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(1100, 700, "フランドール・Ｓ", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_48_8());
}
void CharaSelect::Draw_CharaAbility()
{
	//咲夜スキル説明
	DrawStringToHandle(160, 250, "　スキル", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(160, 325, "敵の動きを", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(100, 375, "5秒間停止させる", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(120, 450, "使用回数：３回", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());

	//咲夜ステータス
	DrawStringToHandle(120, 530, "power  ★", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(120, 580, "speed  ★★★", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());

	//フランスキル説明
	DrawStringToHandle(1550, 250, "　スキル", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(1515, 325, "画面上の敵を", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(1515, 375, "全て破壊する", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(1515, 450, "使用回数：２回", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());

	//フランステータス
	DrawStringToHandle(1515, 530, "power  ★★★", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(1515, 580, "speed  ★", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
}