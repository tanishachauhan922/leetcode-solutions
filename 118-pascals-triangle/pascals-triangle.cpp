class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int num=1;
        vector<vector<int>>ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int>output;
              int size=ans[i-1].size()+1;
              for(int j=0;j<size;j++){
                if(j==0 || j==size-1)  num=1; 
                else  num=ans[i-1][j-1]+ans[i-1][j];
                output.push_back(num);
              }
              ans.push_back(output);
        }
        return ans;
    }
};