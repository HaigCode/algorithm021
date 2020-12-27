//
// Created by HaigCode.
//
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return -1;
        if(nums.size() == 1) return nums[0];
        int p1 = 0, p2 = nums.size() - 1;
        int mid = p1; // 假如旋转了数组的前面0个元素（也就是没有旋转），我们直接返回numbers[p1]
        while(nums[p1] > nums[p2])
        {
            if(p2 - p1 == 1)
            {
                // 循环终止条件：当p2-p1=1时，p2所指元素为最小值
                mid = p2;
                break;
            }
            mid = (p1 + p2) / 2;
            if(nums[mid] > nums[p1]) p1 = mid;
            else p2 = mid;
        }
        return nums[mid];
    }
};

