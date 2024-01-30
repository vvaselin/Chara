#pragma once
#include "Common.hpp"

//キャラの情報
class Chara
{
public:
	Chara(const String& name, const int32& lv);

	Chara();

	void show() const;

	// シリアライズに対応させるためのメンバ関数を定義する
	template <class Archive>
	void SIV3D_SERIALIZE(Archive& archive)
	{
		archive(m_name, m_lv);
	}

private:
	String m_name;
	int32 m_lv;
};
