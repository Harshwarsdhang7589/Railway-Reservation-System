#pragma once
#include <string>
#include "CreateAccount.h" // <-- IMPORTANT: Include the correct base class

namespace Railway {
    
    // The duplicate UserAccount class definition has been REMOVED.
    // This class now inherits from the one in CreateAccount.h

    class PrimeAccount : public UserAccount {
    public:
        PrimeAccount(const UserAccount& ua);
        bool loginPrime();
        void choosePass();
        double computeBaseConcession();
        double calculateFinalDiscount();
        void showPrimeBenefits();
        void notifyAdvance(const std::string& event);
    private:
        int passType;
        double discountRate;
        bool isLoggedIn;
    };
}