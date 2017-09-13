#include"_Header.h"

Game::~Game() {
	Cursor::SetStyle(CursorStyle::Default);
}

void Game::init() {
	m_data->lastScore = 0;
}

void Game::update() {
	if (!onGame() && !m_countDownTimer.isActive())
	{
		m_countDownTimer.start();
	}

	if (!onGame() && m_countDownTimer.ms() >= 3000)
	{
		m_gameTimer.start();

		m_biscuit = generateBiscuit();
	}

	if (!onGame())
	{
		return;
	}

	if (m_gameTimer.ms() >= gameTimeMillisec)
	{
		m_data->lastScore = m_score;

		changeScene(L"Result", 2000);
	}

	const bool handCursor = m_biscuit.mouseOver;

	Cursor::SetStyle(handCursor ? CursorStyle::Hand : CursorStyle::Default);

	if (m_biscuit.leftClicked)
	{
		++m_score;

		m_biscuit = generateBiscuit();
	}
}

void Game::draw() const {
	if (onCountDown())
	{
		const int32 timeMillisec = Max((3999 - m_countDownTimer.ms()), 0);
		const int32 countDown = timeMillisec / 1000;
		const double e = EaseIn<Easing::Expo>((timeMillisec % 1000) / 1000.0);

		if (countDown > 0)
		{
			Transformer2D t(Mat3x2::Scale(1.0 + e * 2, Window::Center()));
			FontAsset(L"CountDown")(countDown).drawAt(Window::Center());
		}
		else
		{
			Transformer2D t(Mat3x2::Scale(1.0 + (1.0 - e) * 2, Window::Center()));
			FontAsset(L"CountDown")(L"START").drawAt(Window::Center(), AlphaF(e));
		}
	}

	if (!onGame())
	{
		return;
	}

	DrawBiscuit(m_biscuit, m_biscuit.mouseOver);

	const int32 timeLeftMillisec = Max(gameTimeMillisec - m_gameTimer.ms(), 0);

	FontAsset(L"GameTime")(L"TIME: {:0>2}'{:0>2}"_fmt, timeLeftMillisec / 1000, timeLeftMillisec % 1000 / 10).draw(60, 60);
}