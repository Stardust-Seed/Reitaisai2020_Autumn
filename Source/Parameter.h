#ifndef _PARAMETER_H
#define _PARAMETER_H

#include <map>
#include <string>

using namespace std;

/// <summary>
/// �p�����[�^�N���X
/// </summary>
class Parameter final {
private:
	map<string, int> mapData;	//�V�[�����L�̃f�[�^
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Parameter() = default;

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Parameter() = default;

	/// <summary>
	/// ���t���̐��l���쐬����
	/// </summary>
	/// <param name="_key">���̖��O</param>
	/// <param name="_val">���l</param>
	void Set(string _key, int _val);

	/// <summary>
	/// �I�����ꂽ���̐��l��Ԃ�
	/// </summary>
	/// <param name="_key">���̖��O</param>
	int Get(string _key)const;
};

#endif // !_PARAMETER_H