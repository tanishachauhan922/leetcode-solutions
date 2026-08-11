class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans=-1;
        int n=nums.size();
        vector<int>lefty(n,0);
        vector<int>righty(n,0);
        int sum=0;
       for(int i=0;i<n;i++){
        sum+=nums[i];
        lefty[i]=sum;
       }
       sum=0;
       for(int i=n-1;i>=0;i--){
        sum+=nums[i];
        righty[i]=sum;
       }
        for(int i=0;i<n;i++){
            int leftsum=lefty[i]-nums[i];
            int rightsum=righty[i]-nums[i];
            if(leftsum==rightsum){ans=i;break;}
        }
        return ans;
    }
};