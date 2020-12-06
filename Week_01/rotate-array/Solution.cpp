//
// Created by HaigCode.
//

class Solution {
public:
    // 三次旋转
    void rotate(vector<int>& nums, int k) {
        //1.整体旋转
        reverse(nums.begin(),nums.end());
        //2.0-k旋转
        reverse(nums.begin(),nums.begin()+k%nums.size());
        //3.k-nums.size()旋转
        reverse(nums.begin()+k%nums.size(),nums.end());

    }
};

class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        int N = nums.size();
        k = k % N;
        for (int i = 0; i < k; i++) {
            auto back = nums.back(); //返回List最后一个元素
            nums.pop_back();//删除最后一个元素
            nums.insert(nums.begin(), back);//在list头部插入最后一个元素
        }
    }
};

