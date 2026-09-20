class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        int mini=nums[0];
        int maxi=nums[0];
        for(int i=1;i<n;i++){
            int currmaxi=maxi;
            int currmini=mini;
            maxi=max(nums[i],max(currmaxi*nums[i],currmini*nums[i]));
            mini=min(nums[i],min(currmaxi*nums[i],currmini*nums[i]));
            ans=max(ans,maxi);
        }
        return ans;
    }
};