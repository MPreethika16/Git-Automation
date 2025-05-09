package tests;
import solutions.Solution; // Ensure this is present
import java.util.Arrays;


public class Test {
    public static Solution solution = new Solution();

    private static void testTwoSum(int[] nums, int target, int[] expected, String testName) {
        int[] result = solution.twoSum(nums, target);
        boolean passed = Arrays.equals(result, expected);
        
        System.out.println("Test: " + testName);
        System.out.println("Input: " + Arrays.toString(nums) + ", Target: " + target);
        System.out.println("Expected: " + Arrays.toString(expected));
        System.out.println("Result: " + Arrays.toString(result));
        System.out.println("Status: " + (passed ? "✅ PASSED" : "❌ FAILED"));
        System.out.println("------------------------------------");

        if (!passed) {
            System.out.println("⚠️  Debug Info: Possible issue with array indexing or target sum calculation.");
        }
    }

    public static void main(String[] args) {
        int passedCount = 0;
        final int totalTests = 11;

        // Running all test cases
        if (runTest(new int[]{2, 7, 11, 15}, 9, new int[]{0, 1}, "Basic Case")) passedCount++;
        if (runTest(new int[]{3, 3}, 6, new int[]{0, 1}, "Duplicate Numbers")) passedCount++;
        if (runTest(new int[]{1000000000, 9}, 1000000009, new int[]{0, 1}, "Max Positive Numbers")) passedCount++;
        if (runTest(new int[]{-1000000000, -1}, -1000000001, new int[]{0, 1}, "Max Negative Numbers")) passedCount++;
        if (runTest(new int[]{1000000000, 1000000000}, 2000000000, new int[]{0, 1}, "Overflow Prevention")) passedCount++;
        if (runTest(new int[]{-1000000000, 1000000000}, 0, new int[]{0, 1}, "Extreme Values To Zero")) passedCount++;
        if (runTest(new int[]{-1, -2, -3, -4}, -5, new int[]{1, 2}, "Negative Numbers")) passedCount++;
        if (runTest(new int[]{-5, 10, 3, -2}, 8, new int[]{1, 3}, "Mixed Positive/Negative")) passedCount++;
        if (runTest(new int[]{0, 5, 3, 0}, 5, new int[]{0, 1}, "Zeros Included")) passedCount++;
        if (runTest(new int[]{-3, -3, 4, 90}, -6, new int[]{0, 1}, "Duplicate With Negative Target")) passedCount++;
        if (runTest(new int[]{1, 2, 3, 4}, 10, new int[]{}, "No Solution Case")) passedCount++;  // New test case

        System.out.println("Summary: " + passedCount + "/" + totalTests + " tests passed.");
        // ✅ Proper exit code for CI
        if (passedCount != totalTests) {
            System.exit(1); // fail
        } else {
            System.exit(0); // pass
        }
    }

    private static boolean runTest(int[] nums, int target, int[] expected, String testName) {
        testTwoSum(nums, target, expected, testName);
        return Arrays.equals(solution.twoSum(nums, target), expected);
    }
}
