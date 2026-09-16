class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int n1=s.size();
        int n2=p.size();
        if(n2 > n1) return ans;
        unordered_map<char,int>pmp;
        unordered_map<char,int>smp;
        for(int i=0;i<n2;i++)pmp[p[i]]++;
        int i=0;
        int cnt=0;
        for( i=0;i<n2;i++){
            smp[s[i]]++;
            if(pmp.find(s[i])!=pmp.end() && smp[s[i]]<=pmp[s[i]])cnt++;
        }
        int j=0;
        if(cnt==n2)ans.push_back(0);
      while(i<n1){
        //remove old one
        smp[s[j]]--;
         if(pmp.find(s[j])!=pmp.end() && smp[s[j]]<pmp[s[j]])cnt--;
         j++;
        //ad new one
        smp[s[i]]++;
        if(pmp.find(s[i])!=pmp.end() && smp[s[i]]<=pmp[s[i]])cnt++;
         if(cnt==n2)ans.push_back(j);
         i++;
      }
      return ans;
    }
};