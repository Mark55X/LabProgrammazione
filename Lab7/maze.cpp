#include "maze.h"
#include <fstream>

using std::ifstream;

namespace my_game {

	Maze::Maze(string file_path)
	{
		ifstream file(file_path);
		if (file.is_open()) {
			AllocateMatrix();

			std::string line;
			int i = 0;
			while (!file.eof()) { 
				std::getline(file, line);
				int j = 0;			
				for(char character : line) {
					matrix_[i][j++] = character;
					switch (character) {
					case 'S': start_position_.x = i;
							  start_position_.y = j;
							  current_position_.x = i;
							  current_position_.y = j;
							  break;

					case 'E':Position pos;
							 pos.x = i;
							 pos.y = j;
							 end_positions_.push_back(pos);
							 break;
					}
				}

				if (j != 8) {
					// Gestione errore di Maze che ha poche colonne
				}

				i++;
			}

			if (i == 8) {
				// Gestione errore di apertura file
			}
		}
		else 
		{
			// Gestione errore di Maze che ha poche righe
		}
	
		file.close();
	}

	Maze::~Maze()
	{
		for (int i{ 0 }; i < kMatrixLength; i++)
			delete[] matrix_[i];

		delete[] matrix_; 
	}

	char** Maze::matrix()
	{
		return matrix_;
	}

	bool Maze::set_current_position(Position pos)
	{
		if (pos.x < 0
			|| pos.y >= kMatrixLength
			|| pos.x >= kMatrixLength
			|| pos.y < 0)
				return false;

		if (matrix_[pos.x][pos.y] == '*') {
			return false;
		}

		char& curr_pos = matrix_[current_position_.x][current_position_.y];
		if (curr_pos != 'S') {
			curr_pos = ' ';
			matrix_[pos.x][pos.y] = 'R';
		}
		
		current_position_ = pos;
	}

	void Maze::AllocateMatrix() {
		matrix_ = new char* [kMatrixLength] ;
		for (int i{ 0 }; i < kMatrixLength; i++)
			matrix_[i] = new char[kMatrixLength];
	}
	
}

