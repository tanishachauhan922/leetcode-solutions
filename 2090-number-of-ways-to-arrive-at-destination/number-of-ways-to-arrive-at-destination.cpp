class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>mp(n);
        int mod=1e9+7;
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int d=roads[i][2];
            mp[u].push_back({v,d});
            mp[v].push_back({u,d});
        }
        vector<long long>dist(n,LLONG_MAX);
        vector<int>ways(n,0);
        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>,greater<pair<long long,pair<int,int>>>>q;
        q.push({0,{0,0}});
        while(!q.empty()){
            long long d=q.top().first;
            int node=q.top().second.first;
            int w=q.top().second.second;
            q.pop();
            if (d > dist[node]) continue; 
            for(auto it : mp[node]){
                int ngh=it.first;
                int dplus=it.second;
                if(d+dplus<dist[ngh]){
                    ways[ngh] = ways[node];
                    int newways=ways[ngh];
                    dist[ngh]=d+dplus;
                    q.push({d+dplus,{ngh,newways%mod}});
                }
                else if (d + dplus== dist[ngh]) {     // equal: add ways, do NOT push
            ways[ngh] = (ways[ngh] + ways[node]) % mod;
        }
                }
            }
        
        return ways[n-1];
    }
};