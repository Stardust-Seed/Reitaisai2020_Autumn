#ifndef _IMAGE_H
#define _IMAGE_H

#include <vector>
#include "Singleton.h"

/// <summary>
/// �摜�̃^�C�v
/// </summary>
enum class eImageType {
	Title_Logo				= 0,	//�^�C�g�����S
	Background_Title		= 1,	//�^�C�g���w�i
	Background_Filter		= 2,	//�w�i�t�B���^�[
	Background_Game			= 3,	//�Q�[���w�i
	Event_Darkness			= 4,	//�_�[�N�l�X�C�x���g�̉摜
	Gpicture_MainCastle		= 5,	//�Q�[���̑f�� �g����
	Gpicture_Forest			= 6,	//�Q�[���̑f�� �X
	Gpicture_Magic			= 7,	//�Q�[���̑f�� ���@�w
	Gpicture_Star			= 8,	//�Q�[���̑f�� ��
	UI_MessageBox			= 9,	//UI�̑f�� ���b�Z�[�W�{�b�N�X
	Spicture_Sakuya			= 10,	//�����G ���
	Spicture_Fran			= 13,	//�����G �t����
	Spicture_SelectPlayer	= 16,	//�����G �I�����ꂽ�v���C���[
	Gpicture_Player			= 18,	//�Q�[���̑f�� �v���C���[
	Gpicture_Enemy			= 22,	//�Q�[���̑f�� �G�l�~�[
	Gpicture_SubCastle		= 32,	//�Q�[���̑f�� �T�u���_
	Gpicture_Sukima			= 34,	//�Q�[���̑f�� �X�L�}
	Gpicture_Explosion		= 38,	//�Q�[���̑f�� ���j�G�t�F�N�g
	Gpicture_Bomb			= 44,	//�Q�[���̑f�� ���e
	Gpicture_FakeBomb		= 46,	//�Q�[���̑f�� ���e(�U��)
	Gpicture_Bullet			= 49,	//�Q�[���̑f�� �e
	Gpicture_Item			= 51,	//�Q�[���̑f�� �A�C�e��
	Effect_Slashing			= 53,	//�G�t�F�N�g�f�� �a��
	Effect_Explosion2		= 61,	//�G�t�F�N�g�f�� ���j
	UI_CursorFrame			= 69,	//UI�̑f�� �J�[�\���̃t���[��
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
	void Load() {}

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

	/*------------------------------------------------------------------------------
	Beta�@�\
	�E���ߕ`��(LR���]�@�\����)
	�E�t�F�[�h�A�E�g�`��(LR���]�@�\����)
	------------------------------------------------------------------------------*/

	/// <summary>
	/// ���ߕ`��
	/// </summary>
	/// <param name="_x">�\������x���W</param>
	/// <param name="_y">�\������y���W</param>
	/// <param name="_gHandle">�摜�n���h��</param>
	/// <param name="_pal">���ߓx�����̃p�����[�^</param>
	/// <param name="_isTurn">LR���]�t���O true:����/false:���Ȃ�(default)</param>
	/// <param name="_transFlag">���߃t���O ����{�I�ɓ��͂��Ȃ��đ��v</param>
	void TransparentGraph(float _x, float _y, int _gHandle, int _pal = 255,
		bool _isTurn = false, int _transFlag = 1);

	/// <summary>
	/// �t�F�[�h�A�E�g�`��
	/// </summary>
	/// <param name="_x">�\������x���W</param>
	/// <param name="_y">�\������y���W</param>
	/// <param name="_gHandle">�摜�n���h��</param>
	/// <param name="_fadeCnt">���݂̃J�E���g</param>
	/// <param name="_fadeMaxCnt">�ő�J�E���g</param>
	/// <param name="_isTurn">LR���]�t���O true:����/false:���Ȃ�(default)</param>
	/// <param name="_transFlag">���߃t���O ����{�I�ɓ��͂��Ȃ��đ��v</param>
	/// <returns>���̃J�E���g</returns>
	int FadeOutGraph(float _x, float _y, int _gHandle, int _fadeCnt, int _fadeMaxCnt,
		bool _isTurn = false, int _transFlag = 1);

	/// <summary>
	/// �t�F�[�h�C���`��
	/// </summary>
	/// <param name="_x">�\������x���W</param>
	/// <param name="_y">�\������y���W</param>
	/// <param name="_gHandle">�摜�n���h��</param>
	/// <param name="_fadeCnt">���݂̃J�E���g</param>
	/// <param name="_fadeMaxCnt">�ő�J�E���g</param>
	/// <param name="_isTurn">LR���]�t���O true:����/false:���Ȃ�(default)</param>
	/// <param name="_transFlag">���߃t���O ����{�I�ɓ��͂��Ȃ��đ��v</param>
	/// <returns>���̃J�E���g</returns>
	int FadeInGraph(float _x, float _y, int _gHandle, int _fadeCnt, int _fadeMaxCnt,
		bool _isTurn = false, int _transFlag = 1);
};

#endif // !_IMAGE_H