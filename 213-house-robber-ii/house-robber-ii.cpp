class Solution {
    int solve(vector<int>& temp,vector<int>& dp,int i){
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        int take=temp[i]+solve(temp,dp,i-2);
        int nottake=solve(temp,dp,i-1);
       dp[i]=max(take,nottake);
       return dp[i];
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>temp1;
        vector<int>temp2;
        for(int i=0;i<n;i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        vector<int>dp1(temp1.size(),-1);
        vector<int>dp2(temp2.size(),-1);
      int case1= solve(temp1,dp1,temp1.size()-1);
      int case2= solve(temp2,dp2,temp2.size()-1);
    return max(case1,case2);
    }
};