class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
       int maxlen=0;
       int maxfreq=0;
       int i=0,j=0;
       vector<int>mp(26,0);
       int l=0,r=0;
       while(r<n){
        int index=s[r]-'A';
          mp[index]++;
          
          maxfreq=max(maxfreq,mp[index]);
          if((r-l+1)-maxfreq<=k){
            maxlen=max(maxlen,r-l+1);
          }
          else{
            int lindex=s[l]-'A';
            mp[lindex]--;
            l++;
          }
          r++;
       }
     return maxlen;
    }
};