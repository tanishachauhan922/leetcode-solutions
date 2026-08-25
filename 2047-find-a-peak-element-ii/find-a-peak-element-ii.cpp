class Solution {
    private:
    int findmaxele(vector<vector<int>>& mat,int n,int m,int mid){
        int row=0;
        int maxi=-1;
        for(int i=0;i<m;i++){
           if(maxi<mat[i][mid]){
            maxi=mat[i][mid];
           row=i;
        }
        }
        return row;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
         int m=mat.size();
        int n=mat[0].size();
        int l=0,r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
          int  row=findmaxele(mat,n,m,mid);
            int left=(mid-1>=0)? mat[row][mid-1] : -1;
            int right=(mid+1<n)? mat[row][mid+1] : -1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid} ;
                }
           else  if(mat[row][mid]<left ){r=mid-1 ;}
            else l=mid+1;
        }
        return {-1,-1};
    }
};