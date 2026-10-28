#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<vector<int>>& board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<vector<int>>& board, int row, int col, int n)
{
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

void solveNQueens(vector<vector<int>>& board, int row, int n, int& count)
{
    if (row == n)
    {
        printBoard(board, n);
        count++;
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 1;
            solveNQueens(board, row + 1, n, count);
            board[row][col] = 0;
        }
    }
}

int main()
{
    int n, firstRow, firstCol, count = 0;

    cout << "Enter size of board (N): ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid board size!" << endl;
        return 0;
    }

    vector<vector<int>> board(n, vector<int>(n, 0));

    cout << "Enter position of first queen (row and column, starting from 0): ";
    cin >> firstRow >> firstCol;

    if (firstRow < 0 || firstRow >= n || firstCol < 0 || firstCol >= n)
    {
        cout << "Invalid position!" << endl;
        return 0;
    }

    board[firstRow][firstCol] = 1;

    if (!isSafe(board, firstRow, firstCol, n))
    {
        cout << "No solution exists." << endl;
        return 0;
    }

    cout << "\nAll possible solutions:\n";

    solveNQueens(board, firstRow + 1, n, count);

    if (count == 0)
        cout << "No solution exists." << endl;

    return 0;
}

