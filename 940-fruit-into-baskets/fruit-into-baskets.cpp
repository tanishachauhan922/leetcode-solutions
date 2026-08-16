class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int>mp; //fruit,freq
        int l=0,r=0,cnt=0;
        int maxi=INT_MIN;
        while(r<n){
            mp[fruits[r]]++;
            cnt++;
            if(mp.size()<=2){
                maxi=max(maxi,cnt);
            }
            else{
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++;
                cnt--;
            }
            r++;
        }
        return maxi;
    }
};