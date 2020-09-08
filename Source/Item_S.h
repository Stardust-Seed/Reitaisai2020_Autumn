#ifndef _ITEM_S_H
#define _ITEM_S_H

#include "BaseItem.h"

/// <summary>
/// Item_S class
/// </summary>
class Item_S final :public virtual BaseItem {
public:
	/// <summary>
	/// Item_S�̃R���X�g���N�^
	/// </summary>
	/// <param name="_x">x���W</param>
	/// <param name="_y">y���W</param>
	/// <param name="_width">����</param>
	/// <param name="_height">����</param>
	/// <param name="_itemType">�A�C�e�����ʕϐ�</param>
	Item_S(float _x, float _y, float _width, float _height, eItem _itemType);

	/// <summary>
	/// Item_S�̃f�X�g���N�^
	/// </summary>
	~Item_S();

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

#endif // !_ITEM_S_H