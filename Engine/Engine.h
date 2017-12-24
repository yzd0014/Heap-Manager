#pragma once
namespace Engine
{
	void init();
	void ConsolePrint(const char * i_fmt, ...);
	char * duplicateString(const char * i_string);
}

#if defined(_DEBUG)  &&  !defined(DISABLE_DEBUG_PRINT)
#define DEBUG_PRINT(fmt, ...) Engine::ConsolePrint((fmt), __VA_ARGS__)
#else
#define DEBUG_PRINT(fmt, ...) void(0)
#endif

#define dupstring(str) Engine::duplicateString(str)

#include "Source/MemoryManagement/HeapManager.h"
#include "Source/MemoryManagement/FixedSizeAllocator.h"
#include "Source/MemoryManagement/HeapOperations.h"
#include "Source/Utility/GameObject.h"
#include "Source/Utility/GameObjectController.h"
#include "UnitTest/Vector2D_UnitTest.h"
#include "UnitTest/HeapManager_UnitTest.h"
#include "UnitTest/BitArray_UnitTest.h"
#include "UnitTest/FSA_UnitTest.h"
