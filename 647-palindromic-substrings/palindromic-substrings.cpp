class Solution {
    private:
    int check(string s, int l,int r){
        
        int cnt=0;
        while( l>=0 && r<s.size() && s[l]==s[r]){
            //if(s[l]==s[r]){
                cnt++;
                l--;
                r++;
            

        }
        return cnt;
    }
public:
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
           cnt+=check(s,i,i);
           cnt+=check(s,i,i+1);
        }
        return cnt;
    }
};