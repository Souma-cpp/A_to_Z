#include<iostream>
#include<vector>
#include <algorithm>
using namespace std ;
int number_of_minimum_intervals(vector<vector<int>> arr , vector<vector<int>>& ans){
    sort(arr.begin() , arr.end()) ;
    int count = 0 ;
    int n = arr.size() ;
    for(int i = 0 ; i < n ; i++){
        if(ans.empty() || ans.back()[1] < arr[i][0]){
            // either its the first value or a new interval
            ans.push_back(arr[i]) ;
        }else{
            // it belongs to the current ongoing interval
            ans.back()[1] = max(ans.back()[1] , arr[i][1]) ;
        }
    }
    for(auto interval : ans){
        count ++ ;
    }
    return count ;
}
int main(){
    vector<vector<int>> arr = {{1,3},{2,4},{2,6},{8,9},{8,10},{9,11},{15,18},{16,17}} ;
    vector<vector<int>> ans = {} ;
    int num = number_of_minimum_intervals(arr , ans) ;
    cout << "The number of minimum intervals can be :" << num << endl ;
    for(auto interval : ans){
        cout << "{" << interval[0] << "," << interval[1] << "} " ;
    }
    cout << endl ;
    return 0 ; 
}