#include "RegularAccount.h"
#include <iostream>
using namespace Railway;

std::vector<std::string> RegularAccount::locations;
std::vector<Train> RegularAccount::schedule;

RegularAccount::RegularAccount(std::string n, std::string g)
    : name(n), gender(g), paid(false), source("Chinchwad"), ticketPrice(0), distance(0) {}

void RegularAccount::setupTrains() {
    locations = {"Swargate","RTO","Range Hills","Dighi","Allandhi","PMC",
                "Kumbhar Wada","Hinjawadi","Ramwadi"};
    schedule = {
        {"T001","Chinchwad","Swargate","08:00",50,20},
        {"T002","Chinchwad","Kumbhar Wada","09:30",60,15},
        {"T003","Chinchwad","PMC","10:00",40,10}
    };
}

void RegularAccount::chooseDestination() {
    std::cout << "Choose your destination:\n";
    for(size_t i=0; i < locations.size(); ++i)
        std::cout << i+1 << ". " << locations[i] << "\n";
    int opt;
    std::cin >> opt;
    if(opt < 1 || (size_t)opt > locations.size()) {
        std::cout << "Invalid. Try again.\n";
        return chooseDestination();
    }
    destination = locations[opt-1];
}

void RegularAccount::showTrainsToDestination() {
    std::cout << "Available trains to " << destination << ":\n";
    for(const auto& t : schedule) {
        if(t.destination == destination) {
            std::cout << t.trainNo << ": " << t.departureTime
                      << " | General: " << t.generalSeats
                      << ", AC: " << t.acSeats << "\n";
        }
    }
}

void RegularAccount::selectTrainAndSeat() {
    std::string trainno, stype;
    std::cout << "Enter Train Number to book: "; std::cin >> trainno;
    for(auto& t : schedule) {
        if(t.trainNo == trainno && t.destination == destination) {
            chosenTrain = t;
            break;
        }
    }
    std::cout << "Choose seat type (General/AC): "; std::cin >> stype;
    seatType = stype;
    if(seatType == "General" && chosenTrain.generalSeats > 0) --chosenTrain.generalSeats;
    else if(seatType == "AC" && chosenTrain.acSeats > 0) --chosenTrain.acSeats;
    else std::cout << "Seat not available. Try again.\n";
}

void RegularAccount::inputDistance() {
    std::cout << "Enter distance to destination (km): "; std::cin >> distance;
}

void RegularAccount::calculateTicketPrice() {
    ticketPrice = (distance/2)*11;
    if(gender == "Female" || gender == "female") {
        ticketPrice = ticketPrice * 0.8;
    }
}

void RegularAccount::payment() {
    std::cout << "Ticket price: \u20B9" << ticketPrice << "\n";
    std::cout << "Proceed to pay? (1-Yes, 0-No): ";
    int payOpt; std::cin >> payOpt;
    paid = (payOpt == 1);
    if(paid)
        std::cout << "Ticket paid successfully.\n";
    else
        std::cout << "Payment failed. Booking cancelled.\n";
}

void RegularAccount::generateReceipt() {
    if(paid) {
        std::cout << "\n--- Ticket Receipt ---\n";
        std::cout << "Name: " << name << "\nGender: " << gender << "\nSource: " << source
                  << "\nDestination: " << destination << "\nTrain: " << chosenTrain.trainNo
                  << "\nDeparture: " << chosenTrain.departureTime
                  << "\nSeat Type: " << seatType
                  << "\nTicket Price: \u20B9" << ticketPrice << "\n";
    }
}
