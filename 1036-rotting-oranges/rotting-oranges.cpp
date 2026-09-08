class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0 && grid[i][j]==2){
                    visited[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        vector<int>rows={-1,0,1,0};
        vector<int>cols={0,1,0,-1};
        int ans=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            
             ans=max(ans,t);
             for(int i=0;i<4;i++){
                int newr=rows[i]+r;
                int newc=cols[i]+c;
                if(newr>=0 && newc>=0 && newr<m && newc<n && visited[newr][newc]==0 && grid[newr][newc]!=0 ){
                    visited[newr][newc]=1;
                    grid[newr][newc]=2;
                    q.push({{newr,newc},t+1});
                }
             }
        }
        //final check
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                     return -1;
                }
            }
        }
        return ans;
    }
};