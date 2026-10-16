class Solution {
    private:
    int solve(int i,int j,int m,vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i==m-1) return triangle[i][j];
        if(dp[i][j]!=1e9)return dp[i][j];
        int down= triangle[i][j]+solve(i+1,j,m,triangle,dp);
        int diag=triangle[i][j]+solve(i+1,j+1,m,triangle,dp);
        return dp[i][j]=min(down,diag);
    }
    int tabulation(vector<vector<int>>& triangle,int n,vector<vector<int>>& dp){
         for(int i=n-1;i>=0;i--) dp[n-1][i]=triangle[n-1][i];

         for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down= triangle[i][j]+dp[i+1][j];
        int diag=triangle[i][j]+dp[i+1][j+1];
          dp[i][j]=min(down,diag);
            }
         }
         return dp[0][0];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        // int n=m;
         vector<vector<int>>dp(m,vector<int>(m,1e9));
        // return solve(0,0,m,triangle,dp);
        return tabulation(triangle,m,dp);
        
    }
};