#ifndef _INPUT_H
#define _INPUT_H

#include "Singleton.h"

class Input : public Singleton<Input> {

	Input();
	friend Singleton< Input >;

public:
	int UpdateKey();	            //キーの入力状態の更新更新
	int GetPressCount(int keyCode);	//キーが押されているフレームを取得

private:
	static const int KEY_NUM = 256;	//キー総数
	int KeyPressCount[KEY_NUM];		//キーが押されてる場合のカウンタ
	//int KeyRelessCount[KEY_NUM];	//キーが離されてる時のカウンタ

	bool IsAvailableCode(int keyCode);//keyCodeが有効なキー番号か問う
};

#endif 