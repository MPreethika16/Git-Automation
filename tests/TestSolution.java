import java.util.Arrays;

public class TestSolution {
    private static final Solution solution = new Solution();

    private static void testTwoSum(int[] nums, int target, int[] expected, String testName) {
        int[] result = solution.twoSum(nums, target);
        boolean passed = Arrays.equals(result, expected);
        
        System.out.println("Test: " + testName);
        System.out.println("Input: " + Arrays.toString(nums) + ", Target: " + target);
        System.out.println("Expected: " + Arrays.toString(expected));
        System.out.println("Result: " + Arrays.toString(result));
        System.out.println("Status: " + (passed ? "PASSED" : "FAILED"));
        System.out.println("------------------------------------");
    }

    public static void main(String[] args) {
        int passedCount = 0;
        final int totalTests = 10;
        
        // Running all test cases
        testTwoSum(new int[]{2, 7, 11, 15}, 9, new int[]{0, 1}, "Basic Case");
        testTwoSum(new int[]{3, 3}, 6, new int[]{0, 1}, "Duplicate Numbers");
        testTwoSum(new int[]{1000000000, 9}, 1000000009, new int[]{0, 1}, "Max Positive Numbers");
        testTwoSum(new int[]{-1000000000, -1}, -1000000001, new int[]{0, 1}, "Max Negative Numbers");
        testTwoSum(new int[]{1000000000, 1000000000}, 2000000000, new int[]{0, 1}, "Overflow Prevention");
        testTwoSum(new int[]{-1000000000, 1000000000}, 0, new int[]{0, 1}, "Extreme Values To Zero");
        testTwoSum(new int[]{-1, -2, -3, -4}, -5, new int[]{1, 2}, "Negative Numbers");
        testTwoSum(new int[]{-5, 10, 3, -2}, 8, new int[]{1, 3}, "Mixed Positive/Negative");
        testTwoSum(new int[]{0, 5, 3, 0}, 5, new int[]{0, 1}, "Zeros Included");
        testTwoSum(new int[]{-3, -3, 4, 90}, -6, new int[]{0, 1}, "Duplicate With Negative Target");
    }
}