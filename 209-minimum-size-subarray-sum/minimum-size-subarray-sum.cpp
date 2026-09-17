class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int n=nums.size();
        int sum=0,len=0;
        int i=0,j=0;
        while(i<n && sum<target){
            sum+=nums[i];
            len++;
            i++;
        }
        if(sum>=target)
        ans=min(ans,len);
       while(i<=n){
         //reducing the len
         while(sum>=target){
            sum-=nums[j];
            j++;
            len--;
            if(sum>=target)  ans=min(ans,len);
         
         }
         if(i==n) break;
         //add new 
         sum+=nums[i];
         len++;
         i++;
         if(sum>=target){
            ans=min(ans,len);
         }
       }
       if(ans==INT_MAX) return 0;
       return ans;
    }
};