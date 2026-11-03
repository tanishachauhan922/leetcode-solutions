class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
         vector<vector<int>>visited(m,vector<int>(n,0));
         queue<pair<int,pair<int,int>>>q;
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    visited[i][j]=1;
                }
            }
         }
         //ans
          int t=0;
         while(!q.empty()){
             t=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
             int delrow[]={-1,0,1,0};
             int delcol[]={0,1,0,-1};
             for(int i=0;i<4;i++){
              int newr=r+delrow[i];
              int newc=c+delcol[i];
              if(newr>=0 && newc>=0 && newr<m && newc<n && grid[newr][newc]==1 && visited[newr][newc]==0){
                grid[newr][newc]=2;
                visited[newr][newc]=1;
                q.push({t+1,{newr,newc}});
              }
             }
         }
         int freshcnt=0;
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    freshcnt++;
                    break;
                }
            }
         }
        if(freshcnt>0) return -1;
         return t;
    }
};