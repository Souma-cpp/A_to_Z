#include <iostream>
#include <vector>
using namespace std;

void merge_two_sorted_arrays(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size(), m = arr2.size();
    vector<int> temp(n + m) ;
    int left = 0 , right = 0 , index = 0 ;
    while(left < n && right < m){
        if(arr1[left] < arr2[right]){
            temp[index++] = arr1[left++] ;
        }else{
            temp[index++] = arr2[right++];
        }
    }
    while(left < n) {
        temp[index++] = arr1[left++];
    }
    while(right < m){
        temp[index++] = arr2[right++];
    }

    for(int i = 0 ; i < temp.size() ; i++){
        if(i < n) arr1[i] = temp[i] ;
        else arr2[i - n] = temp[i] ;
    }

}

int main()
{
    vector<int> arr1 = {1,3,5,7};
    vector<int> arr2 = {0,2,6,8,9};
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