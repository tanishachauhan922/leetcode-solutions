class Solution {
    private:
    bool ispossible(vector<int>& nums, int k,long long mid,int n){
        long long cnt=0,sum=0;
         for(int i=0;i<n;i++){
            if(nums[i]>mid) return false;
            else if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                cnt++;
                sum=nums[i];
            }
         }
         if(sum>0) cnt++;
         if(cnt<=k) return true;
         else return false;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        long long s=*max_element(nums.begin(),nums.end());
        long long e=0;
        long long ans=INT_MAX;
        for(int i=0;i<n;i++) e+=nums[i];
        while(s<=e){
            long long mid=(s+e)/2;
            if(ispossible(nums,k,mid,n)){
                ans=min(ans,mid);
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};