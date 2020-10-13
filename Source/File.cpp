#include "File.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
File::File() {
	//�t�@�C�����J��
	LoadFile("./res/File/ConfigFile.bin", eOpenType::Int);
	LoadFile("./res/File/ClearData.bin", eOpenType::Int);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
File::~File() {
	//�t�@�C������������
	WriteFile("./res/File/ConfigFile.bin", eOpenType::Int, eFileType::Config, 2);
	WriteFile("./res/File/ClearData.bin", eOpenType::Int, eFileType::Clear, 3);
}

/// <summary>
/// �t�@�C����ǂݍ���
/// </summary>
/// <param name="_filePath">�t�@�C���p�X</param>
/// <param name="_type">�J���^�C�v</param>
void File::LoadFile(const char* _filePath, eOpenType _type) {
	FILE* fp;		//�t�@�C���|�C���^
	int count = 0;	//�J�E���^
	int buf[100];

	//�t�@�C�����J��
	fopen_s(&fp, _filePath, "rb");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}

	//�t�@�C����ǂݍ���
	while (!feof(fp)) {
		//�ǂݍ��݃^�C�v��int�^�̂Ƃ�
		if (_type == eOpenType::Int) {
			fread(&buf[count], sizeof(int), 1, fp);
		}
		count++;
	}

	for (int i = 0; i < count - 1; i++) {
		datas.push_back(buf[i]);
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
	fopen_s(&fp,_filePath, "wb");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}

	//�t�@�C������������
	for (int i = 0; i < _num; i++) {
		//�t�@�C���̊J�����[�h��Int�̏ꍇ
		if (_type == eOpenType::Int) {
			fwrite(&datas[static_cast<int>(_fileType) + i], sizeof(int), 1, fp);
		}
	}

	//�t�@�C�������
	fclose(fp);
}