#ifndef _SUBCASTLE_H
#define _SUBCASTLE_H

#include "BaseCastle.h"

/*-------------------------------------------------------------
�I�u�W�F�N�g��:	SubCastle
�T�v	      : �T�u���_
�A�N�Z�X      :
�p���N���X    : BaseCastle
�Ă΂��      :
�ڍא���	  : �T�u���_�A�j�󂳂ꂽ��G����
--------------------------------------------------------------*/

class EnemyManager;
class BaseEnemy;
class SubCastle :public virtual BaseCastle {

private:
	int posType;                   //�T�u���_�̏ꏊ

	int bx;                        //�e��X���W
	int by;                        //�e��Y���W
	int bheight;                   //�e�̍���
	int bwidth;                    //�e�̕�

	int cnt;                       //�e���˂̃J�E���g
	int alpha;                     //�e�̓����x
	int directionMove;             //�e�̐i�s����

	bool bflg;                     //�e�̕\���t���O
	bool discoveryFlg;             //�����t���O

public:
	//�T�u���_�̐ݒu�ꏊ�̍��W
	static const int COORDINATE_X_ONE = GAME_WIDTH / 2 - 375 + 80;
	static const int COORDINATE_Y_ONE = GAME_HEIHGT / 2;

	static const int COORDINATE_X_TWO = GAME_WIDTH / 2 - 225 + 48;
	static const int COORDINATE_Y_TWO = GAME_HEIHGT / 2;

	static const int COORDINATE_X_THREE = GAME_WIDTH / 2 ;
	static const int COORDINATE_Y_THREE = GAME_HEIHGT / 2 - 350 + 48;

	static const int COORDINATE_X_FOUR = GAME_WIDTH / 2;
	static const int COORDINATE_Y_FOUR = GAME_HEIHGT / 2 - 225 + 48;

	static const int COORDINATE_X_FIVE = GAME_WIDTH / 2 + 300 - 48;
	static const int COORDINATE_Y_FIVE = GAME_HEIHGT / 2;

	static const int COORDINATE_X_SIX = GAME_WIDTH / 2 + 175 - 48;
	static const int COORDINATE_Y_SIX = GAME_HEIHGT / 2 ;

	static const int COORDINATE_X_SEVEN = GAME_WIDTH / 2;
	static const int COORDINATE_Y_SEVEN = GAME_HEIHGT / 2 + 300 - 48;

	static const int COORDINATE_X_EIGHT = GAME_WIDTH / 2 ;
	static const int COORDINATE_Y_EIGHT = GAME_HEIHGT / 2 + 175 - 48;

	SubCastle(int,int,int);

	void Update(EnemyManager*);    //�X�V����
	void Draw();                   //�`�揈��
};

#endif //_SUBCASTLE_H