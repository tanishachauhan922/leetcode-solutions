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
public:
    int largestRectangleArea(vector<int>& heights) {
        int area=0;
        int n=heights.size();
        vector<int>nextsmaller(n,-1);
        vector<int>prevsmaller(n,-1);
        prev(heights,prevsmaller,n);
        next(heights,nextsmaller,n);
        for(int i=0;i<n;i++){
            int h=heights[i];
            int p=prevsmaller[i];
            int ne=nextsmaller[i];
            //if(prevsmaller[i]==-1)p=0;
            if(nextsmaller[i]==-1)ne=n;
            int b=abs(ne-p)-1;
            area=max(area,h*b);
        }
  return area;

    }
};