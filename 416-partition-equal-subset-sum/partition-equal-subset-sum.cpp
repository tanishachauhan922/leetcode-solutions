class Solution {
    private:
    bool solve(vector<int>& nums,int n,int target, vector<vector<int>>& dp,int i){
        if(target==0) return true;
     if(i==0) return (nums[0]==target);
     //if(nums[i]>target) return false;
     if(dp[i][target]!=-1) return dp[i][target];
     bool nottake=solve(nums,n,target,dp,i-1);
     bool take=false;
     if(nums[i]<=target)take=solve(nums,n,target-nums[i],dp,i-1);
     return dp[i][target]=(nottake)||(take);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totsum=0;
        for(int i=0;i<n;i++)totsum+=nums[i];
        if(totsum%2==1) return false;
        int target=totsum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(nums,n,target,dp,n-1);
    }
};