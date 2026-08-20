class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int n=nums.size();
        int rotated=-1;
        int s=0,e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target)return true;
            if((nums[mid]==nums[s] && nums[mid]==nums[e])){
                s++;
                e--;
                continue;
            }
           else  if(nums[mid]>=nums[s]){
                if(target<nums[mid] && target>=nums[s])    e=mid-1;
                else s=mid+1;
            }
            else{
                  if(target>nums[mid] && target<=nums[e])    s=mid+1;
                else e=mid-1;
            }
        }
        return false;
    }
};