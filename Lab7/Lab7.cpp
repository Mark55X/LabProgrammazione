#include <iostream>
#include "maze.h"
#include "random_robot.h"
#include "right_hand_rule_robot.h"
#include <random>

using my_game::Maze;
using my_game::RandomRobot;
using my_game::RightHandRuleRobot;

void printMaze(Maze& m) {

    const char** maze = m.matrix();
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << maze[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
}

int main()
{
    std::cout << "LABIRINTO GAME!\n\n";
    Maze m("maze.txt");
    printMaze(m);


    RightHandRuleRobot r;
    int count = 0;
    while(m.end_reached() == false){
        r.move(m);
        printMaze(m);
        count++;
    }
   
    std::cout << "Concluso in: " << count << " mosse";
}



