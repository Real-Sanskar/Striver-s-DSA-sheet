// find all unique quadruplets (a,b,c,d) in an array such that 
//   (a+b+c+d) = target
// RETURN quadraplets without duplicates

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;



// 1. Brute force approach (TC : O(N*N*N*N)    SC : O(1))

// LOGIC : check all possible quardaplets, store unique ones in set
// ALGORITHM :
// use 4 nested loops
// if sum == target , store the target
// convert set to vector

// vector<vector<int>> four_sum(vector<int> &arr, int target){
//     int n = arr.size();

//     set<vector<int>> ans;
    
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             for(int k=j+1; k<n; k++){
//                 for(int l=k+1; l<n; l++){
//                     int sum = arr[i] + arr[j] + arr[k] + arr[l];
//                     if(sum == target){
//                         vector<int> temp = {arr[i],arr[j],arr[k],arr[l]};
//                         sort(temp.begin(),temp.end());
//                         ans.insert(temp);
//                     }
//                 }
//             }
//         }
//     }
//     vector<vector<int>> result(ans.begin(),ans.end());

//     return result;
// } 





// 2. Better approach (TC : O(N*N*N)    SC : O(2*M) + O(N))

// LOGIC : fix 3 numbers, check if 4th exits in hash Set
// ALGORITHM : 
//      -> fix 3 numbers i,j,k using 3 loops
//      -> find (target - arr[i] - arr[j] - arr[k]) in hash set
//      -> use set to avoid duplicates

// vector<vector<int>> four_sum(vector<int> &arr, int target){
//     int n = arr.size();

//     set<vector<int>> ans;

//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             set<int> hashSet;
//             for(int k = j+1; k<n; k++){
//                 int sum = target - (arr[i] + arr[j] + arr[k]);
//                 if(hashSet.find(sum) != hashSet.end()){
//                     vector<int> temp = {arr[i],arr[j],arr[k],sum};
//                     sort(temp.begin(),temp.end());
//                     ans.insert(temp);
//                 }
//                 hashSet.insert(arr[k]);
//             }
//         }
//     }
//     vector<vector<int>> result(ans.begin(),ans.end());

//     return result;
// }




// 3. Optimal approach : 2 pointer

// LOGIC : sort, fix 2 elements, use 2 pointer for remaining 2
// ALGORITHM : 
//      -> sort the array
//      -> fix i and j 
//      -> reduce to 2-sum problem with 2 pointers (left,right)
//      -> skip duplicates at all levels (i,j, left, right)

vector<vector<int>> four_sum(vector<int> &arr, int target){
    int n = arr.size();

    vector<vector<int>> ans;

    sort(arr.begin(),arr.end());

    for(int i=0; i<n; i++){
        if(i != 0 && arr[i] == arr[i-1]) continue;
        for(int j=i+1; j<n; j++){
            if(j != i+1 && arr[j] == arr[j-1]) continue;

            int left = j+1;
            int right = n-1;
            while(left < right){
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[left];
                sum += arr[right];

                if(sum > target) right--;
                else if(sum < target) left++;
                else{
                    ans.push_back({arr[i],arr[j],arr[left],arr[right]});
                    left++, right--;

                    while(left < right && arr[left] == arr[left-1]) left++;
                    while(left < right && arr[right] == arr[right+1]) right--;
                }
            }
        }
    }
    return ans;
}


int main(){
    vector<int> arr = {1,0,-1,0,-2,2};
    int target = 0;

    vector<vector<int>> ans = four_sum(arr,target);

    for(auto row : ans){
        for(int val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}