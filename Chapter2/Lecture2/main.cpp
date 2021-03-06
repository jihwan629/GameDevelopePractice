#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"
#include "Triangle.h"
#include "Circle.h"
#include "Box.h"

namespace jm
{
	class Example : public Game2D
	{
	public:
		Triangle my_tri [5];
		Circle my_cir [5];
		Box my_box [5];

		Example()
			: Game2D()
		{
			//my_tri.init(Colors::gold, vec2{ -0.5f, 0.2f }, 0.25f, 45.0f);
			//my_cir.init(Colors::olive, vec2{ 0.1f, 0.1f }, 0.2f);
			//my_box.init(Colors::blue, vec2{ 0.0f, 0.5f }, 0.15f, 0.25f);

			RandomNumberGenerator rnd;

			for (int i = 0; i < 5; i++)
			{
				my_tri[i].init(Colors::gold, vec2{ rnd.getFloat(-1.0f, 1.0f), rnd.getFloat(-0.5f, 0.5f) }
					, 0.25f, rnd.getFloat(0.0f, 360.0f));
				my_cir[i].init(Colors::olive, vec2{ rnd.getFloat(-1.0f, 1.0f), rnd.getFloat(-0.5f, 0.5f) }
					, 0.2f);
				my_box[i].init(Colors::blue, vec2{ rnd.getFloat(-1.0f, 1.0f), rnd.getFloat(-0.5f, 0.5f) }
					, 0.15f, 0.25f);
			}
		}

		void update() override
		{
			//my_tri.draw();
			//my_cir.draw();
			//my_box.draw();

			for (int i = 0; i < 5; i++)
			{
				my_tri[i].draw();
				my_cir[i].draw();
				my_box[i].draw();
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
