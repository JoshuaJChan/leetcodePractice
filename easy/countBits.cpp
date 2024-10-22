class Solution {
public:
    vector<int> countBits(int n) {
        int digit;
        vector<int> ret(n + 1);

        for (int i = 0; i <= n; i++) {
            if (i == 0) { // catch 0 case where i & (i-1) works but does not
                          // make sense
                ret[0] = 0;
            } else if ((i & (i - 1)) ==
                       0) { // if have went to the next digit of binary,
                            // remember. o/w, have to calculate it which i did
                            // not do
                digit = i;
                ret[i] = 1;
            } else {
                ret[i] = 1 + ret[i - digit]; // used the pattern where the next digit is
                                    // added to the already discovered bits:
                                    // // one bit group
                                    //  0=   0(0)
                                    //  1=   1(1)
                                    // // two bits group
                                    //  2=  10(1) = 10(higest bit) + 0
                                    //  3=  11(2) = 10 + 1
                                    // // three bits group
                                    //  4= 100(1) = 100(higest bit) + 0
                                    //  5= 101(2) = 100 + 1
                                    //  6= 110(2) = 100 + 2
                                    //  7= 111(3) = 100 + 3
                                    // // four bits group
                                    //  8=1000(1)=1000(higest bit) + 0
                                    //  9=1001(2) = 1000 + 1
                                    // 10=1010(2) = 1000 + 2
                                    // 11=1011(3) = 1000 + 3
                                    // 12=1100(2) = 1000 + 4
                                    // 13=1101(3) = 1000 + 5
                                    // 14=1110(3) = 1000 + 6
                                    // 15=1111(4) = 1000 + 7
                                    // // five bits group
                                    // 16=10000(1)
            }
        }
        return ret;
    }
};
