class Solution {
public:
    string reverseWords(string s) {
        int i = 0;

        while (s[i] == ' ') {
            i++;
        }
        s.erase(0, i);

        i = s.length() - 1;
        while (s[i] == ' ') {
            i--;
        }
        s.erase(i + 1, s.length() - i);

        for (int j = 0; j < s.length(); j++) {
            if (s[j] == ' ')
                if (s[j + 1] == ' ') {
                    s.erase(j, 1);
                    j--;
                }
        }

        for (int j = 0; j < s.length() / 2; j++) {
            swap(s[j], s[s.length() - 1 - j]);
        }

        int l = 0;
        for (int j = 0; j < s.length(); j++){
            if(s[j] == ' '){
                for(int k = 0;k<(j-l)/2;k++){
                    swap(s[l+k], s[j-1-k]);
                }
                if(s[j+1] != ' ')
                    l = j+1;
            }
            
        }
        for(int k = 0;k<(s.length()-l)/2;k++){
                    swap(s[l+k], s[s.length()-1-k]);
        }
        return s;
    }
};
