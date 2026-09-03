class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string ans=countAndSay(n-1); 
        char num=ans[0];
        int cnt=1;
        string result="";
        for(int i=1;i<ans.size();i++){
            if(ans[i]==num)cnt++;
            else{
                result+=to_string(cnt);
                cnt=1;
                result+=num;
                num=ans[i];
            }
        }
        result+=to_string(cnt);
                cnt=1;
                result+=num;
        
        return result;
    }
};