class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
          int n1=nums1.size();
          int n2=nums2.size();
          int n=n1+n2;
          int i=0,j=0,k=0;
          int ele1indx=n/2;
          int ele2indx=(n-1)/2;
          double ele2=-1;
          double ele1=-1;
          while(i<n1 && j<n2 && k<n){
                if(nums1[i]<nums2[j]){
                    if(k==ele1indx)    ele1=nums1[i];
                   if(k==ele2indx)    ele2=nums1[i];
                    i++;
                    k++;
                }  
                else{
                      if(k==ele1indx)    ele1=nums2[j];
                       if(k==ele2indx)    ele2=nums2[j];
                    j++;
                    k++;
                }  
          }
          while(i<n1 && k<n){
             if(k==ele1indx)    ele1=nums1[i];
                    if(k==ele2indx)    ele2=nums1[i];
                    i++;
                    k++;
          }
           while(j<n2 && k<n){
             if(k==ele1indx)    ele1=nums2[j];
                   if(k==ele2indx)    ele2=nums2[j];
                    j++;
                    k++;
          }
          if(n%2==0) return (ele1+ele2)/2.0;
          else return ele1;
       
    }
};