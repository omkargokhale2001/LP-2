#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Board
{
public:
    int n = 0;
    vector<vector<int>> board;

    Board(int n)
    {
        this->n = n;
        board.resize(n);
        int i, j;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                board[i].push_back(0);
            }
        }
    }

    void display_board()
    {
        int i, j;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool isSafe(int row, int col)
    {

        int i, j;
        for (i = 0; i < col; i++)
            if (board[row][i])
                return false;

        /* Check upper diagonal on left side */
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j])
                return false;

        /* Check lower diagonal on left side */
        for (i = row, j = col; j >= 0 && i < n; i++, j--)
            if (board[i][j])
                return false;

        return true;
    }

    bool NQueen_help(int col)
    {
        if (col >= n)
        {
            return true;
        }

        int i;

        for (i = 0; i < this->n; i++)
        {
            if (isSafe(i, col))
            {
                board[i][col] = 1;
                if (NQueen_help(col + 1))
                {
                    return true;
                }
                // backtrack
                board[i][col] = 0;
            }
        }
        return false;
    }

    void solveNQueen()
    {
        if (NQueen_help(0) == false)
        {
            cout << "No solution to this problem" << endl;
        }
        else
        {
            display_board();
        }
    }
};

int main()
{
    Board b(4);
    // b.display_board();
    b.solveNQueen();
    return 0;
}