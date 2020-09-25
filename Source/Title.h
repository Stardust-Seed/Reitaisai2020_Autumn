#ifndef _TITLE_H_
#define _TITLE_H_

#include "BaseScene.h"
#include "Image.h"
#include "Define.h"
#include "FontHandle.h"
#include "Input.h"
#include "math.h"
#include "SE.h"

class Title final :public BaseScene {
private:
	float deg, rad;             //sin、cosの計算用
	float textPosition;         //タイミング調整用
	int cnt;                    //タイミング調整用
	int r, g, b;                //色用
	int type;
public:
	Title(ISceneChanger* _sceneChanger);
	~Title() = default;
	void Update();				//更新処理
	void Draw();				//描画処理
	void Move();                //移動処理
};

#endif //TITLE_H_