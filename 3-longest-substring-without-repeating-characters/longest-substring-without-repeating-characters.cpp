class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        int l=0,r=0;
        int maxi=0,len=0;
        while(l<=r && r<n){
            if(mp.find(s[r])==mp.end()){
                mp[s[r]]=r;
                len=r-l+1;
            }
            else{
                int val=mp[s[r]];
                if(val>=l) l=val+1;
                len=r-l+1;
                mp[s[r]]=r;
            }
            r++;
            maxi=max(maxi,len);
        }
        return maxi;
    }
};