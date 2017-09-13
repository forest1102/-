#include"_Header.h"

void Score::init() {
	if (FileSystem::Exists(GameInfo::SaveFilePath))
	{
		Deserializer<BinaryReader>{GameInfo::SaveFilePath}(m_highScores);
	}
	else
	{
		Serializer<BinaryWriter>{GameInfo::SaveFilePath}(m_highScores);
	}
}

void Score::update() {
	if ((Input::MouseL | Input::KeyEscape).clicked)
	{
		changeScene(L"Title");
	}
}

void Score::draw() const {
	const int32 h = FontAsset(L"ScoreList").height;

	for (auto i : step(m_highScores.size()))
	{
		const Rect rect = Rect(520, 100).setCenter(Window::Center().x, 120 + i * 120);

		rect.draw(ColorF(1.0, 0.2));

		FontAsset(L"ScoreList")(m_highScores[i].score)
			.draw(rect.pos + Point(42, (rect.h - h) / 2 + 2), Palette::Gray);

		FontAsset(L"ScoreList")(m_highScores[i].score)
			.draw(rect.pos + Point(40, (rect.h - h) / 2));

		const Size dateSize = FontAsset(L"ScoreListDate")(m_highScores[i].date).region().size;

		FontAsset(L"ScoreListDate")(m_highScores[i].date)
			.draw(rect.br.x - dateSize.x - 40, rect.center.y - dateSize.y / 2);


	}
}