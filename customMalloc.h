#ifndef CUSTOM_MALLOC_H
#define CUSTOM_MALLOC_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
   size_t size;
   struct MemoryBlock* next;
} MemoryBlock;

typedef struct {
   MemoryBlock memory_block[MAX_SIZE];
} FreeList;

void* malloc(size_t size);
void* realloc(void* ptr, size_t size);
void* calloc(size_t num, size_t size);

void* find_block(FreeList* free_list_ptr, size_t size);
void* get_me_blocks(__ssize_t how_much);
void break_block(MemoryBlock* memory_block_ptr, size_t size);
void add_block_to_free_list(FreeList* free_list_ptr,
                            MemoryBlock* memory_block_ptr);

void free(void* ptr);
void print_free_list(void* free_list);

#endif