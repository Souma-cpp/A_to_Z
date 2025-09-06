#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> find_inversions(vector<int> arr, int n)
{
    vector<pair<int,int>> ans ;
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(arr[i] > arr[j]){
                pair<int,int> p = {arr[i] , arr[j]} ;
                ans.push_back(p) ;
            }
        }
    }
    return ans ;
}

int main()
{
    vector<int> arr = {5, 3, 2, 4, 1} ;
    vector<pair<int,int>> answer = find_inversions(arr , arr.size()) ;
    int count = 0 ;
    cout << "The pairs are :" ;
    for(auto p : answer){
        cout << "{" << p.first << " , " << p.second << "}" << endl ;
        count++ ;
    }
    cout << "The number of inversions are :" << count << endl ;
    return 0;
}