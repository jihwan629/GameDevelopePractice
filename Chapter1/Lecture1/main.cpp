#include "Game2D.h"
#include "PrimitivesGallery.h"
#include "TankExample.h"
#include "FaceExample.h"
#include "WalkingPerson.h"
#include "SolarSystem.h"

namespace jm
{
	class RotatingStarExample : public Game2D
	{
		float time = 0.0f;

	public:
		void update() override
		{
			rotate(time * 180.0f);
			drawFilledStar(Colors::gold, 0.4f, 0.25f);

			time += this->getTimeStep();
		}
	};
}

int main(void)
{
	//jm::Game2D().init("This is my digital canvas!", 1280, 960, false).run();
	//jm::SolarSystem().run();
	//jm::PrimitivesGallery().init("Primitive Gallery", 1280, 960, false).run();
	//jm::FaceExample().run();
	//jm::WalkingPerson().run();
	//jm::TankExample().run();

	jm::RotatingStarExample().init("RotatingStarExample", 1280, 960, false, 2).run();
	//jm::MouseExample().init("This is my digital canvas!", 1000, 1000, false).run();

	return 0;
}
