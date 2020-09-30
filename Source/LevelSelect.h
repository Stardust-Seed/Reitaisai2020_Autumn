#ifndef _LEVELSELECT_H
#define _LEVELSELECT_H

#include <string>
#include "BaseScene.h"

using namespace std;

/// <summary>
/// �I�𒆂̃��x��
/// </summary>
enum class eLevelType {
	Easy,		//�ȒP
	Normal,		//����
	Hard,		//���
};

/// <summary>
/// ��Փx�I���N���X
/// </summary>
class LevelSelect final :public BaseScene {
private:
	const int CURSOR_UP		= 0;	//�J�[�\�����オ����(�萔)
	const int CURSOR_DOWN	= 1;	//�J�[�\������������(�萔)

	string EASY		= "Easy";
	string NORMAL	= "Normal";
	string HARD		= "Hard";

	eLevelType selectLevel;	//�I�����ꂽ���x��
	eLevelType tmpLevel;	//�ύX�O�̃��x��

	//Easy���W
	float easyX;
	float easyY;

	//Normal���W
	float normalX;
	float normalY;

	//Hard���W
	float hardX;
	float hardY;

	int animationCnt;	//�A�j���[�V�����J�E���g
	bool isChange;		//�؂�ւ��t���O

	void ChangeLevel(int _changeMode);

	void DrawUIBox(float _x, float _y, string _text,
		eLevelType _levelType, Cursor _cursor);

	/// <summary>
	/// UI�̐؂�ւ��A�j���[�V����
	/// </summary>
	void Animation();
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="_sceneChanger">�V�[���؂�ւ��N���X���</param>
	LevelSelect(ISceneChanger* _sceneChanger, Parameter* _parameter);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>	
	~LevelSelect() = default;

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();
};

#endif // !_LEVELSELECT_H