class Solution {
public:
    string minWindow(string s, string t) {
        int ssize=s.size();
        int tsize=t.size();
      unordered_map<char,int>smp;
      unordered_map<char,int>tmp;
      for(int i=0;i<tsize;i++)tmp[t[i]]++;
      int n=tmp.size();
      int i=0,j=0;
      int len=0,mini=INT_MAX;
      int cnt=0;
      int st=0;
      while(j<ssize){
          smp[s[j]]++;
          len++;
          //if(smp[s[j]]==tmp[s[j]])cnt++;
          if(tmp.find(s[j]) != tmp.end() && smp[s[j]] == tmp[s[j]]) cnt++;
          if(cnt==n){
            while(i<ssize && cnt==n){
                 if(len<mini){mini=len;st=i;}
                smp[s[i]]--;
               // if(tmp[s[i]]>smp[s[i]])cnt--;
                if(tmp.find(s[i]) != tmp.end() && smp[s[i]] < tmp[s[i]])  cnt--;
                len--;
                if(smp[s[i]]==0)smp.erase(s[i]);
                i++;
            }
          }
          j++;
      }
      if(mini==INT_MAX) return "";
      else return s.substr(st,mini);
    }
};