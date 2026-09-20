class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>>ans;
        map<string,vector<int>>mp;
        for(int i=0;i<n;i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
           mp[temp].push_back(i);
        }
        for(auto it :mp){
            vector<string>temp;
            for(int i=0;i<it.second.size();i++)  temp.push_back(strs[it.second[i]]);
             ans.push_back(temp);
        }
       return ans;
    }
};