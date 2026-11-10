class Solution {
private:
int memo(vector<int>& prices,int i,bool buy,int n,vector<vector<int>>& dp){
 if(i==n)return 0;
 if(dp[i][buy]!=-1) return dp[i][buy];
 int p=0;
 if(buy){
     p=max(-prices[i]+memo(prices,i+1,0,n,dp),memo(prices,i+1,1,n,dp));
 }
 else p=max(prices[i]+memo(prices,i+1,1,n,dp),memo(prices,i+1,0,n,dp));
 return dp[i][buy]=p;
}
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        bool buy=1;
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return memo(prices,0,buy,n,dp);

        
    }
};