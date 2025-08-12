#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &arr)
{
    int maxPro = 0;
    int n = arr.size();
    int minPrice = INT16_MAX;

    for (int i = 0; i < arr.size(); i++)
    {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }

    return maxPro;
}

int main()
{
    vector<int> arr = {7, 5 , 9 , 8 , 10 , 21 , 11};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}
