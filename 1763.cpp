class Solution {
public:
    string longestNiceSubstring(string s) {
        string output = "";
        int count = 0;
        for(int i = 0;i<s.length();i++){
            int smallMask=0;
            int largeMask = 0;
            char ch = s[i];
            int chint = 0;
            if(ch>=65 && ch<=90){
                chint = ch-'A';
                largeMask = 1<<chint;
            }
            else{
                chint = ch-'a';
                smallMask = 1<<chint;
            }
            for(int j = i+1;j<s.length();j++){
                ch = s[j];
                if(ch>=65 && ch<=90){
                    chint = ch-'A';
                    largeMask |= 1<<chint;
                }
                else{
                    chint = ch-'a';
                    smallMask |= 1<<chint;
                }
                //checking for nice
                if((smallMask^largeMask) == 0){
                    if(count<j-i+1){
                        count = j-i+1;
                        string temp(s.begin()+i,s.begin()+j+1);
                        output = temp;
                    }
                }
            }
        }
        return output;
    }
};



Input: "YazaAay"
  Output: "aAa"
