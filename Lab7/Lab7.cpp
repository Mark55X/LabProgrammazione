#include <iostream>
#include "maze.h"

using my_game::Maze;

int main()
{
    std::cout << "LABIRINTO GAME!\n\n";
    Maze m("maze.txt");
    char** maze = m.matrix();

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << maze[i][j];
        }
        std::cout << std::endl;
    }
}


