class Solution {
    private:
    long long solve(vector<int>& piles, int n,int mid){
        long long hrs=0;
        for(int i=0;i<n;i++){
            hrs+=ceil((double)piles[i]/mid);
        }
        return hrs;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        long long maxi=-1;
        for(int i=0;i<n;i++) maxi=max(maxi,(long long)piles[i]);
         long long s=1,e=maxi;
         int ans=INT_MAX;
         while(s<=e){
            long long  mid=(s+e)/2;
            long long totalhrs=solve(piles,n,mid);
            if(totalhrs<=h){
                ans=mid;
                e=mid-1;
            }
            else    s=mid+1;
            
         }
         return ans;
    }
};