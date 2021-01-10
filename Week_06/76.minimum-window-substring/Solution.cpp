//
// Created by HaigCode..
//
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> worker(128, 0);
        for (char &c : t) ++worker[c];
        int l = 0, r = 0, n = t.size(), len = INT_MAX, start = 0;
        while (r < s.size()) {
            if (worker[s[r++]]-- > 0) --n; // 非t类字母永远 >= 0
            while (!n) {
                if (r - l < len) len = r - (start = l);
                if (++worker[s[l++]] > 0) ++n; // t类字母永远 <= 0
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
