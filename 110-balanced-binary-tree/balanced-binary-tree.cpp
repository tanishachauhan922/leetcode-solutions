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
    pair<bool,int>solve(TreeNode* root){
        if(root==NULL) return {true,0};
        pair<bool,int>lefty=solve(root->left);
        pair<bool,int>righty=solve(root->right);
        if(lefty.first==false || righty.first==false) return {false,0};
        if(abs(lefty.second - righty.second)>1) return {false,0};
        return {true,max(lefty.second,righty.second)+1};
        
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
       pair<bool,int>ans= solve(root);
       if(ans.first ==false) return false;
       return true;
    }
};