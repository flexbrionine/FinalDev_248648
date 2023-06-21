#pragma
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>
#include <cmath>

class Engine
{
public:
    Engine() {};
    ~Engine() {};

    inline std::vector<int> startTiles(unsigned int seed);
    std::vector<int> pushNewElement(std::vector<int> qeue);
    inline std::vector<sf::Sprite> textureObjFromQeue(std::vector<int> qeue);
    void plaseObjFromQeue(std::vector<sf::Sprite> qeueSprites);
    std::vector<std::vector<int>> whitchGrisIsPress(int x, int y);
    int hightestInThisColl(int coll, std::vector<std::vector<int>> gameGrid);
    std::vector<sf::Sprite> updateGridSprites(std::vector<std::vector<int>> gameGrid, sf::RenderWindow& window);
    std::vector<std::vector<int>> grupElements(std::vector<std::vector<int>> gameGrid, int lastMod);
    void moveAnimation(sf::Sprite sp, sf::Vector2f vect, std::vector<int> destiny);
    std::string getScore(std::vector<std::vector<int>> gameGrid);

private:
    std::vector<int> startTilesArray { 0, 0, 0 };
    //std::vector<sf::Sprite> qeueSprites;
    std::vector<std::vector<int>> _position {{ 0, 0 }};

    sf::Texture textureTmpOne;
    sf::Texture textureTmpTwo;
    sf::Texture textureTmpThree;

    sf::Sprite one;
    sf::Sprite two;
    sf::Sprite three;

    std::vector<sf::Sprite> qeueSprites { one, two, three };
    //std::vector<int> newQeue;
    int highColl = 0;
    std::string score;
};

std::vector<int> Engine::startTiles(unsigned int seed){
    std::srand(seed);
    for (int i = 0; i < 3; i++) {
        int tmp = rand() % 3;
        //std::cout << tmp << std::endl;
        startTilesArray[i] = tmp;

    }
    
    return startTilesArray;
}


std::vector<int> Engine::pushNewElement(std::vector<int> qeue){
    qeue.erase(qeue.begin());
    qeue.push_back(rand() % 3);
    return qeue;
}

std::vector<sf::Sprite> Engine::textureObjFromQeue(std::vector<int> qeue){
    
    for (int i = 0; i < 3; i++) {
        if (qeue[i] == 0) {
            //std::cout << "00 ";
            textureTmpOne.loadFromFile("C:/Users/maxon/project/graphics/2.png");
            one.setTexture(textureTmpOne);
            qeueSprites[i] = one;
        }
        if (qeue[i] == 1)
        {
            //std::cout << "11 ";
            textureTmpTwo.loadFromFile("C:/Users/maxon/project/graphics/4.png");
            two.setTexture(textureTmpTwo);
            qeueSprites[i] = two;
        }
        if (qeue[i] == 2)
        {
            //std::cout << "22 ";
            textureTmpThree.loadFromFile("C:/Users/maxon/project/graphics/8.png");
            three.setTexture(textureTmpThree);
            qeueSprites[i] = three;
        }
    }
    //std::cout << std::endl;
    
    return qeueSprites;
}

void Engine::plaseObjFromQeue(std::vector<sf::Sprite> qeueSprites){
    for (int i = 0; i < 3; i++) {
        for (sf::Sprite spr : qeueSprites) {
            switch (i)
            {
            case 0:
                spr.setPosition(sf::Vector2f(100,100));
                break;
            case 1:
                spr.setPosition(sf::Vector2f(200,200));
                break;
            case 2:
                spr.setPosition(sf::Vector2f(300,300));
                break;
            default:
                break;
            }       
        }
    }
}

