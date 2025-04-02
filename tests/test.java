import java.util.HashMap;
import java.util.Arrays;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> numMap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (numMap.containsKey(complement)) {
                return new int[] {numMap.get(complement), i};
            }
            numMap.put(nums[i], i);
        }
        return new int[] {};
    }
}

class Main {
    static boolean testTwoSum(int[] nums, int target, int[] expected, String testName) {
        Solution solution = new Solution();
        int[] result = solution.twoSum(nums, target);
        
        System.out.println("Test: " + testName);
        System.out.println("Input: " + Arrays.toString(nums) + ", target = " + target);
        System.out.println("Expected: " + Arrays.toString(expected));
        System.out.println("Result: " + Arrays.toString(result));
        
        boolean passed = result.length == 2 && result[0] == expected[0] && result[1] == expected[1];
        System.out.println("Status: " + (passed ? "PASSED" : "FAILED") + "\n");
        return passed;
    }

    public static void main(String[] args) {
        int passedCount = 0;
        final int totalTests = 15;

        // Test 1
        int[] nums1 = {2, 7, 11, 15};
        int[] expected1 = {0, 1};
        passedCount += testTwoSum(nums1, 9, expected1, "Basic Case") ? 1 : 0;

        // Test 2
        int[] nums2 = {3, 3};
        int[] expected2 = {0, 1};
        passedCount += testTwoSum(nums2, 6, expected2, "Duplicate Numbers") ? 1 : 0;

        // Test 3
        int[] nums3 = {1000000000, 9};
        int[] expected3 = {0, 1};
        passedCount += testTwoSum(nums3, 1000000009, expected3, "Max Positive Numbers") ? 1 : 0;

        // Test 4
        int[] nums4 = {-1000000000, -1};
        int[] expected4 = {0, 1};
        passedCount += testTwoSum(nums4, -1000000001, expected4, "Max Negative Numbers") ? 1 : 0;

        // Test 5
        int[] nums5 = {1000000000, 1000000000};
        int[] expected5 = {0, 1};
        passedCount += testTwoSum(nums5, 2000000000, expected5, "Overflow Prevention") ? 1 : 0;

        // Test 6
        int[] nums6 = {-1000000000, 1000000000};
        int[] expected6 = {0, 1};
        passedCount += testTwoSum(nums6, 0, expected6, "Extreme Values to Zero") ? 1 : 0;

        // Test 7
        int[] nums7 = {-1, -2, -3, -4};
        int[] expected7 = {1, 2};
        passedCount += testTwoSum(nums7, -5, expected7, "Negative Numbers") ? 1 : 0;

        // Test 8
        int[] nums8 = {-5, 10, 3, -2};
        int[] expected8 = {1, 3};
        passedCount += testTwoSum(nums8, 8, expected8, "Mixed Positive/Negative") ? 1 : 0;

        // Test 9
        int[] nums9 = {0, 5, 3, 0};
        int[] expected9 = {0, 1};
        passedCount += testTwoSum(nums9, 5, expected9, "Zeros Included") ? 1 : 0;

        // Test 10
        int[] nums10 = {-3, -3, 4, 90};
        int[] expected10 = {0, 1};
        passedCount += testTwoSum(nums10, -6, expected10, "Duplicate with Negative Target") ? 1 : 0;

        // Test 11
        int[] nums11 = new int[100];
        nums11[98] = 1;
        nums11[99] = 2;
        int[] expected11 = {98, 99};
        passedCount += testTwoSum(nums11, 3, expected11, "Large Array") ? 1 : 0;

        // Test 12
        int[] nums12 = {5, 1, 2, 3, 4};
        int[] expected12 = {0, 4};
        passedCount += testTwoSum(nums12, 9, expected12, "Pair at Start and End") ? 1 : 0;

        // Test 13
        int[] nums13 = {1, 1, 1, 2, 1, 1, 3, 1};
        int[] expected13 = {3, 6};
        passedCount += testTwoSum(nums13, 5, expected13, "Pair Among Duplicates") ? 1 : 0;

        // Test 14
        int[] nums14 = {10, 20, 30, -25};
        int[] expected14 = {0, 3};
        passedCount += testTwoSum(nums14, -15, expected14, "Negative Target Positive Numbers") ? 1 : 0;

        // Test 15
        int[] nums15 = {1000000000, -1000000000, 5};
        int[] expected15 = {1, 2};
        passedCount += testTwoSum(nums15, -999999995, expected15, "Precision Issues") ? 1 : 0;

        System.out.println("Total Tests Passed: " + passedCount + " out of " + totalTests);
    }
}