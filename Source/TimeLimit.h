#ifndef _TIMELIMIT_H
#define _TIMELIMIT_H

#include "Define.h"

class TimeLimit {
private:
	static const int TIME = 180;							//実際の制限時間

	static const int MAX_LIMITTIME = FRAME * (TIME + 1)	-1;	// フレームレート * (指定した秒数 +1) - 1 // "+1) - 1"この部分は表示の違和感をなくすため

	int timer;						//制限時間(減少表示)
	
	int color;						//テキストカラー

	bool finishTime;				//終了フラグ

public:
	TimeLimit();					//コンストラクタ

	void Update();					//更新処理

	void Draw();					//描画処理

	void CountDown();				//カウントダウン

	bool Get_finishTime();			//終了フラグのゲッター
};

#endif //_TIMELIMIT_H
