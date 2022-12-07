#ifndef maze_h
#define maze_h

#include <string>
#include <vector>

using std::string;
using std::vector;

/// <summary>
/// Maze rappresenta un entità che non ha nulla a che fare con il robot
/// il quale definisce solamente UN MECCANISMO MOMENTANEO di fare la prossima 
/// mossa, tramite il suo metodo Move.
///
/// Oppure il metodo Move non riguarda una singola mossa ma tutto il percorso?
/// </summary>
namespace my_game {

	struct Position{
		int x, y;
	};

	class Maze {

	public:
		Maze(string file_path);
		~Maze();
		char** matrix();
		bool set_current_position(Position pos);

	private:
		void AllocateMatrix();

		char** matrix_;
		Position start_position_;
		Position current_position_;
		vector<Position> end_positions_;
		bool isExited;

		static constexpr int kMatrixLength = 9;

	};


}


#endif