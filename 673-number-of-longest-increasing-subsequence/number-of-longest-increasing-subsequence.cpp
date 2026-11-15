class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int maxi=0;
        int len=0;
        int indx=0;
        int n=nums.size();
        vector<int>dp(n,1),cnt(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev] && dp[i]<1+dp[prev]){
                    dp[i]=1+dp[prev];
                    cnt[i]=cnt[prev];
                }
                else if(nums[prev]<nums[i] && dp[i]==dp[prev]+1)cnt[i]+=cnt[prev];
               
            }
            if(dp[i]>=len){
              len=dp[i];
            }
            
            
        }
        
        for(int i=0;i<n;i++){
            if(dp[i]==len)maxi+=cnt[i];
        }
        return maxi;
    }
};