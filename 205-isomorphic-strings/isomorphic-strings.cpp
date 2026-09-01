class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        int i=0,j=0;
        unordered_map<char,char>mp1;
        unordered_map<char,char>mp2;
        while(i<n1 && j<n2){
            if(mp1.find(s[i])!=mp1.end()){
                char val=mp1[s[i]];
                if(val!=t[j]) return false;
            }
            else if(mp2.find(t[j])!=mp2.end()){
                char val=mp2[t[j]];
                if(val!=s[i]) return false;
            }
            else{
                mp1[s[i]]=t[j];
                mp2[t[j]]=s[i];
            }
              i++;j++;
             }
             return true;
    }
};