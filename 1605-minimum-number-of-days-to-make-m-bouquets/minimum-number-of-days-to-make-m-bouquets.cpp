class Solution {
    private:
    long long solve(vector<int>& bloomDay, int m, int k,long long mid,int n){
        long long cnt=0;
        long long bqts=0;
       for(int i=0;i<n;i++){
        if(bloomDay[i]<=mid){
            cnt++;
            if(cnt==k){
                bqts++;
                cnt=0;
            }
        }
        else cnt=0;
       }
       return bqts;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long out=(long long)m*k;
        if((out)>n) return -1;
        long long maxi=bloomDay[0];
        long long mini=bloomDay[0];
        for(int i=0;i<n;i++){
             maxi=max(maxi,(long long)bloomDay[i]);
             mini=min(mini,(long long)bloomDay[i]);
        }
        long long s=mini,e=maxi;
        long long ans=INT_MAX;
        while(s<=e){
            long long mid=(s+e)/2;
            long long bqts=solve(bloomDay,m,k,mid,n);
            if(bqts>=m){
                ans=min(ans,mid);
           e=mid-1;
            }
        
        else s=mid+1;
    } 
    if(ans==INT_MAX) return -1;
    return ans;
    }
};