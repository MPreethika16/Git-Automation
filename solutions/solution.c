#include "solution.h"
#include <stdlib.h>
#include <stdio.h>

// HashMap Structure
typedef struct {
    int key;
    int value;
} HashEntry;

typedef struct {
    HashEntry* entries;
    int size;
    int capacity;
} HashMap;

// Function to create hash map
HashMap* createHashMap(int capacity) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->entries = (HashEntry*)malloc(capacity * sizeof(HashEntry));
    map->size = 0;
    map->capacity = capacity;
    return map;
}

// Function to add an entry to hash map
void put(HashMap* map, int key, int value) {
    map->entries[map->size].key = key;
    map->entries[map->size].value = value;
    map->size++;
}

// Function to find value by key
int* find(HashMap* map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            return &map->entries[i].value;
        }
    }
    return NULL;
}

// Function to free hash map
void freeHashMap(HashMap* map) {
    free(map->entries);
    free(map);
}

// Optimized Two Sum function
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;  // Set return size

    HashMap* numMap = createHashMap(numsSize);
    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int* found = find(numMap, complement);

        if (found != NULL) {  // Found valid pair
            result[0] = *found;
            result[1] = i;
            freeHashMap(numMap);
            return result;
        }

        put(numMap, nums[i], i);  // Store number and its index
    }

    freeHashMap(numMap);
    free(result);
    return NULL;
}
