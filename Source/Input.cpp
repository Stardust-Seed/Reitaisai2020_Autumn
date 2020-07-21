#include "Input.h"
#include <DxLib.h>


/*************************************************
シングルトンを外部から呼ぶにはインスタンスを取得してから->UpdateKey()でアクセスする
↓↓↓
Input::Instance()->UpdateKey();

*****************************************************
↓の例の場合は、Enterキーを押した瞬間だけ処理が実行される↓
(KEY_INPUT_RETURN) == 1)で、Enterキーが押された最初の1フレーム目だけ処理を実行している
(KEY_INPUT_RETURN) == 1)の==1を消すと、押されている間ずっと動く処理に使える。たぶん。
******************************************************
DrawFormatString(0, 0, white, "押している：%d", Input::Instance()->GetPressCount(KEY_INPUT_RETURN) == 1);

*************************************************/


Input::Input() {

    // キーカウントのメモリ解放
    memset(KeyPressCount, 0, sizeof(KeyPressCount));

}

// キーの入力状態を更新する
int Input::UpdateKey() {
    char tmpKey[KEY_NUM];          // 現在のキーの入力状態を格納する
    GetHitKeyStateAll(tmpKey);     // 全てのキーの入力状態を得る
    for (int i = 0; i < KEY_NUM; i++) {
        if (tmpKey[i] != 0) {       // i番のキーコードに対応するキーが押されていたら
            KeyPressCount[i]++;     // 加算
        }
        else {                      // 押されていなければ
            KeyPressCount[i] = 0;   // 0にする
        }
    }
    return 0;
}

//keyCodeのキーが押されているフレーム数を返す
int Input::GetPressCount(int keyCode) {
    if (!Input::IsAvailableCode(keyCode)) {
        return -1;
    }
    return KeyPressCount[keyCode];
}

//keyCodeが有効な値かチェックする
bool Input::IsAvailableCode(int keyCode) {
    if (!(0 <= keyCode && keyCode < KEY_NUM)) {
        return false;
    }
    return true;
}