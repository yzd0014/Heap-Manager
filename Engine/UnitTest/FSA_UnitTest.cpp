#include "Engine.h"
bool FSA_UnitTest() {
	size_t blockSize = 1024 * 1024;
	void * initPointer = _aligned_malloc(blockSize, 4);
	HeapManager::create(initPointer, blockSize, 2048);

	DEBUG_PRINT("line #%d: start total free memory %zu", __LINE__, HeapManager::heapManager->getTotalFreeMemory());
	DEBUG_PRINT("line #%d: total number of descriptors %zu", __LINE__, HeapManager::heapManager->getTotalNumDescriptors());

	FixedSizeAllocator * pFSA_8 = static_cast<FixedSizeAllocator *>(HeapManager::heapManager->_alloc(sizeof(FixedSizeAllocator)));
	FixedSizeAllocator::FSAs[0] = new (pFSA_8) FixedSizeAllocator(16, 10 * 1024);

	FixedSizeAllocator * pFSA_16 = static_cast<FixedSizeAllocator *>(HeapManager::heapManager->_alloc(sizeof(FixedSizeAllocator)));
	FixedSizeAllocator::FSAs[1] = new (pFSA_16) FixedSizeAllocator(24, 10 * 1024);


	FixedSizeAllocator * pFSA_32 = static_cast<FixedSizeAllocator *>(HeapManager::heapManager->_alloc(sizeof(FixedSizeAllocator)));
	FixedSizeAllocator::FSAs[2] = new (pFSA_32) FixedSizeAllocator(40, 3 * 1024);

	FixedSizeAllocator * pFSA_64 = static_cast<FixedSizeAllocator *>(HeapManager::heapManager->_alloc(sizeof(FixedSizeAllocator)));
	FixedSizeAllocator::FSAs[3] = new (pFSA_64) FixedSizeAllocator(72, 1 * 1024);
	
	char * pChar = new char[2];
	char * pChar2 = new char[10];
	printf("test...");
	delete[] pChar;
	delete[] pChar2;

	for (int i = 0; i < 4; i++) {
		delete FixedSizeAllocator::FSAs[i];
	}
	
	HeapManager::heapManager->collect();
	DEBUG_PRINT("line #%d: start total free memory %zu", __LINE__, HeapManager::heapManager->getTotalFreeMemory());
	DEBUG_PRINT("line #%d: total number of descriptors %zu", __LINE__, HeapManager::heapManager->getTotalNumDescriptors());

	HeapManager::heapManager->destroy();
	_aligned_free(initPointer);
	getchar();
	return true;
}