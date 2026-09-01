class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        if(n1!=n2) return false;
        vector<int>freq(26,0);
        for(int i=0;i<n1;i++){
            int index =s[i]-'a';
            freq[index]++;
        }
         for(int i=0;i<n2;i++){
            int index =t[i]-'a';
            freq[index]--;
        }
        for(int i=0;i<26;i++){
            if(freq[i]!=0) return false;
        }
        return true;
    }
};