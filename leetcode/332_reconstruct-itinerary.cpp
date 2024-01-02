#include <bits/stdc++.h>
using namespace std;
// 找到一个从start可以到的目的地，需要全部存下来，然后排序。优先尝试字典序小的，然后再尝试其他的城市。不能只选择一个最小的城市，例如[["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]，最小的那个可能走不通

class Solution {
public:
    vector<string> path;
    vector<string> res;
    using Destination = pair<string, int>; // 目的地名称，到此地的机票下标
    unordered_map<string, vector<Destination>> from; // 从key能到哪。由于想要对目的地排序，用vector存起然后排序
    void dfs(vector<vector<string>> &tickets, string start, vector<bool> used) {
        for (string p : path) {
            cout << p << "->" ;
        }
        cout << endl;
        if (res.size() != 0) return;  // 剪枝，尽快结束dfs
        if (path.size() == tickets.size()) {
            if (res.size() == 0) res = path;
            return;
        }
        
        vector<Destination> &to = from[start];

        for (Destination d : to) {
            if (used[d.second]) continue;
            used[d.second] = true;
            path.push_back(d.first);
            dfs(tickets, d.first, used);
            path.pop_back();
            used[d.second] = false;
        }
/*
        vector<pair<string,int>> next; //<目的地next,对应ticket的下标> 


        if (next.size() == 0 && path.size() == tickets.size() && res.size() == 0) { // 用完了所有机票&&走完了所有地方&&是第一个路线（最小）（dfs过程中"JFK"不包含在path中，所以两个size相等）
            res = path;
            return;
        }

        for (auto p : next) {
            used[p.second] = true;
            path.push_back(p.first);
            dfs(tickets,p.first, used);
            path.pop_back();
            used[p.second] = false;

        }
        */
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 将机票信息加入map
        for (int i = 0; i < tickets.size(); i++) {
            vector<string> &ticket = tickets[i];
            from[ticket[0]].push_back(make_pair(ticket[1], i));
        }
        // 将目的地排序
        for (auto it = from.begin(); it != from.end(); it++) {
            sort(it->second.begin(), it->second.end());
        }

        vector<bool> used(tickets.size());
        dfs(tickets, "JFK", used);
        res.insert(res.begin(), "JFK");
        return res;
    }
};
int main() {
   // vector<vector<string>> tickets{{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    //vector<vector<string>> tickets{{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    //vector<vector<string>> tickets{{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    //vector<vector<string>> tickets{{"AXA","EZE"},{"EZE","AUA"},{"ADL","JFK"},{"ADL","TIA"},{"AUA","AXA"},{"EZE","TIA"},{"EZE","TIA"},{"AXA","EZE"},{"EZE","ADL"},{"ANU","EZE"},{"TIA","EZE"},{"JFK","ADL"},{"AUA","JFK"},{"JFK","EZE"},{"EZE","ANU"},{"ADL","AUA"},{"ANU","AXA"},{"AXA","ADL"},{"AUA","JFK"},{"EZE","ADL"},{"ANU","TIA"},{"AUA","JFK"},{"TIA","JFK"},{"EZE","AUA"},{"AXA","EZE"},{"AUA","ANU"},{"ADL","AXA"},{"EZE","ADL"},{"AUA","ANU"},{"AXA","EZE"},{"TIA","AUA"},{"AXA","EZE"},{"AUA","SYD"},{"ADL","JFK"},{"EZE","AUA"},{"ADL","ANU"},{"AUA","TIA"},{"ADL","EZE"},{"TIA","JFK"},{"AXA","ANU"},{"JFK","AXA"},{"JFK","ADL"},{"ADL","EZE"},{"AXA","TIA"},{"JFK","AUA"},{"ADL","EZE"},{"JFK","ADL"},{"ADL","AXA"},{"TIA","AUA"},{"AXA","JFK"},{"ADL","AUA"},{"TIA","JFK"},{"JFK","ADL"},{"JFK","ADL"},{"ANU","AXA"},{"TIA","AXA"},{"EZE","JFK"},{"EZE","AXA"},{"ADL","TIA"},{"JFK","AUA"},{"TIA","EZE"},{"EZE","ADL"},{"JFK","ANU"},{"TIA","AUA"},{"EZE","ADL"},{"ADL","JFK"},{"ANU","AXA"},{"AUA","AXA"},{"ANU","EZE"},{"ADL","AXA"},{"ANU","AXA"},{"TIA","ADL"},{"JFK","ADL"},{"JFK","TIA"},{"AUA","ADL"},{"AUA","TIA"},{"TIA","JFK"},{"EZE","JFK"},{"AUA","ADL"},{"ADL","AUA"},{"EZE","ANU"},{"ADL","ANU"},{"AUA","AXA"},{"AXA","TIA"},{"AXA","TIA"},{"ADL","AXA"},{"EZE","AXA"},{"AXA","JFK"},{"JFK","AUA"},{"ANU","ADL"},{"AXA","TIA"},{"ANU","AUA"},{"JFK","EZE"},{"AXA","ADL"},{"TIA","EZE"},{"JFK","AXA"},{"AXA","ADL"},{"EZE","AUA"},{"AXA","ANU"},{"ADL","EZE"},{"AUA","EZE"}};
    vector<vector<string>> tickets{{"JFK","SFO"},{"JFK","ATL"},{"SFO","JFK"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"},{"ATL","AAA"},{"AAA","BBB"},{"BBB","ATL"}};
    auto res = Solution().findItinerary(tickets);
    for (string s : res) {
        cout << s << " -> ";
    }
    cout << endl;
}
