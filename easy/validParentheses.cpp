#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        char c;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            else if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                if(stk.empty())
                    return false;
                c = stk.top(); stk.pop();
                if(s[i] == ')' && c != '(' || s[i] == ']' && c != '[' || s[i] == '}' && c != '{')
                    return false;
            }
        }
        if(stk.empty())
            return true;
        return false;
    }

     //this solution allows unordered parentheses in the string
    int pa,sq,cu;
    void check(char c) {
        switch (c){
                case '(':pa++; break;
                case '[':sq++;break;
                case '{':cu++;break;
                case ')':pa--;break;
                case ']': sq--;break;
                case '}':cu--;break;
            }
    }
    bool isValid2(string s) {
        for(int i = 0;i<s.size();i++){
            check(s[i]);
            if(pa<0 || sq<0 ||cu<0)
                return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    cout << s.isValid("]");

    return 0;
}