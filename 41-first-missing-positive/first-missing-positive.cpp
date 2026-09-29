class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
           if(nums[i]>0 && nums[i]<=n && nums[nums[i]-1] != nums[i] ){
            int in=nums[i]-1;
             swap(nums[i],nums[in]);
           }
           else i++;
        }
        int ans=1;
        for(int i=0;i<n;i++){
            if(nums[i]!=ans) return ans;
            ans++;
        }
        return ans;
    }
};