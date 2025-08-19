#include <iostream>
using namespace std;

void set_matrix_zero(int arr[][100], int rows, int cols)
{
    bool row[rows] = {false}, col[cols] = {false};
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == 0)
            {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            if(row[i] == true || col[j] == true){
                arr[i][j] = 0 ;
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

    set_matrix_zero(matrix, m, n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}