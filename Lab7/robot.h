#ifndef robot_h
#define robot_h

#include <string>
#include "maze.h"
using std::string;

namespace my_game {

	class Robot {

	public:
		void virtual move(Maze& const) = 0;

	private:
		


	};
}


#endif