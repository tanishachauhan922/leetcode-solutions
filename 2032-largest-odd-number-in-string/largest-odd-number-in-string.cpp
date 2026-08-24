class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        string ans="";
        int i=n-1;
        for( i=n-1;i>=0;i--){
            if(num[i]%2!=0) break;
        }
        if(i<=-1) return "";
        for(int j=0;j<=i;j++ ) ans+=num[j];
        return ans;
    }
};