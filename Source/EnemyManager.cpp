#include <DxLib.h>
#include "EnemyManager.h"
#include "BasePlayer.h"

EnemyManager::EnemyManager(int level) {
	
	addEnemyNum = 0;				//������
	activeCount = 0;
	waitCount = 0;
	enemyType = 0;
	_direction = 0;
	direction = eDirection::None;
	addSpeed = 0.0f;

	for (int num = 0; num < MAX_ENEMY_NUM; num++) {//�z�񏉊���
		Enemys[num] = NULL;		
		eBombs[num] = NULL;
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
		addSpeed = 0.5;			//�G�X�e�[�^�X�㏸
		break;
	default:					//��O
		enemyNum = POPENEMY_HARD;
		break;
	}

}

EnemyManager::~EnemyManager() {
	for (int num = 0; num < MAX_ENEMY_NUM; num++) {
		delete Enemys[num];		//�f���[�g����
	}
}

void EnemyManager::Update(CastleManager *_castle,BasePlayer *_player,BulletManager *_bulletManager,ItemManager *_itemManager){
	if (_player->Get_AbilityType() == FRAN_Ability || _player->Get_isAbility() == false && _player->Get_AbilityType() == SAKUYA_Ability) {
		SpawnEnemy(_castle);						//�����Ăяo��
	}
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

		if (eBombs[num] != NULL) {
		//	eBombs[num]->Update(_player,_castle,this);
			if (eBombs[num]->Get_IsActive() == false) {
				delete eBombs[num];
				eBombs[num] = NULL;
			}
		}
	}
	/*********************************************************
		�t�����̃X�L���g�p���̏���
		�G�l�~�[���S�ł��܂�
	*********************************************************/
	if (_player->Get_isAbility() == true && _player->Get_AbilityType() == FRAN_Ability) {

		for (int num = 0; num < MAX_ENEMY_NUM; num++) {		
			if (Enemys[num] != NULL) {					//���������Ă�ꍇ
				_itemManager->SpawnItem(Enemys[num]->Get_CX(), Enemys[num]->Get_CY());	//�A�C�e������

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
		if (eBombs[num] != NULL) {
			eBombs[num]->Draw();
		}
	}
}

void EnemyManager::SpawnEnemy(CastleManager* _castle) {

	addEnemyNum = 2 * _castle->Get_OccupiedNum();
	waitCount++;				//�J�E���g���Z

	if (waitCount >= (FRAME / 2) ) {		//0.5�b�Ԃ͑ҋ@

		if ((rand() % 100) == 0) {	//�o���m��

			_direction = 0;			//����������

			enemyType = GetRand(ENEMY_TYPES - 2);		//�����_���ȓG�̎�� -2�Ȃ͍̂Ō�̒l���{�X�̂��߃����_���ŏo�Ȃ��悤�ɂ��Ă���

			//if (����) {	//�����B�����Ɋm��Ń{�X���o��������
			//	enemyType = ENEMY_TYPES - 1;
			//}

			for (int num = 0; num < enemyNum; num++) {	//�G�l�~�[�̐�����������

				if (Enemys[num] == NULL) {				//NULL�̏ꍇ�����J�n

					activeCount++;						//�����J�E���g���Z

					_direction = GetRand(3);			//�����_���ȏo������	

					direction = static_cast<eDirection>(_direction);	//int�^����enum�N���X�^�ɕϊ�

					if (enemyType == 0) {				//�X�s�[�h�^

						Enemys[num] = new Fairy_Speed(SPEED[enemyType] + addSpeed, POWER[enemyType], DURABILITY[enemyType], direction);        //��������

						waitCount = 0;
						break;							//��̐��������甲����
					}

					if (enemyType == 1) {				//�̗͌^

						Enemys[num] = new Fairy_Endurance(SPEED[enemyType] + addSpeed, POWER[enemyType], DURABILITY[enemyType], direction);    //��������

						waitCount = 0;
						break;							//��̐��������甲����
					}

					if (enemyType == 2) {				//�p���[�^

						Enemys[num] = new Fairy_Power(SPEED[enemyType] + addSpeed, POWER[enemyType], DURABILITY[enemyType], direction);        //��������

						waitCount = 0;
						break;							//��̐��������甲����
					}

					if (enemyType == 3) {				//�{���^

						Enemys[num] = new Fairy_Bomb(SPEED[enemyType] + addSpeed, POWER[enemyType], DURABILITY[enemyType], direction);         //��������

						waitCount = 0;
						break;							//��̐��������甲����
					}

					if (enemyType == 4) {				//�{�X

						Enemys[num] = new Boss(SPEED[enemyType] + addSpeed, POWER[enemyType], DURABILITY[enemyType], direction);			   //��������

						waitCount = 0;
						break;							//��̐��������甲����
					}
				}
			}
		}
		/*******************
		��������ǉ���������
		*******************/

		if ((rand() % 400) == 0) {	//�o���m��

			_direction = 0;			//����������

			enemyType = GetRand(ENEMY_TYPES - 1);	//�����_���ȓG�̎��

			for (int num = enemyNum; num < enemyNum + addEnemyNum; num++) {    //�ǉ���������

				_direction = GetRand(4);				//�����_���ȏo������

				direction = static_cast<eDirection>(_direction);	//int�^����enum�N���X�^�ɕϊ�

				if (_castle->Get_IsActive(_direction) == false) {

					if (Enemys[num] == NULL) {      //NULL�̏ꍇ�����J�n

						activeCount++;				//�����J�E���g���Z

						if (enemyType == 0) {            //�X�s�[�h�^

							Enemys[num] = new Fairy_Speed(_castle->Get_PopPosX(_direction), _castle->Get_PopPosY(_direction),
								SPEED[enemyType], POWER[enemyType], DURABILITY[enemyType],
								_castle->Get_CastleDirection(_direction));        //��������

							waitCount = 0;
							break;      //��̐��������甲����
						}

						if (enemyType == 1) {            //�ϋv�^

							Enemys[num] = new Fairy_Endurance(_castle->Get_PopPosX(_direction), _castle->Get_PopPosY(_direction),
								SPEED[enemyType], POWER[enemyType], DURABILITY[enemyType],
								_castle->Get_CastleDirection(_direction));        //��������

							waitCount = 0;
							break;      //��̐��������甲����
						}

						if (enemyType == 2) {				//�p���[�^

							Enemys[num] = new Fairy_Power(_castle->Get_PopPosX(_direction), _castle->Get_PopPosY(_direction),
								SPEED[enemyType], POWER[enemyType], DURABILITY[enemyType],
								_castle->Get_CastleDirection(_direction));        //��������

							waitCount = 0;
							break;								//��̐��������甲����
						}
						
					}
				}
			}
		}

	}
}

void EnemyManager::SpawnBomb(int eNum,int bNum,float _x,float _y,eExType _exType) {
	for (eNum = 0; eNum < enemyNum + addEnemyNum; eNum++) {
		if (Enemys[eNum] != NULL) {

			for (bNum = 0; bNum < enemyNum; bNum++) {
				if (eBombs[bNum] == NULL) {
					eBombs[bNum] = new EnemyBomb(_x, _y, _exType);
				}
			}
		}
	}

}

//void EnemyManager::DamageSend(int num,int _damage) {
//	if (Enemys[num] != NULL) {
//		Enemys[num]->DamageProc(_damage);
//	}
//}

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

eInactiveType EnemyManager::Get_InactiveType(int num) {
	if (Enemys[num] != NULL) {
		return Enemys[num]->GetInactiveType();
	}
	return eInactiveType::None;
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