class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int anslen=0;
        int l=1;
        char ch=chars[0];
        int i=1;
        while(i<n){
            if(chars[i]==ch)l++;
            else{
                if(l==1)chars[anslen++]=ch;
                else{
                   chars[anslen++]=ch;
                  string temp=to_string(l);
                int j=0;
                while(j<temp.size()){
                    chars[anslen++]=temp[j++];
                }
                }
                ch=chars[i];
                l=1;
            }
            i++;
        }
        if(l==1)chars[anslen++]=ch;
                else{
                   chars[anslen++]=ch;
                string temp=to_string(l);
                int j=0;
                while(j<temp.size()){
                    chars[anslen++]=temp[j++];
                }
                }
                   return anslen;
    }
};