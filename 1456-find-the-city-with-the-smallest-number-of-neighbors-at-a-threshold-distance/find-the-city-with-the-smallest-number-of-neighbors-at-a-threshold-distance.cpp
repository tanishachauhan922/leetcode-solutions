class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
         dist[u][v]=w;
         dist[v][u]=w;
        }
       for(int via=0;via<n;via++){
        for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
              if(dist[i][via]!=1e9 && dist[via][j]!=1e9 && dist[i][j] > dist[i][via]+dist[via][j]){
                dist[i][j]=dist[i][via]+dist[via][j];
              }
          }
        }
        }
        for(int i=0; i<n; i++){
    dist[i][i] = 0;
}
        //evaluating ans
        int ans=-1;
        int maxi=INT_MAX;
         for(int i=0;i<n;i++){
            int cnt=0;
          for(int j=0;j<n;j++){
          if(dist[i][j]<=distanceThreshold){
            cnt++;
          }
          }
          if(cnt<maxi){
            maxi=cnt;
            ans=i;
          }
          if(cnt==maxi){
            ans=max(ans,i);
          }
         }
         return ans;
    }
};