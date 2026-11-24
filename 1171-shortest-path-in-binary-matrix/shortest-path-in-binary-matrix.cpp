class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1)return -1;
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>visited(n,vector<int>(n,0));
        q.push({1,{0,0}});
        visited[0][0]=1;
        while(!q.empty()){
            int d=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            if(r==n-1 && c==n-1) return d;
            
            int rows[]={-1,0,1,0,-1,-1,1,1};
            int cols[]={0,1,0,-1,-1,1,1,-1};
            for(int i=0;i<8;i++){
                int newr=r+rows[i];
                int newc=c+cols[i];
             if(newr<n && newc<n && newr>=0 && newc>=0 && visited[newr][newc]!=1 && grid[newr][newc]==0){
                q.push({d+1,{newr,newc}});
                visited[newr][newc]=1;
             }
            }
        }
        return -1;
    }
};