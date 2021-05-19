#include <DxLib.h>
#include "Boss.h"

#include "BasePlayer.h"
#include "BulletManager.h"
#include "CastleManager.h"

//�����X�|�[���ʒu����̐����p�R���X�g���N�^
Boss::Boss(float _speed, float _power, int _durability,
	eDirection _direction, eEnemyType _enemyType)
	:BaseEnemy(_speed, _power, _durability, _direction, _enemyType) {
	stopCnt = 0;
	attackCnt = 0;
	effectArray = new int[EFFECT_MAX_NUM] { 0, 1, 2, 3, 4, 5, 6, 7 };
	effectIndex = 0;
	effectDrawX = 0;
	effectDrawY = 0;
	isEffect = false;
}

//�f�X�g���N�^
Boss::~Boss() {
	//���I�Ɋm�ۂ����z����������
	delete effectArray;
}

//�X�V����
void Boss::Update(GameResource* _gameRes) {
	//BaseEnemy�̍X�V����
	BaseEnemy::Update(_gameRes);

	if (isHitCastle) {
		isAttack = true;
	}

	//�G�t�F�N�g�t���O���I���̏ꍇ
	if (isEffect) {
		if (effectIndex == EFFECT_MAX_NUM - 1) {
			isEffect = false;
			effectIndex = 0;


		}
		else {
			effectIndex++;
		}
	}
	
	//�J�E���g���Z�b�g
	if (stopCnt == STOPTIME)stopCnt = 0;

	//�J�E���g��0�̏ꍇ
	if (stopCnt == 0 && !isHitCastle) {
		//�ړ�����
		Move(_gameRes->player->Get_isAbility(), _gameRes->player->Get_AbilityType());

		//�ړ�����ۂɉ摜��؂�ւ���
		if (imageIndex == static_cast<int>(eEnemyType::Boss)) {
			imageIndex = static_cast<int>(eEnemyType::Boss) + 1;
		}
		else {
			imageIndex = static_cast<int>(eEnemyType::Boss);
		}
	}

	//�U������
	if (isAttack) {
		//�U���J�E���^��60�̎��U���t���O���I�t�ɂ���
		if (attackCnt == 300) {
			isAttack = false;
			attackCnt = 0;

			for (int i = 0; i < _gameRes->castleManager->Get_CastleNum(); i++) {
				if (direction == _gameRes->castleManager->Get_CastleDirection(i) &&
					_gameRes->castleManager->Get_IsActive(i)) {
					//�����Ƀ_���[�W������������Ə�����

					effectDrawX = _gameRes->castleManager->Get_DrawPosX(i);
					effectDrawY = _gameRes->castleManager->Get_DrawPosY(i);

					isEffect = true;
					break;
				}
			}
		}

		//�U���J�E���^�����Z����
		attackCnt++;
	}

	//�J�E���^�����Z����
	if (!isAttack)stopCnt++;
}

//�`�揈��
void Boss::Draw(GameResource* _gameRes) {
	//�`�揈��
	Image::Instance()->TransparentGraph(x, y,
		Image::Instance()->GetGraph(eImageType::Gpicture_Enemy,imageIndex),
		255, isTurn);

	//�U���G�t�F�N�g��`��
	if (isEffect) {
		DrawExtendGraphF(effectDrawX, effectDrawY,
			effectDrawX + 120 * 0.45833f, effectDrawY + 120 * 0.45833f,
			Image::Instance()->GetGraph(eImageType::Effect_Slashing, effectArray[effectIndex]), TRUE);
	}
}