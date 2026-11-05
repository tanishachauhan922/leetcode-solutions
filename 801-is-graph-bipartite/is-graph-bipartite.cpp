class Solution {
    private:
    bool  bfs(int node,vector<vector<int>>& graph,vector<pair<int,bool>>& visited){
        queue<pair<int,int>>q;
        q.push({node,0});
        visited[node].first=1;
        visited[node].second=0;
        while(!q.empty()){
            int top=q.front().first;
            int color=q.front().second;
            q.pop();
            for(auto i : graph[top]){
                if(visited[i].first==0){
                    visited[i].first=1;
                    visited[i].second=!color;
                    q.push({i,!color});
                }
                else{
                   if(visited[i].second==color) return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<pair<int,bool>>visited(n);
    for(int i=0;i<n;i++){
        if(visited[i].first==0){
           bool ans= bfs(i,graph,visited);
         if(ans==false) return false;
        }
    }
    return true;
    }
};