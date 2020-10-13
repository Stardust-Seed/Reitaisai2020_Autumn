#ifndef _BASEITEM_H
#define _BASEITEM_H

#include "Object.h"

class BasePlayer;

/// <summary>
/// eItem
/// </summary>
enum class eItem {
	Power,
	Speed,
};

/// <summary>
/// BaseItem class
/// </summary>
class BaseItem :public virtual Object {
private:
	float moveSpeed;	//�A�C�e���̈ړ����x
	bool isActive;		//�A�N�e�B�u��ԃt���O
	eItem itemType;		//�A�C�e�����ʗp�ϐ�
public:
	/// <summary>
	/// BaseItem�̃R���X�g���N�^
	/// </summary>
	/// <param name="_x">x���W</param>
	/// <param name="_y">y���W</param>
	/// <param name="_width">����</param>
	/// <param name="_height">����</param>
	/// <param name="_itemType">�A�C�e�����ʕϐ�</param>
	BaseItem(float _x, float _y, float _width, float _height, eItem _itemType);

	/// <summary>
	/// BaseItem�̃f�X�g���N�^
	/// </summary>
	virtual ~BaseItem() {}

	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name="_player">�v���C���[���</param>
	virtual void Update(BasePlayer* _player) = 0;

	/// <summary>
	/// �`�揈��
	/// </summary>
	virtual void Draw() = 0;

	/// <summary>
	/// �ړ�����
	/// </summary>
	/// <param name="_px">�v���C���[��x���W</param>
	/// <param name="_py">�v���C���[��y���W</param>
	void Move(float _px, float _py);

	/// <summary>
	/// ���݃A�C�e���I�u�W�F�N�g���A�N�e�B�u���`�F�b�N���鏈��
	/// </summary>
	void CheckIsActive();

	/// <summary>
	/// �����蔻�菈��
	/// </summary>
	/// <param name="mx">Item��x���W</param>
	/// <param name="my">Item��y���W</param>
	/// <param name="mw">Item�̉���</param>
	/// <param name="mh">Item�̍���</param>
	/// <param name="ox">���������I�u�W�F�N�g��x���W</param>
	/// <param name="oy">���������I�u�W�F�N�g��y���W</param>
	/// <param name="ow">���������I�u�W�F�N�g�̉���</param>
	/// <param name="oh">���������I�u�W�F�N�g�̍���</param>
	/// <returns>�����������ǂ�����bool�l</returns>
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);

	/// <summary>
	/// itemType�̃Q�b�^�[
	/// </summary>
	/// <returns>�A�C�e���̎��ʃ^�C�v</returns>
	eItem Get_ItemType() { return itemType; }

	/// <summary>
	/// isHit�̃Q�b�^�[
	/// </summary>
	/// <returns>�����������ǂ�����bool�l</returns>
	bool Get_IsHit() { return isHit; }

	/// <summary>
	/// isActive�̃Q�b�^�[
	/// </summary>
	/// <returns>�I�u�W�F�N�g���A�N�e�B�u���ǂ�����bool�l</returns>
	bool Get_IsActive() { return isActive; }
};

#endif // !_BASEITEM_H