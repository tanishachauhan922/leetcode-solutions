class Solution {
    private:
    int memo(int amount,vector<int>& coins,vector<vector<int>>& dp,int i){
        if(i==0){
            return (amount%coins[0]==0);
        }
    int nottake=memo(amount,coins,dp,i-1);
    int take=0;
    if(coins[i]<=amount)take=memo(amount-coins[i],coins,dp,i);
    return dp[i][amount]=take+nottake;
    }

public:
    int change(int amount, vector<int>& coins) {
       int n=coins.size();
        vector<vector<unsigned long long >>dp(n,vector<unsigned long long >(amount+1,0));
       // return memo(amount,coins,dp,n-1);
       for(int t=0;t<=amount;t++){
        dp[0][t]=(t%coins[0]==0);
       }
       for(int i=1;i<n;i++){
        for(int t=0;t<=amount;t++){
            unsigned long long  nottake=dp[i-1][t];
            unsigned long long  take=0;
            if(coins[i]<=t)take=dp[i][t-coins[i]];
            dp[i][t]=nottake+take;
        }
       }
       return (int)dp[n-1][amount];
    }
};