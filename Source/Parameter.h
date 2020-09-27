#ifndef _PARAMETER_H
#define _PARAMETER_H

#include <map>
#include <string>

using namespace std;

/// <summary>
/// パラメータクラス
/// </summary>
class Parameter final {
private:
	map<string, int> mapData;	//シーン共有のデータ
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Parameter() = default;

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Parameter() = default;

	/// <summary>
	/// 鍵付きの数値を作成する
	/// </summary>
	/// <param name="_key">鍵の名前</param>
	/// <param name="_val">数値</param>
	void Set(string _key, int _val);

	/// <summary>
	/// 選択された鍵の数値を返す
	/// </summary>
	/// <param name="_key">鍵の名前</param>
	int Get(string _key)const;
};

#endif // !_PARAMETER_H