#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    printf("next permutation is : ");
    next_permutation(arr.begin(), arr.end());
    for (int num : arr)
    {
        cout << num << " ";
    }
}