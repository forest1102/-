#pragma once

///////////////////////////////////////////////////////////////////////
//
//  �^�C�g����ʂ̔w�i�G�t�F�N�g
//
struct TitleBackGroundEffect : IEffect
{
	Line m_line;

	TitleBackGroundEffect()
	{
		const Vec2 pos = RandomVec2(Window::ClientRect());
		const Vec2 direction = Circular(Window::Width() + Window::Height(), Random(TwoPi));
		m_line.set(pos - direction, pos + direction);
	}

	bool update(double timeSec)
	{
		m_line.draw(2, AlphaF((1.0 - Abs(timeSec - 1.0)) * 0.3));
		return timeSec < 2.0;
	}
};

///////////////////////////////////////////////////////////////////////
//
//  �^�C�g����ʂ̃��j���[�I�����̃G�t�F�N�g
//
struct MenuEffect : IEffect
{
	Rect m_rect;

	MenuEffect(const Rect& rect)
		: m_rect(rect) {}

	bool update(double timeSec)
	{
		const double e = EaseOut<Easing::Quad>(timeSec);
		RectF(m_rect).stretched(e * 20).shearedX(20).draw(AlphaF((1.0 - e) * 0.4));
		return timeSec < 1.0;
	}
};



///////////////////////////////////////////////////////////////////////
//
//  �^�C�g�����
//
class Title : public MyApp::Scene
{
private:

	Effect m_effect;

	Stopwatch m_effectBackgroundStopwatch{ true };

	Stopwatch m_effectMenuItemStopwatch{ true };

	Array<Rect> m_menuBoxes;

	Array<String> m_menuTexts =
	{
		L"�Q�[���X�^�[�g",
		L"�X�R�A",
		L"�N���W�b�g",
		L"Web�y�[�W",
		L"��߂�"
	};

public:

	~Title();

	void init() override;

	void update() override;

	void draw() const override;
};