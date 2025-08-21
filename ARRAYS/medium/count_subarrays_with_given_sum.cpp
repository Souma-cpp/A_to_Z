#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int number_of_subarrays_with_given_sum(vector<int> arr, int k)
{
    int n = arr.size();
    int count = 0, prefix_sum = 0;
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1; // to handle subarrays starting from index 0

    for (int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        int remainder = prefix_sum - k;

        if (prefixCount.count(remainder))
            count += prefixCount[remainder];

        prefixCount[prefix_sum]++;
    }

    return count;
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

    int target;
    cout << "Enter the target value: ";
    cin >> target;

    int ans = number_of_subarrays_with_given_sum(arr, target);

    cout << "The number of subarrays with sum " << target << " is: " << ans << endl;

    return 0;
}
