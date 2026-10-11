class Solution {
    private:
    int memoization(int i,int j, vector<vector<int>> & dp){
     if(i<0 || j<0) return 0;
     if(dp[i][j]!=-1) return dp[i][j];
     int up=memoization(i-1,j,dp);    
     int left=memoization(i,j-1,dp);    
     return dp[i][j]=up+left;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        dp[0][0]=1;
        return memoization(m-1,n-1,dp);
    }
};