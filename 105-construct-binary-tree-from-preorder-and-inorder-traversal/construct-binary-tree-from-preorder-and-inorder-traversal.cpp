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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int& i,int inst,int inend,unordered_map<int,int>& mp){
      if(i>=preorder.size()) return NULL;
      if(inst>inend) return NULL;
      int rootval=preorder[i++];
      int indx=mp[rootval];
      TreeNode* root=new TreeNode(rootval);
      root->left=solve(preorder,inorder,i,inst,indx-1,mp);
      root->right=solve(preorder,inorder,i,indx+1,inend,mp);
      return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()!=inorder.size()) return NULL;
        int i=0;
        int inst=0,inend=inorder.size()-1;
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)  mp[inorder[i]]=i;
        return solve(preorder,inorder,i,inst,inend,mp );
    }
};