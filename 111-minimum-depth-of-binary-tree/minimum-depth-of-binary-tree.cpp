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
    void solve(TreeNode* root,int h,int& ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) {
            ans=min(ans,h+1);
            return;
        }
        solve(root->left,h+1,ans);
        solve(root->right,h+1,ans);
    }
public:
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int h=0;
        int ans=INT_MAX;
        solve(root,h,ans);
        return ans;
    }
};