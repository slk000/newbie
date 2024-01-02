#include <climits>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
/*
1 3 1
1 5 1
4 2 1
*/
/*
1 4 5 
2 7 6 
6 8 7 
 */
class Solution {
public:
    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     vector<vector<int>> dp(m, vector<int>(n,0));
    //     dp[0][0] = grid[0][0];
    //     for (int i = 1; i < n; i++) {
    //         dp[0][i] = dp[0][i-1] + grid[0][i];
    //     }
    //     for (int i = 1; i < m; i++) {
    //         dp[i][0] = dp[i-1][0] + grid[i][0];
    //     }

    //     for (int i = 1; i < m; i++) {
    //         for (int j = 1; j < n; j++) {
    //             dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
    //         }
    //     }

    //     for (auto v : dp) {
    //         for (int val : v) {
    //             cout << val << " ";
    //         }
    //         cout << endl;
    //     }
    //     return dp[m-1][n-1];


    // }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // vector<int> dp(n);
        int a = 0, b = 0; // dp[j-1], dp[j]
        for (int i = 0; i < m; i++) {
            
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    // dp[j] = grid[0][0];
                    b = grid[0][0];
                }
                else if (i == 0) {
                    // dp[j] = dp[j-1] + grid[i][j];
                    b = a + grid[i][j];
                }
                else if (j == 0) {
                    // dp[j] = dp[j] + grid[i][j];
                    b = b + grid[i][j];
                }
                else {
                    // dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
                    b = min(a, b) + grid[i][j];
                }
                cout << a << " " << b << endl;
                a = b;
            }
            a = 0;
        }
        return b;


    }

};

int main() {
    vector<vector<int>> grid= {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    cout << Solution().minPathSum(grid) << endl;

}
