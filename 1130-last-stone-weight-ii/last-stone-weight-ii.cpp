class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int total=0;
        for(int i=0;i<n;i++)total+=stones[i];
        vector<vector<bool>>dp(n,vector<bool>(total+1,0));
        for(int i=0;i<n;i++)dp[i][0]=1;
        if(stones[0]<=total)dp[0][stones[0]]=true;
        for(int i=1;i<n;i++){
            for(int t=0;t<=total;t++){
                bool nottake=dp[i-1][t];
                bool take=0;
                if(stones[i]<=t)take=dp[i-1][t-stones[i]];
                dp[i][t]=(nottake)||(take);
            }
        }
        int mini=total;
        for(int i=0;i<=total/2;i++){
            if(dp[n-1][i]==1){
                int s1=i;
            int s2=total-s1;
            mini=min(mini,abs(s1-s2));
            }
        }
        return mini;
    }
};