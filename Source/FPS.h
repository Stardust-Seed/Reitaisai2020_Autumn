#ifndef _FPS_H
#define _FPS_H

class FPS final {
private:
	int mStartTime;         //測定開始時刻
	int mCount;             //カウンタ
	float mFps;             //fps
	static const int N = 60;//平均を取るサンプル数
	static const int AVG_FPS = 60;	//設定したFPS
public:
	FPS();
	void Wait();
	void Update();
	void Draw();
};

#endif // !_FPS_H