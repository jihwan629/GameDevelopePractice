#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"
#include "Triangle.h"
#include "Circle.h"
#include "Box.h"
#include <memory>

namespace jm
{
	class Example : public Game2D
	{
	public:

		//std::vector<GeometricObject *> my_objs;
		std::vector<std::shared_ptr<GeometricObject>> my_objs;

		Example()
			: Game2D()
		{
			/*auto *my_tri = new Triangle(Colors::gold, vec2{ -0.5f, 0.2f }, 0.25f);
			auto *my_cir = new Circle(Colors::olive, vec2{ 0.1f, 0.1f }, 0.2f);
			auto *my_box = new Box(Colors::blue, vec2{ 0.0f, 0.5f }, 0.15f, 0.25f);*/

			/*my_objs.push_back(my_tri);
			my_objs.push_back(my_cir);
			my_objs.push_back(my_box);*/

			my_objs.push_back(std::make_shared<Triangle>(Colors::gold, vec2{ -0.5f, 0.2f }, 0.25f));
			my_objs.push_back(std::make_shared<Circle>(Colors::olive, vec2{ 0.1f, 0.1f }, 0.2f));
			my_objs.push_back(std::make_shared<Box>(Colors::blue, vec2{ 0.0f, 0.5f }, 0.15f, 0.25f));
		}

		~Example()
		{
			//for (const auto &obj : my_objs)
			//	delete obj;
		}

		void update() override
		{
			for (const auto &obj : my_objs)
				obj->draw();
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
