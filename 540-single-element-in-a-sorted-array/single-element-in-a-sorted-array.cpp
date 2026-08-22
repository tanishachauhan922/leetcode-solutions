class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        if(n==1) return ans;
        int s=0,e=n-1;
        while(s<e){
            int mid=(s+e)/2;
           if(mid%2==1) mid--;
           if(nums[mid]==nums[mid+1]){
            s=mid+2;
           }
           else e=mid;
        }
        return nums[s];
    }
};