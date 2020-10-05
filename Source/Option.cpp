#include <DxLib.h>
#include <cstdio>
#include "Input.h"
#include "SE.h"
#include "BGM.h"
#include "Option.h"
#include "Image.h"
#include "FontHandle.h"

const float Option::BGMBAR_WIDTH = 76.9f;
const float Option::BGMBAR_HEIGHT = 17.9f;
const float Option::BGMBAR_INTERVAL = 5.0f;
const int Option::BGM_MAXVOLUME = 10;

const float Option::SEBAR_WIDTH = 76.9f;
const float Option::SEBAR_HEIGHT = 17.9f;
const float Option::SEBAR_INTERVAL = 5.0f;
const int Option::SE_MAXVOLUME = 10;

const float Option::SELECTBAR_X1 = 555.0f;
const float Option::SELECTBAR_X2 = 645.0f;
const float Option::SELECTBAR_YBGM = 120.0f;
const float Option::SELECTBAR_YSE = 454.0f;

const float Option::UIAREA_X1 = 550.0f;
const float Option::UIAREA_X2 = 1374.0f;
const float Option::UIAREA_Y1BGM = 100.0f;
const float Option::UIAREA_Y2BGM = 414.0f;
const float Option::UIAREA_Y1SE = 434.0f;
const float Option::UIAREA_Y2SE = 748.0f;

const int Option::STRING_XBGM = 555;
const int Option::STRING_YBGM = 105;
const int Option::STRING_XSE = 555;
const int Option::STRING_YSE = 439;

const int Option::BUF_SIZE = 256;
const int Option::CONFIGFILE_NUM = 2;

/*�R���X�g���N�^*/
Option::Option(ISceneChanger* _sceneChanger, Parameter* _parameter)
	:BaseScene(_sceneChanger, _parameter) {
	LoadConfigFile();

	//bgmVolume = 5;
	//seVolume = 5;

	bColor = GetColor(255, 100, 100);
	sColor = GetColor(0, 0, 0);

	selectType = select_BGM;
}

/*�X�V����*/
void Option::Update() {
	//�ݒ肵�����ڂ̕ۑ�����
	if (Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1) {
		SaveConfigFile();
		BGM::Instance()->VolumeBGM(bgmVolume);
		SE::Instance()->VolumeSE(seVolume);
		BGM::Instance()->Set_Volume(bgmVolume);
		SE::Instance()->Set_Volume(seVolume);
		SE::Instance()->PlaySE(SE_cursor);
	}

	if (Input::Instance()->GetPressCount(KEY_INPUT_X) == 1) {
		SE::Instance()->PlaySE(SE_cursor);
		sceneChanger->SceneChange(eScene_MENU, parameter, false, true);
	}

	//�ύX���ڂ̕ύX����
	if (Input::Instance()->GetPressCount(KEY_INPUT_UP) == 1) {
		SE::Instance()->PlaySE(SE_cursor);
		if (selectType == select_BGM) {
			selectType = select_SE;
			return;
		}

		if (selectType == select_SE) {
			selectType = select_BGM;
		}
	}

	if (Input::Instance()->GetPressCount(KEY_INPUT_DOWN) == 1) {
		SE::Instance()->PlaySE(SE_cursor);
		if (selectType == select_BGM) {
			selectType = select_SE;
			return;
		}

		if (selectType == select_SE) {
			selectType = select_BGM;
		}
	}

	//�{�����[���̐ݒ菈��
	if (Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) == 1) {
		//BGM���ʂ��㏸
		if (selectType == select_BGM) {
			if (bgmVolume >= BGM_MAXVOLUME) {
				return;
			}
			bgmVolume++;
		}
		//SE���ʂ��㏸
		if (selectType == select_SE) {
			if (seVolume >= SE_MAXVOLUME) {
				return;
			}
			seVolume++;
		}
	}

	if (Input::Instance()->GetPressCount(KEY_INPUT_LEFT) == 1) {
		//BGM���ʂ�����
		if (selectType == select_BGM) {
			if (bgmVolume <= 0) {
				return;
			}
			bgmVolume--;
		}
		//SE���ʂ�����
		if (selectType == select_SE) {
			if (seVolume <= 0) {
				return;
			}
			seVolume--;
		}
	}
}

