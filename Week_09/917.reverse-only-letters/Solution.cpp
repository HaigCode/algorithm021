//
// Created by HaigCode.
//
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int begin = 0,end=S.length()-1;
        while(begin<end)
        {
            if(!isalpha(S[begin]))
                begin++;
            if(!isalpha(S[end]))
                end--;
            if(isalpha(S[begin])&&isalpha(S[end]))
                swap(S[begin++],S[end--]);
        }
        return S;
    }
};
