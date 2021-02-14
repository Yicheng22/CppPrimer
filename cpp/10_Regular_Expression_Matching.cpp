#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, false));
        dp[s.length()][p.length()] = true;
        
        for (int i = s.length(); i >= 0; i--){
            for (int j = p.length() - 1; j >= 0 ; j--) {
                bool first_match = (i < s.length() && (p.at(j) == s.at(i) || p.at(j) == '.'));
                if (j + 1 < p.length() && p.at(j+1) == '*') {
                    dp[i][j] = dp[i][j+2] || first_match && dp[i+1][j];
                } else {
                    dp[i][j] = first_match && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};

int main()
{
    Solution sol;
    string s{"aab"}, p{"c*a*b"};
    if (sol.isMatch(s,p))
        cout << "Match" << endl;
    else
        cout << "Not match." << endl;
    return 0;
}