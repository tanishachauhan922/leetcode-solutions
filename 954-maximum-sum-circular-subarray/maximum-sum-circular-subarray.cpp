class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        int sum=nums[0];
        int mini=nums[0];
        int currmini=nums[0];
        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
            if(i>0){
                 if(sum<0)sum=0;
                sum+=nums[i];
                maxi=max(maxi,sum);
               
                currmini=min(nums[i],currmini+nums[i]);
                mini=min(mini,currmini);
            }
        }
        if(maxi<0) return maxi;
        return max(maxi,total-mini);
    }
};