#pragma once
#include <string>

namespace Railway 
{
    class UserAccount {
    public:
        // Constructor
        UserAccount(std::string n, int a, std::string g, std::string w, std::string d, std::string c);
        
        // Default constructor (needed for inheritance)
        UserAccount();

        // Public methods
        void generateOTP();
        std::string getOTP() const; // Main.cpp calls this
        void saveToFile();

        // Getters needed by PrimeAccount
        std::string getName() const;
        std::string getGender() const;
        std::string getWork() const;
        int getAge() const;

    protected:
        // Changed from 'private' to 'protected' for inheritance
        std::string name, gender, work, dob, contactNo;
        std::string uniqueID; // Added this to store the OTP
        int age;
    };
}