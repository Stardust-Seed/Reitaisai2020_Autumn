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
	float deg, rad;             //sin�Acos�̌v�Z�p
	float textPosition;         //�^�C�~���O�����p
	int cnt;                    //�^�C�~���O�����p
	int r, g, b;                //�F�p
	int type;
public:
	Title(ISceneChanger* _sceneChanger);
	~Title() = default;
	void Update();				//�X�V����
	void Draw();				//�`�揈��
	void Move();                //�ړ�����
};

#endif //TITLE_H_