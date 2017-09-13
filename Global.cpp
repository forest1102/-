#include"_Header.h"

void DrawBiscuit(const Circle& c, bool drawShadow)
{
	c.drawShadow({ 0, 2 }, 12, 2 + drawShadow * 2)
		.draw(Color(250, 180, 100))
		.drawFrame(1, 1, Color(240, 140, 80));

	Circle(c.center, 1.5).draw(ColorF(0.0, 0.3));

	for (auto i : step(6))
	{
		Circle(c.center + Circular(c.r * 0.5, i * 60_deg), 1.5).draw(ColorF(0.0, 0.3));
	}
}