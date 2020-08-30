#include"DxLib.h"
#include"Bullet.h"
#include"BulletManager.h"

//�R���X�g���N�^
BulletManager::BulletManager()
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		//NULL�����鎖�ŁA��Ă�delete���鎞��
		//NULL���������|�C���^�͖�������邽�߃G���[���Ȃ��Ȃ�
		bullet[i] = NULL;
	}

	activeBullet = 0;  //�ŏ��̓A�N�e�B�u�Ȓe�͂Ȃ�

}
//�f�X�g���N�^
BulletManager::~BulletManager()
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		delete bullet[i];
	}

}
//�e�𔭎˂���֐�
void BulletManager::Shot(VECTOR& pos, int pl_pos, bool pl_attack)
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		//NULL�̕���T����,���I�m�ۂ���̂�
		if (bullet[i] == NULL)
		{
			bullet[i] = new Bullet(pos, pl_pos, pl_attack);
			activeBullet++;
			break;
		}
	}
}
//�X�V����
void BulletManager::Update(EnemyManager* _enemyManager)
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		//NULL�łȂ��ꍇ,Bullet��Update�֐����s��
		if (bullet[i] != NULL)
		{
			bullet[i]->Update(_enemyManager);

			//�e����ʊO�ɏo�Ă����ꍇ���e���G�ɓ��������ꍇ
			if (bullet[i]->Get_isActive() == false)
			{
				//�폜����NULL�����āA�܂��g����悤�ɂ���
				delete bullet[i];
				bullet[i] = NULL;
				activeBullet--;
			}
		}
	}

}
//�`�揈��
void BulletManager::Draw()
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		//NULL�łȂ��ꍇ,Bullet��Draw�֐����s��
		if (bullet[i] != NULL)
		{
			bullet[i]->Draw();

		}
	}

}
//�e���U�������̃Q�b�^�[
bool BulletManager::Get_IsActive(int i) {
	if (bullet[i] != NULL) {
		return bullet[i]->Get_isActive();
	}

	return false;
}
//�e��x���W�Q�b�^�[
float BulletManager::Get_X(int i) {
	if (bullet[i] != NULL) {
		return bullet[i]->Get_x();
	}
}
//�e��y���W�Q�b�^�[
float BulletManager::Get_Y(int i) {
	if (bullet[i] != NULL) {
		return bullet[i]->Get_y();
	}
}
//�e��width�Q�b�^�[
float BulletManager::Get_Width(int i) {
	if (bullet[i] != NULL) {
		return bullet[i]->Get_width();
	}
}
//�e��height�Q�b�^�[
float BulletManager::Get_Height(int i) {
	if (bullet[i] != NULL) {
		return bullet[i]->Get_height();
	}
}
//�e�̃A�N�e�B�u�Q�b�^�[
int BulletManager::Get_ActiveBullet() {
		return activeBullet;
}
//�e�̍ő吔�̃Q�b�^�[
int BulletManager::Get_MaxBullet() {
	return MAX_BULLET;
}
bool BulletManager::Get_IsHit(int i) {
	if (bullet[i] != NULL) {
		return bullet[i]->Get_isHit();
	}
}
void BulletManager::Set_isActive(int i, bool flg) {

	if (bullet[i] != NULL) {
		bullet[i]->Set_isActive(flg);
	}
}