class Solution {
         string len(int  st,int e,int n,string s){
            //int l=0;
            while(st>=0 && e<n && s[st]==s[e]){
                st--;
                e++;
            }
            st++;
        e--;
           return s.substr(st,e-st+1);
         }
public:
    string longestPalindrome(string s) {
        int n=s.size();int maxi=0;string ans="";
        for(int i=0;i<n;i++){
            string len1=len(i,i,n,s);
            if(len1.size()>maxi){
                maxi=len1.size();
                ans=len1;
            }
            string len2=len(i,i+1,n,s);
            if(len2.size()>maxi){
                maxi=len2.size();
                ans=len2;
            }
        }
     return ans;   
    }
};