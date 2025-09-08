#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int find_maximum_product(vector<int> arr, int n)
{
    int max_product = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int product = 1;
        for (int j = i; j < n; j++)
        {
            product *= arr[j];
            max_product = max(max_product, product);
        }
    }

    return max_product;
}

int main()
{
    vector<int> arr = {5, 3, 1, 5, -10, 0, 4, 3, 2, 1};
    cout << "Answer from the better approach: " << find_maximum_product(arr, arr.size());

    return 0;
}
