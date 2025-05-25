#include <iostream>
using namespace std;

class Game
{
public:
    int arr[3][3];

    // setting all matrix value to negative
    void set_zero()
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                arr[i][j] = -1;
    }

    // printing the matrix
    void print()
    {
        for (int i = 0; i < 3; i++)
        {
            cout << endl;
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] == -1)
                {
                    cout << " ";
                }
                else if (arr[i][j] == 0)
                {
                    cout << "O";
                }
                else if (arr[i][j] == 1)
                {
                    cout << "X";
                }
                if (j != 2)
                {
                    cout << " | ";
                }
            }
            if (i != 2)
            {
                cout << endl
                     << "----------";
            }
        }
    }

    // taking inputs
    static int turn;
    bool take_input(int i, int j, char a)
    {
        if (turn == 0)
        {
            if ((a == 'O' || a == 'o') && arr[i][j] == -1)
            {
                arr[i][j] = 0;
                turn = 1;
                return true;
            }
            else
                return false;
        }
        else
        {
            if ((a == 'X' || a == 'x') && arr[i][j] == -1)
            {
                arr[i][j] = 1;
                turn = 0;
                return true;
            }
            else
                return false;
        }
    }

    // checking the matrix
    bool check()
    {
        // Check rows and columns
        for (int i = 0; i < 3; ++i)
        {
            if (arr[i][0] != -1 && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2])
                return true; // Row
            if (arr[0][i] != -1 && arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i])
                return true; // Column
        }

        // Check diagonals
        if (arr[0][0] != -1 && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
            return true;
        if (arr[0][2] != -1 && arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
            return true;

        return false;
    }

    // using ai
    bool isFull()
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (arr[i][j] == -1)
                    return false;
        return true;
    }

    int minimax(int depth, bool isMax)
    {
        if (check())
        {
            if (isMax) {
                return -10 + depth;} // Previous move was human, so human won
            else
                return 10 - depth; // Previous move was AI, so AI won
        }
        if (isFull())
            return 0; // Draw

        if (isMax)
        {
            int bestScore = -1000;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (arr[i][j] == -1)
                    {
                        arr[i][j] = 1; // AI move (X)
                        int score = minimax(depth + 1, false);
                        arr[i][j] = -1;
                        bestScore = max(bestScore, score);
                    }
                }
            }
            return bestScore;
        }
        else
        {
            int bestScore = 1000;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (arr[i][j] == -1)
                    {
                        arr[i][j] = 0; // Human move (O)
                        int score = minimax(depth + 1, true);
                        arr[i][j] = -1;
                        bestScore = min(bestScore, score);
                    }
                }
            }
            return bestScore;
        }
    }

    pair<int, int> bestMove()
    {
        int bestScore = -1000;
        int move_i = -1;
        int move_j = -1;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] == -1)
                {
                    arr[i][j] = 1; // AI tries this move
                    int score = minimax(0, false);
                    arr[i][j] = -1;
                    if (score > bestScore)
                    {
                        bestScore = score;
                        move_i = i;
                        move_j = j;
                    }
                }
            }
        }
        return {move_i, move_j};
    }
};

int Game::turn = 0;

int main()
{
    while (true)
    {
        char a;
        cout << "Do you guys want to play tic-tac-toe(y/n): ";
        cin >> a;
        if (a == 'y' || a == 'Y')
        {
            Game::turn = 0;
            cout << "Enter row (0-2), column (0-2), and your symbol (O/X).\nExample: 1 2 O\n";
            Game G;
            G.set_zero();
            G.print();
            char ai = 'n';
            cout << endl
                 << "Do you guys want to play with AI(y/n): ";
            cin >> ai;
            int flag = 0;
            int count = 0;
            while (true)
            {
                int i, j;
                char piece;
                if (flag == 0 && count < 9)
                {
                    cout << endl
                         << "Player 1 turn(p1 p2 O/o): ";
                    cin >> i >> j >> piece;
                    if (G.take_input(i, j, piece))
                    {
                        count++;
                        flag = 1;
                        G.print();
                        if (G.check())
                        {
                            cout << endl
                                 << "Player 1 WINS!!!!" << endl;
                            break;
                        }
                    }
                    else
                    {
                        cout << endl
                             << "Wrong input try again:(";
                    }
                }
                else if (flag == 1 && count < 9 && (ai == 'n' || ai == 'N'))
                {
                    cout << endl
                         << "Player 2 turn(p1 p2 X/x): ";
                    cin >> i >> j >> piece;
                    if (G.take_input(i, j, piece))
                    {
                        count++;
                        flag = 0;
                        G.print();
                        if (G.check())
                        {
                            cout << endl
                                 << "Player 2 WINS!!!!" << endl;
                            break;
                        }
                    }
                    else
                    {
                        cout << endl
                             << "Wrong input try again:(";
                    }
                }
                else if (flag == 1 && count < 9 && (ai == 'y' || ai == 'Y'))
                {
                    cout << endl
                         << "AI turn (X): ";
                    pair<int, int> ai_move = G.bestMove();
                    int i = ai_move.first;
                    int j = ai_move.second;
                    cout << i << " " << j << " X" << endl;
                    G.take_input(i, j, 'X');
                    count++;
                    flag = 0;
                    G.print();
                    if (G.check())
                    {
                        cout << endl
                             << "AI WINS!!!!" << endl;
                        break;
                    }
                }

                else
                {
                    cout << endl
                         << "This is a draw." << endl;
                    break;
                }
            }
        }
        else
        {
            cout << "Okay maybe next time:(";
            break;
        }
    }
}