#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

pair<int, int> find_answer_brute(vector<int> arr, int n)
{
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++)
    {
        int count = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] == i)
            {
                count++;
            }
        }
        if (count == 0)
            missing = i;
        else if (count > 1)
            repeating = i;
    }
    return {repeating, missing};
}

pair<int, int> find_answer_better(vector<int> arr, int n)
{
    int hashArray[n + 1] = {0};
    int missing = -1, repeating = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        hashArray[arr[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (hashArray[i] > 1)
        {
            repeating = i;
        }
        else if (hashArray[i] == 0)
        {
            missing = i;
        }
    }

    return {repeating, missing};
}

pair<int, int> find_answer_optimal_mathemetical(vector<int> arr, int k)
{
    int x = -1, y = -1, s1 = 0, s2 = 0, s_square1 = 0, s_square2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        s1 += arr[i];
    }
    s2 = (k * (k + 1)) / 2;
    for (auto el : arr)
    {
        s_square1 += pow(el, 2);
    }
    s_square2 = (k * (k + 1) * (2 * k + 1)) / 6;
    int sub1 = s1 - s2;               // x - y
    int sub2 = s_square1 - s_square2; // x^2 - y^2
    int sum = sub2 / sub1;            // x + y
    x = (sum + sub1) / 2;
    y = sum - x;
    return {x, y};
}

int main()
{
    vector<int> arr = {4, 3, 6, 2, 1, 1};
    // Approach 1
    pair<int, int> ans1 = find_answer_brute(arr, 6);
    cout << "Brute Force: Repeating = " << ans1.first << ", Missing = " << ans1.second << endl;

    // Approach 2
    pair<int, int> ans2 = find_answer_better(arr, 6);
    cout << "Better Approach: Repeating = " << ans2.first << ", Missing = " << ans2.second << endl;

    // Approch 3
    pair<int, int> ans3 = find_answer_optimal_mathemetical(arr, 6);
    cout << "Optimal mathemetical Approach: Repeating = " << ans3.first << ", Missing = " << ans3.second << endl;

    return 0;
}
