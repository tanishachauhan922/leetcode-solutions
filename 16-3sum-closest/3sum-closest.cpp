class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0;
        int ans=-1;
        int maxdiff=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                int diff=abs(target-sum);
                if(diff<maxdiff){
                    ans=sum;
                    maxdiff=diff;
                }
                if(sum<target)j++;
                else k--;
            }
        }
    return ans;
    }
};