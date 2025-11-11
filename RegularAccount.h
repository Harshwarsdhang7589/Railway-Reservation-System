#pragma once
#include <string>
#include <vector>
namespace Railway {
    struct Train {
        std::string trainNo;
        std::string source;
        std::string destination;
        std::string departureTime;
        int generalSeats, acSeats;
    };
    class RegularAccount {
    public:
        RegularAccount(std::string n, std::string g);
        static void setupTrains();
        void chooseDestination();
        void showTrainsToDestination();
        void selectTrainAndSeat();
        void inputDistance();
        void calculateTicketPrice();
        void payment();
        void generateReceipt();
        // statics
        static std::vector<std::string> locations;
        static std::vector<Train> schedule;
    private:
        std::string name, gender;
        std::string source, destination, seatType;
        int distance;
        int ticketPrice;
        bool paid;
        Train chosenTrain;
    };
}
