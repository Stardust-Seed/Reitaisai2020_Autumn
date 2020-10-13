#ifndef _BUFFMANAGER_H
#define _BUFFMANAGER_H

class EnemyManager;
class ItemManager;

/// <summary>
/// BuffManager class
/// </summary>
class BuffManager final {
private:
	const int MAX_BUFFLEVEL = 3;	//�o�t���x���̍ő�l

	const float POWERBUFF_LV0 = 1.0f;	//�U���o�tLv0
	const float POWERBUFF_LV1 = 1.25f;	//�U���o�tLv1
	const float POWERBUFF_LV2 = 1.5f;	//�U���o�tLv2
	const float POWERBUFF_LV3 = 1.75f;	//�U���o�tLv3

	const float SPEEDBUFF_LV0 = 1.0f;	//���x�o�tLv0
	const float SPEEDBUFF_LV1 = 1.25f;	//���x�o�tLv1
	const float SPEEDBUFF_LV2 = 1.5f;	//���x�o�tLv2
	const float SPEEDBUFF_LV3 = 1.75f;	//���x�o�tLv3

	int powerLevel;			//���݂̃p���[�o�t���x��
	int speedLevel;			//���݂̃X�s�[�h�o�t���x��
	bool isPowerLevelMax;	//���݂̃p���[�o�t�̃��x���}�b�N�X�t���O
	bool isSpeedLevelMax;	//���݂̃X�s�[�h�o�t�̃��x���}�b�N�X�t���O

	bool isLevelDown;	//���x���_�E���t���O

	float powerBuff;	//�o�t����p���[
	float speedBuff;	//�o�t���鑬�x
public:
	/// <summary>
	/// BuffManager�̃R���X�g���N�^
	/// </summary>
	BuffManager();

	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name="_itemManager">�A�C�e���}�l�[�W���[�̏��</param>
	/// <param name="_enemyManager">�G�l�~�[�}�l�[�W���[�̏��</param>
	void Update(ItemManager* _itemManager, EnemyManager* _enemyManager);

	/// <summary>
	/// ���x���_�E���̏���
	/// </summary>
	void DownBuffLevel();

	/// <summary>
	///	�p���[�o�t���x���̃��x���㏸����
	/// </summary>
	/// <param name="_powerCount">�p���[�A�C�e���̎擾��</param>
	/// <returns>�擾�����l or 0(Error�̂Ƃ�)</returns>
	int PowerBuff_LevelUpCheck(int _powerCount);

	/// <summary>
	/// �X�s�[�h�o�t���x���̃��x���㏸����
	/// </summary>
	/// <param name="_speedCount">�X�s�[�h�A�C�e���̎擾��</param>
	/// <returns>�擾�����l or 0(Error�̂Ƃ�)</returns>
	int SpeedBuff_LevelUpCheck(int _speedCount);

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

	/// <summary>
	/// ���݂̃p���[�o�t�̃��x���}�b�N�X�t���O���擾����
	/// </summary>
	/// <returns>���݂̃p���[�o�t�̃��x���}�b�N�X�t���O</returns>
	bool GetIsPowerLevelMax() { return isPowerLevelMax; }

	/// <summary>
	/// ���݂̃X�s�[�h�o�t�̃��x���}�b�N�X�t���O���擾����
	/// </summary>
	/// <returns>���݂̃X�s�[�h�o�t�̃��x���}�b�N�X�t���O</returns>
	bool GetIsSpeedLevelMax() { return isSpeedLevelMax; }

	/// <summary>
	/// ���x���_�E���t���O���擾����
	/// </summary>
	/// <returns>���x���_�E���t���O</returns>
	bool GetIsLevelDown() { return isLevelDown; }
};

#endif // !_BUFFMANAGER_H