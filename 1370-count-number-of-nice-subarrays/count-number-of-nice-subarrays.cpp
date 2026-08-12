class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int>mp;//to store odd freq
        mp[0]=1;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0){
                cnt++;
            }
            if(mp.find(cnt-k)!=mp.end()){
                ans+=mp[cnt-k];
            }
            mp[cnt]++;
    }
        return ans;
    }
};