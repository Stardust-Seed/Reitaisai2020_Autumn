#include "File.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
File::File() {
	//�t�@�C�����J��
	LoadFile(FILE_PATH[0], eOpenType::Int);
	LoadFile(FILE_PATH[1], eOpenType::Int);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
File::~File() {
	//�t�@�C������������
	WriteFile(FILE_PATH[0], eOpenType::Int, eFileType::Config, 2);
	WriteFile(FILE_PATH[1], eOpenType::Int, eFileType::Clear, 3);
}

/// <summary>
/// �t�@�C����ǂݍ���
/// </summary>
/// <param name="_filePath">�t�@�C���p�X</param>
/// <param name="_type">�J���^�C�v</param>
void File::LoadFile(const char* _filePath, eOpenType _type) {
	FILE* fp;		//�t�@�C���|�C���^
	char buf[256];	//�o�b�t�@
	int count = 0;	//�J�E���^

	//�t�@�C�����J��
	fopen_s(&fp, _filePath, "r");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}

	//�t�@�C����1�s���Ƃ�savebuf�Ɋi�[����
	while (fgets(buf, BUF_SIZE, fp) != NULL) {
		//�t�@�C���̊J�����[�h��Int�̏ꍇ
		if (_type == eOpenType::Int) {
			datas.push_back(atoi(buf));
		}
	}

	//�t�@�C�������
	fclose(fp);
}

/// <summary>
/// �t�@�C������������
/// </summary>
/// <param name="_filePath">�t�@�C���p�X</param>
/// <param name="_type">�J���^�C�v</param>
/// <param name="_fileType">�t�@�C���̎��</param>
/// <param name="_num">��</param>
void File::WriteFile(const char* _filePath, eOpenType _type, eFileType _fileType, int _num) {
	FILE* fp;	//�t�@�C���|�C���^

	//�t�@�C�����J��
	fopen_s(&fp,_filePath, "w");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}

	//�t�@�C������������
	for (int i = 0; i < _num; i++) {
		//�t�@�C���̊J�����[�h��Int�̏ꍇ
		if (_type == eOpenType::Int) {
			fprintf_s(fp, "%d\n", datas[static_cast<int>(_fileType) + i]);
		}
	}

	//�t�@�C�������
	fclose(fp);
}