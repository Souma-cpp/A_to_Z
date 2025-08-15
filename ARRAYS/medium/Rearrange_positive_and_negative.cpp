#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeArray(int nums[], int n)
{
    vector<int> positive, negative;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
            positive.push_back(nums[i]);
        else
            negative.push_back(nums[i]);
    }

    vector<int> final_answer;
    for (int i = 0; i < positive.size(); i++)
    {
        final_answer.push_back(positive[i]);
        final_answer.push_back(negative[i]);
    }
    return final_answer;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element arr[" << i + 1 << "] : ";
        cin >> arr[i];
    }

    vector<int> answer = rearrangeArray(arr, n);

    cout << "The rearranged array looks like : ";
    for (int num : answer)
        cout << num << " ";

    return 0;
}
