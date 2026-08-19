class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         int n=nums.size();
         if(n==0) return {-1,-1};
        int s=0,e=n-1;
        vector<int>ans;
        int stin=-1,enin=-1;
        while(s<=e){
          int mid=(s+e)/2;
          if(nums[mid]==target){
              stin=mid;
              e=mid-1;
          }
          else if(nums[mid]>target){
            e=mid-1;
          }
          else{
            s=mid+1;
          }
        }
        
         ans.push_back(stin);
        s=0,e=n-1;
        while(s<=e){
          int mid=(s+e)/2;
          if(nums[mid]==target){
              enin=mid;
              s=mid+1;
          }
          else if(nums[mid]>target){
            e=mid-1;
          }
          else{
            s=mid+1;
          }
        }
         ans.push_back(enin);
          return ans;
    }
};