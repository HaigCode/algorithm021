//
// Created by HaigCode.
//
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int len=p.size(),slen=s.size();
        if(slen<len)    return res;
        string key(26,0),tmp(26,0);
        for(int i=0;i<len;i++){
            key[p[i]-'a']++;
            tmp[s[i]-'a']++;
        }
        if(tmp==key)
            res.push_back(0);
        for(int i=0;i+len<slen;i++){
            tmp[s[i]-'a']--;
            tmp[s[i+len]-'a']++;
            if(tmp==key)
                res.push_back(i+1);
        }
        return res;
    }
};
