class Solution {
    private:
    bool comparing(string s1,string s2){
        if(s1.size()!=s2.size()+1) return false;
        int i=0,j=0;
        while(i<s1.size()){
            if(j<s2.size() && s1[i]==s2[j]){i++;j++;}
            else i++;
        }
        if(i==s1.size() && j==s2.size())return true;
        return false;
    }
   static  bool compare( const string &s1,const string &s2){
         return s1.size()<s2.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),compare);
       vector<int>dp(n,1);
       int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(comparing(words[i],words[prev]) && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                }
            }
            if(dp[i]>maxi) maxi=dp[i];
        }
        return maxi;
    }
};