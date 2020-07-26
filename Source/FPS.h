#ifndef _FPS_H
#define _FPS_H

/*******************************************************************************
参考サイト→https://dixq.net/s/2.html
*******************************************************************************/

class FPS final {
private:
    int fpsTime[2];
    int fpsTime_i;
    int refreshTime;
    float nowFps;
public:
    FPS();
    void Update();
    void Draw()const;
    void Wait();
};

#endif // !_FPS_H