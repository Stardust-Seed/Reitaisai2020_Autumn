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

void EnemyBomb::Update(Player* _player, CastleManager* _castleManager,
	EnemyManager* _enemyManager) {
	//���j�J�E���g�������܂ł̃^�C���̂Ƃ�
	if (exCnt == EXTIME)isExplosion = true;

	//���j����
	if (isExplosion) {

		if (effectIndex == 0) {
			//��Ɣ��e�̓����蔻��
			for (int i = 0; i < _castleManager->Get_CastleNum(); i++) {
				//�邪�A�N�e�B�u�ȏꍇ
				if (_castleManager->Get_IsActive(i)) {
					//���������ꍇ
					if (ClisionHit(cx - (exAreaSize / 2), cy - (exAreaSize / 2), width, height,
						_castleManager->Get_X(i), _castleManager->Get_Y(i),
						_castleManager->Get_Width(i), _castleManager->Get_Height(i))) {
						//�����Ƀ_���[�W�̏���
					}
				}
			}

			//�G�Ɣ��e�̓����蔻��
			for (int i = 0; i < _enemyManager->Get_enemyNum(); i++) {
				//�G���A�N�e�B�u�ȏꍇ
				if (_enemyManager->Get_ActiveFlg(i)) {
					//���������ꍇ
					if (ClisionHit(cx - (exAreaSize / 2), cy - (exAreaSize / 2), width, height,
						_enemyManager->Get_x(i), _enemyManager->Get_y(i),
						_enemyManager->Get_width(i), _enemyManager->Get_height(i))) {
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

void EnemyBomb::Draw() {
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
