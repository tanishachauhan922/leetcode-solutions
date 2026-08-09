class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int m=matrix.size();
            int n=matrix[0].size();
            vector<int>ans;
            int top=0,bottom=m-1;
            int right=n-1;
            int left=0;
            while(top<=bottom && left<=right){
                //first row
               int j=left;
               while( j<=right){
                ans.push_back(matrix[top][j]);
                j++;
               }
               top++;
               //last col
               int i=top;
               while(i<=bottom){
                ans.push_back(matrix[i][right]);
                i++;
               }
               right--;
               //last row
               if(top <= bottom){ 
               j=right;
               while(j>=left){
                ans.push_back(matrix[bottom][j]);
                j--;
               }
               bottom--;
               //first col
               }
               if(left <= right) {
                i=bottom;
               while(i>=top){
                ans.push_back(matrix[i][left]);
                i--;
               }
               left++;
               }
            }
            return ans;
            }
};