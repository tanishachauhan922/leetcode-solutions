class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]=='{' || s[i]=='[' || s[i]=='(')st.push(s[i]);
            else {
                char ch='x';
                if(!st.empty()) ch=st.top();
                else return false;
                if(s[i]=='}' && ch=='{')st.pop();
                else if(s[i]==')' && ch=='(')st.pop();
                else if(s[i]==']' && ch=='[')st.pop();
                else return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};