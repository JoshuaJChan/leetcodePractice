#include <iostream>
#include <string>
#include <unordered_map> 

using namespace std;

class Solution{
public:
    int romanToInt(string s) {
        int sum = 0;
        for(int i = 0;i<s.size();i++){
            if (s[i] == 'I')
                if(i != s.size()-1)
                    if(s[i+1] == 'V'){
                        sum += 4;
                        i++;
                    }
                    else if(s[i+1] == 'X'){
                        sum += 9;
                        i++;
                    }
                    else
                        sum += 1;
                else
                    sum += 1;
            else if (s[i] == 'V')
                sum += 5;
            else if (s[i] == 'X')
                if(i != s.size()-1)
                    if(s[i+1] == 'L'){
                        sum += 40;
                        i++;
                    }
                    else if(s[i+1] == 'C'){
                        sum += 90;
                        i++;
                    }
                    else
                        sum += 10;
                else
                    sum += 10;
            else if (s[i] == 'L')
                sum += 50;
            else if (s[i] == 'C')
                if(i != s.size()-1)
                    if(s[i+1] == 'D'){
                        sum += 400;
                        i++;
                    }
                    else if(s[i+1] == 'M'){
                        sum += 900;
                        i++;
                    }
                    else
                        sum += 100;
                else
                    sum += 100;
            else if (s[i] == 'D')
                sum += 500;
            else if (s[i] == 'M')
                sum += 1000;
        }
        return sum;
    }

    int romanToInt2(string s) {
        int sum = 0;
        unordered_map <char,int> hash{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

        for(int i = 0;i < s.size();i++){
            if(hash[s[i]] < hash[s[i+1]]){
                sum += hash[s[i+1]] - hash[s[i]];
                i++;
            }
            else
                sum += hash[s[i]];
        }
        return sum;
    }
};

int main()
{
    Solution s;
    cout << s.romanToInt2("MCMXCIV");
    return 0;
}