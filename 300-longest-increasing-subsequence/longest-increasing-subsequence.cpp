class Solution {
private:
int memo(int i,vector<int>& nums,int n,vector<vector<int>>& dp,int prev_i){
    if(i>=n) return 0;
    if(dp[i][prev_i+1]!=-1) return dp[i][prev_i+1];
    int len=memo(i+1,nums,n,dp,prev_i);
    if(prev_i==-1 || nums[i]>nums[prev_i])len=max(len,1+memo(i+1,nums,n,dp,i));
    return dp[i][prev_i+1]=len;
}
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        int i=0,prev_i=-1;
        return  memo(i,nums,n,dp,prev_i);
    }
};