#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"

namespace jm
{
	class House
	{
	private:
		RGB roof_color;
		vec2 pos;
		float angle;

	public:
		House()
			: roof_color(Colors::red), pos(0.0f, 0.0f), angle(0.0f)
		{}

		void setPos(const vec2 &_pos)
		{
			pos = _pos;
		}

		void setRoof_color(const RGB &_color)
		{
			roof_color = _color;
		}

		void setAngle(const float &_angle)
		{
			angle = _angle;
		}

		void draw()
		{
			beginTransformation();
			{
				translate(pos);
				rotate(angle);

				// body
				drawFilledBox(Colors::yellow, 0.2f, 0.2f);

				// roof
				drawFilledTriangle(roof_color, { -0.13f, 0.1f }, { 0.13f, 0.1f }, { 0.0f, 0.2f });
				drawWiredTriangle(roof_color, { -0.13f, 0.1f }, { 0.13f, 0.1f }, { 0.0f, 0.2f });

				//window
				drawFilledBox(Colors::skyblue, 0.1f, 0.1f);
				drawWiredBox(Colors::skyblue, 0.1f, 0.1f);
				drawLine(Colors::gray, { 0.0f, -0.05f }, Colors::gray, { 0.0f, 0.05f });
				drawLine(Colors::gray, { -0.05f, 0.0f }, Colors::gray, { 0.05f, 0.0f });
			}
			endTransformation();
		}
	};

	class Example : public Game2D
	{
	public:
		House houses[10];

		Example()
		{
			RandomNumberGenerator rnd;

			for (int i = 0; i < 10; i++)
			{
				houses[i].setPos({ -1.3f + 0.3f * float(i), rnd.getFloat(-0.5f, 0.5f) });
			}
		}

		void update() override
		{
			for (int i = 0; i < 10; i++)
			{
				houses[i].draw();
			}
		}
	};
}

int main(void)
{
	jm::Example().run();
	//jm::Game2D().init("This is my digital canvas!", 1280, 960, false).run();
	//jm::PrimitivesGallery().run();
	
	return 0;
}
