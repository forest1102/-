#include"_Header.h"

Title::~Title() {
	Cursor::SetStyle(CursorStyle::Default);
}

void Title::init() {
	if (GameInfo::WebURL.isEmpty)
	{
		m_menuTexts.erase(m_menuTexts.begin() + 3);
	}

	m_menuBoxes.resize(m_menuTexts.size());

	int32 boxWidth = 0;

	for (const auto& text : m_menuTexts)
	{
		boxWidth = Max(boxWidth, FontAsset(L"Menu")(text).region().w);
	}

	for (auto i : step(m_menuBoxes.size()))
	{
		m_menuBoxes[i].set(240, 280 + i * 80, boxWidth + 80, 60);
	}
}

void Title::update() {
	bool handCursor = false;

	for (auto i : step(m_menuBoxes.size()))
	{
		const Quad item = m_menuBoxes[i].shearedX(20);

		handCursor |= item.mouseOver;

		if (item.mouseOver && m_effectMenuItemStopwatch.elapsed() > 300ms)
		{
			m_effect.add<MenuEffect>(m_menuBoxes[i]);

			m_effectMenuItemStopwatch.restart();
		}

		if (item.leftClicked)
		{
			if (i == 0)
			{
				changeScene(L"Game");
			}
			else if (i == 1)
			{
				changeScene(L"Score");
			}
			else if (i == 2)
			{
				changeScene(L"Credit");
			}
			else if (!GameInfo::WebURL.isEmpty && i == 3)
			{
				Internet::LaunchWebBrowser(GameInfo::WebURL);
			}
			else
			{
				System::Exit();
			}

			break;
		}
	}

	if (m_effectBackgroundStopwatch.elapsed() > 50ms)
	{
		m_effect.add<TitleBackGroundEffect>();

		m_effectBackgroundStopwatch.restart();
	}

	Cursor::SetStyle(handCursor ? CursorStyle::Hand : CursorStyle::Default);
}

void Title::draw() const {
	Graphics2D::SetBlendState(BlendState::Additive);

	m_effect.update();

	Graphics2D::SetBlendState(BlendState::Default);

	const double titleHeight = FontAsset(L"Title")(GameInfo::Title).region().h;

	FontAsset(L"Title")(GameInfo::Title).drawAt(Window::Center().x, titleHeight);

	for (auto i : step(m_menuBoxes.size()))
	{
		m_menuBoxes[i].shearedX(20).draw();

		FontAsset(L"Menu")(m_menuTexts[i]).drawAt(m_menuBoxes[i].center, Color(40));
	}

	const Size versionSize = FontAsset(L"Version")(GameInfo::Version).region().size;

	FontAsset(L"Version")(GameInfo::Version).drawAt(Window::Size().moveBy(-versionSize));
}