std::vector<std::vector<int>> Engine::whitchGrisIsPress(int x, int y){
    int row = 0, coll = 0;

    if (x>33 && x<33+65) 
        coll = 1;
    if (x>100 && x<100+65) 
        coll = 2;
    if (x>167 && x<167+65) 
        coll = 3;
    if (x>234 && x<234+65) 
        coll = 4;
    if (x>301 && x<301+65) 
        coll = 5;


    if (y>95 && y<95+65) 
        row = 1;
    if (y>162 && y<162+65)
        row = 2;
    if (y>229 && y<229+65)
        row = 3;
    if (y>296 && y<296+65)
        row = 4;
    if (y>363 && y<363+65)
        row = 5;
    if (y>430 && y<430+65)
        row = 6;
    if (y>497 && y<497+65)
        row = 7;
    if (y>564 && y<564+65)
        row = 8;
    
    _position[0] = {row, coll};

    return _position;
}

int Engine::hightestInThisColl(int coll, std::vector<std::vector<int>> gameGrid){
    int selectedColl = coll-1;

    //cout << selectedColl;
    for (int i = 0; i <= 7; i++) {
        if (gameGrid[i][selectedColl] == -1) {
            //std::cout << i << std::endl;
            return i;
        }
    }
    return -2;
}



//sf::Sprite spriteTmp;
std::vector<int> cordinates { 0, 0 };
                sf::Texture textureTmp, textureTmp1, textureTmp2, textureTmp3, textureTmp4, textureTmp5, textureTmp6, textureTmp7, textureTmp8, textureTmp9, textureTmp10;
                sf::Sprite tmp, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8, tmp9, tmp10;
int x_x = 0, y_y = 0;
std::vector<sf::Sprite> Engine::updateGridSprites(std::vector<std::vector<int>> gameGrid, sf::RenderWindow& window){
    std::vector<sf::Sprite> gridSpritesList;
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 4; j++) {
            if (gameGrid[i][j] != -1) {
                sf::Sprite spriteTmp;
                switch (gameGrid[i][j])
                {
                case 0:
                    textureTmp.loadFromFile("graphics/2.png");
                    tmp.setTexture(textureTmp);
                    spriteTmp = tmp;
                    break;
                case 1:
                    textureTmp1.loadFromFile("graphics/4.png");
                    tmp1.setTexture(textureTmp1);
                    spriteTmp = tmp1;
                    break;
                case 2:
                    textureTmp2.loadFromFile("graphics/8.png");
                    tmp2.setTexture(textureTmp2);
                    spriteTmp = tmp2;
                    break;
                case 3:
                    textureTmp3.loadFromFile("graphics/16.png");
                    tmp3.setTexture(textureTmp3);
                    spriteTmp = tmp3;
                    break;
                case 4:
                    textureTmp4.loadFromFile("graphics/32.png");
                    tmp4.setTexture(textureTmp4);
                    spriteTmp = tmp4;
                    break;
                case 5:
                    textureTmp5.loadFromFile("graphics/64.png");
                    tmp5.setTexture(textureTmp5);
                    spriteTmp = tmp5;
                    break;
                case 6:
                    textureTmp6.loadFromFile("graphics/128.png");
                    tmp6.setTexture(textureTmp6);
                    spriteTmp = tmp6;
                    break;
                case 7:
                    textureTmp7.loadFromFile("graphics/256.png");
                    tmp7.setTexture(textureTmp7);
                    spriteTmp = tmp7;
                    break;
                case 8:
                    textureTmp8.loadFromFile("graphics/512.png");
                    tmp8.setTexture(textureTmp8);
                    spriteTmp = tmp8;
                    break;
                case 9:
                    textureTmp9.loadFromFile("graphics/1024.png");
                    tmp9.setTexture(textureTmp9);
                    spriteTmp = tmp9;
                    break;
                case 10:
                    textureTmp10.loadFromFile("graphics/2048.png");
                    tmp10.setTexture(textureTmp10);
                    spriteTmp = tmp10;
                    break;
                default:
                    break;
                }
                
                //cordinates = {i, j};

                switch (j)
                {
                case 0:
                    x_x = 33;
                    break;

                case 1:
                    x_x = 100;
                    break;

                case 2:
                    x_x = 167;
                    break;

                case 3:
                    x_x = 234;
                    break;
                
                case 4:
                    x_x = 301;
                    break;

                default:
                    break;
                }

                switch (i)
                {
                case 0:
                    y_y = 95;
                    break;

                case 1:
                    y_y = 162;
                    break;

                case 2:
                    y_y = 229;
                    break;
                
                case 3:
                    y_y = 296;
                    break;

                case 4:
                    y_y = 363;
                    break;

                case 5:
                    y_y = 430;
                    break;

                case 6:
                    y_y = 497;
                    break;

                case 7:
                    y_y = 564;
                    break;
                
                default:
                    break;
                }
                
                spriteTmp.setPosition(sf::Vector2f( x_x, y_y ));
                gridSpritesList.push_back(spriteTmp);
            }
        }
    }
    
    return gridSpritesList;
}

