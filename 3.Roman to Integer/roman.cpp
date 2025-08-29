#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        
        
        return 0;
    }
};



int main() {
    Solution sol;

    vector<string> tests     = {"III", "LVIII", "MCMXCIV"};
    vector<int> expected     = {3, 58, 1994};

    for (size_t i = 0; i < tests.size(); ++i) {
        int result = sol.romanToInt(tests[i]);
        cout << "Input: " << tests[i]
             << " | Expected: " << expected[i]
             << " | Obtained: " << result
             << "\n";
    }

    return 0;
}
