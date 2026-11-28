class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)    mp[nums[i]]=i;
        for(int i=0;i<n;i++){
            int left=target-nums[i];
            if(mp.find(left)!=mp.end() && mp[left]!=i){
                ans.push_back(i);
                ans.push_back(mp[left]);
                break;
            }
        }
         return ans;
    }
};