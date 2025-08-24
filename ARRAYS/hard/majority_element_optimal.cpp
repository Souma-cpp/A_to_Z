#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> find_majority_element(vector<int> arr, int n)
{
    vector<int> ans;
    int count1 = 0, count2 = 0, el1 = 0, el2 = 0;

    // Step 1: Find potential candidates
    for (int i = 0; i < n; i++)
    {
        if (el1 == arr[i])
            count1++;
        else if (el2 == arr[i])
            count2++;
        else if (count1 == 0)
        {
            el1 = arr[i];
            count1 = 1;
        }
        else if (count2 == 0)
        {
            el2 = arr[i];
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    // Step 2: Verify actual counts
    count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el1)
            count1++;
        else if (arr[i] == el2)
            count2++;
    }

    int mini = (n / 3) + 1;
    if (count1 >= mini)
        ans.push_back(el1);
    if (count2 >= mini)
        ans.push_back(el2);

    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element arr[" << i << "]: ";
        cin >> arr[i];
    }

    vector<int> majority_elements = find_majority_element(arr, n);

    if (majority_elements.empty())
        cout << "No majority element found.";
    else
        for (auto el : majority_elements)
            cout << el << " ";

    return 0;
}
