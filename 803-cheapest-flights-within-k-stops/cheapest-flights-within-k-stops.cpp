class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int d=flights[i][2];
            adj[u].push_back({v,d});
        }
        //priority_queue<int,vector<int>,graeter<int>>pq;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        pq.push({0,{0,src}});
        while(!pq.empty()){
            int steps=pq.top().first;
            int cost=pq.top().second.first;
            int node=pq.top().second.second;
            pq.pop();
            if(steps>k) continue;
            for(auto ngh : adj[node]){
                int v=ngh.first;
                int tempcost=ngh.second;
                if(cost+tempcost<dist[v] && steps<=k+1){
                    dist[v]=cost+tempcost;
                     pq.push({steps+1,{cost+tempcost,v}});                }
               
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];

    }
};