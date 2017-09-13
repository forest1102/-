#pragma once

///////////////////////////////////////////////////////////////////////
//
//  Œ‹‰Ê‰æ–Ê
//
class Result : public MyApp::Scene
{
private:

	std::array<ScoreData, GameInfo::MAX_SCORE_SIZE> m_highScores;

	const Circle titleButton = Circle(Window::Center().x - 300, Window::Height() * 0.7, 35);

	const Circle tweetButton = Circle(Window::Center().x + 300, Window::Height() * 0.7, 35);

public:

	~Result();

	void init() override;

	void update() override;

	void draw() const override;
};