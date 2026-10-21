/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    void solve(TreeNode* root,map<int,map<int,multiset<int>>> & mp,int r,int c){
        if(root==NULL) return;
       mp[c][r].insert(root->val);
       solve(root->left,mp,r+1,c-1);
       solve(root->right,mp,r+1,c+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        map<int,map<int,multiset<int>>>mp;
        int r=0,c=0;
        solve(root,mp,r,c);
        for(auto i : mp){
           // int size=i.first.size();
            vector<int>cols;
            for(auto row : i.second){
                 for(auto ele : row.second){
                    cols.push_back(ele);
                 }
            }
            ans.push_back(cols);
        }
        return ans;
    }
};