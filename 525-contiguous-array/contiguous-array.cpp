class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int s=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0)s+=(-1);
            else s+=1;
            if(mp.find(s)!=mp.end()){
                ans=max(ans,i-mp[s]);
            }
            else mp[s]=i;
        }
        return ans;
    }
};