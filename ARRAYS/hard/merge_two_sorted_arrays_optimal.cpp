#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

void merge_two_sorted_arrays(vector<int> &arr1 , vector<int> &arr2){
    //swap based approach
    int n = arr1.size() , m = arr2.size() ;
    int left = n - 1 , right = 0 ;
    while(left < n && right < m){
        if(arr1[left] > arr2[right]){
            swap(arr1[left--] , arr2[right++]) ;
        }else{
            break ;
        }
    }
    sort(arr1.begin() , arr1.end()) ;
    sort(arr2.begin() , arr2.end()) ;
}

int main()
{
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {0, 2, 6, 8, 9};
    merge_two_sorted_arrays(arr1, arr2);
    cout << "The array 1 looks like : {";
    for (auto el : arr1)
    {
        cout << el << " ";
    }
    cout << "}" << endl;

    cout << "The array 2 looks like : {";
    for (auto el : arr2)
    {
        cout << el << " ";
    }
    cout << "}" << endl;

    return 0;
}