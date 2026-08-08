class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        int k=0,i=0,j=0;
        while(i<n){
            if(nums[i]>0) break;
            i++;
        }
         while(j<n){
            if(nums[j]<0) break;
            j++;
        }
        while(k<n){
            ans[k++]=nums[i++];
             while(i<n){
            if(nums[i]>0) break;
            i++;
        }
        ans[k++]=nums[j++];
          while(j<n){
            if(nums[j]<0) break;
            j++;
        }
        }
        return ans;
    }
};