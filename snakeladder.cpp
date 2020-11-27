#include"header.h"

Player_ladder::Player_ladder()
{
	position = 1;
}

Game_ladder::Game_ladder()
	{
		ladder[22] = 38;
		ladder[55] = 68;
		ladder[75] = 91;
		ladder[20] = 34;
		snake[66] = 33;
		snake[52] = 48;
		snake[62] = 45;
		snake[82] = 14;
		snake[97]= 5;
		ladder[6]= 27;
		snake[22]= 12;
		p1 = new Player_ladder();
		p2 = new Player_ladder();
	}

int Game_ladder::Minimum_moves(int current_position)
	{
		vector<vector<int>> v;
		v.resize(101);
		vector<int> dis, vis;
		int mx = 1e9;
		dis.resize(101, mx); vis.resize(101, 0);
		dis[current_position] = 0; vis[current_position] = 1;
		for (int i = 1; i <= 100; i++)
		{
			for (int j = 1; j <= 6; j++)
			{
				if (i + j > 100)
					continue;
				if (snake[i + j] != 0)
				{

				}
				else if (ladder[i + j] != 0)
				{
					v[i].push_back(ladder[i + j]);
				}
				else
				{
					v[i].push_back(i + j);
				}
			}
		}
		set<pair<int, int>> sets;

		for (int i = 1; i <= 100; i++)
		{
			sets.insert(make_pair(dis[i], i));
		}
		while (vis[100] != 1 && sets.size() != 0)
		{

			auto iterate = sets.begin();
			int value = iterate->first; int position = iterate->second;
			sets.erase(iterate);
			vis[position] = 1;
			for (int i = 0; i < v[position].size(); i++)
			{
				int y = v[position][i];
				if (dis[y] > value + 1)
				{
					auto it = sets.find(make_pair(dis[y], y));
					sets.erase(it);
					dis[y] = value + 1;
					sets.insert(make_pair(dis[y], y));
				}
			}

		}

		return dis[100];
	}

void Game_ladder::Draw()
	{

		for (int i = 0; i < 10; i++)
		{
			cout << "# # # # # # ";
		}
		cout << "#";
		for (int i = 100; i >= 1; i--)
		{
			if (i % 10 != 0)
				continue;

			for (int j = 0; j <= 3; j++)
			{
				cout << endl;
				cout << "# ";
				if ((i / 10) % 2 == 1)
				{
					int l, r; l = i - 9; r = i;
					for (l; l <= r; l++)
					{
						if (j == 0)
						{
							if (l < 10)
							{
								if (p1->position == l)
									cout << l << "  P1";
								else
									cout << l << "    ";
								if (p2->position == l)
									cout << " P2 ";
								else
									cout << "    ";

								if (l != 100)
									cout << " ";
							}
							else
							{
								if (p1->position == l)
									cout << l << "  P1";
								else
									cout << l << "    ";
								if (p2->position == l)
									cout << "P2 ";
								else
									cout << "   ";

								if (l != 100)
									cout << " ";
							}
						}
						else if (j == 1)
						{
							cout << "          ";
						}
						else if (j == 2)
						{
							if (ladder[l] != 0)
							{
								cout << "L  -> ";
								cout << ladder[l] << "  ";
							}
							else if (snake[l] != 0)
							{
								cout << "S  -> ";
								cout << snake[l] << "  ";
							}
							else
							{
								cout << "          ";
							}

						}
						else
						{
							cout << "# # # # # ";
						}

						cout << "# ";

					}
					//cout << endl;
				}
				else
				{
					int l, r;
					l = i; r = i - 9;
					for (l; l >= r; l--)
					{
						if (j == 0)
						{

							if (p1->position == l)
								cout << l << "  P1";
							else
								cout << l << "    ";
							if (p2->position == l)
								cout << " P2";
							else
								cout << "   ";

							if (l != 100)
								cout << " ";
						}
						else if (j == 1)
						{
							cout << "          ";
						}
						else if (j == 2)
						{
							if (ladder[l] != 0)
							{
								cout << "L  -> ";
								cout << ladder[l] << "  ";
							}
							else if (snake[l] != 0)
							{
								cout << "S  -> ";
								cout << snake[l] << "  ";
							}
							else
							{
								cout << "          ";
							}

						}
						else
						{
							cout << "# # # # # ";
						}

						cout << "# ";

					}
					//cout << endl;
				}
			}
		}
	}

void Game_ladder::Logic(int flag)
	{
		srand(time(0));
		int random = rand() % 6;
		random++;
		if (flag == 1)
		{
			if (p1->position + random <= 100)
			{
				for (int i = 0; i < random; i++)
				{
					p1->position++;
					system("CLS");
					Draw();
					cout << endl << "Your move " << random << " steps currently moved :" << i + 1 << endl;
					Sleep(1000);
					//sleep_for(seconds(1));

				}
				if (ladder[p1->position] != 0)
				{

					p1->position = ladder[p1->position];
					system("CLS");
					Draw();
				}
				else if (snake[p1->position] != 0)
				{

					p1->position = snake[p1->position];
					system("CLS");
					Draw();
				}

			}

		}
		else
		{
			if (p2->position + random <= 100)
			{
				for (int i = 0; i < random; i++)
				{
					p2->position++;
					system("CLS");
					Draw();
					cout << endl << "Your move " << random << " steps currently moved :" << i + 1 << endl;
					Sleep(1000);

				}
				if (ladder[p2->position] != 0)
				{

					p2->position = ladder[p2->position];
					system("CLS");
					Draw();
				}
				else if (snake[p2->position] != 0)
				{

					p2->position = snake[p2->position];
					system("CLS");
					Draw();
				}

			}
		}
	}

void Game_ladder::Run()
	{
		int f = 1;
		Draw();
		while (p1->position != 100 && p2->position != 100)
		{
			cout << endl;

			if (f % 2 == 1)
			{
				cout << "Player 1's turn " << endl;
				char s;
				cout << "Enter r to roll" << endl;
				cout << "Enter q to quit" << endl;
				cout << "Enter s to get the minimum moves needed to win" << endl;
				cin >> s;
				if (s == 'r')
					Logic(1);
				else if (s == 'q')
				{
					break;
				}
				else if (s == 's')
				{
					cout << Minimum_moves(p1->position) << endl;
					f++;
				}
				else
				{
					cout << "Invalid move" << endl;
					f++;
				}
			}
			else
			{
				cout << "Player 2's turn " << endl;
				char s;
				cout << "Enter r to roll" << endl;
				cout << "Enter q to quit" << endl;
				cout << "Enter s to get the minimum moves needed to win" << endl;
				cin >> s;
				if (s == 'r')
					Logic(2);
				else if (s == 'q')
				{
					break;
				}
				else if (s == 's')
				{
					cout << Minimum_moves(p2->position) << endl;
					f++;
				}
				else
				{
					cout << "Invalid move" << endl;
					f++;
				}
			}
			if (p1->position == 100)
			{
				cout << "Player 1 is the winner";
			}
			if (p2->position == 100)
			{
				cout << "Player 2 is the winner";
			}
			f++;
		}
	}
