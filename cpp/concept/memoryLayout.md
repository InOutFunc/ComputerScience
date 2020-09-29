## memory layout

1、Memory Layout of C Programs

https://www.geeksforgeeks.org/memory-layout-of-c-program/

**1. Text Segment:**

executable instructions

**2. Initialized Data Segment:**

Initialized data segment, usually called simply the Data Segment.

the global variables and static variables that are initialized by the programmer.

**3. Uninitialized Data Segment:**

Uninitialized data segment, often called the “bss” segment, named after an ancient assembler operator that stood for “block started by symbol."

uninitialized data starts at the end of the data segment and contains all global variables and static variables that are initialized to zero or do not have explicit initialization in source code.

For instance a variable declared static int i; would be contained in the BSS segment.

For instance a global variable declared int j; would be contained in the BSS segment.

**4. Stack:**

The stack area traditionally adjoined the heap area and grew the opposite direction; when the stack pointer met the heap pointer, free memory was exhausted.

**5. Heap:**

Heap is the segment where dynamic memory allocation usually takes place.

The Heap area is managed by malloc, realloc, and free, which may use the brk and sbrk system calls to adjust its size (note that the use of brk/sbrk and a single “heap area” is not required to fulfill the contract of malloc/realloc/free; they may also be implemented using mmap to reserve potentially non-contiguous regions of virtual memory into the process’ virtual address space). 

2、Heap overflow and Stack overflow

https://www.geeksforgeeks.org/heap-overflow-stack-overflow/