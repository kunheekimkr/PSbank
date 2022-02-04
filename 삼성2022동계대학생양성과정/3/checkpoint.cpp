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
            firenear(r + 1, c);
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
            firenear(r - 1, c);
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
            firenear(r, c + 1);
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
            firenear(r, c - 1);
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
        for (int i = 0; i < 50; i++)
        {
            int r = i / 5;
            int c;
            if (i % 10 < 5)
                c = 2 * (i % 10) + 1;
            else
                c = (2 * (i % 10)) % 10;
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
    // debug();
}