//
//  Ball.h
//  SfMl
//
//  Created by Isabel Prado-Tucker on 7/3/20.
//  Copyright © 2020 Isabel Prado-Tucker. All rights reserved.
//

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
private:
    Vector2f position;
    RectangleShape ballShape;

    // WAS .1
    float xVelocity = .1f;
    float yVelocity = .1f;

public:
    Ball(float startX, float startY);
    RectangleShape getShape();
    FloatRect getPosition();
    

    float getXVelocity();
    void reboundSides();
    void reboundBatOrTop();
    void hitBottom();
    void update();
};
