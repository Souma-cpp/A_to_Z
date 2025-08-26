#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> foursum_problem(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int k = j + 1, l = n - 1;

            while (k < l)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                if (sum == target)
                {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    while (k < l && nums[k] == nums[k + 1])
                        k++;
                    while (k < l && nums[l] == nums[l - 1])
                        l--;
                    k++;
                    l--;
                }
                else if (sum < target)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5};
    int target;
    cout << "Enter the value of the target: ";
    cin >> target;

    vector<vector<int>> possible_quarts = foursum_problem(nums, target);

    cout << "The possible quarts are:\n";
    for (auto quarts : possible_quarts)
    {
        cout << "{ ";
        for (auto element : quarts)
        {
            cout << element << " , ";
        }
        cout << "}" << "    ";
    }

    return 0;
}
