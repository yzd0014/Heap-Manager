Instructions for the Program:

There are three unit tests at the top of the main function. HeapManager_UnitTest is the one we used through the semester; FSA_UnitTest is to only test FixedSizeAllocator; BitArray is to test class BitArray. Uncomment them to run. Note that don’t run HeapManager_UnitTest, FSA_UnitTest and MonsterChase game at the same time, all of them use my own heapManager and my own heapManager will be only created once. In both HeapManager_UnitTest and MonsterChase game, my default heap’s states are emitted at the beginning and the end to make sure that there is no memory leaking. Also FixedSizeAllocators will emit information before they are destroyed. 


Implementation Comments:

FixedSizeAllocator.cpp
Line 5: static variables to store all FixedSizeAllocators.
Line 7: FixedSizeAllocator’s constructor. It will occupy two resources for BitArray and the chunk of memory it will manage respectively. I didn’t write a copy constructor and assignment operator for this as this class is a tool that serves for the program and all its instances will be created by this constructor.

Line 26: guradband is supported. For a FxiedSizeAllocator with 8 bytes, 16 bytes will be passed to its constructor, 4 bytes at beginning, 4 bytes at the end, 8 bytes at the middle that will be used by users.

Line 53: all resources will be released. In debug mode emit information if there is still unreleased memory.

BitArray.cpp
Line 11: allocate resource from my own heapManager to store all bits. 
Line 9, line 12: support both 32 and 64 bits.
Line 32: use _BitScanForward64 to find the first set bit.
Line 130: release resource.

HeapOperations.cpp
Line 8: it will try to find the optimal size that matches the request. If the optimal option is not available, it will try to allocate memory from the FixedSizeAllocator with block size that is just larger than the optimal one. 

Line 10: emit information to know which FixedSizeAllocator is used.

Line 40: By testing if the given pointer is in the range of a certain FixedSizeAllocator, I will be able to know which FixedSizeAllocator the pointer is from.

