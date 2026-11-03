class Solution {
    private:
    void dfs(unordered_map<int,vector<int>>& adj,vector<vector<bool>>& visited,int r,int c,int m,int n,vector<vector<char>>& grid){
        visited[r][c]=true;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
       for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && visited[nrow][ncol]!=1 && grid[nrow][ncol]=='1'){
                dfs(adj,visited,nrow,ncol,m,n,grid);
        }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
        }
        vector<vector<bool>>visited(m,vector<bool>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            if(visited[i][j]==0 && grid[i][j]=='1'){
                visited[i][j]=1;
                ans++;
        dfs(adj,visited,i,j,m,n,grid);
            }
            }
        }
            return ans;
    }
};