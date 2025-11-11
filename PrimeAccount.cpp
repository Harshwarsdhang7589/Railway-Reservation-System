#include "PrimeAccount.h"
#include <iostream>

// Added namespace wrapper
namespace Railway {

// All UserAccount::... function implementations have been DELETED from this file.
// They are now correctly placed in CreateAccount.cpp.

PrimeAccount::PrimeAccount(const UserAccount& ua)
: UserAccount(ua), isLoggedIn(false), passType(0), discountRate(0.0) {}

bool PrimeAccount::loginPrime() {
    std::string enteredID;
    for(int attempt = 1; attempt <= 3; ++attempt) {
        std::cout << "Enter your unique Prime ID (OTP from registration): ";
        std::cin >> enteredID;
        
        // This now correctly accesses the protected 'uniqueID' from the UserAccount base class
        if (enteredID == uniqueID) { 
            std::cout << "Login successful.\n";
            isLoggedIn = true;
            return true;
        } else {
            std::cout << "Incorrect ID. Attempt " << attempt << " of 3.\n";
        }
    }
    std::cout << "Exceeded maximum login attempts.\n";
    return false;
}

void PrimeAccount::choosePass() {
    std::cout << "Choose Prime Pass duration:\n1. 1 year (30%)\n2. 6 months (25%)\n3. 2 years (65%)\n";
    std::cin >> passType;
    if (passType == 1) discountRate = 0.30;
    else if (passType == 2) discountRate = 0.25;
    else if (passType == 3) discountRate = 0.65;
    else discountRate = 0.0;
}

double PrimeAccount::computeBaseConcession() {
    // These now correctly access protected members from the UserAccount base class
    if (gender == "Female" && age > 30)     return 0.47;
    if (age >= 60)                           return 0.50;
    if (work == "gov" || work == "Gov")     return 0.50;
    if (work == "student" && age < 22)      return 0.60;
    // Added "non-gov" to match the prompt in Main.cpp
    if (work == "nongov" || work == "NonGov" || work == "non-gov") return 0.30;
    return 0.0;
}

double PrimeAccount::calculateFinalDiscount() {
    double base = computeBaseConcession();
    return (base > discountRate) ? base : discountRate;
}

void PrimeAccount::showPrimeBenefits() {
    std::cout << "\nPrime Account Benefits:\n";
    std::cout << "- Priority seat allocation\n";
    std::cout << "- Faster check-in and support\n";
    std::cout << "- Advance notification (simulated)\n";
    std::cout << "- Special concession: " << calculateFinalDiscount() * 100 << "%\n\n";
}

void PrimeAccount::notifyAdvance(const std::string& event) {
    // This now correctly accesses the protected 'name' from the UserAccount base class
    std::cout << "Notification: Dear Prime user " << name
              << ", your " << event << " is approaching in 2 days!\n";
}

} // End of namespace Railway