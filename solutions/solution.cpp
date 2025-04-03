#include <vector>
#include <unordered_map>
  

using namespace std;
  
class Solution {
public: 
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> map;
        for (size_t i = 0; i < nums.size(); i++) {
            int rem = target - nums[i];
            if (map.find(rem) != map.end()) {
                return {map[rem], static_cast<int>(i)};

            }
            map[nums[i]] = i;
        }
        return {};
    }
};
