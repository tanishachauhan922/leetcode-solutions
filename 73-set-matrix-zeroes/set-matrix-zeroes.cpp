class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<pair<int,int>>st;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    st.push_back({i,j});
                }
            }
        }
        //to make
        int size=st.size();
        for(auto it : st){
            int row=it.first;
            int col=it.second;
           for(int j=0;j<n;j++){
            matrix[row][j]=0;
           }
              for(int j=0;j<m;j++){
            matrix[j][col]=0;
           }
        }
    }
};