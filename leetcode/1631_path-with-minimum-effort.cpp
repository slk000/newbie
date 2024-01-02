#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ii[4]{-1,1,0,0};
    int jj[4]{0,0,-1,1};
    bool check(vector<vector<int>> &m, bool vis[100][100], int limit) { // diff between two cell <= limit
        cout << sizeof(vis) << endl;
        memset(vis, 0, sizeof(vis));
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        vis[0][0] = true;
        while (!q.empty()) {
            pair<int,int> cur = q.front();
            if (cur.first == m.size()-1 && cur.second == m[0].size()-1) return true;
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nextI = cur.first + ii[d];
                int nextJ = cur.second + jj[d];
                if (nextI < 0 || nextJ < 0 || nextI >= m.size() || nextJ >= m[0].size() || vis[nextI][nextJ]) continue;
                if (abs(m[cur.first][cur.second] - m[nextI][nextJ]) > limit) continue;
                vis[nextI][nextJ] = true;
                q.push(make_pair(nextI, nextJ));
            }

        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        bool vis[100][100];
        return check(heights, vis, 2);
    }
};

int main() {
     vector<vector<int>> m{{1,2,3},{3,8,4},{5,3,5}};
   // vector<vector<int>> m{{1,2,2},{3,8,2},{5,3,5}};
    cout << Solution().minimumEffortPath(m) << endl;
}
