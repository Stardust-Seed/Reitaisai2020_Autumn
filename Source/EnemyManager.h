#ifndef _ENEMYMANAGER_H
#define _ENEMYMANAGER_H

class EnemyManager {
private:
	static const int POPENEMY_EASY = 2;		//��Փx�ʉ�ʓ��̐�����

	static const int POPENEMY_NORMAL = 3;	//3�̂܂�

	static const int POPENEMY_HARD = 4;		//4�̂܂�

public:
	EnemyManager();					//�R���X�g���N�^

	~EnemyManager();				//�f�X�g���N�^

	void SpawnEnemy();				//�G�l�~�[��������

	void Update();					//�X�V����

	void Draw();					//�`�揈��

	int Get_ActiveFlg(int);			//�A�N�e�B�u�����󂯎��

	int Get_Power(int);				//�U���͂��󂯎��

	int Get_x();					//x���W���󂯎��

	int Get_y();					//y���W���󂯎��

	int Get_width();				//�����󂯎��

	int Get_height();				//�������󂯎��

	int Set_x(int _x);				//x���W���Z�b�g

	int Set_y(int _y);				//y���W���Z�b�g

	int Set_width(int _width);		//�����Z�b�g

	int Set_height(int _height);	//�������Z�b�g
};
#endif // !_ENEMYMANAGER_H
