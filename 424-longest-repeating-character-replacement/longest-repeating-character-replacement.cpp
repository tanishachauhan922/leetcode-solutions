class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0;
        int j=0;
        int len=0;
        int ans=0;
        int maxfreq=0;
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;
            len++;
            if(mp[s[j]]>maxfreq)maxfreq=mp[s[j]];
            if((len-maxfreq)>k){
                while(i<n){
                    if(len-maxfreq<=k)break;
                    mp[s[i]]--;
                    len--;
                    if(mp[s[i]]==0)mp.erase(s[i]);
                    i++;
                }
            }
             ans = max(ans, len);
            j++;
        }
        return ans;
    }
};