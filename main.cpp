#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>

using namespace sf;
using namespace std;

int main()
{

    bool welcome = true;

    RenderWindow app(VideoMode(380, 380), "CATCH & DIE !");
    Texture texture,swelcome;



    texture.loadFromFile("image/pic1.jpg");
    swelcome.loadFromFile("image/cover.jpg");
    Sprite sprite(texture),cover(swelcome);




    while (app.isOpen())
    {

        Event event;
        while (app.pollEvent(event))
        {

            if (event.type == Event::Closed)
                app.close();


        }


        app.clear(Color::White);

        if(welcome == true)
        {
            app.draw(cover);
            if(Keyboard::isKeyPressed(Keyboard::Enter))     welcome = false;
        }
        else{
        app.draw(sprite);
        }

        app.display();
    }

    return EXIT_SUCCESS;
}
