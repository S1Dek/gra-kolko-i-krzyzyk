#include <iostream>
#include <locale.h>                             // biblioteka ustawienia specyficzne dla lokalizacji
using namespace std;

void display(string table[3][3], bool* go) {                      // funckja wyświetlająca kółka i krzyżyki
    *go = false;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (table[i][j] == " ") {
                *go = true;
            }
            cout << table[i][j] << "|";
        }
        cout << endl;
    }
}
int turn(int turn_h) {                                          // funckja zmieniająca turę graczy
    int player = turn_h % 2 + 1;
    cout << "Gracz " << player << ", podaj pole: ";
    return player;
}
void move(string table[3][3], int player) {                     // funckja odpowiedzialna za oddawanie ruchów
    bool found{};
    int row, col, array_h, row_h = 0, col_h = 0;
    int table_h[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
    do {
        cout << "od 1 do 9: ";
        do {
            cin >> array_h;
        } while (array_h > 9);
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (table_h[row][col] == array_h) {
                    found = true;
                    row_h = row;
                    col_h = col;
                }
            }
        }
    } while (table[row_h][col_h] != " ");
    if (player == 1) {
        table[row_h][col_h] = "X";
    }
    else {
        table[row_h][col_h] = "O";
    }
}
void check_win(string table[3][3], bool *go, bool *win) {        // funkcja sprawdzająca czy aktualne ustawienie oznacza zwycięstwo
    int i = 0, j = 0;
    *win = false;
    for (i = 0; i < 3; i++)
    {
        if (table[i][0] == table[i][1] && table[i][0] == table[i][2] && table[i][0]!=" ") {
            *win = true;
        }
    }
    for (i = 0; i < 3; i++)
    {
        if (table[0][i] == table[1][i] && table[0][i] == table[2][i] && table[0][i]!=" ") {
            *win = true;
        }
    }
    if (table[0][0] == table[1][1] && table[0][0] == table[2][2] && table[0][0] != " ") {
        *win = true;
    }
    if (table[0][2] == table[1][1] && table[0][2] == table[2][0] && table[0][2] != " ") {
        *win = true;
    }
    if (*win == true)
    {
        *go = false;
    }
}
bool end(bool *win, int player) {            // funkcja wypisująca rezultat
    cout << "KONIEC" << endl;
    if (*win==true) {
        cout << "Zwycięzcą został gracz nr "<< player << endl;
    }
    else {
    cout << "Brak zwycięzcy" << endl;
    }
    return true;
}
int main()
{
    setlocale(LC_ALL, "");                   // UTF-8 polskie znaki
    string table[3][3] = { {" "," "," "},{" "," "," "},{" "," "," "} };
    int turn_h = 0;
    bool go = true, win = false;
    int player;
    while (go) {
        player = turn(turn_h);
        move(table, player);
        turn_h++;
        display(table, &go);
        check_win(table, &go, &win);
    }
    end(&win, player);
    return 0;
}