class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=-1;
        int st=0,e=n-1;
        while(st<=e){
            int mid=(st+e)/2;
            if(nums[mid]==target) return mid;
            else if(nums[st]<=nums[mid]){
            if(target>=nums[st] && target<=nums[mid])e=mid;
            else st=mid+1;
            }
            else{
                if(target<=nums[e] && target>=nums[mid] )st=mid+1;
                else e=mid;
            }

        }
        return ans;
    }
};