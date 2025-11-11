//1st file named:
// Create Account.cpp

#include "CreateAccount.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <sstream> // Needed for std::stringstream

using namespace Railway;

// The array of digits to use for the OTP
int primeDigits[] = {2, 3, 5, 7};

// Default constructor
UserAccount::UserAccount() : age(0) {}

// Main constructor
UserAccount::UserAccount(std::string n, int a, std::string g, std::string w, std::string d, std::string c) 
    : name(n), age(a), gender(g), work(w), dob(d), contactNo(c), uniqueID("") {}

void UserAccount::generateOTP() {
    srand(static_cast<unsigned int>(time(0)));
    std::stringstream ss;
    for(int i = 0; i < 4; ++i) {
        ss << primeDigits[rand() % 4];
    }
    uniqueID = ss.str(); // Store the generated OTP as the uniqueID
}

// getOTP() now just returns the stored string
std::string UserAccount::getOTP() const {
    return uniqueID;
}

void UserAccount::saveToFile() {
    std::ofstream file("accounts.txt", std::ios::app);
    if (!file) {
        throw std::runtime_error("Unable to open file!");
    }
    // Save the member variables (note: using 'dob', not 'DOB')
    file << name << "," << age << "," << gender << "," << work << "," << dob << "," << contactNo << "," << uniqueID << "\n";
    file.close();
}

// Implementations for the new getters
std::string UserAccount::getName() const { return name; }
std::string UserAccount::getGender() const { return gender; }
std::string UserAccount::getWork() const { return work; }
int UserAccount::getAge() const { return age; }