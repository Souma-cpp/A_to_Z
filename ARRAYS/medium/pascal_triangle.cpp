// find the value[i][j] in the pascal triangle
#include <iostream>
using namespace std;

int find_nCr(int n, int r)
{
    int result = 1; // Initialize to 1
    for (int i = 0; i < r; i++)
    {
        result = result * (n - i);
        result = result / (i + 1);
    }
    return result;
}

int main()
{
    int row;
    cout << "Enter the row number of the position :";
    cin >> row;
    int col;
    cout << "Enter the col number of the position :";
    cin >> col;

    cout << "The element at the position " << row << " , "
         << col << " is :" << find_nCr(row - 1, col - 1) << endl; // Adjust for 0-based indexing
    return 0;
}