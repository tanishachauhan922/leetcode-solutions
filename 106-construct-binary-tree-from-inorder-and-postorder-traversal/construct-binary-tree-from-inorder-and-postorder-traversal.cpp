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
     TreeNode* solve(vector<int>& postorder, vector<int>& inorder,int& i,int inst,int inend,unordered_map<int,int>& mp){
      if(i<0) return NULL;
      if(inst>inend) return NULL;
      int rootval=postorder[i--];
      int indx=mp[rootval];
      TreeNode* root=new TreeNode(rootval);
      root->right=solve(postorder,inorder,i,indx+1,inend,mp);
      root->left=solve(postorder,inorder,i,inst,indx-1,mp);
      return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size()!=inorder.size()) return NULL;
        int i=postorder.size()-1;
        int inst=0,inend=inorder.size()-1;
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)  mp[inorder[i]]=i;
        return solve(postorder,inorder,i,inst,inend,mp );
    }
};