class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int n=t.size();
        unordered_map<char,int>tmap;
        unordered_map<char,int>smap;
        int start=0;
        for(int i=0;i<n;i++)tmap[t[i]]++;
        int l=0,r=0;
        int cnt=0;
        int mini=INT_MAX;
        int len=0;
        while(r<m){
           smap[s[r]]++;
           if(smap[s[r]]<=tmap[s[r]]){
            cnt++;
           }
           while(cnt==n){
            if(r - l + 1 < mini) {
                    mini = r - l + 1;
                    start = l;
                }
                if(smap[s[l]] <= tmap[s[l]]) {
                    cnt--;
                }
                smap[s[l]]--;
                if(smap[s[l]] == 0)
                    smap.erase(s[l]);
                l++;
            }
            r++;
        }


            
          

        
        if(mini==INT_MAX) return "";

        return s.substr(start, mini);
    }
};