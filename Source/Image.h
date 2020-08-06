#ifndef _IMAGE_H
#define _IMAGE_H

#include <vector>
#include "Singleton.h"

enum eImageType {
	eImageType_Test,
	eImageType_Test2
};

class Image final :public Singleton<Image> {
private:
	std::vector<int> images;

	void MyLoadGraph(const char* _filePath);
	void MyLoadDivGraph(const char* _filePath, int _allNum, int _xNum, int _yNum,
		int _xSize, int _ySize);
public:
	Image();
	~Image() = default;
	void Load(){}
	int GetGraph(eImageType _imageType, int _num = 0);
	void Release();
};

#endif // !_IMAGE_H