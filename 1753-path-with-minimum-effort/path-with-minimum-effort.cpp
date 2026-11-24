class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
    vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
    //priority_queue<int,vector<int>,greater<int>>pq;
    //vector<vector<int>visited(n,vector<int>(m,0));
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({0,{0,0}});
    dist[0][0]=0;
    while(!pq.empty()){
        int d=pq.top().first;
        int r=pq.top().second.first;
        int c=pq.top().second.second;
        pq.pop();
        if(r==n-1 && c==m-1){
            return d;
        }
        if(d>dist[r][c])continue;
        int rows[]={-1,0,1,0};
        int cols[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int newr=r+rows[i];
            int newc=c+cols[i];
            if(newr>=0 && newc>=0 && newr<n && newc<m ){
                int d2=heights[newr][newc];
                int d1=heights[r][c];
                int temp=abs(d1-d2);  
                int neweffort=max(d,temp);         
                if(neweffort<dist[newr][newc]){
    
                         pq.push({neweffort,{newr,newc}});
                          dist[newr][newc]=neweffort;
                    }
                    
                }
            
        }

    }
    return dist[n-1][m-1];
    }
};