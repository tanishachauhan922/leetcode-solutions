class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         int balance=0;
         int start=0;
         int defiency=0;
         int n=gas.size();
         for(int i=0;i<n;i++){
            balance=balance+gas[i]-cost[i];
            if(balance<0){
                defiency+=balance;
                balance=0;
                start=i+1;
            }
         }
         if(defiency+balance>=0) return start;
         else return -1;
    }
};