#include <iostream>
using namespace std;

void print_spiral_matrix(int arr[][100], int m, int n)
{
    int startrow = 0, startcol = 0;
    int endrow = m - 1, endcol = n - 1;

    while (startrow <= endrow && startcol <= endcol)
    {
        // 1. Left to right
        for (int j = startcol; j <= endcol; j++)
            cout << arr[startrow][j] << " ";
        startrow++;

        // 2. Top to bottom
        for (int i = startrow; i <= endrow; i++)
            cout << arr[i][endcol] << " ";
        endcol--;

        // 3. Right to left
        if (startrow <= endrow)
        {
            for (int j = endcol; j >= startcol; j--)
                cout << arr[endrow][j] << " ";
            endrow--;
        }

        // 4. Bottom to top
        if (startcol <= endcol)
        {
            for (int i = endrow; i >= startrow; i--)
                cout << arr[i][startcol] << " ";
            startcol++;
        }
    }
}

int main()
{
    int m, n;
    cout << "Enter the row number of the matrix: ";
    cin >> m;
    cout << "Enter the col number of the matrix: ";
    cin >> n;

    int matrix[100][100];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter the matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nSpiral Order: ";
    print_spiral_matrix(matrix, m, n);
    cout << endl;

    return 0;
}
