#include <DxLib.h>
#include "Image.h"
#include "Background.h"
#include "Define.h"
/*----------------------------------------------------------------------------------
��ʏ�ɏo������h�~�����Z�b�g
----------------------------------------------------------------------------------*/

Background::Background() {
	//������
	extCnt = 0;
	xCnt = 0;
	yCnt = 0;

	for (int i = 0; i < MAX_STAR; i++) {
		stars[i] = nullptr;
	}

	for (int i = 0; i < static_cast<int>(starsExtData.max_size()); i++) {
		starsExtData[i] = 0;
	}

	for (int i = 0; i < static_cast<int>(starsXData.max_size()); i++) {
		starsXData[i] = 0;
	}

	for (int i = 0; i < static_cast<int>(starsYData.max_size()); i++) {
		starsYData[i] = 0;
	}
}

void Background::Update() {
	bool isSpawn = false;				//�X�|�[���t���O
	int spawnPercent = GetRand(100);	//�X�|�[������m���p�ϐ�

	//�g�嗦�̃J�E���^�Ɣ��h�~�f�[�^�����Z�b�g����
	if (extCnt >= static_cast<int>(starsExtData.max_size())) {
		extCnt = 0;
		for (int i = 0; i < static_cast<int>(starsExtData.max_size()); i++) {
			starsExtData[i] = 0;
		}
	}

	//x���W�̃J�E���^�Ɣ��h�~�f�[�^�����Z�b�g
	if (xCnt >= static_cast<int>(starsXData.max_size())) {
		xCnt = 0;
		for (int i = 0; i < static_cast<int>(starsXData.max_size()); i++) {
			starsXData[i] = 0;
		}
	}

	//y���W�̃J�E���^�Ɣ��h�~�f�[�^�����Z�b�g
	if (yCnt >= static_cast<int>(starsYData.max_size())) {
		yCnt = 0;
		for (int i = 0; i < static_cast<int>(starsYData.max_size()); i++) {
			starsYData[i] = 0;
		}
	}

	//��������5�ȉ��̏ꍇ
	if (spawnPercent % 10 <= 5) {
		isSpawn = true;
	}

	//�����폜���鏈��
	for (int i = 0; i < MAX_STAR; i++) {
		//���N���X����łȂ��ꍇ
		if (stars[i] != nullptr) {
			/*--------------------------------------------------
			��ʊO�ɐ��N���X���o���ꍇ
			(���̍��W(x) > gameWidth(1920)+(�摜��width / 2)) ||
			(���̍��W(y) > gameWidth(1080)+(�摜��height / 2))
			--------------------------------------------------*/
			if (stars[i]->GetX() > (GAME_WIDTH + (900 / 2)) ||
				stars[i]->GetY() > (GAME_HEIHGT + (900 / 2))) {
				delete stars[i];
				stars[i] = nullptr;
			}
		}
	}

	//���������p�̃��[�v
	for (int i = 0; i < MAX_STAR; i++) {
		if (stars[i] == nullptr) {
			//isSpawn��true�̏ꍇ�������s��
			if (isSpawn == true) {

				bool isExt = true;
				bool isX = true;
				bool isY = true;
				double ext;
				float x;
				float y;

				while (isExt == true) {
					ext = (GetRand(4) + 1.0) * 0.1;

					for (int j = 0; j < static_cast<int>(starsExtData.max_size()); j++) {
						if (ext == starsExtData[j]) {
							break;
						}
						else if (j < static_cast<int>(starsExtData.max_size()) - 1) {
							continue;
						}
						//��肪�Ȃ������ꍇ���l����h�~�f�[�^�ɑ�������[�v�𔲂���
						starsExtData[extCnt] = ext;
						isExt = false;
						extCnt++;
					}
				}

				while (isX == true) {
					x = static_cast<float>(-(GAME_WIDTH * 2)) + (GetRand(6) * 900);

					for (int j = 0; j < static_cast<int>(starsXData.max_size()); j++) {
						if (x == starsXData[j]) {
							break;
						}
						else if (j < static_cast<int>(starsXData.max_size() - 1)) {
							continue;
						}
						//��肪�Ȃ������ꍇ���l����h�~�f�[�^�ɑ�������[�v�𔲂���
						starsXData[xCnt] = x;
						isX = false;
						xCnt++;
					}
				}

				while (isY == true) {
					y = static_cast<float>(-(GAME_HEIHGT * 2)) + (GetRand(20) * 100) +
						((900 * ext) / 2);

					for (int j = 0; j < static_cast<int>(starsYData.max_size()); j++) {
						if (y == starsYData[j]) {
							break;
						}
						else if (j < static_cast<int>(starsYData.max_size() - 1)) {
							continue;
						}
						//��肪�Ȃ������ꍇ���l����h�~�f�[�^�ɑ�������[�v�𔲂���
						starsYData[yCnt] = y;
						isY = false;
						yCnt++;
					}
				}

				float angle = GetRand(359);

				//���𐶐�
				stars[i] = new Star(x, y, ext, ext, angle);
				break;
			}
		}
	}

	for (int i = 0; i < MAX_STAR; i++) {
		if (stars[i] != nullptr) {
			stars[i]->Update();
		}
	}
}

void Background::Draw(eBackgroundType _backgroundType) {
	switch (_backgroundType)
	{
	case eBackgroundType::Title:
		break;
	case eBackgroundType::Menu:
		DrawGraph(0, 0, Image::Instance()->GetGraph(eImageType::Background_Menu), TRUE);
		for (int i = 0; i < MAX_STAR; i++) {
			if (stars[i] != nullptr) {
				stars[i]->Draw();
			}
		}

		DrawRotaGraph3F(45, 45, 900.0f / 2, 900.0f / 2, 0.1, 0.1,
			(0 * PAI) / 180,
			Image::Instance()->GetGraph(eImageType::Background_Star), TRUE);

		DrawFormatString(0, 0, GetColor(0, 0, 0), "%d",starsExtData.max_size());
		break;
	case eBackgroundType::Game:
		break;
	}
}