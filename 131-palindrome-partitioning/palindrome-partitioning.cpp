class Solution {
    private:
    bool isvalidpal(int st,int e,int n,string s){
          while(st<=e){
            if(s[st]==s[e]){
                st++;e--;
            }
            else return false;
          }
          return true;
    }
    void solve(int index,int n,string s,vector<vector<string>>& ans,vector<string> temp){
        if(index>=n){
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<n;i++){
            if(isvalidpal(index,i,n,s)){
                temp.push_back(s.substr(index,i-index+1));
                 solve(i+1,n,s,ans,temp);
                   temp.pop_back();
            }
            
           // temp.clear();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        int n=s.size();
        solve(0,n,s,ans,temp);
    return ans;
    }
};