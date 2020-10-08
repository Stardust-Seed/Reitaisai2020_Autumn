#include <DxLib.h>
#include <cmath>
#include "Define.h"
#include "BaseEnemy.h"

#include "BasePlayer.h"
#include "BulletManager.h"
#include "CastleManager.h"
#include "Image.h"
#include "SE.h"

const float BaseEnemy::ENEMY_SPAWNXLEFT = 420;
const float BaseEnemy::ENEMY_SPAWNYLEFT = (GAME_HEIHGT / 2) - (48 / 2);
const float BaseEnemy::ENEMY_SPAWNXUP = (GAME_WIDTH / 2) - (48 / 2);
const float BaseEnemy::ENEMY_SPAWNYUP = 0 - 48;
const float BaseEnemy::ENEMY_SPAWNXRIGHT = 1500;
const float BaseEnemy::ENEMY_SPAWNYRIGHT = (GAME_HEIHGT / 2) - (48 / 2);
const float BaseEnemy::ENEMY_SPAWNXDOWN = (GAME_WIDTH / 2) - (48 / 2);
const float BaseEnemy::ENEMY_SPAWNYDOWN = GAME_HEIHGT + 48;

/// <summary>
/// �ʏ�X�|�[���p�̃R���X�g���N�^
/// </summary>
/// <param name="_speed">�X�|�[������Enemy�̑��x</param>
/// <param name="_power">�X�|�[������Enemy�̍U����</param>
/// <param name="_durability">�X�|�[������Enemy�̑ϋv��</param>
/// <param name="_direction">�X�|�[������Enemy�̕���</param>
/// <param name="_enemyType">�X�|�[������Enemy�̎��</param>
BaseEnemy::BaseEnemy(float _speed, float _power, int _durability,
	eDirection _direction, eEnemyType _enemyType) {
	//�e�p�����[�^�̏�����
	Init(_speed, _power, _durability, _direction, _enemyType);

	if (direction == eDirection::Left) {
		x = ENEMY_SPAWNXLEFT;
		y = ENEMY_SPAWNYLEFT;
	}

	if (direction == eDirection::Right) {
		x = ENEMY_SPAWNXRIGHT;
		y = ENEMY_SPAWNYRIGHT;
	}

	if (direction == eDirection::Up) {
		x = ENEMY_SPAWNXUP;
		y = ENEMY_SPAWNYUP;
	}

	if (direction == eDirection::Down) {
		x = ENEMY_SPAWNXDOWN;
		y = ENEMY_SPAWNYDOWN;
	}

	cx = x + (width / 2);
	cy = y + (height / 2);

}

/// <summary>
/// �T�u���_�X�|�[���p�̃R���X�g���N�^
/// </summary>
/// <param name="_x">�X�|�[���ʒux���W</param>
/// <param name="_y">�X�|�[���ʒuy���W</param>
/// <param name="_speed">�X�|�[������Enemy�̑��x</param>
/// <param name="_power">�X�|�[������Enemy�̍U����</param>
/// <param name="_durability">�X�|�[������Enemy�̑ϋv��</param>
/// <param name="_direction">�X�|�[������Enemy�̕���</param>
/// <param name="_enemyType">�X�|�[������Enemy�̎��</param>
BaseEnemy::BaseEnemy(float _x, float _y, float _speed, float _power, int _durability,
	eDirection _direction, eEnemyType _enemyType) {
	//�e�p�����[�^�̏�����
	Init(_speed, _power, _durability, _direction, _enemyType);

	x = _x;
	y = _y;
	cx = x + (width / 2);
	cy = y + (height / 2);
}

