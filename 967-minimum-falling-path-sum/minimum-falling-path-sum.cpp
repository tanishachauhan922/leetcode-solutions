class Solution {
    private:
    int memoization(vector<vector<int>>& matrix,int n,int m,int i,int j,vector<vector<int>>& dp){
        if(j<0 || j>=m)return 1e9;
        if(i==0) return matrix[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int up=1e9,leftdia=1e9,rightdia=1e9;
        up=matrix[i][j]+memoization(matrix,n,m,i-1,j,dp);
        if(j-1>=0) leftdia=matrix[i][j]+memoization(matrix,n,m,i-1,j-1,dp);
        if(j+1<m) rightdia=matrix[i][j]+memoization(matrix,n,m,i-1,j+1,dp);
       return dp[i][j]=min(up,min(leftdia,rightdia));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        // int ans=0;
        // int mini=1e9;
        // for(int j=m-1;j>=0;j--)mini=min(mini,memoization(matrix,n,m,n-1,j,dp));
        for(int j=0;j<m;j++)dp[0][j]=matrix[0][j];
        //tabulation
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up=1e9,leftdia=1e9,rightdia=1e9;
                up=matrix[i][j]+dp[i-1][j];
        if(j-1>=0) leftdia=matrix[i][j]+dp[i-1][j-1];
        if(j+1<m) rightdia=matrix[i][j]+dp[i-1][j+1];
        dp[i][j]=min(up,min(leftdia,rightdia));
            }
        }
        int mini=1e9;
        for(int j=0;j<m;j++)mini=min(mini,dp[n-1][j]);
        return mini;
    }
};