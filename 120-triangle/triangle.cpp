class Solution {
    private:
    int solve(int i,int j,int m,vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i==m-1) return triangle[i][j];
        if(dp[i][j]!=1e9)return dp[i][j];
        int down= triangle[i][j]+solve(i+1,j,m,triangle,dp);
        int diag=triangle[i][j]+solve(i+1,j+1,m,triangle,dp);
        return dp[i][j]=min(down,diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=m;
        vector<vector<int>>dp(m,vector<int>(n,1e9));
        return solve(0,0,m,triangle,dp);
        
    }
};