/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
    void mapping(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& mp,unordered_map<TreeNode*,int>& visited){
        if(root==NULL) return;
        visited[root]=0;
        if(root->left){
            mp[root->left]=root;
            mapping(root->left,mp,visited);
        }
         if(root->right){
            mp[root->right]=root;
            mapping(root->right,mp,visited);
        }
    }
        void solve(int d,TreeNode* target,int k,unordered_map<TreeNode*,TreeNode*>& mp,unordered_map<TreeNode*,int>& visited,vector<int>& ans){
            if(target==NULL) return;
            if(visited[target]==1)return;
            visited[target]=1;
            if(d==k){
                ans.push_back(target->val);
                return;
            }
           solve(d+1,target->left,k,mp,visited,ans);
           solve(d+1,target->right,k,mp,visited,ans);
          if(mp[target]->val!=-1) solve(d+1,mp[target],k,mp,visited,ans);
        }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            vector<int>ans;
            if(root==NULL) return ans;
            unordered_map<TreeNode*,TreeNode*>mp;
            mp[root]= new TreeNode(-1);
            //child->parent
            unordered_map<TreeNode*,int>visited;
            mapping(root,mp,visited);
            solve(0,target,k,mp,visited,ans);
    return ans;
    }
};