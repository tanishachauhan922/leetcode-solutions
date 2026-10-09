class Solution {
public:
    int hammingWeight(int n) {
        int i=0;
        int cnt=0;
        while(n!=0){
         if((n & 1)!=0)cnt++;
         n=n>>1;
        } 
        return cnt;
    }
};