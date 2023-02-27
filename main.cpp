#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>

using namespace sf;
using namespace std;

int main()
{

    int w=32;
    int grid[12][12];
    int sgrid[12][12]; //for showing
    bool welcome = true;
    bool inclick = true;
    bool gameover = false;
    int boomcount = 100;

    RenderWindow app(VideoMode(380, 380), "CATCH & DIE !");
    Texture texture,swelcome,game_over,win;



    texture.loadFromFile("image/pic1.jpg");
    swelcome.loadFromFile("image/cover.jpg");
    game_over.loadFromFile("image/over.png");
    win.loadFromFile("image/win.png");
    Sprite sprite(texture),cover(swelcome),spover(game_over),swin(win);

    SoundBuffer sndover,sndclick;
    sndover.loadFromFile("sound effects/bomb sound.wav");
    sndclick.loadFromFile("sound effects/click sound.wav");

    Sound sover,sclick;
    sover.setBuffer(sndover);
    sclick.setBuffer(sndclick);


    for (int i=1;i<=10;i++)
     for (int j=1;j<=10;j++)
      {
        sgrid[i][j]=10;
        if (rand()%5==0)  grid[i][j]=9;
        else grid[i][j]=0;
      }
      for (int i=1;i<=10;i++)
     for (int j=1;j<=10;j++)
      {
        int n=0;
        if (grid[i][j]==9)
        {
            continue;
            boomcount--;
        }
        if (grid[i+1][j]==9) n++;
        if (grid[i][j+1]==9) n++;
        if (grid[i-1][j]==9) n++;
        if (grid[i][j-1]==9) n++;
        if (grid[i+1][j+1]==9) n++;
        if (grid[i-1][j-1]==9) n++;
        if (grid[i-1][j+1]==9) n++;
        if (grid[i+1][j-1]==9) n++;
        grid[i][j]=n;
      }

    while (app.isOpen())
    {
        Vector2i pos = Mouse::getPosition(app);
        int x = pos.x/w;
        int y = pos.y/w;

        Event event;
        while (app.pollEvent(event))
        {

            if (event.type == Event::Closed)
                app.close();

            if (event.type == Event::MouseButtonPressed){
              if (event.key.code == Mouse::Left)
              {
                  sgrid[x][y]=grid[x][y];
                  boomcount--;
              }
              else if (event.key.code == Mouse::Right) sgrid[x][y]=11;      //flag value 11
              sclick.play();
              if(sgrid[x][y] == 9)
              {
                  sover.play();
                  gameover = true;
              }
              if (event.key.code == Mouse::Left && inclick)
              {
                  for(int i=x-2;i<x+2;i++)
                    for(int j=y-2;j<y+2;j++)
                  {
                      if(i==x && j==y)  continue;
                      else if(grid[i][j]!=9)
                      {
                          sgrid[i][j]=grid[i][j];
                          boomcount--;
                      }
                  }
                  inclick = false;
              }
            }

        }


        app.clear(Color::White);

        if(welcome == true)
        {
            app.draw(cover);
            if(Keyboard::isKeyPressed(Keyboard::Enter))     welcome = false;
        }
        else{
        for (int i=1;i<=10;i++)
         for (int j=1;j<=10;j++)
          {
            if (sgrid[x][y]==9) sgrid[i][j]=grid[i][j];
           sprite.setTextureRect(IntRect(sgrid[i][j]*w,0,w,w));
           sprite.setPosition(i*w, j*w);
           app.draw(sprite);
          }
        }
        if(gameover)    app.draw(spover);
        if(boomcount==0)    app.draw(swin);

        app.display();
    }

    return EXIT_SUCCESS;
}
