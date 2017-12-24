//Yitong 12/10/2017
#include <iostream>
#include <stdio.h>
#include <vector>
#include "Character/MonsterController.h"
#include "Character/SmartMonsterController.h"
#include "Character/PlayerController.h"
#include "Engine.h"

using namespace std;

int main(int argc, const char * argv[])
{
	//HeapManager_UnitTest();
	//Vector2D_UnitTest();
	//BitArray_UnitTest();
	//FSA_UnitTest();
	// initialize default heap manager
	size_t blockSize = 1024*1024;
	void * initPointer = _aligned_malloc(blockSize, 4);
	HeapManager::create(initPointer, blockSize, 2048);
	DEBUG_PRINT("line #%d: start total free memory %zu", __LINE__, HeapManager::heapManager->getTotalFreeMemory());
	DEBUG_PRINT("line #%d: total number of descriptors %zu", __LINE__, HeapManager::heapManager->getTotalNumDescriptors());
	//initialize fixed size heap manager
	FixedSizeAllocator * pFSA_8 = static_cast<FixedSizeAllocator *>(HeapManager::heapManager->_alloc(sizeof(FixedSizeAllocator)));
	FixedSizeAllocator::FSAs[0] = new (pFSA_8) FixedSizeAllocator(16, 7 * 1024);

	FixedSizeAllocator * pFSA_16 = static_cast<FixedSizeAllocator *>(HeapManager::heapManager->_alloc(sizeof(FixedSizeAllocator)));
	FixedSizeAllocator::FSAs[1] = new (pFSA_16) FixedSizeAllocator(24, 10 * 1024);


	FixedSizeAllocator * pFSA_32 = static_cast<FixedSizeAllocator *>(HeapManager::heapManager->_alloc(sizeof(FixedSizeAllocator)));
	FixedSizeAllocator::FSAs[2] = new (pFSA_32) FixedSizeAllocator(40, 3 * 1024);

	FixedSizeAllocator * pFSA_64 = static_cast<FixedSizeAllocator *>(HeapManager::heapManager->_alloc(sizeof(FixedSizeAllocator)));
	FixedSizeAllocator::FSAs[3] = new (pFSA_64) FixedSizeAllocator(72, 1 * 1024);

	{
		
		cout << "Number of monsters: ";
		int num_monster;
		cin >> num_monster;
		vector<GameObjectController *> controllers;
		size_t controllersSize = 0;
		controllers.reserve(50);
		//GameObjectController *M[50];
	
		//initialize monsters
		int counter = 0;//counter for while loop
		getchar();
		while (counter < num_monster) {
			char monsterName[20];
			cout << "Name of moster-" << counter << ": ";
			gets_s(monsterName);
			GameObject *mObj = new GameObject(monsterName, Vector2D(0, counter), 3);
			
			MonsterController *monster = new MonsterController(mObj);
			controllers.push_back(monster);
			counter++;

		}
		
		//initialize player
		cout << "Name of the player: ";
		char playerName[20];
		gets_s(playerName);
		
		GameObject *pObj = new GameObject(playerName, Vector2D(50, 50), 100);
		PlayerController *player = new PlayerController(pObj);

		//intial render
		cout << "Player " << player->getGameObject()->getPosition() << endl;
		controllersSize = controllers.size();
		for (int i = 0; i < static_cast<int>(controllersSize); i++) {
				cout << "Monster " << controllers[i]->getGameObject()->getPosition() << endl;
		}

		char action = 0;//store users' input
		int main_loop_counter = 0;
		while (1) {
			if (main_loop_counter == 100) main_loop_counter = 0;
			//update screen
			cout << "Please enter w, a, s, d or q: ";
			cin >> action;
			if (action == 'q') {
				break;
			}
			else {
				player->getDirectionFromUser(action);
				player->updateGameObject();
			}
			controllersSize = controllers.size();
			for (int i = 0; i < static_cast<int>(controllersSize); i++) {//move or destroy monsters
				if (controllers[i]->getGameObject()->getLife() > 0) {
					controllers[i]->updateGameObject();
					controllers[i]->getGameObject()->setLife(controllers[i]->getGameObject()->getLife() - 1);
				}
				else {
					delete controllers[i];
					controllers.erase(controllers.begin() + i);
					i--;
					controllersSize = controllers.size();
				}
			}
			if (main_loop_counter % 99 == 0) {//creat two new monsters
				for (int j = 0; j < 2; j++) {
					Vector2D smartMonsterPosition(0, 0);
					if (j == 0) {
						smartMonsterPosition.set_x(50);
						smartMonsterPosition.set_y(47);
					}
					else {
						smartMonsterPosition.set_x(50);
						smartMonsterPosition.set_y(53);
					}
					GameObject *smObj = new GameObject("Tiger", smartMonsterPosition, 90);
					SmartMonsterController *smartMonster = new SmartMonsterController(smObj,pObj);
					controllers.push_back(smartMonster);
				}
			}
			//render
			cout << "Player " << player->getGameObject()->getPosition() << endl;
			controllersSize = controllers.size();
			for (int i = 0; i < static_cast<int>(controllersSize); i++) {
				cout << "Monster " << controllers[i]->getGameObject()->getPosition() << endl;
			}
			main_loop_counter++;
		}
		
		delete player;//delete player
		controllersSize = controllers.size();//delete all remaining monstrs
		for (int i = 0; i < static_cast<int>(controllersSize); i++) {
			if (controllers[i]) delete controllers[i];
		}
		controllers.clear();
	}
	
	for (int i = 0; i < 4; i++) {
		delete FixedSizeAllocator::FSAs[i];
		FixedSizeAllocator::FSAs[i] = nullptr;
	}
	HeapManager::heapManager->collect();
	DEBUG_PRINT("line #%d: start total free memory %zu", __LINE__, HeapManager::heapManager->getTotalFreeMemory());
	DEBUG_PRINT("line #%d: total number of descriptors %zu", __LINE__, HeapManager::heapManager->getTotalNumDescriptors());
	HeapManager::heapManager->destroy();
	HeapManager::heapManager = nullptr;
	_aligned_free(initPointer);
	getchar();
	getchar();
	return 0;
}
