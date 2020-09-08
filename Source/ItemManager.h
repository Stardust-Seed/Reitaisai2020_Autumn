#ifndef _ITEMMANAGER_H
#define _ITEMMANAGER_H

#include "BaseItem.h"

class BasePlayer;

/// <summary>
/// ItemManager class
/// </summary>
class ItemManager final {
private:
	static const int MAX_ITEM_NUM = 50;				//�A�C�e���̉�ʏ�ő吶����
	static const int ITEM_GENERATION_RATE = 100;	//�A�C�e���̐�����

	BaseItem* items[MAX_ITEM_NUM];	//�A�C�e��

	int p_Count;	//P�̎擾���J�E���g
	int s_Count;	//S�̎擾���J�E���g
public:
	/// <summary>
	/// ItemManager�̃R���X�g���N�^
	/// </summary>
	ItemManager();

	/// <summary>
	/// ItemManager�̃R���X�g���N�^
	/// </summary>
	~ItemManager();

	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name="_player">�v���C���[���</param>
	void Update(BasePlayer* _player);

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

	/// <summary>
	/// �A�C�e���̐�������
	/// </summary>
	/// <param name="_ex">�G�l�~�[��x���W</param>
	/// <param name="_ey">�G�l�~�[��y���W</param>
	void SpawnItem(float _ex, float _ey);

	/// <summary>
	/// p_Count�̃Q�b�^�[
	/// </summary>
	/// <returns>p_Count</returns>
	int Get_P_Count() { return p_Count; }

	/// <summary>
	/// s_Count�̃Q�b�^�[
	/// </summary>
	/// <returns>s_Count</returns>
	int Get_S_Count() { return s_Count; }
};

#endif // !_ITEMMANAGER_H