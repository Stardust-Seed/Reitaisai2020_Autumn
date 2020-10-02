#include <DxLib.h>
#include "GameMain.h"
#include "Input.h"
#include "SE.h"
#include "BGM.h"

GameMain::GameMain() {

}

GameMain::~GameMain() {

}

void GameMain::Init() {
	FILE* fp;						//�t�@�C���|�C���^
	int savebuf[2];	//�o�b�t�@���琔�l�ɕϊ������v�f���u������z��ϐ�
	char buf[256];				//�o�b�t�@
	int count = 0;					//fgets�Ɏg���ϐ�

	//savebuf��0�ŏ�����
	memset(savebuf, 0, sizeof(savebuf));

	//�t�@�C�����J��
	fopen_s(&fp, "./res/File/ConfigFile.txt", "r");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}

	//�t�@�C����1�s���Ƃ�savebuf�Ɋi�[����
	while (fgets(buf, 256, fp) != NULL) {
		savebuf[count] = atoi(buf);
		count++;
	}

	BGM::Instance()->VolumeBGM(savebuf[0]);
	SE::Instance()->VolumeSE(savebuf[1]);
	BGM::Instance()->Set_Volume(savebuf[0]);
	SE::Instance()->Set_Volume(savebuf[1]);

	fclose(fp);
}

bool GameMain::GameLoop() {

	Input::Instance()->UpdateKey();

	sManager.Update();
	sManager.Draw();

	return true;
}