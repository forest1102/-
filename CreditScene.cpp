#include"_Header.h"

void Credit::init() {
	double y = 0;

	for (const auto& credit : GameInfo::Credits)
	{
		m_credits.emplace_back(credit.first, y, true);
		y += 70;

		for (const auto& name : credit.second)
		{
			m_credits.emplace_back(name, y, false);
			y += 60;
		}

		y += 60;
	}

	m_height = y;
}

void Credit::update() {
	if ((Input::MouseL | Input::KeyEscape).clicked)
	{
		changeScene(L"Title");
	}

	if ((m_height + yOffset()) < 0)
	{
		m_stopwatch.restart();
	}
}

void Credit::draw() const {
	const double offset = yOffset();

	for (const auto& credit : m_credits)
	{
		FontAsset(std::get<bool>(credit) ? L"CreditBig" : L"CreditSmall")(std::get<String>(credit))
			.drawAt(Window::Center().x, std::get<double>(credit) + offset);
	}
}