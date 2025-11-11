// Corrected Security.h
#pragma once
#include <string>
#include <set>

namespace Railway {
    class Security {
    public:
        // Added '&' to dailyFile and primeFile
        Security(const std::string& dailyFile, const std::string& primeFile);
        
        // Added '&' to code
        bool isDuplicateTicketCode(const std::string& code);
        
        // Added '&' to code
        bool isDuplicatePrimeCode(const std::string& code);
    
    private:
        std::set<std::string> dailyTicketCodes;
        std::set<std::string> primeCardCodes;
        void loadCodes(const std::string& dailyFile, const std::string& primeFile);
    };
}