class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        if( n==1) return 0;
        int st=0,e=n-1;
        while(st<=e){
            int mid=(st+e)/2;
            int left=INT_MIN;
            int right=INT_MIN;
            if(mid-1>=0)left=nums[mid-1];
            if(mid+1<n)right=nums[mid+1];
            if(nums[mid]>left && nums[mid]>right) return mid;
            else if(left>nums[mid])e=mid-1;
            else st=mid+1;
        }
        return ans;
    }
};