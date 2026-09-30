class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size();
        int n=needle.size();
        int ans=-1;
        int i=0,j=0,k=0;
        string temp="";
        while(i<m && j <n){
            if(temp==needle)return k;
            if(haystack[i]==needle[j]){
                temp+=haystack[i];
            j++;
            }
            else{
                i=k;
                k++;
               temp="";
                j=0;
            }
        i++;
        }
         if(temp==needle)return k;
        return -1;
    }
};