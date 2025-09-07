#include <iostream>
#include <vector>
using namespace std;

int find_reverse_pairs(vector<int> arr , int n , vector<vector<int>>& pairs){
    int count = 0 ;  
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(i < j && arr[i] > 2 * arr[j]){
                count++ ;
                pairs.push_back({arr[j] , arr[i]}) ;
            }
        }
    }
    return count ;
}

int main()
{
    vector<int> arr = {40, 25, 19, 12, 9, 6, 2};
    vector<vector<int>> answer = {} ;
    int cnt = find_reverse_pairs(arr , arr.size() , answer) ;
    cout << "The number of pairs with the following condistions is :" << cnt << endl ;
    cout << "The pairs are :" ;
    for(auto p : answer){
        cout << "{" << p[1] << "," << p[0] << "}" << endl ;
    }
    return 0;
}