def twoSum(nums, target):
    num_map = {}
    for i in range(len(nums)):
        complement = target - nums[i]
        if complement in num_map:
            return [num_map[complement], i]
        num_map[nums[i]] = i
    return []

def testTwoSum(nums, target, expected, test_name):
    result = twoSum(nums, target)
    
    print(f"Test: {test_name}")
    print(f"Input: {nums}, target = {target}")
    print(f"Expected: {expected}")
    print(f"Result: {result}")
    
    passed = len(result) == 2 and result[0] == expected[0] and result[1] == expected[1]
    print(f"Status: {'PASSED' if passed else 'FAILED'}\n")
    return passed

def main():
    passed_count = 0
    total_tests = 15

    # Test 1
    nums1 = [2, 7, 11, 15]
    expected1 = [0, 1]
    passed_count += testTwoSum(nums1, 9, expected1, "Basic Case")

    # Test 2
    nums2 = [3, 3]
    expected2 = [0, 1]
    passed_count += testTwoSum(nums2, 6, expected2, "Duplicate Numbers")

    # Test 3
    nums3 = [1000000000, 9]
    expected3 = [0, 1]
    passed_count += testTwoSum(nums3, 1000000009, expected3, "Max Positive Numbers")

    # Test 4
    nums4 = [-1000000000, -1]
    expected4 = [0, 1]
    passed_count += testTwoSum(nums4, -1000000001, expected4, "Max Negative Numbers")

    # Test 5
    nums5 = [1000000000, 1000000000]
    expected5 = [0, 1]
    passed_count += testTwoSum(nums5, 2000000000, expected5, "Overflow Prevention")

    # Test 6
    nums6 = [-1000000000, 1000000000]
    expected6 = [0, 1]
    passed_count += testTwoSum(nums6, 0, expected6, "Extreme Values to Zero")

    # Test 7
    nums7 = [-1, -2, -3, -4]
    expected7 = [1, 2]
    passed_count += testTwoSum(nums7, -5, expected7, "Negative Numbers")

    # Test 8
    nums8 = [-5, 10, 3, -2]
    expected8 = [1, 3]
    passed_count += testTwoSum(nums8, 8, expected8, "Mixed Positive/Negative")

    # Test 9
    nums9 = [0, 5, 3, 0]
    expected9 = [0, 1]
    passed_count += testTwoSum(nums9, 5, expected9, "Zeros Included")

    # Test 10
    nums10 = [-3, -3, 4, 90]
    expected10 = [0, 1]
    passed_count += testTwoSum(nums10, -6, expected10, "Duplicate with Negative Target")

    # Test 11
    nums11 = [0] * 100
    nums11[98] = 1
    nums11[99] = 2
    expected11 = [98, 99]
    passed_count += testTwoSum(nums11, 3, expected11, "Large Array")

    # Test 12
    nums12 = [5, 1, 2, 3, 4]
    expected12 = [0, 4]
    passed_count += testTwoSum(nums12, 9, expected12, "Pair at Start and End")

    # Test 13
    nums13 = [1, 1, 1, 2, 1, 1, 3, 1]
    expected13 = [3, 6]
    passed_count += testTwoSum(nums13, 5, expected13, "Pair Among Duplicates")

    # Test 14
    nums14 = [10, 20, 30, -25]
    expected14 = [0, 3]
    passed_count += testTwoSum(nums14, -15, expected14, "Negative Target Positive Numbers")

    # Test 15
    nums15 = [1000000000, -1000000000, 5]
    expected15 = [1, 2]
    passed_count += testTwoSum(nums15, -999999995, expected15, "Precision Issues")

    print(f"Total Tests Passed: {passed_count} out of {total_tests}")

if __name__ == "__main__":
    main()