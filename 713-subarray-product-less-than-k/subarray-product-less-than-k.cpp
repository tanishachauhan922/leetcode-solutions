class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long  ans=0;
        int n=nums.size();
        long long mul=1;
        int i=0,j=0;

        while(i<n){
            mul*=nums[i];
            //removing old ones
            while(mul>=k && j<=i){
                mul=mul/nums[j];
                j++;
            }
             
           if(mul<k) ans+=(i-j+1);
            i++;
        }
        return ans;
        
    }
};