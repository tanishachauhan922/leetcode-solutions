class Solution {
    private:
    string solve(string s,int l,int r){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
        }
        return s.substr(l+1,r-l-1);
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            //odd
            string len1=solve(s,i,i);
            //even
            string len2=solve(s,i,i+1);
            if(len1.size()>ans.size()){
                ans=len1;
            }
             if(len2.size()>ans.size()){
                ans=len2;
            }
        }
        return ans;
    }
};