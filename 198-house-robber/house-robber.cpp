class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
       int p2=0,p1=0;
       for(int i=0;i<n;i++){
        int take=nums[i]+p2;
        int nottake=p1;
        maxi=max(take,nottake);
        p2=p1;
        p1=maxi;
       }
        return maxi;
    }
};