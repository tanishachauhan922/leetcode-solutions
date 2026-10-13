class Solution {
    private:
    void next(vector<int>& heights,vector<int>& nextsmaller,int n){
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            if(st.empty())nextsmaller[i]=-1;
            else nextsmaller[i]=st.top();
            st.push(i);
        }
    }
     void prev(vector<int>& heights,vector<int>& prevsmaller,int n){
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i])       st.pop();
            if(st.empty())prevsmaller[i]=-1;
            else prevsmaller[i]=st.top();
            st.push(i);
        }
    }
    int height(vector<vector<char>>& matrix,vector<int>& heights,int n,int m,int j,int i){
      int cnt=0;
      for(int k=i;k>=0;k--){
        if(matrix[k][j]=='0')break;
        cnt++;
      }
      return cnt;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int area=0;

        //
        for(int i=n-1;i>=0;i--){
            vector<int>heights(m,0);
        for(int j=0;j<m;j++){
        heights[j]= height(matrix,heights,n,m,j,i);
        }

         vector<int>nextsmaller(m,-1);
        vector<int>prevsmaller(m,-1);
        prev(heights,prevsmaller,m);
        next(heights,nextsmaller,m);
        for(int i=0;i<m;i++){
            int h=heights[i];
            int p=prevsmaller[i];
            int ne=nextsmaller[i];
            //if(prevsmaller[i]==-1)p=0;
            if(nextsmaller[i]==-1)ne=m;
            int b=abs(ne-p)-1;
            area=max(area,h*b);
        }
        }
        
        
return area;
    }
};