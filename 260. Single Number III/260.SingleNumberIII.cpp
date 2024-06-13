#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int val = nums[0];
        for(int i = 1; i < nums.size(); i++){
            val = val ^ nums[i];
        }
        
        int i = 0;
        while(!(1&(val >> i))){
            i++;
        }

        int a = 0, b = 0;
        for(auto val : nums){
            if(((val >> i)&1) == 0){
                a ^= val;
            }
            else{
                b ^= val;
            }
        }

        vector<int> result;
        result.push_back(a);
        result.push_back(b);
        return result;
    }
};

int main()
{

    Solution sol;
    vector<int> nums1 = {1,2,1,3,2,5};
    vector<int> nums2 = {-1,0};
    vector<int> nums3 = {0,1};
    for(auto i : sol.singleNumber(nums1)){
        cout << i << " ";
    }
    cout << endl;
    for(auto i : sol.singleNumber(nums2)){
        cout << i << " ";
    }
    cout << endl;
    for(auto i : sol.singleNumber(nums3)){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}