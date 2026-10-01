class Solution {
    int count(int st,int e,int n,string s){
        int cnt=0;
        while(st>=0 && e<n && s[st]==s[e]){
            st--;e++;
            cnt++;
        }
        return cnt;
    }
public:
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=count(i,i,n,s);
            cnt+=count(i,i+1,n,s);
        }
        return cnt;
    }
};