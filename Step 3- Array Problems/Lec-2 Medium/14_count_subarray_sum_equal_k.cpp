// given an array an an integer k,
// Return total no. of subarray whose sum equal to k

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


// 1. Brute force approach (TC : O(N*N*N)    SC : O(1))

// loop-1 : starting point of subarray
// loop-2 : ending point of subarray
// loop-3 : calculate sum 
// If (sum == k), increament count

// int count_sum(vector<int> &arr, int k){
//     int n = arr.size();

//     int count = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             int sum = 0;
//             for(int K= i; K <= j; K++){
//                 sum += arr[K];
//             }
//             if(sum == k){
//                 count++;
//             }
//         }
//     }
//     return count;
// }



// 2. Better approach (TC : O(N*N)   SC : O(1)) 

// loop-1 : starting point of subarray
// loop-2 : ending point of subarray, calculate sum within loop
// if(sum == k), increament count

// int count_sum(vector<int> &arr, int k){
//     int n = arr.size();

//     int count = 0;
//     for(int i=0; i<n; i++){
//         int sum = 0;
//         for(int j=i ; j<n; j++){
//             sum += arr[j];
//             if(sum == k){
//                 count++;
//             }
//         }
//     }
//     return count;
// }



int count_sum(vector<int> &arr, int k){
    int n = arr.size();
    unordered_map<int,int> prefixSum;

    prefixSum[0] = 1;

    int count = 0, sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];

        int rem = sum - k ;

        count += prefixSum[rem];

        prefixSum[sum]++;
    }
    return count;
}


int main(){
    vector<int> arr = {3,1,2,4};
    int k = 6;

    cout << count_sum(arr,k) << endl;

    return 0;
}