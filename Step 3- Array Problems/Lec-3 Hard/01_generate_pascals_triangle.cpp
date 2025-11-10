#include<iostream>
#include<vector>
#include<cstdlib> // for system("pause")
using namespace std;



// // 🔺 Pascal's Triangle — Dry Run Notes

// // ✅ Variation 1: Generate Full Triangle (n = 4)
// Input: n = 4

// Step-by-step triangle build:
// Row 0: [1]
// Row 1: [1, 1]
// Row 2: [1, 2, 1]       // 2 = 1 + 1
// Row 3: [1, 3, 3, 1]    // 3 = 1 + 2, 3 = 2 + 1

// Final triangle:
// [
//   [1],
//   [1, 1],
//   [1, 2, 1],
//   [1, 3, 3, 1]
// ]

// // ✅ Variation 2: Generate Specific Row (rowIndex = 4)
// Input: rowIndex = 4

// Step-by-step value generation using nCr:
// val = 1
// i = 1 → val = 1 * (4 / 1) = 4
// i = 2 → val = 4 * (3 / 2) = 6
// i = 3 → val = 6 * (2 / 3) = 4
// i = 4 → val = 4 * (1 / 4) = 1

// Final row: [1, 4, 6, 4, 1]

// // ✅ Variation 3: Get Specific Element (n = 5, r = 2)
// Input: n = 5, r = 2

// Step-by-step nCr calculation:
// res = 1
// i = 0 → res = 1 * (5 / 1) = 5
// i = 1 → res = 5 * (4 / 2) = 10

// Final result: C(5, 2) = 10


// 1st approach : Genreate full pascal's triangle

// TC : O(N*N)     SC : O(N*N)

// vector<vector<int>> generatePascal(int n){
//     cout << "Generating Pascal's Triangle for n = " << n << endl;
//     vector<vector<int>> triangle;

//     for(int i=0; i<n; i++){
//         vector<int> row(i+1,1);
//         for(int j=1; j<i; j++){
//             row[j] = triangle[i-1][j-1] + triangle[i-1][j];
//         }
//         triangle.push_back(row);
//     }
//     return triangle;
// }



// 2nd approach : Return nth row

// TC : O(N)     SC : O(N)

// vector<int> generatePascal(int n){
//     vector<int> ans;
//     long long val = 1;
//     ans.push_back(1);

//     for(int i=1; i<n; i++){
//         val = val * (n-i) / i;
//         ans.push_back(val);
//     }
//     return ans;
// }


// 3rd approach : Generate specific element C(n,r)

// TC: O(min(r,n-r))   SC : O(1)

int generatePascal(int n, int r){
    long long res = 1;

    n = n - 1;
    r = r - 1;

    for(int i=0; i<r; i++){
        res = res * (n-i)/(i+1);
    }
    return res;
}


int main(){
    int n = 5;
    int r = 3;

    // vector<vector<int>> ans  = generatePascal(n);

    // for(auto row : ans){
    //     for(int val : row){
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }


    // vector<int> ans = generatePascal(n);
    // for(int val : ans){
    //     cout << val << " ";
    // }
    // cout << endl;



    cout << generatePascal(n,r);

    return 0;
}
