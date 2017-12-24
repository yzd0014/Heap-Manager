#include "Source/MemoryManagement/HeapManager.h"
#include "Source/MemoryManagement/BitArray.h"
bool BitArray_UnitTest()
{
	size_t blockSize = 1024 * 1024;
	void * initPointer = _aligned_malloc(blockSize, 4);
	HeapManager::create(initPointer, blockSize, 2048);
	BitArray bitArray(128, true);
	//BitArray bitArray(128, false);
	size_t firstBit;
	bitArray.GetFirstSetBit(firstBit);

	bitArray.SetBit(2);
	//bitArray.ClearBit(127);
	
	bool result = bitArray.GetFirstSetBit(firstBit);
	//bool result = bitArray.GetFirstClearBit(firstBit);

	bool result_2 = bitArray.IsBitSet(2);
	//bool result_2 = bitArray.IsBitClear(12);

	bitArray.ClearAll();
	bitArray.SetAll();
	
	getchar();
	return true;
}