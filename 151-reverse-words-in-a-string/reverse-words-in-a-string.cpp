class Solution {
    void reversefun(string & temp){
        int s=0,e=temp.size()-1;
        while(s<=e){
            swap(temp[s],temp[e]);
            s++;
            e--;
        }
    }
    public:
    string reverseWords(string s) {
        int n=s.size();
        reverse(s.begin(),s.end());
        string temp="";
        string ans="";
       
        for(int i=0;i<n;i++){
            if(s[i]==' ' ){
                if(!temp.empty()){
               reversefun(temp);
               ans+=temp;
               ans+=' ';
               temp="";
            }
            }
            else {
                temp+=s[i];
            }
        }
         reversefun(temp);
               ans+=temp;
        while(!ans.empty() && ans.back()==' ')ans.pop_back();
                return ans;
    }
};