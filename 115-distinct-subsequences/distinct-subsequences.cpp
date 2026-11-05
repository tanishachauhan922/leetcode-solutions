class Solution {
    private:
    int count(string s,string t,int i,int j,vector<vector<int>>& dp){
      if(j<0) return 1;
      if(i<0) return 0;
      if(dp[i][j]!=-1) return dp[i][j];
      if(s[i]==t[j]) return dp[i][j]=count(s,t,i-1,j-1,dp)+count(s,t,i-1,j,dp);
      else return dp[i][j]= count(s,t,i-1,j,dp);
    }
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
    //vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    //return count(s,t,n-1,m-1,dp);
    vector<unsigned long long>prev(m+1,0);
    prev[0]=1;
    for(int j=1;j<=m;j++)prev[j]=0;
    for(int i=1;i<=n;i++){
        vector<unsigned long long>curr(m+1,0);
        for(int j=1;j<=m;j++){
            curr[0]=1;
            if(s[i-1]==t[j-1])curr[j]=prev[j-1]+prev[j];
            else curr[j]=prev[j];
        }
        prev=curr;
    }
    return (int)prev[m];
    }
};