#include <iostream>
#include <vector>
using namespace std;

// using kadane algorithm by O(n) time and O(1) space complexity

int get_max_subarray_sum(vector<int> arr, int n)
{
    int sum = 0, max_sum = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum > max_sum)
        {
            max_sum = sum;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }
    return max_sum;
}

void get_longest_subarray(vector<int> &longest_subarray, vector<int> arr, int n)
{
    int sum = 0, max_sum = INT16_MIN, start = 0, subarray_start = 0, subarray_end = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
        {
            start = i;
        }
        sum += arr[i];

        if (sum > max_sum)
        {
            max_sum = sum;
            subarray_start = start;
            subarray_end = i;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }

    for (int i = subarray_start; i <= subarray_end; i++)
    {
        longest_subarray.push_back(arr[i]);
    }
}

int main()
{
    int n;
    cout << "Enter n :";
    cin >> n;
    cout << endl;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element of arr[" << i << "] :";
        cin >> arr[i];
    }
    int maximum_subarray_sum = get_max_subarray_sum(arr, n);
    cout << "Maximum subarray sum is :" << maximum_subarray_sum << endl;

    vector<int> longest;
    get_longest_subarray(longest, arr, n);
    cout << "The longest subarray with the largest sum is : ";
    for (auto it : longest)
    {
        cout << it << " ";
    }

    return 0;
}