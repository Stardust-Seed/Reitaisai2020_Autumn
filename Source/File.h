#ifndef _FILE_H
#define _FILE_H

#include <vector>
#include "Singleton.h"

using namespace std;

/// <summary>
/// �J���^�C�v
/// </summary>
enum class eOpenType {
	Int		//���l
};

/// <summary>
/// �t�@�C���^�C�v
/// </summary>
enum class eFileType {
	Config,		//�ݒ�
	Clear = 2	//�N���A���
};

/// <summary>
/// �t�@�C���N���X
/// </summary>
class File final :public Singleton<File> {
private:
	const int BUF_SIZE = 256;			//�o�b�t�@�̃T�C�Y
	const char* FILE_PATH[2]{			//�t�@�C���̃p�X
		"./res/File/ConfigFile.txt",	//�ݒ�t�@�C��
		"./res/File/ClearData.txt"		//�N���A��ԃt�@�C��
	};

	vector<int> datas;	//�J�����f�[�^

	/// <summary>
	/// �t�@�C����ǂݍ���
	/// </summary>
	/// <param name="_filePath">�t�@�C���p�X</param>
	/// <param name="_type">�J���^�C�v</param>
	void LoadFile(const char* _filePath, eOpenType _type);

	/// <summary>
	/// �t�@�C������������
	/// </summary>
	/// <param name="_filePath">�t�@�C���p�X</param>
	/// <param name="_type">�J���^�C�v</param>
	/// <param name="_fileType">�t�@�C���̎��</param>
	/// <param name="_num">��</param>
	void WriteFile(const char* _filePath, eOpenType _type, eFileType _fileType, int _num);
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	File();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~File();

	/// <summary>
	/// ���[�h����
	/// </summary>
	void Load(){}

	/// <summary>
	/// �f�[�^��Ԃ�
	/// </summary>
	/// <param name="_fileType">�t�@�C���̃^�C�v</param>
	/// <param name="_num">��</param>
	/// <returns>�w�肳�ꂽ�t�@�C���f�[�^</returns>
	int GetFileData(eFileType _fileType, int _num = 0) { 
		return datas[static_cast<int>(_fileType) + _num];
	}

	/// <summary>
	/// �f�[�^��Ԃ�
	/// </summary>
	/// <param name="_fileType">�t�@�C���̃^�C�v</param>
	/// <param name="_num">��</param>
	/// <param name="_data">�Z�b�g����f�[�^</param>
	void SetFileData(eFileType _fileType, int _num, int _data) {
		datas[static_cast<int>(_fileType) + _num] = _data;
	}
};

#endif // !_FILE_H