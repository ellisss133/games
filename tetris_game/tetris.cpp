// #include <iostream>
// #include <conio.h>
// #include <windows.h>
// #include <vector>
// #include <cstdlib>
// #include <ctime>

// using namespace std;

// const int width = 10;
// const int height = 20;

// vector<vector<int>> field(height, vector<int>(width, 0));

// const vector<vector<vector<int>>> figures = {
//     {
//         {1, 1},
//         {1, 1}
//     },
//     {
//         {1, 1, 1, 1}
//     },
//     {
//         {0, 1, 0},
//         {1, 1, 1}
//     },
//     {
//         {1, 0, 0},
//         {1, 1, 1}
//     },
//     {
//         {0, 0, 1},
//         {1, 1, 1}
//     }
// };

// vector<vector<int>> figure;
// int x = width / 2, y = 0;

// void spawnFigure() {
//     figure = figures[rand() % figures.size()];
//     x = width / 2 - figure[0].size() / 2;
//     y = 0;
// }

// bool checkCollision(int nx, int ny) {
//     for (int i = 0; i < figure.size(); i++)
//         for (int j = 0; j < figure[i].size(); j++)
//             if (figure[i][j]) {
//                 int fx = x + j + nx;
//                 int fy = y + i + ny;
//                 if (fx < 0 || fx >= width || fy >= height || field[fy][fx])
//                     return true;
//             }
//     return false;
// }

// void placeFigure() {
//     for (int i = 0; i < figure.size(); i++)
//         for (int j = 0; j < figure[i].size(); j++)
//             if (figure[i][j])
//                 field[y + i][x + j] = 1;
//     spawnFigure();
// }

// void clearLines() {
//     for (int i = height - 1; i >= 0; i--) {
//         bool full = true;
//         for (int j = 0; j < width; j++)
//             if (!field[i][j]) full = false;
//         if (full) {
//             for (int k = i; k > 0; k--)
//                 for (int j = 0; j < width; j++)
//                     field[k][j] = field[k - 1][j];
//             for (int j = 0; j < width; j++) field[0][j] = 0;
//             i++;
//         }
//     }
// }

// void rotateFigure() {
//     vector<vector<int>> rotated(figure[0].size(), vector<int>(figure.size()));

//     for (int i = 0; i < figure.size(); i++)
//         for (int j = 0; j < figure[i].size(); j++)
//             rotated[j][figure.size() - 1 - i] = figure[i][j];

//     figure = rotated;

//     if (checkCollision(0, 0)) {
//         for (int i = 0; i < figure.size(); i++)
//             for (int j = 0; j < figure[i].size(); j++)
//                 rotated[j][figure.size() - 1 - i] = 0;

//         figure = rotated;
//     }
// }

// void draw() {
//     for (int i = 0; i < 30; i++) cout << "\n";
//     for (int i = 0; i < height; i++) {
//         for (int j = 0; j < width; j++) {
//             bool isFigure = false;
//             for (int fi = 0; fi < figure.size(); fi++)
//                 for (int fj = 0; fj < figure[fi].size(); fj++)
//                     if (figure[fi][fj] && i == y + fi && j == x + fj)
//                         isFigure = true;
//             cout << (isFigure ? "[]" : (field[i][j] ? "[]" : "  "));
//         }
//         cout << "||" << endl;
//     }

//     for (int j = 0; j < width + 7; j++) cout << "=";
//     cout << "=====" << endl;
//     cout << "A - влево | D - вправо | S - ускорить | Q - выход | W - вращать\n";
// }


// void input() {
//     if (_kbhit()) {
//         char key = _getch();
//         if (key == 'a' && !checkCollision(-1, 0)) x--;
//         if (key == 'd' && !checkCollision(1, 0)) x++;
//         if (key == 's' && !checkCollision(0, 1)) y++;
//         if (key == 'w') rotateFigure();
//         if (key == 'q') exit(0);
//     }
// }
// void logic() {
//     if (!checkCollision(0, 1))
//         y++;
//     else {
//         placeFigure();
//         clearLines();
//         if (checkCollision(0, 0)) {
//             cout << "Game Over!" << endl;
//             exit(0);
//         }
//     }
// }

// int main() {
//     srand(time(0));
//     spawnFigure();

//     while (true) {
//         draw();
//         input();
//         logic();
//         Sleep(200);
//     }
//     return 0;
// }