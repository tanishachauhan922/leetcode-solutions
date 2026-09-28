class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),[](int a,int b){
            return to_string(a)+to_string(b) > to_string(b)+to_string(a);
        });
        string ans="";
        for(int i=0;i<n;i++)ans+=to_string(nums[i]);
         if(ans[0]=='0') return "0";
         return ans;
    }
};