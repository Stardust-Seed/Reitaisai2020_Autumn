#ifndef _OBJECT_H
#define _OBJECT_H

class Object
{
protected:
	float x;		//x���W
	float y;		//y���W
	float cx;		//���S���Wx
	float cy;		//���S���Wy
	float width;	//����
	float height;	//�c��

	bool isHit;     //�����蔻��̃t���O

public:
	virtual bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh) = 0;
	// m = my ����   o = opnet ����

	virtual void Draw() = 0;   //�`�揈��
	
};

#endif //