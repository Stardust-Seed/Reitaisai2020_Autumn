#include "Parameter.h"

void Parameter::Set(string _key, int _val) {
	//�A�z�z��Ƀf�[�^���i�[����
	mapData[_key] = _val;
}

int Parameter::Get(string _key)const {
	auto it = mapData.find(_key);	//�w��L�[���擾

	//�w��L�[�̗v�f�����݂��Ȃ��ꍇ
	if (mapData.end() == it) {
		return -1;
	}
	//���݂����ꍇ
	else {
		return it->second;
	}
}