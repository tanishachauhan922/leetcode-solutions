class Solution {
    private:
    int memo(vector<int>& nums,int n,vector<int>& dp,int i){
        if(i==0)return nums[0];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=nums[i]+memo(nums,n,dp,i-2);
        int nottake=0+memo(nums,n,dp,i-1);
        dp[i]=max(take,nottake);
        return dp[i];
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        int i=n-1;
        return memo(nums,n,dp,i);
        
    }
};