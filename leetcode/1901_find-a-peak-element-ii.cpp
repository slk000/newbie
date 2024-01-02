#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        // 以行号i进行二分
        int l = 0, r = m-1;
        int mid = 0;

        int idx = -1;

        while (l < r) {
            mid = (r-l)/2 + l;
            cout << "l: " << l << " mid: " << mid << " r: " << r << endl;
            // 查找第mid行的最大值maxVal和下标idx
            int maxVal = mat[mid][0];
            idx = 0;
            for (int j = 1; j < n; j++) {
                if (mat[mid][j] > maxVal) {
                    maxVal = mat[mid][j];
                    idx = j;
                }
            }

            // 检查mat[mid][idx]的下面的元素，如果下面的更大，说明峰值在下面一行某个地方（类似于一维问题里的尽量往高处走）
            if (mat[mid][idx] < mat[mid+1][idx]) {
                l = mid+1;
            }
            else {
                r = mid;
            }
            
        }
        return {l, idx};
    }
};

int main() {
    vector<vector<int>> mat{{7,2,3,1,2},{6,5,4,2,1}};
    auto res = Solution().findPeakGrid(mat);
}
