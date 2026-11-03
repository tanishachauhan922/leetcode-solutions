class Solution {
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int r,int c,int m,int n){
        visited[r][c]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int newr=r+delrow[i];
            int newc=c+delcol[i];
            if(newr>=0 && newc>=0 && newr<m && newc<n && grid[newr][newc]==1 && visited[newr][newc]==0){
                dfs(grid,visited,newr,newc,m,n);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
    vector<vector<int>>visited(m,vector<int>(n,0));
    //first and last row
    for(int j=0;j<n;j++){
        if(visited[0][j]==0 && grid[0][j]==1)dfs(grid,visited,0,j,m,n);
        if(visited[m-1][j]==0 && grid[m-1][j]==1)dfs(grid,visited,m-1,j,m,n);
    }
      //first and last col
    for(int i=0;i<m;i++){
        if(visited[i][0]==0 && grid[i][0]==1)dfs(grid,visited,i,0,m,n);
        if(visited[i][n-1]==0 && grid[i][n-1]==1)dfs(grid,visited,i,n-1,m,n);
    }
    int ans=0;
    for(int i=0;i<m;i++){
        if(i==0 || i==m-1)continue;
        for(int j=0;j<n;j++){
            if(j==0 || j==n-1) continue;
            if(visited[i][j]==0 && grid[i][j]==1)ans++;
        }
    }
    return ans;
    }
};