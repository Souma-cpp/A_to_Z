#include <iostream>
#include <vector>
using namespace std;

void mark_row(int arr[][100], int cols, int i)
{
    for (int j = 0; j < cols; j++)
    {
        arr[i][j] = -1;
    }
}

void mark_col(int arr[][100], int rows, int j)
{
    for (int i = 0; i < rows; i++)
    {
        arr[i][j] = -1;
    }
}

void set_matrix_zeroes(int arr[][100], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == 0)
            {
                mark_row(arr, cols, i);
                mark_col(arr, rows, j);
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == -1)
            {
                arr[i][j] = 0;
            }
        }
    }
}

int main()
{
    int n, m;
    cout << "Enter the row number of the matrix :";
    cin >> m;
    cout << "Enter the col number of the matrix :";
    cin >> n;
    int matrix[100][100]; 
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter the matrix[" << i << "][" << j << "] :";
            cin >> matrix[i][j];
        }
    }

    set_matrix_zeroes(matrix, m, n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}