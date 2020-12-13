//
// Created by HaigCode
//

class Solution {
public:
    static vector<long> vec;
    static priority_queue<long, vector<long>, greater<long>> q;
    static long cur;
    int nthUglyNumber(int n) {  //小顶堆法
        while(vec.size() < n){
            cur = vec.back();
            q.push(2 * cur);
            q.push(3 * cur);
            q.push(5 * cur);
            while(q.top() == cur){   //去重复
                q.pop();
            }
            vec.push_back(q.top());
            q.pop();
        }
        return vec[n - 1];
    }
};
vector<long> Solution::vec = {1};
priority_queue<long, vector<long>, greater<long>> Solution::q;
long Solution::cur;