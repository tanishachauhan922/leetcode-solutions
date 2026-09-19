class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int sum=0;
        vector<int>r(n,0);
        for(int i=n-1;i>=0;i--){
             r[i]=sum;
             sum+=nums[i];
        }
        for(int i=0;i<n;i++){
            if(l==r[i])return i;
            l+=nums[i];
        }
        return -1;
    }
};