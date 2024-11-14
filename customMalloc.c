#include <stdio.h>

void* get_me_blocks(__ssize_t how_much) {
   void* ptr = sbrk(0);
   sbrk(how_much);
   return ptr;
}

int main(int argc, char* argv[]) { printf("Hello\n"); }