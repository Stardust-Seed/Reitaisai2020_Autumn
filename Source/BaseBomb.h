#ifndef _BASEBOMB_H
#define _BASEBOMB_H

class BaseBomb
{
protected:
	const float BOMB_SPOWNUPDOWNX = 488;			//�㉺x
	const float BOMB_SPOWNRIGHTX = 584;				//�Ex
	const float BOMB_SPOWNLEFTHX = 392;				//��x
	const float BOMB_SPOWNUPY = 0;					//��y
	const float BOMB_SPOWNDOWNY = 768;				//��y
	const float BOMB_SPOWNLR = 0;					//���Ey
	
	const int DIRECTIONLEFT = 0;
	const int DIRECTIONRIGHT = 1;
	const int DIRECTIONUP = 2;
	const int DIRECTIONDOWN = 3;

	static const int FRAME = 60;							//�t���[�����[�g

	static const int COUNT = 1;								//���ۂ̃J�E���g�_�E��
	static const int COUNTMAX = FRAME * (COUNT + 1) - 1;	

	float speed;		//���e����������X�s�[�h
	float x;
	float y;
	int damage;			//���e�̃_���[�W
	int countdown;		//�J�E���g�_�E��
	int direction;		//���e�����������

	bool isXplosion;    //�����������ǂ���
	bool isTrigger;     //�������Ă邩���ĂȂ���
	bool isSpown;		//���e�̐����������ǂ���

public:
	BaseBomb();
	~BaseBomb();

	void SpawnBomb();								//���e�̐���
	void JudgeTrigger();							//�����������̔���
	void Move();									//���e�̗���
	virtual void Update() = 0;
	virtual void Draw() = 0;

};
#endif // !_BASEBOMB_H