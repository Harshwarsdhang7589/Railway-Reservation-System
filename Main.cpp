#include <iostream>
#include "CreateAccount.h"
#include "RegularAccount.h"
#include "PrimeAccount.h"
#include "History.h"
#include "Security.h"
#include "freeMemory.h"
using namespace Railway;

int main() {
    std::cout << "---- Welcome to Railway Reservation System ----\n";
    std::string userName, gender, work, dob, contactNo;
    int age;
    std::cout << "Create account:\n";
    std::cout << "Name: "; std::getline(std::cin, userName);
    std::cout << "Age: "; std::cin >> age; std::cin.ignore();
    std::cout << "Gender: "; std::getline(std::cin, gender);
    std::cout << "Work (gov/non-gov/student): "; std::getline(std::cin, work);
    std::cout << "Date of birth (DD-MM-YYYY): "; std::getline(std::cin, dob);
    std::cout << "Contact number: "; std::getline(std::cin, contactNo);
    UserAccount account(userName, age, gender, work, dob, contactNo);
    account.generateOTP();
    std::string otp = account.getOTP();
    account.saveToFile();
    std::cout << "Account created! Your OTP (Unique ID): " << otp << "\n";
    std::cout << "\nDo you want to book a regular ticket? (1-Yes, 0-No): ";
    int regOpt; std::cin >> regOpt;
    if (regOpt == 1) {
        RegularAccount regAcc(userName, gender);
        RegularAccount::setupTrains();
        regAcc.chooseDestination();
        regAcc.showTrainsToDestination();
        regAcc.selectTrainAndSeat();
        regAcc.inputDistance();
        regAcc.calculateTicketPrice();
        Security sec("daily_ticket_codes.txt", "prime_card_codes.txt");
        if (!sec.isDuplicateTicketCode(otp)) {
            regAcc.payment();
            regAcc.generateReceipt();
            // (optional) write ticket code to daily file
        } else {
            std::cout << "Duplicate ticket code! Cannot proceed.\n";
        }
    }
    std::cout << "\nDo you want a prime pass card? (1-Yes, 0-No): ";
    int primeOpt; std::cin >> primeOpt;
    if (primeOpt == 1) {
        PrimeAccount primeAcc(account);
        if (primeAcc.loginPrime()) {
            primeAcc.choosePass();
            primeAcc.showPrimeBenefits();
            primeAcc.notifyAdvance("pass expiry");
            // (optional) write prime card code to prime file
        }
    }
    RecordHistory rh;
    rh.loadData();
    rh.showDailyTransactionCount();
    rh.showWeeklyPrimeCounts();
    rh.showMonthlyPeak();
    std::cout << "\nThank you for using the Railway Reservation System. Exiting cleanly...\n";
    return 0;
}
