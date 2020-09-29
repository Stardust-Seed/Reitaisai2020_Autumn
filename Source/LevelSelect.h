#ifndef _LEVELSELECT_H
#define _LEVELSELECT_H

#include "BaseScene.h"
#include "Background.h"

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

	eLevelType selectLevel;	//�I�����ꂽ���x��
	eLevelType tmpLevel;	//�ύX�O�̃��x��

	//Easy���W
	float easyX1;
	float easyX2;
	float easyY1;
	float easyY2;

	//Normal���W
	float normalX1;
	float normalX2;
	float normalY1;
	float normalY2;

	//Hard���W
	float hardX1;
	float hardX2;
	float hardY1;
	float hardY2;

	int animationCnt;	//�A�j���[�V�����J�E���g
	bool isChange;		//�؂�ւ��t���O

	void ChangeLevel();

	/// <summary>
	/// UI�̕`�揈��
	/// </summary>
	/// <param name="_x1">�n�_��x���W</param>
	/// <param name="_y1">�n�_��y���W</param>
	/// <param name="_x2">�I�_��x���W</param>
	/// <param name="_y2">�I�_��y���W</param>
	/// <param name="_color">UI�̐F</param>
	/// <param name="_text">�\������e�L�X�g</param>
	/// <param name="_levelType">����UI�̃��x��</param>
	void DrawUIBox(float _x1, float _y1, float _x2, float _y2, unsigned int _color,
		const char* _text, eLevelType _levelType);

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