class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        int sum=0, l=0,r=0;
        while(l<=r && r<=n){
             
            if(sum<target && r<n){
                sum += nums[r];
            r++;
            }
            else if(sum>=target){
               int len=r-l;
                mini=min(mini,len);
                sum-=nums[l];
                l++;
            }
             else {
                // r == n and sum < target
                break;
            }
        
        }
        if(mini==INT_MAX) return 0;
        return mini;
    }
};