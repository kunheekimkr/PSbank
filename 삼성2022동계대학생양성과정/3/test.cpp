#include <cstring>
#include <random>
#include <iostream>
using namespace std;

#define MISS 0
#define CARRIER 1
#define BATTLESHIP 2
#define CRUISER 3
#define SUBMARINE 4
#define DESTROYER 5

extern int fire(int r, int c);
int guess[10][10];
int lim;
int success;
int shot;

void debug()
{
    cout << '\n';
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << guess[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void init(int limit)
{
    lim = limit;
}

void firenear(int r, int c)
{

    if (r + 1 < 10 && guess[r + 1][c] == -1)
    {
        int result = fire(r + 1, c);
        guess[r + 1][c] = result;
        shot++;
        if (result > 0)
        {
            success++;
            int k = 2;
            while (r + k < 10 && guess[r + k][c] == -1)
            {
                int next = fire(r + k, c);
                guess[r + k][c] = next;
                shot++;
                if (next > 0)
                {
                    success++;
                    k++;
                    continue;
                }
                break;
            }
        }
    }

    if (r - 1 >= 0 && guess[r - 1][c] == -1)
    {
        int result = fire(r - 1, c);
        guess[r - 1][c] = result;
        shot++;
        if (result > 0)
        {
            success++;
            int k = 2;
            while (r - k >= 0 && guess[r - k][c] == -1)
            {
                int next = fire(r - k, c);
                guess[r - k][c] = next;
                shot++;
                if (next > 0)
                {
                    success++;
                    k++;
                    continue;
                }
                break;
            }
        }
    }
    if (c + 1 < 10 && guess[r][c + 1] == -1)
    {
        int result = fire(r, c + 1);
        guess[r][c + 1] = result;
        shot++;
        if (result > 0)
        {
            success++;
            int k = 2;
            while (c + k < 10 && guess[r][c + k] == -1)
            {
                int next = fire(r, c + k);
                guess[r][c + k] = next;
                shot++;
                if (next > 0)
                {
                    success++;
                    k++;
                    continue;
                }
                break;
            }
        }
    }
    if (c - 1 >= 0 && guess[r][c - 1] == -1)
    {
        int result = fire(r, c - 1);
        guess[r][c - 1] = result;
        shot++;
        if (result > 0)
        {
            success++;
            int k = 2;
            while (c - k >= 10 && guess[r][c - k] == -1)
            {
                int next = fire(r, c - k);
                guess[r][c - k] = next;
                shot++;
                if (next > 0)
                {
                    success++;
                    k++;
                    continue;
                }
                break;
            }
        }
    }
}

void play()
{
    memset(guess, -1, sizeof(guess));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 9);
    success = 0;
    shot = 0;

    while (success < 17)
    {
        for (int i = 0; i < 9; i++)
        {
            int r = i + 1;
            int c = i;
            if (guess[r][c] == -1)
            {
                int result = fire(r, c);
                shot++;
                guess[r][c] = result;
                if (result > 0)
                {
                    success++;
                    firenear(r, c);
                }
            }
        }

        for (int i = 0; i < 8; i++)
        {
            int r = i;
            int c = i + 2;
            if (guess[r][c] == -1)
            {
                int result = fire(r, c);
                shot++;
                guess[r][c] = result;
                if (result > 0)
                {
                    success++;
                    firenear(r, c);
                }
            }
        }

        for (int i = 0; i < 6; i++)
        {
            int r = i + 4;
            int c = i;
            if (guess[r][c] == -1)
            {
                int result = fire(r, c);
                shot++;
                guess[r][c] = result;
                if (result > 0)
                {
                    success++;
                    firenear(r, c);
                }
            }
        }

        for (int i = 0; i < 5; i++)
        {
            int r = i;
            int c = i + 5;
            if (guess[r][c] == -1)
            {
                int result = fire(r, c);
                shot++;
                guess[r][c] = result;
                if (result > 0)
                {
                    success++;
                    firenear(r, c);
                }
            }
        }

        for (int i = 0; i < 3; i++)
        {
            int r = i;
            int c = i + 7;
            if (guess[r][c] == -1)
            {
                int result = fire(r, c);
                shot++;
                guess[r][c] = result;
                if (result > 0)
                {
                    success++;
                    firenear(r, c);
                }
            }
        }

        for (int i = 0; i < 2; i++)
        {
            int r = i + 8;
            int c = i;
            if (guess[r][c] == -1)
            {
                int result = fire(r, c);
                shot++;
                guess[r][c] = result;
                if (result > 0)
                {
                    success++;
                    firenear(r, c);
                }
            }
        }

        int r = dis(gen);
        int c = dis(gen);
        while (guess[r][c] != -1)
        {
            r = dis(gen);
            c = dis(gen);
        }
        int result = fire(r, c);
        shot++;
        guess[r][c] = result;
        if (result > 0)
        {
            success++;
            firenear(r, c);
        }
    }
    cout << "Shots: " << shot << '\n';
    debug();
}