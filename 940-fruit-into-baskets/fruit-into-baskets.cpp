class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int maxi=0;
        int f=0,cnt=0;
        int i=0,j=0;
        unordered_map<int,int>mp;
        while(i<n){
            // if(mp.find(fruits[i])==mp.end() && cnt<2){
            //     cnt++;
            // }
              if(cnt>2){
                mp[fruits[j]]--;
                if(mp[fruits[j]]==0){
                mp.erase(fruits[j]);
                cnt--;
                }
                f--;
                j++;
              }
               if(mp.find(fruits[i])==mp.end())cnt++;
              mp[fruits[i]]++;
              f++;
            
             if(cnt<=2)maxi=max(maxi,f);
             i++;
            }
        
        return maxi;
    }
};