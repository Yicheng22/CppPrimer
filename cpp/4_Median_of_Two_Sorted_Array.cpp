#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) //ensure m <= n
            return findMedianSortedArrays(nums2,nums1);
        
        // binary search the position
        int iMin = 0, iMax = m, halfLen = (m+n+1)/2;
        while (iMin <= iMax) {
            int i = (iMax + iMin) / 2; // prevent overflow
            int j = halfLen - i;
            if (i < m && nums2[j-1] > nums1[i]) {
                iMin = i + 1; // i too small
            } else if (i > 0 && nums1[i-1] > nums2[j]) {
                iMax = i - 1; // i is too big
            } else{ // i met the conditions
                int maxLeft(0);
                if (i==0) maxLeft = nums2[j-1];
                else if (j == 0) maxLeft = nums1[i-1];
                else maxLeft = max(nums1[i-1], nums2[j-1]); 
                if ( (m + n) % 2 == 1 )  return maxLeft;  // m+n odd

                int minRight(0);
                if (i == m)  minRight = nums2[j];
                else if (j == n) minRight = nums1[i];
                else minRight = min(nums2[j], nums1[i]);
                                
                return (maxLeft + minRight) / 2.0;                
            }
        }
        return 0.0;
    }
};


int main()
{
    Solution sol;
    vector<int> nums1 = {1,2,4,5};
    vector<int> nums2 = {3,4,7,8};

    cout << sol.findMedianSortedArrays(nums1,nums2)<<endl;
    return 0;
}