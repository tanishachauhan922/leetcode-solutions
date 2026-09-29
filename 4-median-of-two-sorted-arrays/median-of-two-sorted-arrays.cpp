class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
          int m=nums1.size();
          int n=nums2.size();
          int total=m+n;
          int mid=(total)/2;
          int indx1=mid;
          int indx2=mid-1;
          int cnt=0,prev=0;
          int ele2=0,ele1=0;
          int i=0,j=0;
          while(cnt<=mid && i<m && j<n){
            if(nums1[i]<nums2[j])    prev=nums1[i++];
            else prev=nums2[j++];
            if(cnt==indx1)ele1=prev; 
            if(cnt==indx2)ele2=prev; 
            cnt++;
          }
           while(cnt<=mid && i<m){
            prev=nums1[i++];
             if(cnt==indx1)ele1=prev; 
            if(cnt==indx2)ele2=prev; 
            cnt++;
          }
           while(cnt<=mid && j<n){
            prev=nums2[j++];
             if(cnt==indx1)ele1=prev; 
            if(cnt==indx2)ele2=prev; 
            cnt++;
          }
          if(total%2 !=0) return double(ele1);
          else return double((ele1+ele2)/2.0);
    }
};