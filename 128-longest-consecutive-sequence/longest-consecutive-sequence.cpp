class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        unordered_set<int>mp;
        for(int i=0;i<n;i++)mp.insert(nums[i]);
       for(auto it :mp){
            if(mp.find(it-1)!=mp.end())continue;
            int len=1;
            int temp=it;
            while(mp.find(temp+1)!=mp.end()){
                len++;
                temp++;
            }
            maxi=max(maxi,len);
        }
        return maxi;

    }
};