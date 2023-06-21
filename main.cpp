#include <iostream>
#include <SFML/Graphics.hpp>
#include "Engine.h"
#include <vector>
using namespace std;

#define seed 3
Engine en;

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 800), "SFML works!");
    window.setFramerateLimit(60);
    sf::Texture texture;
    sf::Texture textureTmp;
    sf::Texture one;
    sf::Texture two;

    sf::Font font;
    sf::Text text;

    if (!font.loadFromFile("JetBrainsMono-Regular.ttf")) {
        return 0;
    }
    vector<sf::Sprite> qeueSprites;

    if (!texture.loadFromFile("graphics/01.png")){
        return -1;
    }
    vector<int> startTilesArray = en.startTiles((unsigned int)seed);
    vector<int> qeue;

    for (int i : startTilesArray) {
        qeue.push_back(i);
    }
    cout << qeue[0]<<"   "<<qeue[1]<<"   "<<qeue[2]<<endl;
    
    sf::Sprite background;
    vector<sf::Sprite> spritesBuffer {
        background
    };
    spritesBuffer[0].setTexture(texture);
    text.setFont(font); 
    text.setCharacterSize(24); 


    qeueSprites = en.textureObjFromQeue(qeue);
    qeueSprites[0].setPosition(sf::Vector2f(167,672));
    qeueSprites[1].setPosition(sf::Vector2f(238,675));
    qeueSprites[2].setPosition(sf::Vector2f(306,675));

    vector<vector<int>> gameGrid {
        { -1, -1, -1, -1, -1,},
        { -1, -1, -1, -1, -1,},
        { -1, -1, -1, -1, -1,},
        { -1, -1, -1, -1, -1,},
        { -1, -1, -1, -1, -1,},
        { -1, -1, -1, -1, -1,},
        { -1, -1, -1, -1, -1,},
        { -1, -1, -1, -1, -1,},
    };


    int x, y, highColl = 0;
    static sf::Vector2i mousePos;
    vector<vector<int>> pos;
    vector<int> destiny;
    std::vector<sf::Sprite> gridSpritesList;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left ) {
                mousePos = sf::Mouse::getPosition(window);
                //cout << mousePos.x << "   " << mousePos.y << endl;
                pos = en.whitchGrisIsPress(mousePos.x, mousePos.y);
                if (pos[0][0] != 0 && pos[0][1] != 0) {
                    //cout << pos[0][0] << "   " << pos[0][1] << endl;

                    highColl = en.hightestInThisColl(pos[0][1], gameGrid);
                    if (highColl != -1 && highColl != -2) {
                        destiny = { highColl, pos[0][1]-1};
                        gameGrid[highColl][pos[0][1]-1] = qeue[0];
                        qeue = en.pushNewElement(qeue);
                        /*
                        for (int q : qeue)
                            cout << q << " ";
                        cout << endl;
                        */
                        //sf::Sprite elementToMove = qeueSprites[0];
                        //en.moveAnimation(elementToMove, sf::Vector2f(167,672), destiny);

                        qeueSprites = en.textureObjFromQeue(qeue);
                        qeueSprites[0].setPosition(sf::Vector2f(167,672)); //main
                        qeueSprites[1].setPosition(sf::Vector2f(238,675));
                        qeueSprites[2].setPosition(sf::Vector2f(306,675));


                    }
                }
                sf::Time delayTime = sf::milliseconds(10);
                sf::sleep(delayTime);
                
                for (int i = 0; i < 10; i++) {
                    gameGrid = en.grupElements(gameGrid, pos[0][1]-1);
                }
                
  
            }
            
            if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Right ) {
                for (vector<int> row : gameGrid) {
                    for (int element : row) {
                        cout << element << "   ";
                    }
                    cout << endl;
                }
            }
        }
        window.clear();
        
        
        gridSpritesList = en.updateGridSprites(gameGrid, window);

        for (sf::Sprite s : spritesBuffer) {
            window.draw(s);
        }
        for (sf::Sprite qs : qeueSprites) {
            window.draw(qs);
        }
        for (sf::Sprite gs : gridSpritesList) {
           window.draw(gs);
        }
        text.setPosition(sf::Vector2f(167, 23));

        text.setString(en.getScore(gameGrid));
        window.draw(text);
        
        window.display();
    }
    return 0;
}