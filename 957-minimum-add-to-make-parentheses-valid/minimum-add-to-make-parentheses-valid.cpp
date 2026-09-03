class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        int o=0,cnt=0,ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')cnt++;
            else cnt--;
            if(cnt<0){
                ans+=(-cnt);
                cnt=0;
            }
        }
        if(cnt>0) ans+=cnt;
        return ans;
    }
};