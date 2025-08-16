#include <iostream>
#include <vector>
using namespace std;

int lcs(vector<int> arr)
{
    int n = arr.size();
    int longest = 1;

    for (int i = 0; i < n; i++)
    {
        int val = arr[i];
        int count = 1;
        while (true)
        {
            bool found = false;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] == val + 1)
                {
                    count++;
                    val = arr[j];
                    found = true;
                    break;
                }
            }
            if (!found)
                break;
        }

        longest = max(longest, count);
    }

    return longest;
}

int main()
{
    int n;
    cout << "Enter the size: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }

    int ans = lcs(arr);
    cout << "The length of the longest consecutive subsequence is: " << ans << endl;
    return 0;
}
