#include <iostream>
using namespace std;
char tictac[3][3];
bool checkrows(char symbol)
{
    int Ccount = 0;
    for (int rows = 0; rows < 3; rows++)
    {
        for (int cols = 0; cols < 3; cols++)
        {
            if (tictac[rows][cols] == symbol)
            {
                Ccount = Ccount + 1;
            }
        }
        if (Ccount == 3)
        {
            return true;
        }
        else{Ccount=0;}
    }
    return false;
}
bool checkcolumns(char symbol)
{
    int ccount = 0;
    for (int cols = 0; cols < 3; cols++)
    {
        for (int rows = 0; rows < 3; rows++)
        {
            if (tictac[rows][cols] == symbol)
            {
                ccount = ccount + 1;
            }
        }
        if (ccount == 3)
        {
            return true;
        }
        else
        {
            ccount = 0;
        }
    }
    return 0;
}
bool checkdiagnols(char symbol)
{
    int count = 0;
    for (int n = 0; n < 3; n++)
    {
        if (tictac[n][n] == symbol)
        {
            count = count + 1;
        }
    }
    if (count == 3)
    {
        return 1;
    }
    count = 0;
    for (int row = 0, col = 2; row < 3; row++, col--)
    {
        if (tictac[row][col] == symbol)
        {
            count = count + 1;
        }
    }
    if (count == 3)
    {
        return true;
    }
    return false;
}
void display()
{
    cout << "           ----------------------------" << endl;
    cout << "           --------TIC TAC TOO---------" << endl;
    cout << "           ----------------------------" << endl;
    cout << endl;
    cout << "A                      B                   C" << endl;
    cout << "\t" << tictac[0][0] << "\t"
         << "|"
         << "\t" << tictac[0][1] << "\t"
         << "|"
         << "\t" << tictac[0][2] << endl;
    cout << "______________________________________________" << endl;
    cout << "\t" << tictac[1][0] << "\t"
         << "|"
         << "\t" << tictac[1][1] << "\t"
         << "|"
         << "\t" << tictac[1][2] << endl;
    cout << "_____________________________________________" << endl;
    cout << "\t" << tictac[2][0] << "\t"
         << "|"
         << "\t" << tictac[2][1] << "\t"
         << "|"
         << "\t" << tictac[2][2] << endl;
}
main()
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            tictac[row][col] = '-';
        }
    }
    int countt = 0;
    char val1;
    int col, val2;
    string box;
    while (countt < 9)
    {
        display();
        if ((countt % 2) == 0)
        {
            cout << "Player X turn:" << endl;
            cout << "Enter your box:";
            cin >> box;
            val1 = box[0];
            if (val1 == 'A')
            {
                col = 0;
            }
            if (val1 == 'B')
            {
                col = 1;
            }
            if (val1 == 'C')
            {
                col = 2;
            }
            val2 = box[1];
            val2 = val2 - 48;
            tictac[val2][col] = 'X';
            char x = 'X';
            countt = countt + 1;
            if (checkrows(x) || checkcolumns(x) || checkdiagnols(x))
            {
                system("CLS");
                display();
                cout << "PLAYER X WINS!!!!!";
                break;
            }
        }
        else
        {
            cout << "Player O turn:" << endl;
            cout << "Enter your box:";
            cin >> box;
            val1 = box[0];
            if (val1 == 'A')
            {
                col = 0;
            }
            if (val1 == 'B')
            {
                col = 1;
            }
            if (val1 == 'C')
            {
                col = 2;
            }
            val2 = box[1];
            val2 = val2 - 48;
            tictac[val2][col] = 'O';
            countt = countt + 1;
            char o = 'O';
            if (checkrows(o) || checkcolumns(o) || checkdiagnols(o))
            {
                system("CLS");
                display();
                cout << "PLAYER O WINS!!!!!";
            }
        }
        system("CLS");
    }
}