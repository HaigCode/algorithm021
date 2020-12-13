//
// Created by HaigCode..
//

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(Node* root) {
        if(root != NULL){
            helper(root,0);
        }
        return res;
    }
    void helper(Node* root,int level){
        if(res.size() <= level){
            res.push_back({});
        }
        res[level].push_back(root->val);
        for(auto node : root->children){
            helper(node,level+1);
        }
    }
};

