#ifndef _TITLE_H_
#define _TITLE_H_

#include "BaseScene.h"
#include "Image.h"
#include "Define.h"
#include "FontHandle.h"
#include "Input.h"
#include "math.h"
#include "BGM.h"
#include "SE.h"

class Title final :public BaseScene {
private:
	double deg, rad;            //sin�Acos�̌v�Z�p
	int cnt;                    //�^�C�~���O�����p
	int alpha;                  //�����x
	int type;                   //�\���L�����p
public:
	Title(ISceneChanger* _sceneChanger, Parameter* _parameter);
	~Title() = default;
	void Update(GameResource* _gameRes);				//�X�V����
	void Draw(GameResource* _gameRes);				//�`�揈��
	void Move();                //�ړ�����
};

#endif //TITLE_H_