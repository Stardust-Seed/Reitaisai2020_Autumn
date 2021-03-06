#ifndef _TITLE_H_
#define _TITLE_H_

#include "Scene.h"
#include "Image.h"
#include "Define.h"
#include "FontHandle.h"
#include "Input.h"
#include "math.h"
#include "BGM.h"
#include "SE.h"

class Title final :public Scene {
private:
	double deg, rad;            //sin、cosの計算用
	int cnt;                    //タイミング調整用
	int alpha;                  //透明度
	int type;                   //表示キャラ用
public:
	Title();
	~Title() = default;
	void Init(GameResource* _gameRes);		//初期化処理
	void Update(GameResource* _gameRes);	//更新処理
	void Draw(GameResource* _gameRes);		//描画処理
	void Move();							//移動処理
};

#endif //TITLE_H_