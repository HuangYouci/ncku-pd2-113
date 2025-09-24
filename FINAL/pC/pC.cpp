#include <iostream>
#include "pC.hpp"

std::string VIPReservation::getDetails() const {
    std::cout << customerName << " " << numGuests << " " << reservationTime << " " << type;
    return "";
};

std::string StandardReservation::getDetails() const {
    std::cout << customerName << " " << numGuests << " " << reservationTime << " Standard";
    return "";
};

StandardReservation::StandardReservation(const std::string& name, int guests,const std::string& time) : Reservation(customerName,
                numGuests,
                reservationTime) {
                    this->numGuests = guests;
                    this->reservationTime = time;
                    this->customerName = name;
                    // std::cout << "Standard Reservation Created: " << name << guests << time << std::endl;
};

VIPReservation::VIPReservation(const std::string& name, int guests,const std::string& time,const std::string& type) :
    Reservation(customerName,
                numGuests,
                reservationTime) {
            
                    this->numGuests = guests;
                    this->reservationTime = time;
                    this->customerName = name;
    this->type = type;
                    // std::cout << "VIP Reservation Created: " << name << guests << time << type << std::endl;

};

bool cmp(Reservation* a, Reservation* b){
    std::string atime = a->getReservationTime();
    std::string btime = b->getReservationTime();

  
    int ao = (atime[0]-'0')*10 + (atime[1]-'0');
    int bo = (btime[0]-'0')*10 + (btime[1]-'0');
    int as = (atime[3]-'0')*10 + (atime[4]-'0');
    int bs = (btime[3]-'0')*10 + (btime[4]-'0');

    // std::cout << "A time: " << atime << ", ao: " << ao << ", as: " << as << std::endl;
    // std::cout << "B time: " << btime << ", bo: " << bo << ", bs: " << bs << std::endl;
    // std::cout << std::endl;

    if(ao != bo){
        return ao<bo;
    } else {
        return as<bs;
    }
}