#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:

    // O(n²) solution - brute force

    vector<int> twoSumGood(vector<int>& nums, int target) {
        int n = nums.size();
        // run the vector
        for(int i = 0; i < n; i++ ){
            // for each number, run the vector
            for(int j = i+1; j< n;j++){
                int sum = nums[i] + nums[j];
                if (sum == target){
                    vector<int> res = {i,j};
                    return res;
                }
            }
        }
        return {};
    }

    // O(n) solution - hash map
    vector<int> twoSumGreat(vector<int>& nums, int target){
        unordered_map<int,int> hashmap; // {number,index}
        int n = nums.size();
        for(int i = 0; i< n; i++){
            int complement = target - nums[i]; 
            
            // .find() returns an iterator that points to 
            // the pair {number,index} if it exists,
            // or points to .end()

            auto it = hashmap.find(complement);
            if(it != hashmap.end()){
                return {it -> second,i };
            }
            // key = nums[i], value = i; {number, index}
            hashmap.insert({nums[i],i});
        }
        return {};
    }
        
    
};


int main() {
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> expected = {0,1};

    vector<int> result1= s.twoSumGood(nums, target);
    vector<int> result2= s.twoSumGreat(nums, target);
    std::cout << "Expected value: " << "[" << expected[0] << ", " << expected[1] << "]\n";
    std::cout << "Obtained Value - good case: " << "[" << result1[0] << ", " << result1[1] << "]\n"; 
    std::cout << "Obtained Value - great case" << "[" << result2[0] << ", " << result2[1] << "]\n"; 
    return 0;
}