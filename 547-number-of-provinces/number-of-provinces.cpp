class Solution {
    private:
    void dfs(int node,unordered_map<int,vector<int>>& adj,vector<int>& visited){
      visited[node]=1;
      for(auto ngh : adj[node]){
        if(visited[ngh]==0)dfs(ngh,adj,visited);
      }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[j].push_back(i);
                    adj[i].push_back(j);
                }
            }
        }
        int cnt=0;
        vector<int>visited(n,0);
        //call dfs
        for( int i=0;i<n;i++){
            if(visited[i]==0){
                cnt++;
                dfs(i,adj,visited);
            }
        }
        return cnt;
    }
};