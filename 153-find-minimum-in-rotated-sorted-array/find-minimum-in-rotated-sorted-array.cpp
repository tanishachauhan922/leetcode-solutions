class Solution {
public:
    int findMin(vector<int>& nums) {
     int n=nums.size();
    int mini=INT_MAX;
    int s=0,e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(nums[mid]>=nums[s]){
            mini=min(mini,nums[s]);
            s=mid+1;
        }
        else{
           if(nums[mid]<nums[e]){
            mini=min(mini,nums[mid]);
            e=mid-1;
           }
           else{
            s=mid+1;
           }
        }
    }
    return mini;
    }
};