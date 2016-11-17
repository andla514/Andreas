#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
// shift + alt + f => auto indent
int main()
{
    // Create the window
    sf::RenderWindow Window;
    Window.create(sf::VideoMode{800, 600}, "Keyboard test");
    float ballsize{20};
    /*
    //test
    while (Window.isOpen())
    {
        sf::Event Event;
        while (Window.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
            {
                Window.close();
            }

            if(Event.type == sf::Event::KeyPressed)
            {
                if(Event.key.code == sf::Keyboard::Return)
                {
                    std::cout << "tryckt ner enter" << std::endl;
                }
            }
        }

        Window.display();
    }
*/

    // create ball
    sf::CircleShape ball{ballsize};
    ball.setFillColor(sf::Color::Blue);
    //ball.setTexture(&texture);
    ball.setTextureRect(sf::IntRect{0, 0, 128, 128});
    ball.setOrigin(ball.getRadius(), ball.getRadius());

    // set ball position
    ball.setPosition(42, 42);
    int Speed{1};

    // create ball2
    sf::CircleShape ball2{ballsize};
    ball.setFillColor(sf::Color::Yellow);
    // ball.setTexture(&texture);
    ball.setTextureRect(sf::IntRect{0, 0, 128, 128});
    ball.setOrigin(ball.getRadius(), ball.getRadius());

    // set ball position
    ball2.setPosition(100, 100);

    //Main loop
    while (Window.isOpen())
    {
        sf::Event Event;
        while (Window.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
            {
                Window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            ball2.setPosition(ball2.getPosition().x, ball2.getPosition().y - Speed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            ball2.setPosition(ball2.getPosition().x, ball2.getPosition().y + Speed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            ball2.setPosition(ball2.getPosition().x + Speed, ball2.getPosition().y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            ball2.setPosition(ball2.getPosition().x - Speed, ball2.getPosition().y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            ball.setPosition(ball.getPosition().x, ball.getPosition().y - Speed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            ball.setPosition(ball.getPosition().x - Speed, ball.getPosition().y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            ball.setPosition(ball.getPosition().x, ball.getPosition().y + Speed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            ball.setPosition(ball.getPosition().x + Speed, ball.getPosition().y);
        }

        // Clear screen
        Window.clear();

        // Draw things
        Window.draw(ball);
        Window.draw(ball2);

        // show the newly drawn things
        Window.display();

        // wait before drawing the next frame
        sf::sleep(sf::milliseconds(2));
    }

    return 0;
}
