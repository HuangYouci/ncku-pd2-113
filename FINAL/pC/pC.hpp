#include <iostream>


class Reservation {
    protected:
        std::string customerName;
        int numGuests;
        std::string reservationTime;
        std::string type;

    public:
        Reservation(const std::string& name, int guests,
                    const std::string& time)
            : customerName(name),
                numGuests(guests),
                reservationTime(time) {}

        virtual std::string getDetails() const = 0;
        std::string getReservationTime() const { return reservationTime; }
};
class StandardReservation : public Reservation {
    public:
        StandardReservation(const std::string& name, int guests,const std::string& time);
        std::string getDetails() const override;
};
class VIPReservation : public Reservation {
    public:
        VIPReservation(const std::string& name, int guests,const std::string& time, const std::string& type);
        std::string getDetails() const override;
};

bool cmp(Reservation* a, Reservation* b);
