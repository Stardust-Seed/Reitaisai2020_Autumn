#ifndef _TIMELIMIT_H
#define _TIMELIMIT_H

class TimeLimit {
private:
	static const int MAX_LIMITTIME;	//制限時間

	int timer;					//制限時間(減少表示)

	int color;					//テキストカラー

	bool finishTime;			//終了フラグ

public:
	TimeLimit();				//コンストラクタ

	void Update();				//更新処理

	void Draw();				//描画処理

	void CountDown();			//カウントダウン
};

#endif //_TIMELIMIT_H