/// <summary>
/// ���ʂ̏��������ڂ̏���������
/// </summary>
/// <param name="_speed">�X�s�[�h�̏����l</param>
/// <param name="_power">�U���͂̏����l</param>
/// <param name="_durability">�̗͂̏����l</param>
/// <param name="_direction">�����̏����l</param>
/// <param name="_enemyType">�G�l�~�[�̃^�C�v���</param>
void BaseEnemy::Init(float _speed, float _power, int _durability,
	eDirection _direction, eEnemyType _enemyType) {
	speed = _speed;
	power = _power;
	durability = _durability;
	direction = _direction;
	enemyType = _enemyType;

	animationCnt = 0;
	attackCnt = 0;
	coolDownCnt = 0;
	imageIndex = static_cast<int>(enemyType);

	isActive = true;
	isAttack = false;
	isCoolDown = false;
	isHit = false;

	if (direction == eDirection::Left) {
		isTurn = true;
	}
	else {
		isTurn = false;
	}

	addX = 0;
	addY = 0;

	distanceToPlayerX = 0;
	distanceToPlayerY = 0;

	attackType = eAttackType::None;
	inactiveType = eInactiveType::None;

	width = 48;
	height = 48;
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="_castleManager">���_�̊Ǘ��N���X</param>
/// <param name="_player">�v���C���[�N���X</param>
/// <param name="_bulletManager">�e�̊Ǘ��N���X</param>
void BaseEnemy::Update(CastleManager* _castleManager, BasePlayer* _player,
	BulletManager* _bulletManager) {
/*------------------------------------------------------------------------------
�Z���^�[���W�̍Čv�Z
------------------------------------------------------------------------------*/
	cx = x + (width / 2);
	cy = y + (height / 2);

/*------------------------------------------------------------------------------
�U���^�C�v���N���̍ۍU���t���O��false��
------------------------------------------------------------------------------*/
	if (isAttack == true && attackType == eAttackType::Invasion) {
		isAttack = false;
	}

/*------------------------------------------------------------------------------
�_���[�W����
------------------------------------------------------------------------------*/
	for (int i = 0; i < _bulletManager->Get_MaxBullet(); i++) {
		if (_bulletManager->Get_IsActive(i) == true) {
			if (ClisionHit(x, y, width, height, _bulletManager->Get_X(i), _bulletManager->Get_Y(i),
				_bulletManager->Get_Width(i), _bulletManager->Get_Height(i))) {
				if (attackType != eAttackType::Invasion) {
					_bulletManager->Set_isActive(i, false);
					DamageProc(_player->Get_power());
				}
			}
		}
	}
/*------------------------------------------------------------------------------
�������菈��
------------------------------------------------------------------------------*/
	JudgeActive();

/*------------------------------------------------------------------------------
�T�[�`�֘A����
------------------------------------------------------------------------------*/

	//�N�[���_�E���̏���
	if (isCoolDown == true) {
		SearchCoolDownTime();
	}

	//���_�̃T�[�`����
	for (int i = 0; i < _castleManager->Get_CastleNum(); i++) {
		SearchCastle(_castleManager->Get_X(i), _castleManager->Get_Y(i),
			_castleManager->Get_Width(i), _castleManager->Get_Height(i), _castleManager->Get_IsActive(i));
	}

	//�v���C���[�̃T�[�`����
	SearchPlayer(_player->Get_x(), _player->Get_y(), _player->Get_width(), _player->Get_height(),
		_player);

/*------------------------------------------------------------------------------
�U������
------------------------------------------------------------------------------*/
	if (isAttack == true) {
		AttackProc(_player->Get_cx(), _player->Get_cy());
	}

/*------------------------------------------------------------------------------
�ړ�����
------------------------------------------------------------------------------*/
	Move(_player->Get_isAbility(), _player->Get_AbilityType());

/*------------------------------------------------------------------------------
�A�j���[�V��������
------------------------------------------------------------------------------*/
	Animation(_player->Get_isAbility(), _player->Get_AbilityType());
}

/// <summary>
/// �`�揈��
/// </summary>
void BaseEnemy::Draw() {
/*------------------------------------------------------------------------------
�ʏ펞���U�����̕`�揈��
------------------------------------------------------------------------------*/
	if (inactiveType == eInactiveType::None) {
		Image::Instance()->TransparentGraph(x, y, Image::Instance()->GetGraph(
			eImageType::Gpicture_Enemy, imageIndex), 255, isTurn);
	}
/*------------------------------------------------------------------------------
���_�N�����̕`�揈��
------------------------------------------------------------------------------*/
	else if (inactiveType == eInactiveType::Invasion) {
		animationCnt = Image::Instance()->FadeOutGraph(x, y, Image::Instance()->GetGraph(
			eImageType::Gpicture_Enemy, imageIndex), animationCnt, 60, isTurn);
	}
}

/// <summary>
/// �ړ�����
/// </summary>
/// <param name="_isAbility">�v���C���[�̃A�r���e�B�t���O</param>
/// <param name="_abilityType">�v���C���[�̃A�r���e�B�^�C�v</param>
void BaseEnemy::Move(bool _isAbility, int _abilityType) {
	/*--------------------------------------------------------------
	��A�N�e�B�u�̏ꍇ�A�U�����̏ꍇ�A��A�N�e�B�u�^�C�v���N���̏ꍇ
	���̃X�L�����������̏ꍇ�A�ړ��������s��Ȃ�
	--------------------------------------------------------------*/
	if (isActive == false || isAttack == true || inactiveType == eInactiveType::Invasion ||
		(_isAbility == true && _abilityType == SAKUYA)) {
		return;
	}

	//�����ɑΉ�������Zor���Z���������Ȃ�
	switch (direction) {
	case eDirection::Left:		//������
		x += speed;
		break;
	case eDirection::Right:		//�E����
		x -= speed;
		break;
	case eDirection::Up:		//�����
		y += speed;
		break;
	case eDirection::Down:		//������
		y -= speed;
		break;
	}
}

/// <summary>
/// �������菈��
/// </summary>
void BaseEnemy::JudgeActive() {
	//durability��0�ȉ��̂Ƃ�
	if (durability <= 0) {
		//
		SE::Instance()->PlaySE(SE_EnemyDown);

		inactiveType = eInactiveType::Defeat;
		isActive = false;
	}

	//��A�N�e�B�u�^�C�v���N���ł���A�j���[�V�����J�E���g���ő�+1�̂Ƃ�
	if (inactiveType == eInactiveType::Invasion && animationCnt == 60 + 1) {
		isActive = false;
	}
}

/// <summary>
/// �U���̏���
/// </summary>
/// <param name="_cx">�v���C���[��cx���W</param>
/// <param name="_cy">�v���C���[��cy���W</param>
void BaseEnemy::AttackProc(float _cx,float _cy) {

	//�U���^�C�v���N���̏ꍇ�������s��Ȃ�
	if (attackType == eAttackType::Invasion) {
		return;
	}

	//�U�����[�V�����̏��񏈗�
	if (attackCnt == 0) {
		/*--------------------------------------------------
		1�t���[�����̃��[�V�����ړ��������Z�o
		x = (�G�l�~�[��cx - �v���C���[��cx) / �ő�t���[����
		y = (�G�l�~�[��cy - �v���C���[��cy) / �ő�t���[����
		��abs�֐��ɂ���Đ�Βl��Ԃ�
		--------------------------------------------------*/
		distanceToPlayerX = abs(cx - _cx) / 30.0f;
		distanceToPlayerY = abs(cy - _cy) / 30.0f;

		//���[�V�����ړ��Ɏg�p������W�����蓖�Ă�
		switch (direction) {
		case eDirection::Left:						//������
			addX = distanceToPlayerX;
			addY = -(ATTACK_MOTION_JUNPPOWER);
			break;
		case eDirection::Right:						//�E����
			addX = -(distanceToPlayerX);
			addY = -(ATTACK_MOTION_JUNPPOWER);
			break;
		case eDirection::Up:						//�����
			addX = ATTACK_MOTION_JUNPPOWER;
			addY = distanceToPlayerY;
			break;
		case eDirection::Down:						//������
			addX = -(ATTACK_MOTION_JUNPPOWER);
			addY = -(distanceToPlayerY);
			break;
		}
	}

	//���[�V�����̏I������
	if (attackCnt == 100) {
		isAttack = false;
		isCoolDown = true;
		attackCnt = 0;
		attackType = eAttackType::None;
		return;
	}

	if (attackCnt == 30) {
		SE::Instance()->PlaySE(SE_EnemyAttack);
	}

	//���������E�̏ꍇ
	if (direction == eDirection::Left || direction == eDirection::Right) {
		AttackMotion(&x, &y, addX, addY);
	}
	//�������㉺�̏ꍇ
	else if (direction == eDirection::Up || direction == eDirection::Down) {
		AttackMotion(&y, &x, addY, addX);
	}

	//�U���J�E���g�̉��Z����
	attackCnt++;
}

/// <summary>
/// �U�����[�V����
/// </summary>
/// <param name="_move">�ړ��������</param>
/// <param name="_jump">�W�����v�������</param>
/// <param name="_addMove">���Z������ړ��l</param>
/// <param name="_addJump">���Z������W�����v�l</param>
void BaseEnemy::AttackMotion(float* _move, float* _jump, float _addMove, float _addJump) {
	//�v���C���[�̕����֌���������
	if (attackCnt < 30) {
		*_move += _addMove;

		if (attackCnt < 15) {
			*_jump += _addJump;
		}
		else if (attackCnt < 30) {
			*_jump -= _addJump;
		}
	}
	//���̍��W�ɖ߂鏈��
	else if (attackCnt >= 50 && attackCnt < 80) {
		*_move -= _addMove;

		if (attackCnt < 65) {
			*_jump += _addJump;
		}
		else if (attackCnt < 80) {
			*_jump -= _addJump;
		}
	}
}

/// <summary>
/// �_���[�W����
/// </summary>
/// <param name="_damage">�_���[�W��</param>
void BaseEnemy::DamageProc(int _damage) {
	durability -= _damage;
}

/// <summary>
/// �v���C���[�̃T�[�`����
/// </summary>
/// <param name="_px">�v���C���[��x���W</param>
/// <param name="_py">�v���C���[��y���W</param>
/// <param name="_pw">�v���C���[�̉���</param>
/// <param name="_ph">�v���C���[�̏c��</param>
/// <param name="_player">�v���C���[</param>
void BaseEnemy::SearchPlayer(float _px, float _py, float _pw, float _ph, BasePlayer* _player) {

	if (_player->Get_isStan() || isAttack == true || isCoolDown == true ||
		(_player->Get_isAbility() == true && _player->Get_AbilityType() == SAKUYA)) {
		return;
	}

	switch (direction) {
	case eDirection::Left:
		/*******************************************************************************
		�G�l�~�[��cx���W + �G�l�~�[�̉��� >= �v���C���[��x���W &&
		�G�l�~�[��cx���W <= �v���C���[��x���W + �v���C���[�̉����̔��� &&
		�G�l�~�[��y���W + �G�l�~�[�̏c�� >= �v���C���[��y���W
		�G�l�~�[��y���W <= �v���C���[��y���W + �v���C���[�̉���
		*******************************************************************************/
		if (cx + width >= _px && cx <= _px + (_pw / 2) &&
			y + height >= _py && y <= _py + _ph) {
			isAttack = true;
			attackType = eAttackType::Player;
		}
		break;
	case eDirection::Right:
		/*******************************************************************************
		�G�l�~�[��cx���W >= �v���C���[��cx���W &&
		�G�l�~�[��cx���W - �G�l�~�[�̉��� <= �v���C���[��cx + �v���C���[�̉����̔��� &&
		�G�l�~�[��y���W + �G�l�~�[�̏c�� >= �v���C���[��y���W
		�G�l�~�[��y���W <= �v���C���[��y���W + �v���C���[�̉���
		*******************************************************************************/
		if (cx >= (_px + (_pw / 2)) && cx - width <= (_px + (_pw / 2)) + (_pw / 2) &&
			y + height >= _py && y <= _py + _ph) {
			isAttack = true;
			attackType = eAttackType::Player;
		}
		break;
	case eDirection::Up:
		/*******************************************************************************
		�G�l�~�[��x���W + �G�l�~�[�̉��� <= �v���C���[��x���W &&
		�G�l�~�[��x���W <= �v���C���[��x���W + �v���C���[�̉��� &&
		�G�l�~�[��y���W + �G�l�~�[�̏c�� + �Q�Ƃ����̍��W >= �v���C���[��y���W &&
		�G�l�~�[��y���W + �Q�Ƃ����̍��W <= �v���C���[��x���W + �v���C���[�̏c��
		*******************************************************************************/
		if (x + width >= _px && x <= _px + _pw &&
			cy + height >= _py && cy <= _py + (_ph / 2)) {
			isAttack = true;
			attackType = eAttackType::Player;
		}
		break;
	case eDirection::Down:
		/*******************************************************************************
		�G�l�~�[��x���W + �G�l�~�[�̉��� <= �v���C���[��x���W &&
		�G�l�~�[��x���W <= �v���C���[��x���W + �v���C���[�̉��� &&
		�G�l�~�[��y���W + �G�l�~�[�̏c�� + �Q�Ƃ����̍��W >= �v���C���[��y���W &&
		�G�l�~�[��y���W + �G�l�~�[�̏c�� <= �v���C���[��x���W - �Q�Ƃ����̍��W
		*******************************************************************************/
		if (x + width >= _px && x <= _px + _pw &&
			cy >= (_py + (_ph / 2)) && cy - height <= (_py + (_ph / 2)) + (_ph / 2)) {
			isAttack = true;
			attackType = eAttackType::Player;
		}
		break;
	}
}

/// <summary>
/// ���_�̃T�[�`����
/// </summary>
/// <param name="_ox">���_��x���W</param>
/// <param name="_oy">���_��y���W</param>
/// <param name="_ow">���_�̏c��</param>
/// <param name="_oh">���_�̏c��</param>
/// <param name="_isActive">���_�̃A�N�e�B�u�t���O</param>
void BaseEnemy::SearchCastle(float _ox, float _oy, float _ow, float _oh, bool _isActive) {

	//��A�N�e�B�u�^�C�v���N���̏ꍇ�������s��Ȃ�
	if (inactiveType == eInactiveType::Invasion || attackType == eAttackType::Player) {
		return;
	}

	//�邪�������ꍇ
	if ((x + width >= _ox && x <= _ox + _ow && y + height >= _oy && y <= _oy + _oh)
		&& _isActive == true) {
		isAttack = true;
		inactiveType = eInactiveType::Invasion;
		attackType = eAttackType::Invasion;
		animationCnt = 0;
	}
}

/// <summary>
/// �T�[�`�̃N�[���_�E��
/// </summary>
void BaseEnemy::SearchCoolDownTime() {
	//180�t���[���ڃN�[���_�E�����I������
	if (coolDownCnt == 180) {
		coolDownCnt = 0;
		isCoolDown = false;
	}

	//�N�[���_�E���J�E���g�����Z����
	coolDownCnt++;
}

/// <summary>
/// �����蔻�菈��
/// </summary>
/// <param name="mx">�G�l�~�[��x���W</param>
/// <param name="my">�G�l�~�[��y���W</param>
/// <param name="mw">�G�l�~�[�̉���</param>
/// <param name="mh">�G�l�~�[�̏c��</param>
/// <param name="ox">�����x���W</param>
/// <param name="oy">�����y���W</param>
/// <param name="ow">����̉���</param>
/// <param name="oh">����̏c��</param>
/// <returns>���������ꍇ true / ������Ȃ������ꍇ false</returns>
bool BaseEnemy::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh) {

	if (mx + mw >= ox && mx <= ox + ow && my + mh >= oy && my <= oy + oh) {
		return true;
	}

	return false;
}

