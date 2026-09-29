class Solution {
    private:
    bool check(long long mid,vector<int>& weights,int days){
        int tempsum=weights[0];
        int i=1,n=weights.size();
        int cnt=0;
        while(i<n){
            if(tempsum>mid)return false;
           if(tempsum+weights[i]<=mid){
            tempsum+=weights[i];
           }
           else {
           // cnt+=ceil((double)tempsum/mid);
            tempsum=weights[i];
            cnt++;
           }
           i++;
        }
        if(tempsum > mid) return false;
        if(cnt+1<=days)return true;
        else return false;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int st=1,e=0,ans=0;
        for(auto x: weights)e+=x;
        while(st<=e){
            int mid=(st+e)/2;
            if(check(mid,weights,days)){
                ans=mid;
                e=mid-1;
            }
            else st=mid+1;
        }
        return ans;

    }
};