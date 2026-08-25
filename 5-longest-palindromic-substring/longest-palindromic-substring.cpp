class Solution {
    private:
    string solve(string &s,int l,int r){
        string ans="";
        while(l>=0 && r<s.size()){
            if(s[l]==s[r]){
                l--;r++;
            }
            else break;
        }
         return s.substr(l + 1, r - l - 1);

    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans="";
        for(int i=0;i<n;i++){
            string ans1=solve(s,i,i);
            if(ans.size()<ans1.size())ans=ans1;
            string ans2=solve(s,i,i+1);
             if(ans.size()<ans2.size())ans=ans2;
        
        }
       return ans;
    }
};