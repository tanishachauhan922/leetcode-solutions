class Solution {
    bool dfs(vector<vector<int>>& graph,vector<int>& visited,vector<int>& dfsvisited,int node, int n){
      visited[node]=1;
        dfsvisited[node]=1;
        for( auto i : graph[node]){
            if(visited[i]==0){
                if( dfs(graph,visited,dfsvisited,i,n)==false) return false;
            }
            else if(dfsvisited[i]==1) {
                return false;
            }
    
        }
        dfsvisited[node]=0;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>visited(n,0);
        vector<int>dfsvisited(n,0);
        vector<vector<int>>graph(n);
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);

        }
        for(int i=0;i<n;i++){
            if(visited[i]==0){
               bool ans= dfs(graph,visited,dfsvisited,i,n);
               if(ans==false) return false;
            }
        }
        return true;
    }
};