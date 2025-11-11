#pragma once
#include <string>
#include <vector>
#include <map>
namespace Railway {
    struct Transaction {
        std::string date, userID;
        bool isPrime;
        double paid;
        Transaction();
        Transaction(const std::string& d, const std::string& uid, bool ip, double p);
    };
    struct PrimeRegistration {
        std::string date, userID;
        PrimeRegistration();
        PrimeRegistration(const std::string& d, const std::string& uid);
    };
    class RecordHistory {
    public:
        void loadData();
        void showDailyTransactionCount();
        void showWeeklyPrimeCounts();
        void showMonthlyPeak();
    private:
        std::vector<Transaction> dailyTransactions;
        std::vector<PrimeRegistration> primeRegs;
        std::string extractMonth(const std::string& date);
    };
}
