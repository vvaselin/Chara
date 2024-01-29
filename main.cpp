# include "Chara.hpp"

void Main()
{
	Chara a{U"You",10};
	{
		// バイナリファイルをオープン
		Serializer<BinaryWriter> writer{ U"tutorial4.bin" };

		if (not writer) // もしオープンに失敗したら
		{
			throw Error{ U"Failed to open `tutorial4.bin`" };
		}

		// シリアライズに対応したデータを記録
		writer(a);

		// writer のデストラクタで自動的にファイルがクローズされる
	}

	// 読み込み先のデータ
	Chara b{};
	{
		// バイナリファイルをオープン
		Deserializer<BinaryReader> reader{ U"tutorial4.bin" };

		if (not reader) // もしオープンに失敗したら
		{
			throw Error{ U"Failed to open `tutorial4.bin`" };
		}

		// バイナリファイルからシリアライズ対応型のデータを読み込む
		// （Array は自動でリサイズが行われる）
		reader(b);
		b.show();
		// reader のデストラクタで自動的にファイルがクローズされる
	}


	while (System::Update())
	{

	}
}
