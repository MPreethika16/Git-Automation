#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} HashNode;

int findIndex(HashNode* map, int size, int key) {
    for (int i = 0; i < size; i++) {
        if (map[i].key == key) return map[i].value;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashNode* map = (HashNode*)malloc(numsSize * sizeof(HashNode));
    int mapSize = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int rem = target - nums[i];
        int index = findIndex(map, mapSize, rem);
        if (index != -1) {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = index;
            result[1] = i;
            *returnSize = 2;
            free(map);
            return result;
        }
        map[mapSize].key = nums[i];
        map[mapSize].value = i;
        mapSize++;
    }

    *returnSize = 0;
    free(map);
    return NULL;
}
