#include <iostream>
#include <vector>
#include "../solutions/solution.cpp"  // Include the actual solution file

using namespace std;

bool testTwoSum(vector<int> nums, int target, vector<int> expected, string test_name) {
    Solution solution;  // Instantiate Solution class
    vector<int> result = solution.twoSum(nums, target);

    cout << "Test: " << test_name << endl;
    cout << "Input: [";
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i] << (i < nums.size() - 1 ? ", " : "");
    }
    cout << "], target = " << target << endl;

    cout << "Expected: [" << expected[0] << ", " << expected[1] << "]" << endl;
    cout << "Result: [";
    if (!result.empty()) {
        cout << result[0] << ", " << result[1];
    }
    cout << "]" << endl;

    bool passed = (result.size() == 2 && result[0] == expected[0] && result[1] == expected[1]);
    cout << "Status: " << (passed ? "PASSED" : "FAILED") << "\n" << endl;

    return passed;
}

int main() {
    int passed_count = 0;
    int total_tests = 10;

    passed_count += testTwoSum({2, 7, 11, 15}, 9, {0, 1}, "Basic Case");
    passed_count += testTwoSum({3, 3}, 6, {0, 1}, "Duplicate Numbers");
    passed_count += testTwoSum({1000000000, 9}, 1000000009, {0, 1}, "Max Positive Numbers");
    passed_count += testTwoSum({-1000000000, -1}, -1000000001, {0, 1}, "Max Negative Numbers");
    passed_count += testTwoSum({1000000000, 1000000000}, 2000000000, {0, 1}, "Overflow Prevention");
    passed_count += testTwoSum({-1000000000, 1000000000}, 0, {0, 1}, "Extreme Values to Zero");
    passed_count += testTwoSum({-1, -2, -3, -4}, -5, {1, 2}, "Negative Numbers");
    passed_count += testTwoSum({-5, 10, 3, -2}, 8, {1, 3}, "Mixed Positive/Negative");
    passed_count += testTwoSum({0, 5, 3, 0}, 5, {0, 1}, "Zeros Included");
    passed_count += testTwoSum({-3, -3, 4, 90}, -6, {0, 1}, "Duplicate with Negative Target");

    cout << "Total Tests Passed: " << passed_count << " out of " << total_tests << endl;
    return 0;
}
