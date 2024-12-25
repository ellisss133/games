#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver;
const int width = 10;
const int height = 10;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir;

void SetColor(int color)
{
    cout << "\033[" << color << "m";
}

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void DrawMessage(bool win)
{
    for (int i = 0; i < 2; i++)
    {
        if (win)
        {
            SetColor(32);
            cout << "[ Y ] [ O ] [ U ] [   ] [ W ] [ I ] [ N ]\n";
        }
        else
        {
            SetColor(31);
            cout << "[ G ] [ A ] [ M ] [ E ] [   ] [ O ] [ V ] [ E ] [ R ]\n";
        }
    }
    SetColor(0);
}

void Draw()
{
    cout << "\033[H";
    SetColor(31);
    for (int i = 0; i < width; i++)
        cout << "##";
    cout << "##\n";
    for (int i = 0; i < height; i++)
    {
        for (int line = 0; line < 2; line++)
        {
            for (int j = 0; j < width; j++)
            {
                if (j == 0)
                {
                    cout << "##";
                }
                if (i == y && j == x)
                {
                    SetColor(32);
                    cout << "OO";
                }
                else if (i == fruitY && j == fruitX)
                {
                    SetColor(34);
                    cout << "FF";
                }
                else
                {
                    bool print = false;
                    for (int k = 0; k < nTail; k++)
                    {
                        if (tailX[k] == j && tailY[k] == i)
                        {
                            SetColor(32);
                            cout << "oo";
                            print = true;
                        }
                    }
                    if (!print)
                    {
                        SetColor(0);
                        cout << "  ";
                    }
                }
                if (j == width - 1)
                {
                    SetColor(31);
                    cout << "#as#";
                }
            }
            cout << endl;
        }
    }
    for (int i = 0; i < width; i++)
        cout << "##";
    cout << "##\n";

    SetColor(36);
    cout << "Score: " << score << endl;
    SetColor(0);
}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if (x < 0 || x >= width || y < 0 || y >= height)
    {
        gameOver = true;
        DrawMessage(false);
        return;
    }

    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            gameOver = true;
            DrawMessage(false);
            return;
        }
    }

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }

    if (nTail == width * height - 1)
    {
        gameOver = true;
        DrawMessage(true);
        return;
    }
}

int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(200);
    }
    return 0;
}
