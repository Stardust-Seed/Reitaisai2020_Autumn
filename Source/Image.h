#ifndef _IMAGE_H
#define _IMAGE_H

#include <vector>
#include "Singleton.h"

/// <summary>
/// �摜�̃^�C�v
/// </summary>
enum class eImageType {
	Title_Logo		= 0,	//�^�C�g�����S
	Event_Darkness	= 1,	//�_�[�N�l�X�C�x���g�̉摜
	Spicture_Sakuya = 2,	//�����G ���
	Spicture_Fran	= 5,	//�����G �t����
	Gpicture_Player = 8,	//�Q�[���̑f�� �v���C���[
	Gpicture_Enemy	= 12,	//�Q�[���̑f�� �G�l�~�[
	Gpicture_Sukima = 18,	//�Q�[���̑f�� �X�L�}
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