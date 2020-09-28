#ifndef _BACKGROUND_H
#define _BACKGROUND_H

#include <array>
#include "Star.h"

using namespace std;

/// <summary>
/// �w�i�^�C�v
/// </summary>
enum class eBackgroundType {
	Title,	//�^�C�g��
	Menu,	//���j���[
	Game	//�Q�[��
};

/// <summary>
/// �w�i�N���X
/// </summary>
class Background final {
private:
	const int MAX_STAR = 30;	//�ő�̐��̐�
	Star* stars[30];			//���N���X
	
	array<double, 5> starsExtData;
	array<float, 6> starsXData;
	array<float, 20> starsYData;
	int extCnt;
	int xCnt;
	int yCnt;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Background();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �w�i��`�悷��
	/// </summary>
	/// <param name="_buckgroundType">�w�i�̃^�C�v</param>
	void Draw(eBackgroundType _buckgroundType);
};

#endif // !_BACKGROUND_H