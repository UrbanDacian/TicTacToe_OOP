#include <iostream>

using namespace std;

class Player {
private:
    string Name;
    string Symbol;
public:
    Player(string name, string symbol) {
        Name = name;
        Symbol = symbol;
    }

    string getName() {
        return Name;
    }

    string getSymbol() {
        return Symbol;
    }
};

class Table {
private:
    string board[10];
public:
    void PrepareTable() {
        for (int i = 0; i <= 9; ++i) {
            board[i] = " ";
        }

    }

    void ShowTable() {
        cout << "\n";
        cout << "\t\t     |     |     \n";
        cout << "\t\t  " << board[1] << "  |  " << board[2] << "  |  " << board[3] << " \n";
        cout << "\t\t_____|_____|_____\n";
        cout << "\t\t     |     |     \n";
        cout << "\t\t  " << board[4] << "  |  " << board[5] << "  |  " << board[6] << " \n";
        cout << "\t\t_____|_____|_____\n";
        cout << "\t\t     |     |     \n";
        cout << "\t\t  " << board[7] << "  |  " << board[8] << "  |  " << board[9] << " \n";
        cout << "\t\t     |     |     \n";
        cout << "\n";
    }

    string getValue(int index) {
        return board[index];
    }

    void setValue(int index, string symbol) {
        board[index] = symbol;
    }
};

class Game : public Player, public Table {
private:
    Player p1;
    Player p2;
    int winingCombination[10][4] = {{7, 8, 9},
                                    {4, 5, 6},
                                    {1, 2, 3},
                                    {1, 4, 7},
                                    {2, 5, 8},
                                    {3, 6, 9},
                                    {1, 5, 9},
                                    {3, 5, 7}};
public:
    bool stillGoing = true;
    int playerSymbol = 0;

    Game(string name1, string symbol1, string name2, string symbol2) : Player(name1, symbol1), p1(name1, symbol1),
                                                                       p2(name2, symbol2), Table() {}

    void StartGame() {
        PrepareTable();
        ShowTable();
        playMoves();
    }

    void playMoves() {
        while (stillGoing) {
            cout << "Adauga mutare: ";
            int move;
            cin >> move;
            if (move < 1 || move > 9) {
                cout << "Trebuie introdus un numar de la 1 la 9 \n";
            } else {
                if (getValue(move) == " ") {
                    setValue(move, playerSymbol % 2 == 0 ? p1.getSymbol() : p2.getSymbol());
                    ++playerSymbol;
                    cout << "\n";
                    ShowTable();
                    if (playerSymbol >= 5) {
                        checkWinner();
                    }
                } else {
                    cout << "Ai selectat un spatiu deja utilizat. \n";
                }
            }
            if (playerSymbol == 9) {
                cout << "DRAW!!!";
                stillGoing = false;
            }
        }
    }

    void checkWinner() {
        for (int i = 0; i < 8; ++i) {
            string firstCell = getValue(winingCombination[i][0]);
            string secondCell = getValue(winingCombination[i][1]);
            string thirdCell = getValue(winingCombination[i][2]);
            if (firstCell == secondCell && secondCell == thirdCell && firstCell != " ") {
                string winner = p1.getSymbol() == firstCell ? p1.getName() : p2.getName();
                cout << "Felicitari! " << winner << " a castigat!!!\n";
                stillGoing = false;
            }
        }
    }

};

int main() {
    Game TicTacToe("Player1", "X", "Player2", "0");
    TicTacToe.StartGame();

    return 0;
}