#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:

    // O(d) space and O(d) time
    bool isPalindromeString(int x) {

        if ( x < 0) return false ; 

        // convert int to string
        string s = to_string(x);  
        int i = 0;
        int j = s.size() - 1; // 
        while(i<j){
            if(s[i] != s[j]){return false;}
            i++;
            j--;
        }
        return true;

    }
    // O(d) time and O(1) extra space, where d is the number of digits.
    bool isPalindromeNoString(int x) {
    
        // numbers ending in 0 but not 0 itself or negative.
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }

        int reversedHalf = 0; // will hold the reverse of the right half of x

        while (x > reversedHalf) {
            // Append last digit of x to reversedHalf
            reversedHalf = reversedHalf * 10 + (x % 10);
            // Remove last digit from x
            x /= 10;
        }
        return (x == reversedHalf) || (x == reversedHalf / 10);
    }

    bool isPalindromeGreat(int x){
        if(x < 0) return false;
        int y = x;
        long reverse = 0;

        while (y > 0) {
            // copy reversed x
            reverse = reverse * 10 + y % 10;
            y /= 10;
        }

        return reverse == x;
  }

};

int main() {
    Solution s;

    vector<int> tests = {121, -121, 10, 1331, 12321, 0};
    vector<bool> expected = {true, false, false, true, true, true};

    for (size_t i = 0; i < tests.size(); i++) {
        bool result = s.isPalindromeNoString(tests[i]);
        cout << "Input: " << tests[i] 
             << " | Expected: " << (expected[i] ? "true" : "false")
             << " | Obtained: " << (result ? "true" : "false") 
             << "\n";
    };

    return 0;
};
