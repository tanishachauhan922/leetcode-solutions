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
    void solve(TreeNode* root,int &maxi,int height){
        if(root==NULL){
            maxi=max(maxi,height);
            return ;
          }
        solve(root->left,maxi,height+1);
        solve(root->right,maxi,height+1);
        
    }
public:
    int maxDepth(TreeNode* root) {
        int maxi=0;
        int height=0;
        if(root==NULL) return maxi;
        solve(root,maxi,height);
        return maxi;
    }
};