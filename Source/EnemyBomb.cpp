#include <DxLib.h>
#include "EnemyBomb.h"

#include "Image.h"
#include "EnemyManager.h"
#include "CastleManager.h"

//�R���X�g���N�^
EnemyBomb::EnemyBomb(float _x, float _y, eExType _exType) {
	x = _x;
	y = _y;
	exAreaSize = 120.0f;
	width = exAreaSize;
	height = exAreaSize;
	cx = x + (width / 2);
	cy = y + (height / 2);
	isActive = true;
	exCnt = 0;
	effectArray = new int[EFFECT_MAX_NUM] { 0, 1, 2, 3, 4, 5, 6, 7 };
	effectIndex = 0;

	if (_exType == eExType::Immediately) {
		isExplosion = true;
	}
	else if(_exType == eExType::Installation) {
		isExplosion = false;
	}
}

void EnemyBomb::Update(GameResource* _gameRes) {
	//���j�J�E���g�������܂ł̃^�C���̂Ƃ�
	if (exCnt == EXTIME)isExplosion = true;

	//���j����
	if (isExplosion) {

		if (effectIndex == 0) {
			//��Ɣ��e�̓����蔻��
			for (int i = 0; i < _gameRes->castleManager->Get_CastleNum(); i++) {
				//�邪�A�N�e�B�u�ȏꍇ
				if (_gameRes->castleManager->Get_IsActive(i)) {

					float castleX = _gameRes->castleManager->Get_X(i);
					float castleY = _gameRes->castleManager->Get_Y(i);
					float castleW = _gameRes->castleManager->Get_Width(i);
					float castleH = _gameRes->castleManager->Get_Height(i);

					//���������ꍇ
					if (ClisionHit(cx - (exAreaSize / 2), cy - (exAreaSize / 2), width, height,
						castleX, castleY, castleW, castleH)) {
						//�����Ƀ_���[�W�̏���
					}
				}
			}

			//�G�Ɣ��e�̓����蔻��
			for (int i = 0; i < _gameRes->enemyManager->Get_enemyNum(); i++) {
				//�G���A�N�e�B�u�ȏꍇ
				if (_gameRes->enemyManager->Get_ActiveFlg(i)) {

					float enemyX = _gameRes->enemyManager->Get_x(i);
					float enemyY = _gameRes->enemyManager->Get_y(i);
					float enemyW = _gameRes->enemyManager->Get_width(i);
					float enemyH = _gameRes->enemyManager->Get_height(i);

					//���������ꍇ
					if (ClisionHit(cx - (exAreaSize / 2), cy - (exAreaSize / 2), width, height,
						enemyX, enemyY, enemyW, enemyH)) {
						//�����Ƀ_���[�W�̏���
					}
				}
			}
		}
		else if (effectIndex == EFFECT_MAX_NUM - 1) {
			isActive = false;
			isExplosion = false;
			effectIndex = 0;
		}
		else {
			effectIndex++;
		}
	}

	//���j�J�E���g�����Z����
	exCnt++;
}

void EnemyBomb::Draw(GameResource* _gameRes) {
	//���j���̕`��(���j�G�t�F�N�g�̕`��)
	if (isExplosion) {
		DrawGraphF(x, y, Image::Instance()->GetGraph(eImageType::Effect_Explosion2,
			effectArray[effectIndex]), TRUE);
	}
	//���j�O�̕`��(���e��\������)
	else {
		DrawGraphF(x, y, Image::Instance()->GetGraph(eImageType::Gpicture_Bomb), TRUE);
	}
}

bool EnemyBomb::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh) {
	//������������ꍇ
	if (mx + mw >= ox && mx <= ox + ow && my + mh >= oy && my <= oy + oh) {
		return true;
	}

	return false;
}
