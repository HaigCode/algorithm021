//
// Created by HaigCode.
//

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty() || nums.size() == 0) return;
        int index = 0;
        //遍历，非零元素前移
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0) nums[index++] = nums[i];
        }
        //后面补零
        while(index < nums.size()){
            nums[index++] = 0;
        }

    }
};

