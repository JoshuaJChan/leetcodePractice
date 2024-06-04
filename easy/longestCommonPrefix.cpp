#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common;
        for(int i = 0;i<strs[0].size();i++){
            for(int j = 0;j<strs.size();j++){
                if(strs[0][i] != strs[j][i])
                    return common;
            }
            common += strs[0][i];
        }
        return common;
    }
};

int main(){
    Solution s;
    vector<string> strs = {"flower","flow","flight"};
    cout << s.longestCommonPrefix(strs);

    return 0;
}