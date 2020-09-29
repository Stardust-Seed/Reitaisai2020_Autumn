#include <DxLib.h>
#include "EnemyManager.h"
#include "BasePlayer.h"

EnemyManager::EnemyManager(int level) {
	for (int num = 0; num < MAX_ENEMY_NUM; num++) {
		Enemys[num] = NULL;		//Enemys�̃|�C���^��NULL
	}

	switch (level)				//����(0�`2)�œ�Փx�ʂ̐�������ݒ�
	{
	case 0:						//EASY		2��
		enemyNum = POPENEMY_EASY;
		break;
	case 1:						//NORMAL	3��
		enemyNum = POPENEMY_NORMAL;
		break;
	case 2:						//HARD		4��
		enemyNum = POPENEMY_HARD;
		break;
	default:					//��O
		enemyNum = POPENEMY_HARD;
		break;
	}

	addEnemyNum = 0;				//�ŏ��Ȃ̂Œǉ����͂Ȃ�
	activeCount = 0;				//�����J�E���g������
	waitCount = 0;					//�ҋ@�J�E���g������

}

EnemyManager::~EnemyManager() {
	for (int num = 0; num < MAX_ENEMY_NUM; num++) {
		delete Enemys[num];		//�f���[�g����
	}
}

void EnemyManager::Update(CastleManager *_castle,BasePlayer *_player,BulletManager *_bulletManager,ItemManager *_itemManager){
	SpawnEnemy(_castle);						//�����Ăяo��

	for (int num = 0; num < enemyNum + addEnemyNum; num++) {

		if (Enemys[num] != NULL) {		//NULL�łȂ��ꍇ

			Enemys[num]->Update(_castle, _player, _bulletManager);		//�X�V����

			if (Enemys[num]->GetInactiveType() == eInactiveType::Defeat) {

				_itemManager->SpawnItem(Enemys[num]->Get_CX(), Enemys[num]->Get_CY());	//�A�C�e������
			}

			if (Enemys[num]->GetIsActive() == false) {

				delete Enemys[num];		//�A�N�e�B�u�łȂ��ꍇ�f���[�g����
				Enemys[num] = NULL;		//NULL������

				activeCount--;			//�����J�E���g���Z

			}
		}
	}

	if (_player->Get_isAbility() == true && _player->Get_AbilityType() == FRAN_Ability) {	//�t�������X�L�����g������
		for (int num = 0; num < MAX_ENEMY_NUM; num++) {		

			if (Enemys[num]->GetIsActive() == true) {	//�������Ă���G��

				delete Enemys[num];						//�f���[�g����
				Enemys[num] = NULL;						//NULL������

				activeCount--;							//�����J�E���g���Z
			}
		}
	}

}

void EnemyManager::Draw() {
	for (int num = 0; num < enemyNum + addEnemyNum; num++) {
		if (Enemys[num] != NULL) {
			Enemys[num]->Draw();	//�`��
			
		}
	}
}

