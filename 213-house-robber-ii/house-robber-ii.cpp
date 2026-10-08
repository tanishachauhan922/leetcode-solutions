class Solution {
    private:
    int solve(vector<int>& nums,int indx,vector<int>& dp,int n){
           if(indx<0)return 0;
           if(dp[indx]!=-1)return dp[indx];
           int take=nums[indx];
           if(indx-2>=0)take=nums[indx]+solve(nums,indx-2,dp,n);
           int nottake=solve(nums,indx-1,dp,n);
           return dp[indx]=max(nottake,take);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>temp1;
        vector<int>temp2;
        for(int i=0;i<n;i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        vector<int>dp1(temp1.size(),-1);
        vector<int>dp2(temp2.size(),-1);
      int op1=solve(temp1,temp1.size()-1,dp1,temp1.size());
      int op2=solve(temp2,temp2.size()-1,dp2,temp2.size());
      return max(op1,op2);
    }
};