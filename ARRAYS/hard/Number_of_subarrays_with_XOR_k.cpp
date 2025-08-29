#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;

int find_number_of_subarrays(vector<int> arr , int k , vector<vector<int>> &subarrays){
    int n = arr.size() ;
    unordered_map<int,vector<int>> mpp ;
     mpp[0].push_back(-1) ;  //making sure {0,1} is present
    int count = 0 ;
    int prefix_xor = 0 ;
    for(int i = 0 ; i < n ; i++){
        prefix_xor = prefix_xor ^ arr[i] ;
        int x = prefix_xor ^ k ;
        if(mpp.find(x) != mpp.end()){
            for(auto index : mpp[x]){
                vector<int> temp(arr.begin() + index + 1 , arr.begin() + i + 1) ;
                subarrays.push_back(temp) ;
                count++ ;
            }
        }
        mpp[prefix_xor].push_back(i);
    }
    return count ;
}


int main(){

    vector<int> arr = {4,2,2,6,4} ;
    int k ;
    vector<vector<int>> subarrays ;
    cout << "Enter the value of target k : " ;
    cin  >> k ;

    int ans = find_number_of_subarrays(arr , k , subarrays) ;
    cout << "Number of subarrays with XOR k is :" << ans << endl ;

    cout << endl ;
    for(auto subarray : subarrays){
        cout << "{" ;
        for(auto el : subarray){
            cout << el << " ";
        }
        cout << "} , " ;
    }
    

    return 0 ;
}