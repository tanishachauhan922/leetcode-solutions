class Solution {
    private:
    bool check(long long mid,vector<int>& piles,int h){
        long long tempans=0;
        for(int i=0;i<piles.size();i++){
            double c=double(piles[i])/mid;
          tempans+=ceil(c);
        }
        if(tempans<=h)return true;
        else return false;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long n=piles.size();
        long long st=1;
        long long e=1;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(piles[i]>e)e=piles[i];
        }
        while(st<=e){
            int mid=(st+e)/2;
            if(check(mid,piles,h)){
                ans=mid;
                e=mid-1;
            }
            else st=mid+1;
        }
        return ans;
    }
};