#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Hash map entry structure
typedef struct {
    int key;
    int value;
} HashMapEntry;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    HashMapEntry* map = (HashMapEntry*)malloc(numsSize * sizeof(HashMapEntry));
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        long long int complement = (long long)target - nums[i];

        for (int j = 0; j < count; j++) {
            if (map[j].key == complement) {
                result[0] = map[j].value;
                result[1] = i;
                free(map);
                return result;
            }
        }

        map[count].key = nums[i];
        map[count].value = i;
        count++;
    }

    free(map);
    free(result);
    return NULL;
}

// Test function
bool testTwoSum(int* nums, int numsSize, int target, int* expected, const char* testName) {
    int returnSize;  
    int* result = twoSum(nums, numsSize, target, &returnSize);

    printf("Test: %s\n", testName);
    printf("Input: [");
    for (int i = 0; i < numsSize; i++) {
        printf("%d%s", nums[i], i < numsSize - 1 ? ", " : "");
    }
    printf("] Target: %d\n", target);

    if (result == NULL) {
        printf("Expected: NULL\nResult: NULL\nStatus: PASSED\n\n");
        return expected == NULL;
    }

    printf("Expected: [%d, %d]\n", expected[0], expected[1]);
    printf("Result: [%d, %d]\n", result[0], result[1]);

    bool passed = (result[0] == expected[0] && result[1] == expected[1]) ||
                  (result[0] == expected[1] && result[1] == expected[0]);
    printf("Status: %s\n\n", passed ? "PASSED" : "FAILED");

    free(result);
    return passed;
}