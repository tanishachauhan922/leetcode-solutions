class Solution {
    private:
    int  findpi(vector<int>& nums,int left,int right){
        int pivot=nums[right];
        int i=left;
        for(int j=left;j<right;j++){
            if(nums[j]<pivot){
                swap(nums[j],nums[i]);
                i++;
            }
        }
        swap(nums[i],nums[right]);
         return i;
    }

  int  quickselect(vector<int>& nums,int left,int right,int target){
        int pivotindex=findpi(nums,left,right);
        if(target==pivotindex) return nums[pivotindex];
        else if(target>pivotindex){
          return  quickselect(nums,pivotindex+1,right,target);
        }
        else return  quickselect(nums,left,pivotindex-1,target);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int target=n-k;
        return quickselect(nums,0,n-1,target);
    }
};