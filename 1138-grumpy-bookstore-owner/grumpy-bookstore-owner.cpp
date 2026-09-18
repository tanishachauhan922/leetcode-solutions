class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int k=0;
        int maxunsatisfied=0;
        int i=0,j=0;
        int sum=0;
        while(i<minutes){
            if(grumpy[i]==1)sum+=customers[i];
            i++;
        }
        maxunsatisfied=max(maxunsatisfied,sum);
        while(i<n){
            if(grumpy[j]==1)sum-=customers[j];
            j++;
            if(grumpy[i]==1)sum+=customers[i];
            maxunsatisfied=max(maxunsatisfied,sum);
            i++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0)ans+=customers[i];
        }

        return maxunsatisfied+ans;
    }
};