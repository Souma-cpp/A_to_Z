#include <iostream>
using namespace std;
int main()
{
    int m, n;
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
    int rotated[100][100];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rotated[j][m - i - 1] = matrix[i][j];
        }
    }
    cout << "The rotated matrix looks like :" << endl;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            cout << rotated[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}