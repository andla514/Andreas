#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
// shift + alt + f => auto indent
int main()
{
    // Create the window
    sf::RenderWindow window;
    sf::RenderWindow window2;
    int width{800};
    unsigned height{608};
    window.create(sf::VideoMode{800, height}, "Keyboard test");
    window2.create(sf::VideoMode{800, height}, "Keyboard test");
    float ballsize{20};

    sf::Texture texture;
    if (!texture.create(width, height))
        return -1;

    sf::Texture texture2;
    if (!texture2.loadFromFile("floor.jpg"))
    {
        return 2;
    }

    window2.clear(sf::Color::Blue);

    sf::Sprite sprite2(texture2);
    
    /*
    while (i < width)
    {
        sf::Event Event;
        while (window.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
            {
                window.close();
            }
        }


        // Draw things
        sprite2.setPosition(i ,0);
        window2.draw(sprite2);
        i += 32;


        // show the newly drawn things
        window2.display();

        // wait before drawing the next frame
        sf::sleep(sf::milliseconds(200));
    }
    */
    
    

    
    /*
    //test
    while (window.isOpen())
    {
        sf::Event Event;
        while (window.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
            {
                window.close();
            }

            if(Event.type == sf::Event::KeyPressed)
            {
                if(Event.key.code == sf::Keyboard::Return)
                {
                    std::cout << "tryckt ner enter" << std::endl;
                }
            }
        }

        window.display();
    }
*/

    for(int i{-16}; i <= width; i += 16)
    {
        sprite2.setPosition(i ,0);
        window2.draw(sprite2);
        sprite2.setPosition(i ,576);
        window2.draw(sprite2);
        window2.display();
        sf::sleep(sf::milliseconds(50));
        //texture.update(window);
    }

    texture.update(window2);
    window2.close();
    sf::Sprite sprite(texture);
    sprite.setPosition(0 ,0);

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
    while (window.isOpen())
    {
        sf::Event Event;
        while (window.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
            {
                window.close();
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
        window.clear();

        // Draw things
        window.draw(sprite);
        window.draw(ball);
        window.draw(ball2);

        // show the newly drawn things
        window.display();

        // wait before drawing the next frame
        sf::sleep(sf::milliseconds(2));
    }

    return 0;
}
