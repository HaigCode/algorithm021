//
// Created by HaigCode.
//
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = static_cast<int>(digits.size());
        for(int i=length-1; i>=0; --i){
            digits[i] += 1;
            int left = digits[i] % 10;
            if(left != 0){
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};
