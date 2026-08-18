class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        int mini=nums[0];
        int ans=nums[0];
    for(int i=1;i<n;i++){
        int currmax=maxi;
        int currmin=mini;
       maxi=max(nums[i],max(currmax*nums[i],currmin*nums[i]));
       
       mini=min(nums[i],min(currmax*nums[i],currmin*nums[i]));
        
      ans=max(ans,maxi);
      
    }  
    return ans;
    }
};