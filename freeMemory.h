#pragma once
#include <vector>
#include <fstream>
namespace Railway {
    class UserAccount; // forward declaration
    class Train; // forward declaration
    class MemoryManager {
    public:
        static void freeUserAccounts(std::vector<UserAccount*>& users);
        static void freeTrains(std::vector<Train*>& trains);
        static void closeFile(std::ofstream& f);
        static void closeFile(std::ifstream& f);
    };
}
