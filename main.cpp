#include <iostream>
#include<sstream>
#include<process.h>
#include <fstream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<time.h>
#include<ctime>
#include<chrono>
#include<Windows.h>
#include<vector>
#include<set>

#include"header.h"

using namespace std;


class UserDetails
{
    string username, password;
public:
    string retUser()
    {
        return username;
    }
    string retPass()
    {
        return password;
    }
    void getUserName()
    {
        fflush(stdin); // used to flush or clear the output buffer of the stream
                        //It returns zero if successful, otherwise returns EOF and feof error indicator is set.
        cout << "\n\tEnter Username:";
        cin >> username;
    }
    void getPassword()
    {
        fflush(stdin);
        cout << "\n\tEnter Password:";
        cin >> password;
    }
};


int loginFunction()
{
    UserDetails u;
    char regUser;
    cout<<"\n\n\t\tWELCOME\n";
    cout<<"\n\t\tLOGIN TO PLAY THE BEST GAMES...\n";
    cout<<"\n\t\tAre you a registered user?          (y/n)   ";
    cin>>regUser;
    system("cls");
    if(regUser=='y' || regUser=='Y')
    {
        string usr,ptr;
        int found =0;
        ifstream filin;
        filin.open("LoginDetails",ios::in);  // in - read mode
        u.getUserName();
        u.getPassword();
        string STRING="jdjj", STRING2="df";
        while(!filin.eof()) // To get you all the lines.
        {
            getline(filin,STRING); // Saves the line in STRING.
            getline(filin,STRING2);
            if((STRING.compare(u.retUser())==0) && (STRING2.compare(u.retPass())==0))
            {
                system("cls");
                cout<<"\n\n\n\n\n\n\n\n\n\n    \t\t    YOU HAVE SUCCESSFULLY LOGGED IN!\n";
                found=1;
                break;
            }
        }

        if(found==0)
        {
            cout<<"\n\tRECORD NOT FOUND....";
            return -1;
        }
        filin.close();
        return 0;
    }
         else
    {
        int flag = 1;
        string new_username,new_password;

        int found = 0;
        while (flag)
        {
            fstream filout;
            u.getUserName();
            new_username = u.retUser();
            filout.open("LoginDetails");
            while (!filout.eof())
            {
                string username, password;
                filout >> username >> password;
                if (new_username == username)
                {
                    found = 1;
                    break;
                }
            }
            if (found == 1)
            {
                cout << "\t\tUsername already taken" << endl;
                cout << "\t\tPress q to quit" << endl;
                cout << "\t\tPress any other key  to try again" << endl;
                char c;
                cin >> c;
                if (c == 'Q' || c == 'q')
                {
                    flag = 0; filout.close(); return -1;
                }
                else
                    found = 0; filout.close();
            }
            else
            {
                filout.close(); break;
            }

        }
        if (found == 0)
        {
            fstream filout;
            filout.open("LoginDetails",ios::app);
            u.getPassword();
            new_password = u.retPass();
            filout << endl << new_username;
            filout << endl << new_password;
            filout.close();
        }
        return 1;
    }
}

void TakeChoice()
{
a:
    system("cls");
    int counter = 0;
    char ch = 'y';
    fstream fin;
    int choice;
    system("cls");
    cout << "\n\n\tWELCOME\n Please select a game you want to play...";
    cout << endl << endl << "\n\tPress 1 to play Hangman\n\tPress 2 to play Cross The Road\n\tPress 3 to play Snakes\n\tPress 4 to play Snakes & Ladder\n\tPress 5 EXIT" << endl;
    cin >> choice;
    system("cls");
    string str;
    char t;
    if (choice == 1) // Hangman
    {
        Hangman();
    }
    else if (choice == 2) // Road Cross
    {
        srand(time(NULL));
        cGame game(30, 5);
        game.Run();
        cout << "Game over!" << endl;
        getchar();
    }

    else if (choice == 3) // Snakes
    {
        Snake();
    }

    else if (choice == 4) // Snake & Ladder
    {
        system("CLS");
        Game_ladder a;
        a.Run();
    }
    else if (choice == 5) // EXIT
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   EXITING.....\n\n\n\n\n\n\n\n\n\n\n";
        exit(0);
    }
    else // wrong key
    {
        cout << "\n\tWrong Choice...Enter Again\n";
        goto a;
    }


}



int main()
{
    int t;
    char c;
X:
    t = loginFunction();
    if (t == 1)
    {
        system("cls");
        goto X;
    }
    else if (t == -1)
        return 0;
Y:
    TakeChoice();
    cout << "\n\n\tWOULD YOU LIKE TO PLAY ANOTHER GAME....\n \n\tPress y/Y for YES and n/N to EXIT\n";
    cin >> c;
    if (c == 'y' || c == 'Y')
        goto Y;
    else
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tEXITING.....\n\n\n\n\n\n\n\n\n\n\n";
    }
}
