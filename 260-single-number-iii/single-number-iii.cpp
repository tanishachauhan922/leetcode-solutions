class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        long long xxor=0;
        for(int i=0;i<n;i++) xxor=xxor^nums[i];
       int bit = xxor & (-xxor);
        int i=0;
        long long a=0,b=0;
        while(i<n){
            if((bit & nums[i])!=0)a=a^nums[i];
            else b=b^nums[i];
            i++;
        }
        return {(int)a,(int)b};
    }
};