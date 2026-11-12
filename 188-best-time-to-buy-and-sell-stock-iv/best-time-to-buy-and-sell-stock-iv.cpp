class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
    //     vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
    //     for(int i=n-1;i>=0;i--){
    //         for(int buy=0;buy<=1;buy++){
    //             for(int cap=1;cap<=k;cap++){
    //                 int p=0;
    //                 if(buy==1){
    //                     p=max(p,max((-prices[i]+ dp[i+1][0][cap]),dp[i+1][1][cap]));
    //                 }
    //                 else{
    //                     p=max(p,max((prices[i]+dp[i+1][1][cap-1]),dp[i+1][0][cap]));
    //                 }
    //                 dp[i][buy][cap]=p;
    //             }
                
    //         }
    //     }
    // return dp[0][1][k];


     vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));

     for(int i=n-1;i>=0;i--){
        for(int tran=2*k-1;tran>=0;tran--){
            int p=0;
            if(tran%2==0)    p=max(p,max((-prices[i]+ dp[i+1][tran+1]),dp[i+1][tran]));
            
            else  p=max(p,max((prices[i]+dp[i+1][tran+1]),dp[i+1][tran]));
            dp[i][tran]=p;
        }
        
     }
     return dp[0][0]; 
    }
};