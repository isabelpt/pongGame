//
//  Bat.h
//  SfMl
//
//  Created by Isabel Prado-Tucker on 7/3/20.
//  Copyright © 2020 Isabel Prado-Tucker. All rights reserved.
//

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bat
{
public:
    Bat(float startX, float startY);
    RectangleShape getShape();
    FloatRect getPosition();
    
    void moveLeft();
    void moveRight();
    void update();
    
private:
    float batSpeed = .3f;
    RectangleShape batShape;
    Vector2f position;
};
