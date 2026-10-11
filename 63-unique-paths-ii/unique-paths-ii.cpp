class Solution {
    int memoization(int i,int j, vector<vector<int>> & dp,vector<vector<int>>& obstacleGrid){
     if(i<0 || j<0) return 0;
     if(dp[i][j]!=-1) return dp[i][j];
     if(obstacleGrid[i][j]==1) return 0;
     int up=memoization(i-1,j,dp,obstacleGrid);    
     int left=memoization(i,j-1,dp,obstacleGrid);    
     return dp[i][j]=up+left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1) return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        dp[0][0]=1;
        return memoization(m-1,n-1,dp,obstacleGrid);
    }
};