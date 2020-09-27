#ifndef _STAR_H
#define _STAR_H

class Star final {
private:
	float x;
	float y;
	float angle;
	double extX;
	double extY;
public:
	Star(float _x, float _y, double _extX, double _extY, float _angle);
	void Update();
	void Draw();

	float GetX() { return x; }
	float GetY() { return y; }
};

#endif // !_STAR_H