bool isMoreObjectsToGrup(std::vector<std::vector<int>> gameGrid){
        for (int i = 0; i <= 7; i++) { //For each element in grid
        for (int j = 0; j <= 4; j++) {
            if (gameGrid[i][j] > -1) {
                if (
                        gameGrid[i][j] == gameGrid[i][j+1]
                    ||  gameGrid[i][j] == gameGrid[i][j-1]
                    ||  gameGrid[i][j] == gameGrid[i+1][j]
                    ||  gameGrid[i][j] == gameGrid[i-1][j]
                ) {
                    return true;
                }
            }
        }}
    return false;
}

std::vector<std::vector<int>> modiGameGrid, modiGameGridtmp;
std::vector<std::vector<int>> sortVertical(std::vector<std::vector<int>> gameGrid){
    modiGameGrid = gameGrid;
    for (int a = 0; a <= 7; a++) { //For each element in grid
    for (int b = 0; b <= 4; b++) {
        if (modiGameGrid[a][b] == -1) {
            if (modiGameGrid[a+1][b] != -1) {
                modiGameGrid[a][b] = modiGameGrid[a+1][b];
                modiGameGrid[a+1][b] = modiGameGrid[a+2][b];
                modiGameGrid[a+2][b] = modiGameGrid[a+3][b];
                modiGameGrid[a+3][b] = modiGameGrid[a+4][b];
                std::cout << "ERROR IN COLL: " << '\n';
            }
            
        }
    }}

    return modiGameGrid;
}


bool sameAroundMe(int i, int k, std::vector<std::vector<int>> modiGameGrid){
    if (modiGameGrid[i][k] == modiGameGrid[i+1][k] || modiGameGrid[i][k] == modiGameGrid[i][k+1]) {
        return true;
    } else {
        return false;
    }
}

std::vector<std::vector<int>> compact(int i, int k, std::vector<std::vector<int>> modiGameGrid, int lastMod){
    modiGameGridtmp = modiGameGrid;


    // if (modiGameGridtmp[i][k] == modiGameGridtmp[i][k-1] && modiGameGridtmp[i][k] == modiGameGridtmp[i][k+1]) {
    //     std::cout << i << ",  " << k << "    double\n";
    //     modiGameGridtmp[i][k] ++;
    //     modiGameGridtmp[i][k+1] = (int)-1;
    //     modiGameGridtmp[i][k] ++;
    //     modiGameGridtmp[i][k-1] = (int)-1;
    // }

    // if (modiGameGridtmp[i][k] == modiGameGridtmp[i][k+1] && modiGameGridtmp[i][k] == modiGameGridtmp[i+1][k]) {
    //     modiGameGridtmp[i][k] ++;
    //     modiGameGridtmp[i][k+1] = (int)-1;
    //     modiGameGridtmp[i][k] ++;
    //     modiGameGridtmp[i+1][k] = (int)-1;
    // }

    if (modiGameGridtmp[i][k] == modiGameGridtmp[i][k+1]) {
        //std::cout << i << ",  " << k << "    right\n";
        modiGameGridtmp[i][k] ++;
        modiGameGridtmp[i][k+1] = (int)-1;
    }

    if (modiGameGridtmp[i][k] == modiGameGridtmp[i+1][k]) {
        modiGameGridtmp[i][k] ++;
        modiGameGridtmp[i+1][k] = (int)-1;
    }

    return modiGameGridtmp;
}


