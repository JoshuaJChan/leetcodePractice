class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s = "";
        int leng = word1.length();

        if(word1.length() < word2.length())
            leng = word2.length();

        for(int i = 0;i < leng;i++){
            if(i < word1.length())
                s += word1[i];
            if(i < word2.length())
                s += word2[i];
        }

        return s;
    }
};
