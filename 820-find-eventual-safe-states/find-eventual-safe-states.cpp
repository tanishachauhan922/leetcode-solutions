class Solution {
    private:
    bool dfs(vector<vector<int>>& graph,vector<int>& visited,vector<int>& dfsvisited,int node,int n,vector<int>& ans){
        visited[node]=1;
        dfsvisited[node]=1;
        bool s=true;
        for( auto i : graph[node]){
            if(visited[i]==0){
                if( dfs(graph,visited,dfsvisited,i,n,ans)==false) return false;
            }
            else if(dfsvisited[i]==1) {
                return false;
            }
    
        }
        ans.push_back(node);
        dfsvisited[node]=0;
        return true ;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int n=graph.size();
        vector<int>visited(n,0);
        vector<int>dfsvisited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(graph,visited,dfsvisited,i,n,ans);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};