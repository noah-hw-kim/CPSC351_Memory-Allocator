#include "customMalloc.h"

FreeList free_list;

void* malloc(size_t size) {
   void* ptr = find_block(&free_list, size);
   if (ptr == NULL) {
      ptr = get_me_blocks(size);
   }
   break_block(ptr, size);
   return ptr;
}

void* realloc(void* ptr, size_t size);
void* calloc(size_t num, size_t size);

void* find_block(void* free_list, size_t size) {
   MemoryBlock* free_list_ptr = (MemoryBlock*)free_list;
   while (ptr != NULL) {
      if (ptr->size >= size) {
         return ptr;
      }
      ptr = ptr->next;
   }
   return NULL;
}

void* get_me_blocks(__ssize_t how_much) {
   void* ptr = sbrk(0);
   sbrk(how_much);
   return ptr;
}

void break_block(void* ptr, size_t size) {
   MemoryBlock* block_ptr = (MemoryBlock*)ptr;
   if (block_ptr->size > size) {
      MemoryBlock* new_block = ((char*)block_ptr + size);
      new_block->size = block_ptr->size - size;
      new_block->next = NULL;
      block_ptr->size = size;
      add_block_to_free_list(&free_list, new_block);
   }
}

void add_block_to_free_list(void* free_list, void* ptr) {
   MemoryBlock* free_list_ptr = (MemoryBlock*)free_list;

   void* current = free_list->memory_block;
   while (current->next != NULL) {
      current = current->next;
   }
   current->next = ptr;
}

void free(void* ptr) { add_block_to_free_list(&free_list, ptr); }

void print_free_list(void* free_list) {
   void* ptr = free_list->memory_block;
   while (ptr != NULL) {
      printf("Size: %d\n", ptr->size);
      ptr = ptr->next;
   }
}

int main(int argc, char* argv[]) { FreeList free_list; }