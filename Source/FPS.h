#ifndef _FPS_H
#define _FPS_H

class FPS final {
private:
	int mStartTime;         //����J�n����
	int mCount;             //�J�E���^
	float mFps;             //fps
	static const int N = 60;//���ς����T���v����
	static const int AVG_FPS = 60;	//�ݒ肵��FPS
public:
	FPS();
	void Wait();
	void Update();
	void Draw();
};

#endif // !_FPS_H