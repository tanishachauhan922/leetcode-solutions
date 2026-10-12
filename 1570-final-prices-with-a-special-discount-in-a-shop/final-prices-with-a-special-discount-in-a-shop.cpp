class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()>prices[i])st.pop();
            if(st.empty())ans[i]=-1;
            else ans[i]=st.top();
            st.push(prices[i]);
        }
      for(int i=0;i<n;i++){
        if(ans[i]==-1){
           ans[i]=prices[i];
        }
        else  ans[i]=prices[i]-ans[i];
        
      }
      return ans;
    }
};