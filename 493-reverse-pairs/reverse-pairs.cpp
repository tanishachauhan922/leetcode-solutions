class Solution {
    private:
    void merge(vector<int>& nums,int low,int mid,int high){
        vector<int>temp;
        int leftst=low;
        int rightst=mid+1;
        int cnt=0;
        while(leftst<=mid && rightst<=high){
            if(nums[leftst]<=nums[rightst]){
                temp.push_back(nums[leftst++]);
            }
            else {
               
                temp.push_back(nums[rightst++]);
            }
        }
        while(leftst<=mid)    temp.push_back(nums[leftst++]);
        
                while(rightst<=high)    temp.push_back(nums[rightst++]);
        
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    
    }
    int count(vector<int>& nums,int low,int mid,int high){
       int cnt=0;
       int right=mid+1;
       for(int i=low;i<=mid;i++){
        while(right<=high && (nums[i]>((2LL)*nums[right])))  right++;
        cnt+=(right-(mid+1));
       }
       return cnt;
    }
    int mergesort(vector<int>& nums,int low,int high){
        int cnt=0;
        if(low>=high) return cnt;
        int mid=(low+high)/2;
        cnt+=mergesort(nums,low,mid);
        cnt+=mergesort(nums,mid+1,high);
        cnt+=count(nums,low,mid,high);
        merge(nums,low,mid,high); 
        return cnt; 
     }
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        
        int low=0,high=n-1;
        return mergesort(nums,low,high);
    }
};