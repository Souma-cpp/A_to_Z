#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// optimal approach
vector<int> find_leader_elements(vector<int> arr)
{
    int n = arr.size();
    int maxi = INT_MIN;
    vector<int> leaders;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > maxi)
        {
            leaders.push_back(arr[i]);
            maxi = arr[i];
        }
    }
    return leaders;
}

int main()
{
    int n;
    cout << "Enter the size :";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value of : arr[ " << i << " ] :";
        cin >> arr[i];
    }

    vector<int> ans = find_leader_elements(arr);
    //sort(ans.begin(), ans.end());
    cout << "The leader elements are :";
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
