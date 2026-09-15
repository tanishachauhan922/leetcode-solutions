class Solution {
public:
    int trap(vector<int>& height) {
         int n=height.size();
         int l=0,r=n-1;
         int leftmax=0;
         int rightmax=0;
         int water=0;
         while(l<r){
              if(height[l]<height[r]){
                if(height[l]<leftmax)water+=(leftmax-height[l]);
                else    leftmax=height[l];
                    l++;
              }
              else{
                if(height[r]<rightmax)water+=(rightmax-height[r]);
                else    rightmax=height[r];
                    r--;
              }
         }
         return water;
    }
};