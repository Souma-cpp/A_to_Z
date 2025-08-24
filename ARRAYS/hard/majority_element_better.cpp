#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> find_majority_element(vector<int> arr, int n)
{
    unordered_map<int, int> map;
    vector<int> ans;
    for (int num : arr)
    {
        map[num]++;
        if (map[num] > n / 3)
        {
            ans.push_back(num);
        }
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the size of the array :";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element of arr[" << i << "] :";
        cin >> arr[i];
    }
    vector<int> majority_elements = find_majority_element(arr, arr.size());
    for (auto el : majority_elements)
    {
        cout << el << " ";
    }
    return 0;
}