class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
       int maxi=0;
       unordered_map<int,int>mp;
       mp[0]=-1;
       int d=0;
       for(int i=0;i<n;i++){
           if(nums[i]==0)d--;
           else d++;
             if(mp.find(d)!=mp.end()){
                maxi=max(maxi,i-mp[d]);
             }
           else  mp[d]=i;
       }
       return maxi;
    }
};