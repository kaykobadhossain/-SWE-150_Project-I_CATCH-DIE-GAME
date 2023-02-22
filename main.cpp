#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{

    RenderWindow app(VideoMode(600, 600), "CATCH & DIE !");


    while (app.isOpen())
    {

        Event event;
        while (app.pollEvent(event))
        {

            if (event.type == Event::Closed)
                app.close();
        }


        app.clear();


        app.display();
    }

    return EXIT_SUCCESS;
}
