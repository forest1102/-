#pragma once


///////////////////////////////////////////////////////////////////////
//
//  スタッフクレジット
//
class Credit : public MyApp::Scene
{
private:

	Array<std::tuple<String, double, bool>> m_credits;

	double m_height = 0.0;

	Stopwatch m_stopwatch{ true };

	double yOffset() const
	{
		return Window::Height() + 60 - m_stopwatch.ms() / 20.0;
	}

public:

	void init();

	void update() override;

	void draw() const override;
};