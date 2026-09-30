class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(numRows==1 || numRows>=n) return s;
        vector<string>rows(numRows);
        int i=0;int step=1;
        for(auto ch : s){
            rows[i]+=ch;
            if(i==0)step=1;
            if(i==numRows-1)step=-1;
            i+=step;
        }
        string ans="";
        for(auto temp : rows ){
             ans+=temp;
        }
        return ans;
    }
};