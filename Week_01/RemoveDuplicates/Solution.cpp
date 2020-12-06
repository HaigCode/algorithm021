//
// Created by HaigCode.
//
class Solution {
public:
    //快慢指针
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int left = 0, right = 1;
        while(right < nums.size()){
            if(nums[right] != nums[left]){
                left ++;
                nums[left] = nums[right];
            }
            right ++;
        }
        return left + 1;
    }
};
