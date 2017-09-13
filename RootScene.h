#pragma once
///////////////////////////////////////////////////////////////////////
//
//  ゲームの基本情報
//
namespace GameInfo
{
	// ゲームのタイトル
	const String Title = L"Biscuit Clicker";

	// ゲームのバージョン（空の文字列も OK）
	const String Version = L"";

	// ゲームの Web サイト（無い場合は空の文字列にする）
	const String WebURL = L"";

	// 結果ツイートの文章（TweetHead + score + TweetTail)
	const String TweetHead = L"";

	const String TweetTail = L"";

	// ゲームの背景色
	const ColorF BackgroundColor = ColorF(0.4, 0.7, 0.5);

	// シーン切り替え時のフェードイン・アウトの色
	const ColorF FadeInColor = ColorF(1.0, 1.0, 1.0);

	// タイトルのフォントサイズ
	const int32 TitleFontSize = 72;

	// メニューのフォントサイズ
	const int32 MenuFontSize = 24;

	// セーブデータの保存場所
	const FilePath SaveFilePath = L"Save/Score.dat";

	const int MAX_SCORE_SIZE = 5;

	// スタッフロールのクレジット（項目は増減できる）
	const Array<std::pair<String, Array<String>>> Credits
	{
		{ L"ゲームデザイン",{ L"Aaa Aaaa" } },
		{ L"プログラム",{ L"Bbb Bbbb", L"Cccc Cccccc" } },
		{ L"ゲームアート",{ L"Ddddd Ddddd" } },
		{ L"音楽",{ L"Eeeee Eeee" } },
		{ L"Special Thanks",{ L"You!" } },
	};
}

///////////////////////////////////////////////////////////////////////
//
//  全てのシーンからアクセスできるデータ
//
struct GameData
{
	int32 lastScore = 0;
};

using MyApp = SceneManager<String, GameData>;

///////////////////////////////////////////////////////////////////////
//
//  セーブ用スコアデータ
//
struct ScoreData
{
	int32 score;

	Date date;

	template <class Archive>
	void serialize(Archive& archive)
	{
		archive(score, date);
	}
};

