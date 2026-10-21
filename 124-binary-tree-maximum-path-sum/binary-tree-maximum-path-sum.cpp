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
    int solve(TreeNode* root,int & maxi){
        if(root==NULL) return 0;
       int lefty= solve(root->left,maxi);
       int righty= solve(root->right,maxi);
       maxi=max(maxi,max(root->val,root->val+lefty+righty));
       maxi=max(maxi,max(root->val+lefty,root->val+righty));
       return max(root->val,max(root->val+lefty,root->val+righty));
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int maxi=INT_MIN;
        solve(root,maxi);
        return maxi; 
    }
};