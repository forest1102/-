#include"_Header.h"

Result::~Result() {
	Cursor::SetStyle(CursorStyle::Default);
}

void Result::init() {
	if (FileSystem::Exists(GameInfo::SaveFilePath))
	{
		Deserializer<BinaryReader>{GameInfo::SaveFilePath}(m_highScores);
	}
	else
	{
		Serializer<BinaryWriter>{GameInfo::SaveFilePath}(m_highScores);
	}

	if (m_highScores.back().score <= m_data->lastScore)
	{
		m_highScores.back() = { m_data->lastScore, Date::Today() };

		std::sort(m_highScores.begin(), m_highScores.end(), [](const ScoreData& a, const ScoreData& b)
		{
			return a.score > b.score ? true : a.score == b.score ? a.date > b.date : false;
		});

		Serializer<BinaryWriter>{GameInfo::SaveFilePath}(m_highScores);
	}
}

void Result::update() {
	if (titleButton.leftClicked || Input::KeyEscape.clicked)
	{
		changeScene(L"Title");
	}

	if (tweetButton.leftClicked)
	{
		const String tweetMessage = Format(GameInfo::TweetHead, m_data->lastScore, GameInfo::TweetTail);

		Twitter::OpenTweetWindow(tweetMessage);
	}

	const bool handCursor = titleButton.mouseOver || tweetButton.mouseOver;

	Cursor::SetStyle(handCursor ? CursorStyle::Hand : CursorStyle::Default);
}

void Result::draw() const {
	DrawBiscuit(Circle(Window::Center().x - 80, Window::Height() * 0.4, 60), false);

	const double resultHeight = FontAsset(L"Result")(L"x", m_data->lastScore).region().h;

	FontAsset(L"Result")(L"x", m_data->lastScore).draw(Window::Center().x + 50, Window::Height() * 0.4 - resultHeight / 2);

	DrawBiscuit(titleButton, titleButton.mouseOver);
	FontAsset(L"ResultButton")(L"タイトルへ").drawAt(titleButton.center.movedBy(0, 90));

//	DrawBiscuit(tweetButton, tweetButton.mouseOver);
//	FontAsset(L"ResultButton")(L"結果をツイート").drawAt(tweetButton.center.movedBy(0, 90));
}