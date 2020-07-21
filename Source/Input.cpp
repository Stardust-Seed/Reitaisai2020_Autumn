#include "Input.h"
#include <DxLib.h>


/*************************************************
�V���O���g�����O������ĂԂɂ̓C���X�^���X���擾���Ă���->UpdateKey()�ŃA�N�Z�X����
������
Input::Instance()->UpdateKey();

*****************************************************
���̗�̏ꍇ�́AEnter�L�[���������u�Ԃ������������s����遫
(KEY_INPUT_RETURN) == 1)�ŁAEnter�L�[�������ꂽ�ŏ���1�t���[���ڂ������������s���Ă���
(KEY_INPUT_RETURN) == 1)��==1�������ƁA������Ă���Ԃ����Ɠ��������Ɏg����B���Ԃ�B
******************************************************
DrawFormatString(0, 0, white, "�����Ă���F%d", Input::Instance()->GetPressCount(KEY_INPUT_RETURN) == 1);

*************************************************/


Input::Input() {

    // �L�[�J�E���g�̃��������
    memset(KeyPressCount, 0, sizeof(KeyPressCount));

}

// �L�[�̓��͏�Ԃ��X�V����
int Input::UpdateKey() {
    char tmpKey[KEY_NUM];          // ���݂̃L�[�̓��͏�Ԃ��i�[����
    GetHitKeyStateAll(tmpKey);     // �S�ẴL�[�̓��͏�Ԃ𓾂�
    for (int i = 0; i < KEY_NUM; i++) {
        if (tmpKey[i] != 0) {       // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
            KeyPressCount[i]++;     // ���Z
        }
        else {                      // ������Ă��Ȃ����
            KeyPressCount[i] = 0;   // 0�ɂ���
        }
    }
    return 0;
}

//keyCode�̃L�[��������Ă���t���[������Ԃ�
int Input::GetPressCount(int keyCode) {
    if (!Input::IsAvailableCode(keyCode)) {
        return -1;
    }
    return KeyPressCount[keyCode];
}

//keyCode���L���Ȓl���`�F�b�N����
bool Input::IsAvailableCode(int keyCode) {
    if (!(0 <= keyCode && keyCode < KEY_NUM)) {
        return false;
    }
    return true;
}