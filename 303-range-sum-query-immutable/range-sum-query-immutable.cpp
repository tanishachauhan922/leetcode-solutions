class NumArray {
public:
 int sum=0;
     vector<int>s;
    NumArray(vector<int>& nums) {
        //creating the sum array
       s.resize(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            s[i]=sum;
        }
    }
    
    int sumRange(int left, int right) {
       if(left-1>=0) return s[right]-s[left-1];
       else return s[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */