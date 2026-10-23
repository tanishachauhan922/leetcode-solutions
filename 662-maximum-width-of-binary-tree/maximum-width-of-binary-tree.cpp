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
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,int>>q;
        long long ans=0;
        q.push({root,0});
       //q.push({NULL,0});
       long long st=0,e=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* front=q.front().first;
                long long indx=q.front().second;
                q.pop();
                if(i==0) st=indx;
                if(i==n-1) e=indx;
                if(front->left)q.push({front->left,2*(long long)indx+1});
                if(front->right)q.push({front->right,2*(long long)indx+2});
            }
            ans=max(ans,(long long)e-st+1);
                
        }
return ans;
    }
};