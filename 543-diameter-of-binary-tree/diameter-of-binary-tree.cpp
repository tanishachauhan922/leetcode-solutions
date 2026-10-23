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
    int solve(TreeNode* root, int& maxi,int curr){
       if(root==NULL) return 0 ;
    int lefty= solve(root->left,maxi,curr);
     int righty=solve(root->right,maxi,curr);
     maxi=max(maxi,lefty+righty);
     return 1+max(lefty,righty);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int maxi=0;
        solve(root,maxi,0);
      return maxi;
    }
};