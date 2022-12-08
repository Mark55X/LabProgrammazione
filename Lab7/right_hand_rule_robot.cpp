#include "right_hand_rule_robot.h"
#include <vector>
#include <stdexcept>
#include <random>
#include <chrono>

using std::rand;
using std::vector;

namespace my_game {

	void RightHandRuleRobot::move(Maze& const maze)
	{

		//Filtraggio posizioni ammesse per lo spostamento
		const char** matrix = maze.matrix();
		Position current_pos = maze.current_position();
		vector<Position> filtered_pos;

		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i == 0 && j == 0) continue;

				Position newPosition;
				newPosition.x = current_pos.x + i;
				newPosition.y = current_pos.y + j;

				// Verifico se non è corretta negli standard di Maze 
				// (dovrebbe svolgere Maze questo controllo)
				if (newPosition.x < 0 ||
					newPosition.y < 0 ||
					newPosition.x > 8 ||
					newPosition.y > 8) {
					continue;
				}

				if (matrix[newPosition.x][newPosition.y] != '*' &&
					(newPosition.y == 8 || matrix[newPosition.x][newPosition.y + 1] == '*'))
				{
					filtered_pos.push_back(newPosition);
				}
			}
		}

		bool is_correct = false;

		if (filtered_pos.size() == 0)
			throw std::logic_error("Impossibile trovare una posizione da avanzare");

		while (is_correct == false) {
			std::uniform_int_distribution<> dist(0, filtered_pos.size() - 1);
			unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
			std::default_random_engine gen(seed);
			int random = dist(gen);

			is_correct = maze.set_current_position(filtered_pos[random]);
		}


	}
}
