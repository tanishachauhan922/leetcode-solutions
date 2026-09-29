class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int st=0,e=m*n-1;
        while(st<=e){
            int mid=(st+e)/2;
            int r=mid/n;
            int c=mid%n;
            if(matrix[r][c]==target) return true;
            else if(matrix[r][c]<target)st=mid+1;
            else e=mid-1;
        }
        return false;
      
    }
};