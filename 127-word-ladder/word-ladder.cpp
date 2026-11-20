class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len=0;
        queue<pair<string,int>>q;
        set<string>s;
        unordered_map<string,int>mp;
        int n=wordList.size();
        for(int i=0;i<n;i++){
             mp[wordList[i]]=1;
        }
        q.push({beginWord,1});
        s.insert({beginWord});
        string word=beginWord;
        if(mp.find(endWord)==mp.end()){ return 0; }
        int l=1;
        while(!q.empty() && word!=endWord){
             word=q.front().first;
             l=q.front().second;
            q.pop();
            for(int j=0;j<word.size();j++){
                string temp=word;
            for(char ch='a';ch<='z';ch++){
                temp[j]=ch;
                if(mp.find(temp)!=mp.end() && s.find(temp)==s.end()){
                    q.push({temp,l+1});
                    s.insert(temp);
                }
            }
        }
        }
        if(word==endWord) return l;
     return 0;
    }
};