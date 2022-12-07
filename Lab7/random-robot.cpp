#include "random-robot.h"
using std::rand;

namespace my_game {

	void RandomRobot::move(Maze& const maze )
	{
		//Genera numeri da -1 a 1
		int range = 1  + 1;
		int x = rand() % range - 1;
		int y = rand() % range - 1;

		Position newPosition;
		newPosition.x = x;
		newPosition.y = y;


	}
}
