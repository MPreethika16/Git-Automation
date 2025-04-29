
import sys
import os

# Add the solutions folder to the system path
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "../solutions")))
from solution import Solution  # Now it should work


def testTwoSum(nums, target, expected, test_name):
    solution = Solution()  # Instantiate Solution class
    result = solution.twoSum(nums, target)

    print(f"Test: {test_name}")
    print(f"Input: {nums}, target = {target}")
    print(f"Expected: {expected}")
    print(f"Result: {result}")

    passed = len(result) == 2 and result[0] == expected[0] and result[1] == expected[1]
    print(f"Status: {'PASSED' if passed else 'FAILED'}\n")
    return passed

def main():
    passed_count = 0
    total_tests = 10

    passed_count += testTwoSum([2, 7, 11, 15], 9, [0, 1], "Basic Case")
    passed_count += testTwoSum([3, 3], 6, [0, 1], "Duplicate Numbers")
    passed_count += testTwoSum([1000000000, 9], 1000000009, [0, 1], "Max Positive Numbers")
    passed_count += testTwoSum([-1000000000, -1], -1000000001, [0, 1], "Max Negative Numbers")
    passed_count += testTwoSum([1000000000, 1000000000], 2000000000, [0, 1], "Overflow Prevention")
    passed_count += testTwoSum([-1000000000, 1000000000], 0, [0, 1], "Extreme Values to Zero")
    passed_count += testTwoSum([-1, -2, -3, -4], -5, [1, 2], "Negative Numbers")
    passed_count += testTwoSum([-5, 10, 3, -2], 8, [1, 3], "Mixed Positive/Negative")
    passed_count += testTwoSum([0, 5, 3, 0], 5, [0, 1], "Zeros Included")
    passed_count += testTwoSum([-3, -3, 4, 90], -6, [0, 1], "Duplicate with Negative Target")

    print(f"Total Tests Passed: {passed_count} out of {total_tests}")
    if passed_count != total_tests:
        print("Exiting with failure code (1)")
        sys.exit(1)  # Ensure the process exits with a non-zero code if tests fail

if __name__ == "__main__":
    main()
