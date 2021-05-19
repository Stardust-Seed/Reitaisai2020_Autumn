#ifndef _SCENE_H
#define _SCENE_H

#include "GameResource.h"

//シーンクラス
class Scene {
public:
	Scene() {}											//コンストラクタ
	virtual ~Scene() {}									//デストラクタ
	virtual void Init(GameResource* _gameRes) {}		//初期化処理
	virtual void Final() {}								//終了処理
	virtual void Update(GameResource* _gameRes) {}		//更新処理
	virtual void Draw(GameResource* _gameRes) {}		//描画処理
};

#endif // !_SCENE_H

