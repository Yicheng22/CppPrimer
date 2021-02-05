#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;                                                                    
        //the number of changes
        for(int i = 1; i < nums.size() && cnt<=1 ; i++){
            if(nums[i-1] > nums[i]){
                cnt++;
                if(i<2 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];                    
                //modify nums[i-1] of a priority
                else 
                    nums[i] = nums[i-1];                                                
                //have to modify nums[i]
            }
        }
        return cnt<=1;
    } 
};

int main() 
{
    Solution sol;
    vector<int> v{3,4,2,3};
    if (sol.checkPossibility(v))
        cout << "true";
    else
        cout << "false";
    return 0;
}