// Security.cpp
#include "Security.h"
#include <iostream>
#include <fstream>
#include <set>
#include <string>

// Added namespace wrapper
namespace Railway {

// Constructor: Calls the loadCodes helper
Security::Security(const std::string& dailyFile, const std::string& primeFile) {
    loadCodes(dailyFile, primeFile);
}

// Load codes from file into sets for fast lookup
void Security::loadCodes(const std::string& dailyFile, const std::string& primeFile) {
    std::ifstream finDaily(dailyFile);
    std::string code;
    while (getline(finDaily, code)) {
        if (!code.empty())
            dailyTicketCodes.insert(code);
    }
    finDaily.close();

    std::ifstream finPrime(primeFile);
    while (getline(finPrime, code)) {
        if (!code.empty())
            primeCardCodes.insert(code);
    }
    finPrime.close();
}

// Check if a ticket code (regular) is duplicate
bool Security::isDuplicateTicketCode(const std::string& code) {
    // find() returns an iterator to the end if the code is NOT found
    return dailyTicketCodes.find(code) != dailyTicketCodes.end();
}

// Check if a prime card code is duplicate
bool Security::isDuplicatePrimeCode(const std::string& code) {
    return primeCardCodes.find(code) != primeCardCodes.end();
}

} // End of namespace Railway