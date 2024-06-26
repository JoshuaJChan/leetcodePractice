#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class palindrome
{
public:
    bool isPalindrome2(int x) {
        string s = to_string(x);
        string s2;

        for(int i = s.length()-1;i >= 0;i--){ // remember to start at one less
            s2 = s2 + s[i];
        }

        // for(int i = 0;i < s2.length();i++){ // found that there was an extra " " character
        //     cout << s2[i] << endl;
        // }
       
        // cout << "test" << s2.length() << "test" << endl;
        // cout << "test" << s.length() << "test" << endl;
        cout << s2.compare(s) << endl;

        if(s2.compare(s) == 0)
            return true;
        return false;
    }

    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        unsigned int flipped = 0, tempx = x;

        while(x != 0){            
            flipped = flipped * 10 + x % 10;
            x = x / 10;
        }
        return (tempx == flipped);
    }
};

int main()
{
    palindrome p;
    if(p.isPalindrome(121))
        cout << "palindrome";
    else
        cout << "no";

    return 0;
}