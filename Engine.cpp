#include <iostream>
#include "Engine.h"

std::vector<int> Engine::startTiles(unsigned int seed){
    std::srand(seed);
    for (int i = 0; i < 3; i++) {
        int tmp = rand() % 3;
        std::cout << tmp << std::endl;
        startTilesArray[i] = tmp;

    }
    
    return startTilesArray;
}