void EnemyManager::SpawnEnemy(CastleManager* _castle) {

	addEnemyNum = 2 * _castle->Get_OccupiedNum();
	waitCount++;				//�J�E���g���Z

	if (waitCount >= (FRAME / 2) ) {		//0.5�b�Ԃ͑ҋ@

		if ((rand() % 100) == 0) {	//�o���m��

			SRand;					//����������

			_direction = 0;			//����������

			enemyType = GetRand(ENEMY_TYPES - 1);	//�����_���ȓG�̎��

			for (int num = 0; num < enemyNum; num++) {	//�G�l�~�[�̐�����������

				if (Enemys[num] == NULL) {				//NULL�̏ꍇ�����J�n

					activeCount++;						//�����J�E���g���Z

					_direction = GetRand(3);			//�����_���ȏo������	

					direction = static_cast<eDirection>(_direction);	//int�^����enum�N���X�^�ɕϊ�

					if (enemyType == 0) {				//�X�s�[�h�^

						_speed = 1.5f;
						_power = 5.0f;
						_durability = 25;

						Enemys[num] = new Fairy_Speed(_speed, _power, _durability, direction);        //��������

						waitCount = 0;
						break;								//��̐��������甲����
					}

					if (enemyType == 1) {				//�̗͌^

						_speed = 0.8f;
						_power =8.0f;
						_durability = 125;

						Enemys[num] = new Fairy_Endurance(_speed, _power, _durability, direction);        //��������

						waitCount = 0;
						break;								//��̐��������甲����
					}

					/*
					if (enemyType == 2) {				//�p���[�^

						_speed = 0.8f;
						_power = 10.0f;
						_durability = 75;

						Enemys[num] = new Fairy_Power(_speed, _power, _durability, direction);        //��������

						waitCount = 0;
						break;								//��̐��������甲����
					}
					*/
				}
			}
		}
		/*******************
		��������ǉ���������
		*******************/

		if ((rand() % 400) == 0) {	//�o���m��

			SRand;					//����������

			_direction = 0;			//����������

			enemyType = GetRand(ENEMY_TYPES - 1);	//�����_���ȓG�̎��

			for (int num = enemyNum; num < enemyNum + addEnemyNum; num++) {    //�ǉ���������

				_direction = GetRand(4);				//�����_���ȏo������

				direction = static_cast<eDirection>(_direction);	//int�^����enum�N���X�^�ɕϊ�

				if (_castle->Get_IsActive(_direction) == false) {

					if (Enemys[num] == NULL) {      //NULL�̏ꍇ�����J�n

						activeCount++;				//�����J�E���g��

						if (enemyType == 0) {            //�X�s�[�h�^

							_speed = 1.5f;
							_power = 5.0f;
							_durability = 25;

							Enemys[num] = new Fairy_Speed(_castle->Get_X(_direction), _castle->Get_Y(_direction),_speed, _power, _durability,
								_castle->Get_CastleDirection(_direction));        //��������

							waitCount = 0;
							break;      //��̐��������甲����
						}

						if (enemyType == 1) {            //�ϋv�^

							_speed = 0.8f;
							_power = 8.0f;
							_durability = 125;

							Enemys[num] = new Fairy_Endurance(_castle->Get_X(_direction), _castle->Get_Y(_direction),_speed, _power, _durability,
								_castle->Get_CastleDirection(_direction));        //��������

							waitCount = 0;
							break;      //��̐��������甲����
						}

						/*
						if (enemyType == 2) {				//�p���[�^

							_speed = 0.8f;
							_power = 10.0f;
							_durability = 75;

							Enemys[num] = new Fairy_Endurance(_castle->Get_X(_direction), _castle->Get_Y(_direction),_speed, _power, _durability,
								_castle->Get_CastleDirection(_direction));        //��������

							waitCount = 0;
							break;								//��̐��������甲����
						}
						*/
					}
				}
			}
		}

	}
}

void EnemyManager::Set_IsActive(int num, bool _isActive) {
	if (Enemys[num] != NULL) {
		Enemys[num]->SetIsActive(_isActive);
	}
}

void EnemyManager::Set_IsAttack(int num, bool _isAttack) {
	if (Enemys[num] != NULL) {
		Enemys[num]->SetIsAttack(_isAttack);
	}
}

void EnemyManager::Set_direction(int num, eDirection _direction) {
	if (Enemys[num] != NULL) {
		Enemys[num]->SetDirection(_direction);
	}
}

void EnemyManager::Set_x(int num,float _x) {
		if (Enemys[num] != NULL) {
			Enemys[num]->Set_X(_x);			
		}
}

void EnemyManager::Set_y(int num,float _y) {
		if (Enemys[num] != NULL) {
			Enemys[num]->Set_Y(_y);			
		}
}

void EnemyManager::Set_width(int num,float _width) {
		if (Enemys[num] != NULL) {
			Enemys[num]->Set_Width(_width);	
		}
}

void EnemyManager::Set_height(int num,float _height) {
		if (Enemys[num] != NULL) {
			Enemys[num]->Set_Height(_height);	
		}
}

int EnemyManager::Get_enemyNum() {
	return enemyNum + addEnemyNum;
}

int EnemyManager::Get_ActiveCount() {
	return activeCount;
}

bool EnemyManager::Get_ActiveFlg(int num) {
	if (Enemys[num] != NULL) {
		return Enemys[num]->GetIsActive();	
	}
	return false;
}

bool EnemyManager::Get_AttackFlg(int num) {
	if (Enemys[num] != NULL) {
		return Enemys[num]->GetIsAttack();
	}
	return false;
}

eAttackType EnemyManager::Get_AttackType(int num) {
	if (Enemys[num] != NULL) {
		return Enemys[num]->GetAttackType();
	}
	return eAttackType::None;
}

eDirection EnemyManager::Get_direction(int num) {
	if (Enemys[num] != NULL) {
		return Enemys[num]->GetDirection();
	}
	return eDirection::None;
}

int EnemyManager::Get_Power(int num) {
	if (Enemys[num] != NULL) {
		return Enemys[num]->GetPower();
	}
	return 0;
}

float EnemyManager::Get_x(int num) {
	if (Enemys[num] != NULL) {
		return Enemys[num]->Get_X();
	}
	return 0;
}

float EnemyManager::Get_y(int num) {
	if (Enemys[num] != NULL) {
		return Enemys[num]->Get_Y();
	}
	return 0;
}

float EnemyManager::Get_width(int num) {
	if (Enemys[num] != NULL) {
		return Enemys[num]->Get_Width();
	}
	return 0;
}

float EnemyManager::Get_height(int num) {
	if (Enemys[num] != NULL) {
		return Enemys[num]->Get_Height();
	}
	return 0;
}