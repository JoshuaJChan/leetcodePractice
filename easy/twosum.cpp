#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution { 
public:
    //solution uses hash map which is O(n) complexity
    vector<int> twoSum(vector<int> nums, int target) {
        unordered_map<int, int> umap;
        vector<int> sub(nums.size());
        int sec;

        for(int i = 0;i < nums.size();i++){
            sec = target-nums[i];
            unordered_map<int,int>::const_iterator got = umap.find (sec);
            if ( got == umap.end() ){
                // cout << sec << " " << nums[i] << endl;
                umap[nums[i]] = i;
            }
            else
                return {i,umap.at(sec)};
        }
        // cout << endl;
        // for (auto i = umap.begin(); i != umap.end(); i++) 
        // cout << i->first << " " << i->second << endl;

        return {0,0};
    }
    //first submission. uses O(n(n+1)/2) or O(n^2) complexity
    vector<int> twoSumSLOW(vector<int>& nums, int target) {
        for(int i = nums.size()-1;i>0;i--){
            for(int j = i-1;j>=0;j--){
                if(nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {0,0};
    }

};

int main()
{
    vector<int> nums = {2,7,11,15};
    Solution s;

    nums = s.twoSum(nums,9);

    for (int  i: nums)
        cout << i << ' ';

    return 0;
}
