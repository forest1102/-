#pragma once

class Game : public MyApp::Scene
{
private:

	static constexpr int32 gameTimeMillisec = 20 * 1000;

	Stopwatch m_countDownTimer;

	Stopwatch m_gameTimer;

	Circle m_biscuit;

	int32 m_score = 0;

	Circle generateBiscuit() const
	{
		return Circle(RandomVec2(RectF(Window::Size() * 0.8).setCenter(Window::Center())), Random(40, 60));
	}

	bool onCountDown() const
	{
		return m_countDownTimer.isActive() && m_countDownTimer.ms() < 4000;
	}

	bool onGame() const
	{
		return m_gameTimer.isActive();
	}

public:

	~Game();

	void init() override;

	void update() override;

	void draw() const override;
};