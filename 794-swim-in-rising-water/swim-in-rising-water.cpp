class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>visited(n,vector<int>(n,0));
        visited[0][0]=1;
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()){
            int t=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==n-1 && c==n-1) return t;
            int rows[]={-1,0,1,0};
            int cols[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int newr=r+rows[i];
                int newc=c+cols[i];
             if(newr>=0 && newc>=0 && newr<n && newc<n && visited[newr][newc]==0){
                visited[newr][newc]=1;
                if(grid[newr][newc]<=t) pq.push({t,{newr,newc}});
                else pq.push({grid[newr][newc],{newr,newc}});
             }
            }
        }
        return -1;
    }
};