class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
         vector<int>ans;long long exor=0;
         int n=nums.size();
         for(int i=0;i<n;i++){
            exor=exor ^ nums[i];
         }
         long long bit=exor & (-exor);
         long long a=0,b=0;
         for(int i=0;i<n;i++){
            if((nums[i] & bit) !=0)a=a^nums[i];
            else b=b^nums[i];
         }
         return {(int)a,(int)b};
    }
};