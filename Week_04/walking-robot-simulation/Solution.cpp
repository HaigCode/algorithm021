//
// Created by HaigCode.
//
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        int ans = 0;
        unordered_map<int, unordered_set<int>> ob;
        for (auto& p : obstacles)
        {
            ob[p[0]].insert(p[1]);
        }

        vector<vector<int>> dd = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        int dir = 0;
        vector<int> pos = { 0,0 };

        for (auto& c : commands)
        {
            dir = (c == -2) ? (dir + 4 - 1) % 4 : dir;
            dir = (c == -1) ? (dir + 1) % 4 : dir;
            for (int i = 0; i < c; i++)
            {
                vector<int> next = { pos[0] + dd[dir][0], pos[1] + dd[dir][1] };
                if (ob[next[0]].count(next[1]) != 0) break;
                pos = next;
                ans = max(ans, pos[0] * pos[0] + pos[1] * pos[1]);
            }
        }

        return ans;
    }
};

