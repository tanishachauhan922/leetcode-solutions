class Solution {
    private:
    bool check(string s,int i,int j){
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return check(s,i,j-1) || check(s,i+1,j);
            }
        }
        return true;
    }
};