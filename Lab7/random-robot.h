#ifndef random_robot_h
#define random_robot_h

#include <string>
#include "maze.h"
#include "robot.h"

using std::string;
using my_game::Robot;

namespace my_game {

	class RandomRobot :public Robot{

	public:
		 void move(Maze& const) override;

	private:

	};
}


#endif