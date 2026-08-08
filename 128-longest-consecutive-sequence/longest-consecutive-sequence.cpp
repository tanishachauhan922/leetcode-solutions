class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int maxi=0;
       int n=nums.size();
       unordered_set<int>s;
       for(int i=0;i<n;i++) s.insert(nums[i]);
       for(auto st : s){
        if(s.find(st-1)==s.end()){
            int len=1;
            while(s.find(st+len)!=s.end()){
                len++;
            }
            maxi=max(maxi,len);
        }
       }
       return maxi;
    }
};