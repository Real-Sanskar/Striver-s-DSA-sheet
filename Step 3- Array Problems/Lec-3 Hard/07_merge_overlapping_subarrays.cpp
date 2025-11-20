// given an array of intervals, where interval[i] = [starti, endi]
// merge all overlapping intervals and return result in sorted order

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



// 1. Brute force approach (TC : O(N*N + N*logN)      SC : O(N))

// LOGIC : compare every intervals with every other, merge if overlapping
// ALGORITHM :
// sort intervals
// for each intervals, checkkfor all others
// if 2 overlap (end1 >= start2) merge into : {min(start1,start2), max(end1,end2)}
// mark merged intervals 

// vector<vector<int>> merge_subarray(vector<vector<int>> &arr){
//     int n = arr.size();
//     vector<vector<int>> ans;

//     sort(arr.begin(),arr.end());

//     for(int i=0; i<n; i++){
//         int start = arr[i][0], end = arr[i][1];
//         if(!ans.empty() && arr[i][0] <= ans.back()[1]){
//             continue;
//         }
//         for(int j=i+1; j<n; j++){
//             if(arr[j][0] <= end){
//                 end = max(end,arr[j][1]);
//             }
//             else{
//                 break;
//             }
//         }
//         ans.push_back({start,end});
//     }
//     return ans;
// }




// 2. Optmial approach 

// LOGIC :  sort intervals, merge while traversing linearly
// ALGORITHM : 
// sort the array
// traverse the array
// case 1: if no overlap : 
//          if(ans.empty() || arr[i][0] > ans.back()[1])
//              ans.push_back(arr[i]);
//          else 
//              ans.back()[1] = max(ans.back()[1],arr[i][1])

vector<vector<int>> merge_subarray(vector<vector<int>> &arr){
    int n = arr.size();
    vector<vector<int>> ans;

    sort(arr.begin(),arr.end());

    int start = 0, end = 0;
    for(int i=0; i<n; i++){
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> arr = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> ans = merge_subarray(arr);

    for(auto row : ans){
        for(int val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}