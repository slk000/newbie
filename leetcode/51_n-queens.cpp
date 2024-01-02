#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    int n;
    vector<bool> doRowHasQ, doColHasQ; // 记录第i行上是否有皇后，第j列上是否有皇后
    bool hasQ(int i, int j) { // 检查(i,j)位置横纵斜向上是否有皇后
        if (doColHasQ[j] || doRowHasQ[i]) return true;
        int ii = i, jj = j;
        // 往左上
        while (ii >= 0 && jj >= 0) {
            if (path[ii][jj] == 'Q') return true;
            ii--; jj--;
        }
        // 往右下
        ii = i, jj = j;
        while (ii < n && jj < n) {
            if (path[ii][jj] == 'Q') return true;
            ii++; jj++;
        }
        // 往右上
        ii = i, jj = j;
        while (ii >= 0 && jj < n) {
            if (path[ii][jj] == 'Q') return true;
            ii--; jj++;
        }
        // 往左下
        ii = i, jj = j;
        while (ii < n && jj >= 0) {
            if (path[ii][jj] == 'Q') return true;
            ii++; jj--;
        }
        return false;
    }
    void dfs(int start, int leftQ) { // 从第几行开始放。还剩下几个Q要放
        if (leftQ == 0) {
            res.emplace_back(path);
            return;
        }
        // 在第start行，横向遍历各列
        for (int j = 0; j < n; j++) {
            if (hasQ(start, j)) continue;
            doColHasQ[j] = true;
            doRowHasQ[start] = true;
            path[start][j] = 'Q';
            dfs(start+1, leftQ-1);
            path[start][j] = '.';
            doColHasQ[j] = false;
            doRowHasQ[start] = false;
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        path.resize(n, string(n,'.'));
        doColHasQ.resize(n, false);
        doRowHasQ.resize(n, false);
        this->n = n;
        dfs(0, n);
        return res;
    }
};
int main() {
    auto res = Solution().solveNQueens(4);
    for (auto v : res) {
        for (string s : v) {
            cout << s << "\t";
        }
        cout << endl;
    }
}
