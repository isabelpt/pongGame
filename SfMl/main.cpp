//
//  main.cpp
//  SfMl
//
//  Created by Isabel Prado-Tucker on 7/2/20.
//  Copyright © 2020 Isabel Prado-Tucker. All rights reserved.
//

//////////////////////////////////////
// PONG GAME
#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    int windowWidth = 1024;
    int windowHeight = 768;

    RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong Game");

    Bat bat(windowWidth / 2, windowHeight - 20);
    Ball ball(windowWidth / 2, 1);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if(event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            bat.moveLeft();
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            bat.moveRight();
        }

        // Ball hit the top of the window
        if (ball.getPosition().top < 0)
        {
            ball.reboundBatOrTop();
        }

        // Ball hit the bottom of the window
        if (ball.getPosition().top > windowHeight)
        {
            ball.hitBottom();
        }

        // Ball hits the sides
        if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth)
        {
            ball.reboundSides();
        }

        // Ball hit the bat
        if (ball.getPosition().intersects(bat.getPosition()))
        {
            ball.reboundBatOrTop();
        }

        ball.update();
        bat.update();

        window.clear(Color(148, 213, 0, 255));
        window.draw(bat.getShape());
        window.draw(ball.getShape());
        window.display();
    }
}
//////////////////////////////////////


//////////////////////////////////////
// SPRITES
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(200, 200), "Sprites!");
//
//    sf::Texture playerTex;
//    playerTex.loadFromFile("Textures/player_ship.png");
//
//    sf::Sprite playerSprite;
//    playerSprite.setTexture(playerTex);
//    playerSprite.setScale(1.5, 1.5);
//    playerSprite.setPosition(100, 100);
//    playerSprite.setOrigin(32, 32);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(playerSprite);
//        window.display();
//    }
//}
//////////////////////////////////////


//////////////////////////////////////
// JACK-O-LANTERN
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(400, 400), "Jack-O-Lantern");
//
//    sf::CircleShape jackOLantern;
//    jackOLantern.setRadius(200);
//    jackOLantern.setPosition(0, 0);
//    jackOLantern.setFillColor(sf::Color(255, 165, 0));
//
//    sf::CircleShape leftEye;
//    leftEye.setPointCount(3);
//    leftEye.setRadius(50);
//    leftEye.setFillColor(sf::Color::Black);
//    leftEye.setPosition(50, 75);
//
//    sf::CircleShape rightEye;
//    rightEye.setPointCount(3);
//    rightEye.setRadius(50);
//    rightEye.setFillColor(sf::Color::Black);
//    rightEye.setPosition(250, 75);
//
//    sf::ConvexShape mouth;
//    mouth.setFillColor(sf::Color::Black);
//    mouth.setPointCount(5);
//    mouth.setPoint(0, sf::Vector2f(50, 300));
//    mouth.setPoint(1, sf::Vector2f(350, 300));
//    mouth.setPoint(2, sf::Vector2f(300, 350));
//    mouth.setPoint(3, sf::Vector2f(200, 375));
//    mouth.setPoint(4, sf::Vector2f(100, 350));
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(jackOLantern);
//        window.draw(leftEye);
//        window.draw(rightEye);
//        window.draw(mouth);
//        window.display();
//    }
//}
//////////////////////////////////////


//////////////////////////////////////
// CIRCLE PROGRAM
//int main() {
//    sf::CircleShape circle;
//    circle.setRadius(50);
//    circle.setPosition(200, 100);
//    circle.setFillColor(sf::Color::Cyan);
//    sf::RenderWindow window(sf::VideoMode(2560, 1600), "SFML Works");
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//        window.clear();
//        window.draw(circle);
//        window.display();
//    }
//}
//////////////////////////////////////
