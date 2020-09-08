#ifndef _BUFFMANAGER_H
#define _BUFFMANAGER_H

class EnemyManager;
class ItemManager;

/// <summary>
/// BuffManager class
/// </summary>
class BuffManager final {
private:


	int powerLevel;		//���݂̃p���[�o�t���x��
	int speedLevel;		//���݂̃X�s�[�h�o�t���x��
	float powerBuff;	//�o�t����p���[
	float speedBuff;	//�o�t���鑬�x
public:
	/// <summary>
	/// BuffManager�̃R���X�g���N�^
	/// </summary>
	BuffManager();

	void Update(ItemManager* _itemManager, EnemyManager* _enemyManager);

	/// <summary>
	/// ���݂̃p���[�o�t���x�����擾����
	/// </summary>
	/// <returns>���݂̃p���[���x��</returns>
	int GetPowerLevel() { return powerLevel; }

	/// <summary>
	/// ���݂̃X�s�[�h�o�t���x�����擾����
	/// </summary>
	/// <returns>���݂̃X�s�[�h���x��</returns>
	int GetSpeedLevel() { return speedLevel; }

	/// <summary>
	/// �o�t����p���[���擾����
	/// </summary>
	/// <returns>�o�t����p���[</returns>
	float GetPowerBuff() { return powerBuff; }

	/// <summary>
	/// �o�t���鑬�x���擾����
	/// </summary>
	/// <returns>�o�t���鑬�x</returns>
	float GetSpeedBuff() { return speedBuff; }
};

#endif // !_BUFFMANAGER_H