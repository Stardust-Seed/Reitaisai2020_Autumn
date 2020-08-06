#include <DxLib.h>
#include "Image.h"

Image::Image() {
	MyLoadGraph("./res/Image/Test.png");
	MyLoadDivGraph("./res/Image/Test.png", 4, 2, 2, 512, 288);
}

void Image::Release() {
	for (auto release : images) {
		DeleteGraph(release);
	}
	images.clear();
}

int Image::GetGraph(eImageType _imageType, int _num) {

	int identIndex = 0;

	switch (_imageType)
	{
	case eImageType_Test:
		identIndex = 0;
		return images[identIndex];
		break;
	case eImageType_Test2:
		identIndex = 1;
		return images[identIndex + _num];
		break;
	default:
		exit(EXIT_FAILURE);
		break;
	}

	return 0;
}

/*‰æ‘œ‚ğ“Ç‚İ‚Ş*/
void Image::MyLoadGraph(const char* _filePath) {
	int tmp = LoadGraph(_filePath);
	images.push_back(tmp);
}

/*‰æ‘œ‚ğ•ªŠ„‚µ‚Ä“Ç‚İ‚Ş*/
void Image::MyLoadDivGraph(const char* _filePath, int _allNum, int _xNum, int _yNum,
	int _xSize, int _ySize) {
	int tmp[100];

	LoadDivGraph(_filePath, _allNum, _xNum, _yNum, _xSize, _ySize, tmp);

	for (auto add : tmp) {
		images.push_back(add);
	}
}