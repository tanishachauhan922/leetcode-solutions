class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
       int i=0;
       long long ans=0;
       int sign=1;
            while(i<n && s[i]==' ') {
                i++;
            }
             if(i<n && s[i]=='+'){
                i++;
             }
             else if(i<n && s[i]=='-'){
                sign=-1;
                i++;
             }
             while(i<n && s[i]=='0') i++;
             while(i<n && isdigit(s[i])){
                   if(ans > INT_MAX / 10 ||
       (ans == INT_MAX / 10 && (s[i]-'0') > 7)) {
        return sign == 1 ? INT_MAX : INT_MIN;
    }
                ans = ans * 10 +(long long) (s[i] - '0');
                i++;
             }
        if(sign*ans>INT_MAX) return INT_MAX;
        if(sign*ans<INT_MIN) return INT_MIN;
        return sign* ans;
    }
};