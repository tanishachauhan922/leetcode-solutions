class Solution {
    private:
    long long solve(vector<int>& nums, int threshold,int n,long long mid){
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=ceil((double)nums[i]/mid);
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        long long maxi=nums[0];
        long long ans=LLONG_MAX;
    for(int i=0;i<n;i++) maxi=max(maxi,(long long)nums[i]);
     long long s=1;
     long long e=maxi;
     while(s<=e){
        long long mid=(s+e)/2;
        long long sum=solve(nums,threshold,n,mid);
        if(sum<=threshold){
            ans=min(ans,mid);
              e=mid-1;
        }
        else s=mid+1;
     }
     return ans;
    }
};