/// <summary>
/// �ړ�����
/// </summary>
/// <param name="_isAbility">�v���C���[�̃A�r���e�B�t���O</param>
/// <param name="_abilityType">�v���C���[�̃A�r���e�B�^�C�v</param>
void BaseEnemy::Animation(bool _isAbility, int _abilityType) {
	//��A�N�e�B�u�^�C�v��None�̏ꍇ
	if (inactiveType == eInactiveType::None) {
		//�J�E���g��60�̎����Z�b�g����
		if (animationCnt == (ANIMATION_SWITCHING * 2)) {
			animationCnt = 0;
		}

		//0�`29�J�E���g��imageIndex��1���ڂ̗v�f�ԍ���������
		if (animationCnt < ANIMATION_SWITCHING) {
			imageIndex = static_cast<int>(enemyType);
		}
		//30�`59�J�E���g��imageIndex��2���ڂ̗v�f�ԍ���������
		else if (animationCnt < (ANIMATION_SWITCHING * 2)) {
			imageIndex = static_cast<int>(enemyType) + 1;
		}

		//�G�l�~�[����A�N�e�B�u�܂��͍U�����̍ہAanimationCut�����Z���Ȃ�
		if (isActive == false || isAttack == true ||
			(_isAbility == true && _abilityType == SAKUYA)) {
			return;
		}

		animationCnt++;
	}
}

/// <summary>
/// direction��ݒ肷��
/// </summary>
/// <param name="_direction">�ݒ肷�����</param>
void BaseEnemy::SetDirection(eDirection _direction) {
	//������ݒ肷��
	direction = _direction;

	//LR���]�t���O���Đݒ肷��
	if (direction == eDirection::Left) {
		isTurn = true;
	}
	else {
		isTurn = false;
	}
}