class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int r=0,c=n-1;
        while(r<m && c>=0){
            int ele=matrix[r][c];
            if(ele==target) return true;
            else if(ele>target){
                c--;
            }
            else r++;
        }   
    return false;
    }
};