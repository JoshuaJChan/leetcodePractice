#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void reverseString(vector<char>& s) {
        char temp;
        for(int i = 0;i < s.size()/2;i++){
            temp = s[i];
            s[i] = s[s.size()-1-i];
            s[s.size()-1-i] = temp;
        }
    }
};

int main(){
    const char* str = "hello";
    vector<char> str2 = {'h','e','l','l','o'};
    
    Solution s;
    s.reverseString(str2);

    for(int i = 0;i < str2.size();i++)
            cout << str2[i];

    return 0;
}