#include <iostream>
#include <vector>
using namespace std;
void merge_sort(vector<int> &arr, int left, int right, vector<pair<int, int>> &inversions)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid, inversions);
    merge_sort(arr, mid + 1, right, inversions);

    int i = left, j = mid + 1;
    vector<int> temp;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            for (int k = i; k <= mid; k++)
            {
                inversions.push_back({arr[k], arr[j]});
            }
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= right)
        temp.push_back(arr[j++]);
    for (int k = left; k <= right; k++)
    {
        arr[k] = temp[k - left];
    }
}
vector<pair<int, int>> find_inversions(vector<int> arr, int n)
{
    vector<pair<int, int>> inversions;
    merge_sort(arr, 0, n - 1, inversions);
    return inversions;
}

int main()
{
    vector<int> arr = {5, 3, 2, 4, 1};
    vector<pair<int, int>> answer = find_inversions(arr, arr.size());

    cout << "The pairs are:\n";
    for (auto p : answer)
    {
        cout << "{" << p.first << " , " << p.second << "}\n";
    }
    cout << "The number of inversions are: " << answer.size() << endl;
    return 0;
}
