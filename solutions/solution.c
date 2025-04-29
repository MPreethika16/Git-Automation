#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a struct for HashMap Node.
typedef struct HashMapNode {
    int key;
    int value;
    struct HashMapNode* next;
} HashMapNode;// 
 
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
        map->table[i] = NULL; 
    }
}

// Function to find two sum indices
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
   //write your code

}
