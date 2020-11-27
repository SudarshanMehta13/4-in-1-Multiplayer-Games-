#include <iostream>
#pragma once
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<ctime>
#include<chrono>
#include<string>
#include<vector>
#include<set>
#include<deque>
using namespace std;

// snake & Ladder

class Player_ladder {
public:
	int position;
	Player_ladder();
};

class Game_ladder {
private:
	int ladder[101] = { 0 };
	int snake[101] = { 0 };

	Player_ladder* p1;
	Player_ladder* p2;
public:
	Game_ladder();
	int Minimum_moves(int current_position);
	void  Draw();
	void Logic(int flag);
	void  Run();
};


//hangman
int Hangman();
int letterFill(char guess, char secretword[], char guessword[]);
void initUnknown(char word[], char unknown[]);



//snake
int Snake();
void Logic_snake();
void Draw_snake();
void Input_snake();
void Setup();


// road cross
class cPlayer
{
public:
	int x, y;
	cPlayer(int width) { x = width / 2; y = 0; }
};
class cLane
{
private:
	deque<bool> cars;
	bool right;
public:
	bool CheckPos(int pos) { return cars[pos]; }
	void ChangeDirection() { right = !right; }
	cLane(int width);
	void Move();
};
class cGame
{
private:
	bool quit;
	int numberOfLanes;
	int width;
	int score;
	cPlayer* player;
	vector<cLane*> map;
public:
	cGame(int w , int h );
	~cGame();
	void Draw();
	void Input();
	void Run();
	void Logic();
};


