#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;

        int count = 0, curr = nums[0];

        for(int i = 0;i<nums.size();i++){
            if(curr != nums[i]){
                count++;
                nums[count] = nums[i];
                curr = nums[i];
            }
        }
        // for(int i = 0;i<nums.size();i++){
        //     cout << "num:" << nums[i] << endl;
            
        // }
        return count+1;
    }
};

int main(){
    vector<int> arr = {1,1,2,4};
    
    Solution s;
    int k = s.removeDuplicates(arr);

    for(int i = 0;i<k;i++){
            cout << "num:" << arr[i] << endl;
    }

    return 0;
}