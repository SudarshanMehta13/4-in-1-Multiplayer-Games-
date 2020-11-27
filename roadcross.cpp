#include"header.h"


    cLane::cLane(int width)
    {
        for (int i = 0; i < width; i++)
            cars.push_front(true);
        right = rand() % 2;
    }
    void cLane::Move()
    {
        if (right)
        {
            if (rand() % 8 == 1)
                cars.push_front(true);
            else
                cars.push_front(false);
            cars.pop_back();
        }
        else
        {
            if (rand() % 8 == 1)
                cars.push_back(true);
            else
                cars.push_back(false);
            cars.pop_front();
        }

    }


    cGame::cGame(int w = 20, int h = 10)
    {
        numberOfLanes = h;
        width = w;
        quit = false;
        for (int i = 0; i < numberOfLanes; i++)
            map.push_back(new cLane(width));
        player = new cPlayer(width);
    }
    cGame::~cGame()
    {
        delete player;
        for (int i = 0; i < map.size(); i++)
        {
            cLane* current = map.back();
            map.pop_back();
            delete current;
        }
    }
    void cGame::Draw()
    {
        system("cls");
        for (int i = 0; i < numberOfLanes; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (i == 0 && (j == 0 || j == width - 1)) cout << "S";
                if (i == numberOfLanes - 1 && (j == 0 || j == width - 1)) cout << "F";
                if (map[i]->CheckPos(j) && i != 0 && i != numberOfLanes - 1)
                    cout << "#";
                else if (player->x == j && player->y == i)
                    cout << "V";
                else
                    cout << " ";
            }
            cout << endl;
        }
        cout << "Score: " << score << endl;
    }
    void cGame::Input()
    {
        if (_kbhit())
        {
            char current = _getch();
            if (current == 'a')
                player->x--;
            if (current == 'd')
                player->x++;
            if (current == 'w')
                player->y--;
            if (current == 's')
                player->y++;
            if (current == 'q')
                quit = true;
        }
    }
    void cGame::Logic()
    {
        for (int i = 1; i < numberOfLanes - 1; i++)
        {
            if (rand() % 8 == 1)
                map[i]->Move();
            if (map[i]->CheckPos(player->x) && player->y == i)
                quit = true;
        }
        if (player->y == numberOfLanes - 1)
        {
            score++;
            player->y = 0;
            cout << "\x07";
            map[rand() % numberOfLanes]->ChangeDirection();
        }
    }
    void cGame::Run()
    {
        score=0;
        while (!quit)
        {
            Input();
            Draw();
            Logic();
        }
    }