/*�`�揈��*/
void Option::Draw() {
	//DrawBoxAA(UIAREA_X1, UIAREA_Y1BGM, UIAREA_X2, UIAREA_Y2BGM, GetColor(255, 255, 255), TRUE);
	DrawExtendGraph(UIAREA_X1 - 50, UIAREA_Y1BGM - 50, UIAREA_X2 + 50, UIAREA_Y2BGM + 50, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, cNum[0]), TRUE);
	DrawStringToHandle(STRING_XBGM+3, STRING_YBGM+3, "BGM Volume", GetColor(0,0,0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(STRING_XBGM, STRING_YBGM, "BGM Volume", bColor, FontHandle::Instance()->Get_natumemozi_48_8());

	for (int i = 0; i < bgmVolume; i++) {
		DrawBoxAA(550 + (i * BGMBAR_WIDTH) + ((i + 1) * BGMBAR_INTERVAL),
			379 - BGMBAR_HEIGHT - ((BGMBAR_HEIGHT + 10) * i),
			(550 + BGMBAR_WIDTH) + (i * BGMBAR_WIDTH) + ((i + 1) * BGMBAR_INTERVAL),
			409, boxColorB, TRUE);
	}

	//SE�֘A��UI�̕\��
	//DrawBoxAA(UIAREA_X1, UIAREA_Y1SE, UIAREA_X2, UIAREA_Y2SE, GetColor(255, 255, 255), TRUE);
	DrawExtendGraph(UIAREA_X1 - 50, UIAREA_Y1SE, UIAREA_X2 + 50, UIAREA_Y2SE + 100, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, cNum[1]), TRUE);
	DrawStringToHandle(STRING_XSE+3, STRING_YSE + 53, "SE Volume", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(STRING_XSE, STRING_YSE + 50, "SE Volume", sColor, FontHandle::Instance()->Get_natumemozi_48_8());

	for (int i = 0; i < seVolume; i++) {
		DrawBoxAA(550 + (i * SEBAR_WIDTH) + ((i + 1) * SEBAR_INTERVAL),
			763 - SEBAR_HEIGHT - ((SEBAR_HEIGHT + 10) * i),
			(550 + SEBAR_WIDTH) + (i * SEBAR_WIDTH) + ((i + 1) * SEBAR_INTERVAL),
			793,boxColorS, TRUE);
	}

	//�L�[�֘A��UI�̕\������
	//DrawBoxAA(834, 793, 1070, 843, GetColor(255, 255, 255), TRUE);
	DrawExtendGraph(822, 840, 1080, 898, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 2), TRUE);

	//DrawStringToHandle(965, 851+3, "�߂�:X", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8());
	//DrawStringToHandle(834, 851+3, "�ۑ�:Z", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8());
	
	DrawStringToHandle(965, 851, "�߂�:X", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8());
	DrawStringToHandle(834, 851, "�ۑ�:Z", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8());

	//�I�����Ă鍀�ڂ�UI�̕\��
	if (selectType == select_BGM) {
		bColor = GetColor(255, 100, 100);
		sColor = GetColor(125, 125, 125);
		boxColorB = GetColor(100, 230, 0);
		boxColorS = GetColor(150, 150, 150);
		cNum[0] = 3;
		cNum[1] = 0;
		DrawLineAA(SELECTBAR_X1, SELECTBAR_YBGM + 32, SELECTBAR_X2 + 200, SELECTBAR_YBGM + 32, GetColor(255, 100, 100), 3);
	}

	if (selectType == select_SE) {
		bColor = GetColor(125, 125, 125);
		sColor = GetColor(255, 100, 100);
		boxColorB = GetColor(150, 150, 150);
		boxColorS = GetColor(100, 230, 0);
		cNum[0] = 0;
		cNum[1] = 3;
		DrawLineAA(SELECTBAR_X1, SELECTBAR_YSE + 82, SELECTBAR_X2 + 200, SELECTBAR_YSE + 82, GetColor(255, 100, 100), 3);
	}
}

/*Config�t�@�C����ǂݍ��ޏ���*/
void Option::LoadConfigFile() {
	FILE* fp;						//�t�@�C���|�C���^
	int savebuf[CONFIGFILE_NUM];	//�o�b�t�@���琔�l�ɕϊ������v�f���u������z��ϐ�
	char buf[BUF_SIZE];				//�o�b�t�@
	int count = 0;					//fgets�Ɏg���ϐ�

	//savebuf��0�ŏ�����
	memset(savebuf, 0, sizeof(savebuf));

	//�t�@�C�����J��
	fopen_s(&fp, "./res/File/ConfigFile.txt", "r");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}

	//�t�@�C����1�s���Ƃ�savebuf�Ɋi�[����
	while (fgets(buf, BUF_SIZE, fp) != NULL) {
		savebuf[count] = atoi(buf);
		count++;
	}

	//savebuf����e���ڂ֊i�[����
	bgmVolume = savebuf[select_BGM];
	seVolume = savebuf[select_SE];

	fclose(fp);
}

/*Config�t�@�C�����������ޏ���*/
void Option::SaveConfigFile() {
	FILE* fp;	//�t�@�C���|�C���^

	//�t�@�C�����J��
	fopen_s(&fp, "./res/File/ConfigFile.txt", "w");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}

	//�t�@�C���ɏ�������
	fprintf_s(fp, "%d\n", bgmVolume);
	fprintf_s(fp, "%d\n", seVolume);

	fclose(fp);
}