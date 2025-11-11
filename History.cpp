// Corrected History.cpp
#include "History.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>

// All definitions are now correctly inside the namespace
namespace Railway {

// Struct Constructors
Transaction::Transaction() : date(""), userID(""), isPrime(false), paid(0.0) {}
Transaction::Transaction(const std::string& d, const std::string& uid, bool ip, double p)
    : date(d), userID(uid), isPrime(ip), paid(p) {}
PrimeRegistration::PrimeRegistration() : date(""), userID("") {}
PrimeRegistration::PrimeRegistration(const std::string& d, const std::string& uid)
    : date(d), userID(uid) {}

// Class Method Implementations
std::string RecordHistory::extractMonth(const std::string& date) {
    if (date.find("-") == 2) // format DD-MM-YYYY
        return date.substr(3,2);
    else // format YYYY-MM-DD
        return date.substr(5,2);
}

void RecordHistory::loadData() {
    dailyTransactions.clear();
    primeRegs.clear();
    std::ifstream fin("transactions.txt");
    std::string line;
    while (getline(fin, line)) {
        std::istringstream iss(line);
        std::string date, userID, isPrimeStr, paidStr;
        getline(iss, date, ',');
        getline(iss, userID, ',');
        getline(iss, isPrimeStr, ',');
        getline(iss, paidStr);
        Transaction t = {date, userID, isPrimeStr=="1", std::stod(paidStr)};
        dailyTransactions.push_back(t);
    }
    fin.close();
    std::ifstream fin2("prime_regs.txt");
    while (getline(fin2, line)) {
        std::istringstream iss(line);
        std::string date, userID;
        getline(iss, date, ',');
        getline(iss, userID);
        primeRegs.push_back({date, userID});
    }
    fin2.close();
}

void RecordHistory::showDailyTransactionCount() {
    std::map<std::string, int> dayCount;
    for (const auto& t : dailyTransactions) {
        dayCount[t.date]++;
    }
    std::cout << "Daily paid transactions:\n";
    for (const auto& d : dayCount) {
        std::cout << d.first << ": " << d.second << "\n";
    }
}

void RecordHistory::showWeeklyPrimeCounts() {
    std::map<std::string, int> weekCount;
    int weekNum = 1;
    for (size_t i = 0; i < primeRegs.size(); i += 7) {
        int count = 0;
        for (size_t j = i; j < i+7 && j < primeRegs.size(); ++j) count++;
        weekCount["Week_" + std::to_string(weekNum++)] = count;
    }
    std::cout << "\nPrime registrations per week:\n";
    for (auto& w : weekCount) {
        std::cout << w.first << ": " << w.second << "\n";
    }
}

void RecordHistory::showMonthlyPeak() {
    std::map<std::string, int> monthTransCount, monthPrimeCount;
    for (const auto& t : dailyTransactions)
        monthTransCount[extractMonth(t.date)]++;
    for (const auto& p : primeRegs)
        monthPrimeCount[extractMonth(p.date)]++;

    std::string peakTransMonth, peakPrimeMonth;
    int maxTrans = 0, maxPrime = 0;
    for (const auto& m : monthTransCount) {
        if (m.second > maxTrans) {
            maxTrans = m.second;
            peakTransMonth = m.first;
        }
    }
    for (const auto& m : monthPrimeCount) {
        if (m.second > maxPrime) {
            maxPrime = m.second;
            peakPrimeMonth = m.first;
        }
    }
    auto monthName = [](const std::string& mm) {
        const char* names[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        int idx = 0;
        try {
            idx = std::stoi(mm);
        } catch (...) {
            return "Unknown";
        }
        return (idx >= 1 && idx <= 12) ? names[idx] : "Unknown";
    };
    std::cout << "\nMonth with highest paid user travel: " << monthName(peakTransMonth)
              << "\nMonth with highest Prime registrations: " << monthName(peakPrimeMonth) << "\n";
}

} // <-- IMPORTANT: Make sure this closing brace is at the end of the file