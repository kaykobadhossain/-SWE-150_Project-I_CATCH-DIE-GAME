#include <SFML/Graphics.hpp>
#include<iostream>
using namespace sf;
using namespace std;

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

            if(event.type==Event::KeyPressed)
                cout<<"keyboard has been pressed"<<endl;

            if(event.type==Event::MouseButtonPressed)
                cout<<"Mouse has been pressed"<<endl;
                if (event.key.code == Mouse::Left)
                    cout<<"Left mouse pressed"<<endl;
                else if (event.key.code == Mouse::Right)
                    cout<<"Right mouse pressed"<<endl;
        }


        app.clear();


        app.display();
    }

    return EXIT_SUCCESS;
}