std::vector<std::vector<int>> tryToSortVertical(std::vector<std::vector<int>> modiGameGrid, int lastMod){
    modiGameGridtmp = modiGameGrid;
    int swapInt = -1;
    for (int i = 0; i < 7; i++) {
        for (int k = 0; k <= 4; k++) {
            try {
                if (modiGameGridtmp[i][k] == (int)-1) {
                    if (modiGameGridtmp[i][k] != modiGameGridtmp[i+1][k]) {
                        swapInt = modiGameGridtmp[i][k];
                        modiGameGridtmp[i][k] = modiGameGridtmp[i+1][k];
                        modiGameGridtmp[i+1][k] = swapInt;
                    }
                    
                }
            }
            catch(const std::exception& e) {
                std::cerr << e.what() << '\n';
            }
        }
    }
    return modiGameGridtmp;
}

std::vector<std::vector<int>> Engine::grupElements(std::vector<std::vector<int>> gameGrid, int lastMod){
    modiGameGrid = gameGrid;

    for (int i = 0; i < 7; i++)
    {
        for (int k = 0; k <= 4; k++)
        {
            if (modiGameGrid[i][k] != -1)
            {
                if (sameAroundMe(i, k, modiGameGrid))
                {
                    std::cout << i << ",  " << k << "    is the same\n";

                    modiGameGrid = compact(i, k, modiGameGrid, lastMod);
                }
            }

            modiGameGrid = tryToSortVertical(modiGameGrid, lastMod);

        }
        
    }
     
/*
    if (isMoreObjectsToGrup(modiGameGrid)) {
        //std::cout << "canModify\n";
        for (int i = 0; i <= 7; i++) { //For each element in grid
        for (int j = 0; j <= 4; j++) {
            if (modiGameGrid[i][j] > -1) {

                try {                    
                    if (modiGameGrid[i][j] == modiGameGrid[i][j+1] && modiGameGrid[i][j] != modiGameGrid[i][j-1]) {
                        //if (lastMod == j) {
                            modiGameGrid[i][lastMod] ++;
                            modiGameGrid[i][lastMod+1] = -1;
                        //}
                    }

                    if (modiGameGrid[i][j] == modiGameGrid[i][j-1] && modiGameGrid[i][j] != modiGameGrid[i][j+1]) {
                        //if (lastMod == j) {
                            modiGameGrid[i][lastMod] ++;
                            modiGameGrid[i][lastMod-1] = -1;
                        //}
                    }

                    if (modiGameGrid[i][j] == modiGameGrid[i][j-1] && modiGameGrid[i][j] == modiGameGrid[i][j+1]) {
                        //if (lastMod == j) {
                            modiGameGrid[i][lastMod] += 2;
                            modiGameGrid[i][lastMod-1] = -1;
                            modiGameGrid[i][lastMod+1] = -1;
                        //}
                    }

                    //vertical------------------------------------------------

                    if (modiGameGrid[i][j] == modiGameGrid[i+1][j]) {
                        //if (lastMod == j) {
                            modiGameGrid[i][lastMod] ++;
                            modiGameGrid[i+1][lastMod] = -1;
                        //}
                    }

                    //modiGameGrid = sortVertical(modiGameGrid);

                }
                catch(const std::exception& e) {
                    std::cerr << e.what() << '\n';
                }
            }
        }}
    }
*/
    
    return modiGameGrid;
}

float tmp_x;
void Engine::moveAnimation(sf::Sprite sp, sf::Vector2f vect, std::vector<int> destiny){


    sf::Time delayTime = sf::milliseconds(10);
    sf::Clock clock;


    if (sp.getPosition().x < vect.x) {
        while (sp.getPosition().x != vect.x) {
            tmp_x = sp.getPosition().x;
            tmp_x += 1;
            sp.setPosition(tmp_x, sp.getPosition().y);
        }
        
    }
    

}


std::string Engine::getScore(std::vector<std::vector<int>> gameGrid){
    int x = 0, x_tmp = 0;
    

    for (int i = 0; i < 7; i++) {
        for (int k = 0; k <= 4; k++) {
            if (gameGrid[i][k] != -1) {
                x_tmp = pow(2, gameGrid[i][k]+1);
                x += x_tmp;
            }
    }}

    return std::to_string(x);
}