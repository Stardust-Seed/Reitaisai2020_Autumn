#ifndef _ITEM_P_H
#define _ITEM_P_H

#include "BaseItem.h"

/// <summary>
/// Item_P class
/// </summary>
class Item_P final :public virtual BaseItem {
public:
	/// <summary>
	/// Item_P�̃R���X�g���N�^
	/// </summary>
	/// <param name="_x">x���W</param>
	/// <param name="_y">y���W</param>
	/// <param name="_width">����</param>
	/// <param name="_height">����</param>
	/// <param name="_itemType">�A�C�e�����ʕϐ�</param>
	Item_P(float _x, float _y, float _width, float _height, eItem _itemType);

	/// <summary>
	/// Item_P�̃f�X�g���N�^
	/// </summary>
	~Item_P();

	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name="_player">�v���C���[���</param>
	void Update(BasePlayer* _player);

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();
};

#endif // !_ITEM_P_H
