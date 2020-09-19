#ifndef _IMAGE_H
#define _IMAGE_H

#include <vector>
#include "Singleton.h"

/// <summary>
/// �摜�̃^�C�v
/// </summary>
enum class eImageType {
	Title_Logo,			//�^�C�g�����S
	Event_Darkness,		//�_�[�N�l�X�C�x���g�̉摜
	Spicture_Sakuya01,	//�����G ���(�ʏ�)
	Spicture_Sakuya02,	//�����G ���(�Ί�)
	Spicture_Sakuya03,	//�����G ���(�ł�)
	Spicture_Fran01,	//�����G �t����(�ʏ�)
	Spicture_Fran02,	//�����G �t����(�Ί�)
	Spicture_Fran03,	//�����G �t����(�ł�H)
	Gpicture_Sakuya01,	//�Q�[���̑f�� ���01
	Gpicture_Sakuya02,	//�Q�[���̑f�� ���02
	Gpicture_Fran01,	//�Q�[���̑f�� �t����01
	Gpicture_Fran02,	//�Q�[���̑f�� �t����02
	Gpicture_Enemy01,	//�Q�[���̑f�� �G01
	Gpicture_Enemy02	//�Q�[���̑f�� �G02
};

/// <summary>
/// �摜�N���X
/// </summary>
class Image final :public Singleton<Image> {
private:
	std::vector<int> images;	//�摜�f�[�^

	/// <summary>
	/// �摜��ǂݍ���
	/// </summary>
	/// <param name="_filePath">�ǂݍ��މ摜�̃t�@�C���p�X</param>
	void MyLoadGraph(const char* _filePath);

	/// <summary>
	/// �摜�𕪊����ēǂݍ���
	/// </summary>
	/// <param name="_filePath">�ǂݍ��މ摜�̃t�@�C���p�X</param>
	/// <param name="_allNum">�������鑍��</param>
	/// <param name="_xNum">�������̕�����</param>
	/// <param name="_yNum">�c�����̕�����</param>
	/// <param name="_xSize">���������摜�̉���</param>
	/// <param name="_ySize">���������摜�̏c��</param>
	void MyLoadDivGraph(const char* _filePath, int _allNum, int _xNum, int _yNum,
		int _xSize, int _ySize);
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <returns></returns>
	Image();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Image() = default;

	/// <summary>
	/// �摜�����[�h����
	/// </summary>
	void Load(){}

	/// <summary>
	/// �摜���擾����
	/// </summary>
	/// <param name="_imageType">�摜�̎��</param>
	/// <param name="_num">���������摜�̔ԍ�</param>
	/// <returns>�I�����ꂽ�摜</returns>
	int GetGraph(eImageType _imageType, int _num = 0);

	/// <summary>
	/// �摜�f�[�^�̊J��
	/// </summary>
	void Release();
};

#endif // !_IMAGE_H