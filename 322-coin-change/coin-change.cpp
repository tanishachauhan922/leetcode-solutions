class Solution {
private:
int memo(vector<int>& coins,int amount,int indx,vector<vector<int>>& dp){
    if(indx==0){
        if(amount%coins[0]==0) return amount/coins[0];
        else return 1e9;
    }
    if(dp[indx][amount]!=-1) return dp[indx][amount];
    int nottake=memo(coins,amount,indx-1,dp);
    int take=1e9;
    if(amount>=coins[indx])take=1+memo(coins,amount-coins[indx],indx,dp);
    return dp[indx][amount]=min(take,nottake);
}
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
    //   int ans=  memo(coins,amount,n-1,dp);  
    //   if(ans==1e9) return -1;
    //   return ans;
    for(int t=0;t<=amount;t++){
        if(t%coins[0]==0)dp[0][t]=t/coins[0];
        else dp[0][t]=1e9;
    }
    for(int i=1;i<n;i++){
        for(int t=0;t<=amount;t++){
            int nottake=dp[i-1][t];
            int take=1e9;
            if(coins[i]<=t)take=1+dp[i][t-coins[i]];
        dp[i][t]=min(nottake,take);
        }
    }
  if(dp[n-1][amount] == 1e9) return -1;
  else return dp[n-1][amount];
    }
};