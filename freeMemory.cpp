#include "freeMemory.h"
#include "CreateAccount.h"    // If UserAccount is defined here
#include "RegularAccount.h"   // If Train is defined here
#include <iostream>
using namespace Railway;

void MemoryManager::freeUserAccounts(std::vector<UserAccount*>& users) {
    for (auto p : users) {
        delete p;
    }
    users.clear();
    std::cout << "All user account memory freed.\n";
}

void MemoryManager::freeTrains(std::vector<Train*>& trains) {
    for (auto t : trains) {
        delete t;
    }
    trains.clear();
    std::cout << "All train memory freed.\n";
}

void MemoryManager::closeFile(std::ofstream& f) {
    if (f.is_open()) {
        f.close();
        std::cout << "Output file closed safely.\n";
    }
}

void MemoryManager::closeFile(std::ifstream& f) {
    if (f.is_open()) {
        f.close();
        std::cout << "Input file closed safely.\n";
    }
}
