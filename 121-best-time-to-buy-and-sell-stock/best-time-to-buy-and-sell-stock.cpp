class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy=prices[0];
        int sell=n-1;
        int buyin=0;
        int maxi=0;
        for(int i=1;i<n;i++){
            if(prices[i]<buy){
                buy=prices[i];
                buyin=i;
            }
            if(i>buyin && prices[i]-buy > maxi){
                maxi=prices[i]-buy;
            }
           // if(sell!=buyin)  maxi=max(maxi,prices[sell]-buy);
        }
        return maxi;
    }
};