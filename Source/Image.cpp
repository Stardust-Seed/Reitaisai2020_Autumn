#include <DxLib.h>
#include "Image.h"

Image::Image() {
	//画像の読み込み
	MyLoadGraph("./res/Image/東方防衛隊.png");
	MyLoadGraph("./res/Image/darkness.png");
	MyLoadGraph("./res/Image/sakuya_tatie01.png");
	MyLoadGraph("./res/Image/sakuya_tatie02.png");
	MyLoadGraph("./res/Image/sakuya_tatie03.png");
	MyLoadGraph("./res/Image/Fran_tatie01.png");
	MyLoadGraph("./res/Image/Fran_tatie02.png");
	MyLoadGraph("./res/Image/Fran_tatie03.png");
	MyLoadGraph("./res/Image/sakuya01.png");
	MyLoadGraph("./res/Image/sakuya02.png");
	MyLoadGraph("./res/Image/Fran01.png");
	MyLoadGraph("./res/Image/Fran02.png");
	MyLoadGraph("./res/Image/enemy01.png");
	MyLoadGraph("./res/Image/enemy02.png");
}

void Image::Release() {
	for (auto release : images) {
		DeleteGraph(release);
	}
	images.clear();
}

int Image::GetGraph(eImageType _imageType, int _num) {
	//出力する画像を選択
	switch (_imageType) {
	case eImageType::Title_Logo:
		return images[static_cast<int>(eImageType::Title_Logo)];
	case eImageType::Event_Darkness:
		return images[static_cast<int>(eImageType::Event_Darkness)];
	case eImageType::Spicture_Sakuya01:
		return images[static_cast<int>(eImageType::Spicture_Sakuya01)];
	case eImageType::Spicture_Sakuya02:
		return images[static_cast<int>(eImageType::Spicture_Sakuya02)];
	case eImageType::Spicture_Sakuya03:
		return images[static_cast<int>(eImageType::Spicture_Sakuya03)];
	case eImageType::Spicture_Fran01:
		return images[static_cast<int>(eImageType::Spicture_Fran01)];
	case eImageType::Spicture_Fran02:
		return images[static_cast<int>(eImageType::Spicture_Fran02)];
	case eImageType::Spicture_Fran03:
		return images[static_cast<int>(eImageType::Spicture_Fran03)];
	case eImageType::Gpicture_Sakuya01:
		return images[static_cast<int>(eImageType::Gpicture_Sakuya01)];
	case eImageType::Gpicture_Sakuya02:
		return images[static_cast<int>(eImageType::Gpicture_Sakuya02)];
	case eImageType::Gpicture_Fran01:
		return images[static_cast<int>(eImageType::Gpicture_Fran01)];
	case eImageType::Gpicture_Fran02:
		return images[static_cast<int>(eImageType::Gpicture_Fran02)];
	case eImageType::Gpicture_Enemy01:
		return images[static_cast<int>(eImageType::Gpicture_Enemy01)];
	case eImageType::Gpicture_Enemy02:
		return images[static_cast<int>(eImageType::Gpicture_Enemy02)];
	default:
		exit(EXIT_FAILURE);
		break;
	}

	return 0;
}

/*画像を読み込む*/
void Image::MyLoadGraph(const char* _filePath) {
	int tmp = LoadGraph(_filePath);
	images.push_back(tmp);
}

/*画像を分割して読み込む*/
void Image::MyLoadDivGraph(const char* _filePath, int _allNum, int _xNum, int _yNum,
	int _xSize, int _ySize) {
	int tmp[100];

	LoadDivGraph(_filePath, _allNum, _xNum, _yNum, _xSize, _ySize, tmp);

	for (auto add : tmp) {
		images.push_back(add);
	}
}