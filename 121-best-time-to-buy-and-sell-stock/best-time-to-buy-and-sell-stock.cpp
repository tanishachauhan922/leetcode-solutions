class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxi=0;
        int buy=0;
        int sell=1;
        for(int i=1;i<n;i++){
            if(prices[i]<prices[buy])buy=i;
            sell=i;
            if(buy<sell){
                int profit=prices[sell]-prices[buy];
                maxi=max(maxi,profit);
            }
        }
        return maxi;
    }
};