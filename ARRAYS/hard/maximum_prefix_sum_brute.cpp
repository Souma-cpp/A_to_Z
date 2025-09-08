#include<iostream>
#include<vector>
#include<climits>
using namespace std ;

int get_max_product(vector<int> arr , int n){
    int max_product = INT_MIN ;
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            int product = 1 ;
            for(int k = i ; k < j ; k++){
                product = product * arr[k] ;
            }
            max_product = max(max_product , product) ;
        }
    }
    return max_product;
}

int main(){

    vector<int> arr = {2,2,4,6,1,2,-8,5,6} ;
    cout << "The maximum product that can be obtained from the subarrays is :" << get_max_product(arr , arr.size()) << endl ;

    return 0 ;
}