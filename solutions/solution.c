#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a struct for HashMap Node
typedef struct HashMapNode {
    int key;
    int value;
    struct HashMapNode* next;
} HashMapNode;

// Define the HashMap
#define TABLE_SIZE 10007  // Prime number for better hash distribution

typedef struct {
    HashMapNode* table[TABLE_SIZE];
} HashMap;

// Hash function (Handles negative numbers properly)
unsigned int hash(int key) {
    return (unsigned int)((key % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE);
}

// Insert into the hash map
void insert(HashMap* map, int key, int value) {
    unsigned int idx = hash(key);
    HashMapNode* newNode = (HashMapNode*)malloc(sizeof(HashMapNode));
    if (!newNode) return;  // Memory allocation check
    newNode->key = key;
    newNode->value = value;
    newNode->next = map->table[idx];
    map->table[idx] = newNode;
}

// Search for a key in the hash map
bool search(HashMap* map, int key, int* value) {
    unsigned int idx = hash(key);
    HashMapNode* node = map->table[idx];
    while (node) {
        if (node->key == key) {
            *value = node->value;
            return true;
        }
        node = node->next;
    }
    return false;
}

// Free memory allocated for HashMap.
void freeHashMap(HashMap* map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashMapNode* node = map->table[i];
        while (node) {
            HashMapNode* temp = node;
            node = node->next;
            free(temp);
        }
        map->table[i] = NULL; // Ensure clean state
    }
}

// Function to find two sum indices
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    if (!result) return NULL;  // Memory allocation failure check

    HashMap map = {0};  // Initialize hash map

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int index;
        if (search(&map, complement, &index)) {
            result[0] = index;
            result[1] = i;
            freeHashMap(&map);
            return result;
        }
        insert(&map, nums[i], i);
    }

    freeHashMap(&map);
    free(result);
    *returnSize = 0;
    return NULL;
}

// Test the function
int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int* result = twoSum(nums, 4, target, &returnSize);

    if (result) {
        printf("Indices: %d, %d\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
