#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

int largest_subarray(vector<int> arr, int n, vector<int> &subarray)
{
    int maxi = 0; // length of largest subarray
    long long sum = 0;
    unordered_map<long long, int> mpp; // prefix sum -> index
    int start = -1, end = -1;          // store indices of answer

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0)
        {
            if (i + 1 > maxi)
            {
                maxi = i + 1;
                start = 0;
                end = i;
            }
        }
        else
        {
            if (mpp.find(sum) != mpp.end())
            {
                int curr_len = i - mpp[sum];
                if (curr_len > maxi)
                {
                    maxi = curr_len;
                    start = mpp[sum] + 1;
                    end = i;
                }
            }
            else
            {
                mpp[sum] = i; // store first occurrence
            }
        }
    }

    if (start != -1 && end != -1)
    {
        for (int i = start; i <= end; i++)
        {
            subarray.push_back(arr[i]);
        }
    }

    return maxi;
}

int main()
{
    vector<int> arr = {1, -1, 3, 2, -2, -8, 1, 7, 10, 23};
    vector<int> subarray;
    int ans = largest_subarray(arr, arr.size(), subarray);

    cout << "The size of the largest subarray is: " << ans << endl;
    cout << "The subarray is: {";
    for (auto it : subarray)
    {
        cout << it << " ";
    }
    cout << "} " ;
    cout << endl;

    return 0;
}
