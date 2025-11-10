// given an array, find elements that appears more than n/3 times
// if no such element exists, return empty vector

#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;


// 1. Brute force approach (TC : O(N*N)    SC : O(1))

// for each element , count freq by scanning the array
// Outer loop -> Pick element
// Inner loop -> Count occurences 
// If count > n/3 and element NOT IN RESULT, add to answer


// vector<int> majority_element(vector<int> &arr){
//     int n = arr.size();

//     vector<int> ans;
//     for(int i=0; i<n; i++){
//         int count = 0;
//         if(ans.size() == 0 || ans[0] != arr[i]){
//             for(int j=0; j<n; j++){
//                 if(arr[i] == arr[j]){
//                 count++;
//                 }
//             }
//         }
        
//         if(count > n/3){
//             ans.push_back(arr[i]);
//         }

//         if(ans.size() == 2){
//             break;
//         }
//     }
//     return ans;
// }




// 2. Better approach (Hash map) (TC : O(N)    SC : O(N))

// store all elments and their freq in map
// collect elements with freq > n/3

// vector<int> majority_element(vector<int> &arr){
//     int n = arr.size();

//     vector<int> ans;

//     unordered_map<int,int> freq;
//     int count = 0;
//     for(int i=0; i<n; i++){
//         freq[arr[i]]++;
//     }

//     for(auto val : freq){
//         if(val.second > n/3){
//             ans.push_back(val.first);
//         }
//     }

//     return ans;
// }




// 3. Optmial approach (Boyer–Moore Majority Vote Extension)

// LOGIC : At most 2 majority element -> track 2 candidates + count
// ALGORITHM : 
// First pass -> cancels out count, maintain 2 candidates
// Second pass -> verify actual freq (as there can be 0,1, and 2 majority elements)

// TC : O(2*N)    SC : O(1)

vector<int> majority_element(vector<int> &arr){
    int n = arr.size();

    vector<int> ans;
    int count1 = 0, count2 = 0;
    int ele1 = INT_MIN, ele2 = INT_MIN;

    for(int i=0; i<n; i++){
        if(count1 == 0 && arr[i] != ele2){
            ele1 = arr[i];
            count1++;
        }
        else if(count2 == 0 && arr[i] != ele1){
            ele2 = arr[i];
            count2++;
        }
        else if(arr[i] == ele1){
            count1++;
        }
        else if(arr[i] == ele2){
            count2++;
        }
        else{
            count1--, count2--;
        }
    }

    // Manual checking whether ele1 and ele2 are majority element

    count1 = 0 , count2 = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == ele1){
            count1++;
        }
        if(arr[i] == ele2){
            count2++;
        }
    }

    if(count1 > n/3){
        ans.push_back(ele1);
    }
    if(count2 > n/3){
        ans.push_back(ele2);
    }

    return ans;
}



int main(){
    vector<int> arr = {2,2,1,3};

    vector<int> ans = majority_element(arr);

    for(int val : ans){
        cout << val << " ";
    }

    return 0;
}