#include "Parameter.h"

void Parameter::Set(string _key, int _val) {
	//連想配列にデータを格納する
	mapData[_key] = _val;
}

int Parameter::Get(string _key)const {
	auto it = mapData.find(_key);	//指定キーを取得

	//指定キーの要素が存在しない場合
	if (mapData.end() == it) {
		return -1;
	}
	//存在した場合
	else {
		return it->second;
	}
}