#include <iostream>
#include <vector>
using namespace std;

pair<int, pair<int, int>> find_max_product_subarray(const vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return {0, {-1, -1}};

    int max_product = arr[0];
    int curr_max = arr[0], curr_min = arr[0];
    int start = 0, end = 0, temp_start = 0;

    for (int i = 1; i < n; ++i)
    {
        if (arr[i] < 0)
            swap(curr_max, curr_min);

        if (arr[i] > curr_max * arr[i])
        {
            curr_max = arr[i];
            temp_start = i;
        }
        else
        {
            curr_max *= arr[i];
        }

        curr_min = min(arr[i], curr_min * arr[i]);

        if (curr_max > max_product)
        {
            max_product = curr_max;
            start = temp_start;
            end = i;
        }
    }

    return {max_product, {start, end}};
}

int main()
{
    vector<int> arr = {2, 3, -2, 4, -1 , -5 , 1};
    auto result = find_max_product_subarray(arr);
    int max_product = result.first;
    int start = result.second.first;
    int end = result.second.second;

    cout << "Max product: " << max_product << "\n";
    cout << "Subarray: ";
    for (int i = start; i <= end; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
