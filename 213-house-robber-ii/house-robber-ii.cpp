class Solution {
    int solve(vector<int>& temp,int prev2,int prev1,int n){
        for(int i=1;i<temp.size();i++){
           int take=temp[i]+prev2;
           int nottake=prev1;
           int curr=max(take,nottake);
           prev2=prev1;
           prev1=curr;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>temp1;
        vector<int>temp2;
        for(int i=0;i<n;i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        
        int prev2=0;
        
      int case1= solve(temp1,prev2,temp1[0],temp1.size()-1);
      int case2= solve(temp2,prev2,temp2[0],temp2.size()-1);
    return max(case1,case2);
    }
};