#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "solution.h"

typedef struct {
    int key;
    int value;
} HashEntry;

typedef struct {
    HashEntry* entries;
    int size;
    int capacity;
} HashMap;

HashMap* createHashMap(int capacity) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->entries = (HashEntry*)malloc(capacity * sizeof(HashEntry));
    map->size = 0;
    map->capacity = capacity;
    return map;
}

void put(HashMap* map, int key, int value) {
    map->entries[map->size].key = key;
    map->entries[map->size].value = value;
    map->size++;
}

int* find(HashMap* map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            return &map->entries[i].value;
        }
    }
    return NULL;
}

void freeHashMap(HashMap* map) {
    free(map->entries);
    free(map);
}

int* twoSum(int* nums, int numsSize, int target) {
    HashMap* numMap = createHashMap(numsSize);
    int* result = (int*)malloc(2 * sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int* found = find(numMap, complement);
        if (found != NULL) {
            result[0] = *found;
            result[1] = i;
            freeHashMap(numMap);
            return result;
        }
        put(numMap, nums[i], i);
    }
    
    freeHashMap(numMap);
    return NULL;
}

bool testTwoSum(int* nums, int numsSize, int target, int* expected, const char* testName) {
    int* result = twoSum(nums, numsSize, target);
    
    printf("Test: %s\n", testName);
    printf("Input: [");
    for (int i = 0; i < numsSize; i++) {
        printf("%d%s", nums[i], i < numsSize - 1 ? "," : "");
    }
    printf("], target = %d\n", target);
    
    printf("Expected: [%d,%d]\n", expected[0], expected[1]);
    printf("Result: [%d,%d]\n", result[0], result[1]);
    
    bool passed = (result != NULL && result[0] == expected[0] && result[1] == expected[1]);
    printf("Status: %s\n\n", passed ? "PASSED" : "FAILED");
    
    free(result);
    return passed;
}

int main() {
    int passedCount = 0;
    const int totalTests = 15;

    // Test 1
    int nums1[] = {2, 7, 11, 15};
    int expected1[] = {0, 1};
    passedCount += testTwoSum(nums1, 4, 9, expected1, "Basic Case");

    // Test 2
    int nums2[] = {3, 3};
    int expected2[] = {0, 1};
    passedCount += testTwoSum(nums2, 2, 6, expected2, "Duplicate Numbers");

    // Test 3
    int nums3[] = {1000000000, 9};
    int expected3[] = {0, 1};
    passedCount += testTwoSum(nums3, 2, 1000000009, expected3, "Max Positive Numbers");

    // Test 4
    int nums4[] = {-1000000000, -1};
    int expected4[] = {0, 1};
    passedCount += testTwoSum(nums4, 2, -1000000001, expected4, "Max Negative Numbers");

    // Test 5
    int nums5[] = {1000000000, 1000000000};
    int expected5[] = {0, 1};
    passedCount += testTwoSum(nums5, 2, 2000000000, expected5, "Overflow Prevention");

    // Test 6
    int nums6[] = {-1000000000, 1000000000};
    int expected6[] = {0, 1};
    passedCount += testTwoSum(nums6, 2, 0, expected6, "Extreme Values to Zero");

    // Test 7
    int nums7[] = {-1, -2, -3, -4};
    int expected7[] = {1, 2};
    passedCount += testTwoSum(nums7, 4, -5, expected7, "Negative Numbers");

    // Test 8
    int nums8[] = {-5, 10, 3, -2};
    int expected8[] = {1, 3};
    passedCount += testTwoSum(nums8, 4, 8, expected8, "Mixed Positive/Negative");

    // Test 9
    int nums9[] = {0, 5, 3, 0};
    int expected9[] = {0, 1};
    passedCount += testTwoSum(nums9, 4, 5, expected9, "Zeros Included");

    // Test 10
    int nums10[] = {-3, -3, 4, 90};
    int expected10[] = {0, 1};
    passedCount += testTwoSum(nums10, 4, -6, expected10, "Duplicate with Negative Target");

    // Test 11
    int nums11[100] = {0};
    nums11[98] = 1;
    nums11[99] = 2;
    int expected11[] = {98, 99};
    passedCount += testTwoSum(nums11, 100, 3, expected11, "Large Array");

    // Test 12
    int nums12[] = {5, 1, 2, 3, 4};
    int expected12[] = {0, 4};
    passedCount += testTwoSum(nums12, 5, 9, expected12, "Pair at Start and End");

    // Test 13
    int nums13[] = {1, 1, 1, 2, 1, 1, 3, 1};
    int expected13[] = {3, 6};
    passedCount += testTwoSum(nums13, 8, 5, expected13, "Pair Among Duplicates");

    // Test 14
    int nums14[] = {10, 20, 30, -25};
    int expected14[] = {0, 3};
    passedCount += testTwoSum(nums14, 4, -15, expected14, "Negative Target Positive Numbers");

    // Test 15
    int nums15[] = {1000000000, -1000000000, 5};
    int expected15[] = {1, 2};
    passedCount += testTwoSum(nums15, 3, -999999995, expected15, "Precision Issues");

    printf("Total Tests Passed: %d out of %d\n", passedCount, totalTests);
    return 0;
}