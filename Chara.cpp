#include "Chara.hpp"

Chara::Chara(const String& name, const int32& lv)
	:m_name{ name }
	, m_lv{ lv }
{

}

Chara::Chara()
	:m_name{ U"Unknown" }
	, m_lv{ 0 }
{

}

void Chara::show() const
{
	Print << m_name;
	Print << m_lv;
}

// シリアライズに対応させるためのメンバ関数を定義する
template <class Archive>
void Chara::SIV3D_SERIALIZE(Archive& archive)
{
	archive(m_name, m_lv);
}
