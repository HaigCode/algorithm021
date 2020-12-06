//
// Created by HaigCode.
//
class Solution {
public:
    //hash法
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashtable;
        for(int i=0; i<nums.size(); ++i){
            auto iter = hashtable.find(target-nums[i]);
            if(iter != hashtable.end()){
                return {iter->second,i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};
