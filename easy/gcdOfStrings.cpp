class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int len = str1.length();
        string s = "", sub;
        int flag = 0;

        if(str1.length() > str2.length())
            len = str2.length();

        for(int i = 1;i<len+1;i++){
            if(str1.length() % i == 0 && str2.length() % i == 0){
                sub = str1.substr(0,i);
                for(int j = 0;j<str1.length();j+=i){
                    if(str1.substr(j,i) != sub)
                        flag = 1;
                }
                for(int j = 0;j<str2.length();j+=i){
                    if(str2.substr(j,i) != sub)
                        flag = 1;
                }
                if(flag == 0)
                    s = sub;
                flag = 0;
            }
        }
        return s;
    }
    string gcdOfStrings2(string str1, string str2) { // better solution
        if(str1 + str2 != str2 + str1) //check if a gcd substring is even possible
            return (str1)
        return str1.substr(0, gcd(str1.size(), str2.size()));   //if yes, then just get gcd of lengths, and get
                                                                //the substring using that
    }
};
