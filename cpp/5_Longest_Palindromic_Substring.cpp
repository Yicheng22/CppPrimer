#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int getLen(string &s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    }
    string longestPalindrome(string s) {
        const int size = s.length();
        
        int start(0) ,len(0);
        for (int i(0); i < size; ++i ) {
            int cur = max(getLen(s,i,i),getLen(s,i,i+1));
            if (cur > len) {
                len = cur;
                start = i - (len - 1)/2;
            }
        }
        return s.substr(start,len);
    }
};

int main()
{
    Solution sol;
    string s = {"bb"};
    cout << sol.longestPalindrome(s);
    return 0;
}