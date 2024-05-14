#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "allocator.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "allocator.h"
#include "tester.h"
#include "block.h"
#include "tree.h"
#include "avl/avl_impl.h"

#include "tree.h"

int main(void)
{

	void *ptr1, *ptr2, *ptr3, *ptr4;

	ptr1 = mem_alloc(85000);
	mem_show("alloc 85000");
	printf("arena alloc - %zu\n", payload_to_block(ptr1)->size_curr);
	printf("arena alloc block_get_size_curr - %zu\n", block_get_size_curr(payload_to_block(ptr1)));
    
	ptr2 = mem_alloc(2);
	printf("ptr2 - %zu\n", payload_to_block(ptr2)->size_curr);
	printf("ptr2 block_get_size_curr - %zu\n", block_get_size_curr(payload_to_block(ptr2)));

	ptr3 = mem_alloc(7000);
	printf("ptr3 - %zu\n", payload_to_block(ptr3)->size_curr);
	printf("ptr3 block_get_size_curr - %zu\n", block_get_size_curr(payload_to_block(ptr3)));

	ptr4 = mem_alloc(50000);
	printf("ptr4 - %zu\n", payload_to_block(ptr4)->size_curr);
	printf("ptr4 block_get_size_curr - %zu\n", block_get_size_curr(payload_to_block(ptr4)));

	mem_show("allocs");
	ptr1 = mem_realloc(ptr1, 50000);
	mem_show("realloc ptr1 -> 50000");
	mem_free(ptr1);
	mem_show("free ptr1");
	mem_realloc(ptr4, 3000);
	mem_show("realloc ptr4 -> 3000");
	// srand(time(NULL));
	// tester(true);
}

