#include <SFML/Graphics.hpp>
#include<iostream>
using namespace sf;
using namespace std;

int main()
{

    RenderWindow app(VideoMode(380, 380), "CATCH & DIE !");
    Texture texture;
    texture.loadFromFile("image/pic1.jpg");
    Sprite sprite(texture);


    while (app.isOpen())
    {

        Event event;
        while (app.pollEvent(event))
        {

            if (event.type == Event::Closed)
                app.close();


        }


        app.clear();

        app.draw(sprite);
        app.display();
    }

    return EXIT_SUCCESS;
}
