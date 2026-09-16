class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if(n1>n2)return false;
        unordered_map<char,int>s1mp;
        unordered_map<char,int>s2mp;
        int cnt=0;
        int i=0;
        for(int i=0;i<n1;i++)s1mp[s1[i]]++;
        for( i=0;i<n1;i++){
            s2mp[s2[i]]++;
            if(s1mp.find(s2[i])!=s1mp.end() && s2mp[s2[i]]<=s1mp[s2[i]])cnt++;
        }
        if(cnt==n1) return true;
        int j=0;
        while(i<n2){
            //remove old char
          s2mp[s2[j]]--;
          if(s1mp.find(s2[j])!=s1mp.end() && s1mp[s2[j]]>s2mp[s2[j]])cnt--;
          s2mp[s2[i]]++;
           if(s1mp.find(s2[i])!=s1mp.end() && s2mp[s2[i]]<=s1mp[s2[i]])cnt++;
           if(cnt==n1) return true;
           i++;
           j++;
        }
        return false;
    }
};