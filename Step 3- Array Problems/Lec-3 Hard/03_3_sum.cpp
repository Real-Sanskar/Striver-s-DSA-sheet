// given an array of integers, fint unique triplets that adds up to 0

#include<iostream>
#include<vector>
#include<algorithm> // for sort
#include<set>      // for handling duplicates
using namespace std;

// Brute Force Approach
// Time: O(n³), Space: O(no. of unique triplets) for output
vector<vector<int>> three_sum(vector<int> &arr) {
    int n = arr.size();
    // Using set to store unique triplets
    set<vector<int>> uniqueTriplets;
    
    // Try all possible triplets
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(arr[i] + arr[j] + arr[k] == 0) {
                    // Sort the triplet before adding to ensure uniqueness
                    vector<int> triplet = {arr[i], arr[j], arr[k]};
                    sort(triplet.begin(), triplet.end());
                    uniqueTriplets.insert(triplet);
                }
            }
        }
    }
    
    // Convert set to vector for return
    return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
}

int main(){
    vector<int> arr = {-1,0,1,2,-1,-4};

    vector<vector<int>> ans = three_sum(arr);

    for(auto row : ans){
        for(int val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}