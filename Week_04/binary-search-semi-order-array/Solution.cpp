//
// Created by HaigCode..
//
//假定为升序排列且无重复元素，这个问题其实和LeetCode 153题（寻找旋转排序数组中的最小值）类似
//找出最小元素所在下标，若下标不为0（即非有序数组），则该下标往后直至数组末尾都是无序
class Solution {
public:
    int findMin(vector<int>& nums) {//找最小元素下标
        int low = 0;
        int high = nums.size() - 1;
        int min_num = nums[low];
        int min_index = low;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] > nums[low]) {//左半部分有序
                if (min_num < nums[low]) {
                    min_index = low;
                    min_num = nums[low];
                }
                low = mid + 1;
            }
            else if (nums[mid] < nums[low]){//右半部分有序
                if (min_num < nums[mid]) {
                    min_index = mid;
                    min_num = nums[mid];
                }
                high = mid - 1;
            }
            else {//此时，只剩nums[low]和nums[high]未比较
                if (min_num < nums[low]) {
                    min_index = low;
                    min_num = nums[low];
                }
                if (min_num < nums[high]) {
                    min_index = high;
                    min_num = nums[high];
                }
                break;
            }
        }
        return min_index;
    }
};

