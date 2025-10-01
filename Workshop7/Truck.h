// #ifndef TRUCK_H
// #define TRUCK_H

// #include "MotorVehicle.h"

// namespace seneca {
//     class Truck : public MotorVehicle {
//     private:
//         double capacity;
//         double currentCargo;

//     public:
//         Truck(const char* plate, int year, double cap, const char* addr);
//         bool addCargo(double cargo);
//         bool unloadCargo();
//         std::ostream& write(std::ostream& os) const;
//         std::istream& read(std::istream& in);
//     };

//     std::ostream& operator<<(std::ostream& os, const Truck& truck);
//     std::istream& operator>>(std::istream& in, Truck& truck);
// }

// #endif // TRUCK_H



// #ifndef TRUCK_H
// #define TRUCK_H

// #include "MotorVehicle.h"

// namespace seneca {
//     class Truck : public MotorVehicle {
//     private:
//         double capacity;
//         double currentCargo;

//     public:
//         Truck(const char* plate, int year, double cap, const char* addr);
//         bool addCargo(double cargo);
//         bool unloadCargo();
//         std::ostream& write(std::ostream& os) const;
//         std::istream& read(std::istream& in);
//     };

//     std::ostream& operator<<(std::ostream& os, const Truck& truck);
//     std::istream& operator>>(std::istream& in, Truck& truck);
// }

// #endif // TRUCK_H


#ifndef TRUCK_H
#define TRUCK_H

#include "MotorVehicle.h"

namespace seneca {
    class Truck : public MotorVehicle {
    private:
        double capacity;
        double currentCargo;

    public:
        Truck(const char* plate, int year, double cap, const char* addr);
        bool addCargo(double cargo);
        bool unloadCargo();
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& in);
    };

    std::ostream& operator<<(std::ostream& os, const Truck& truck);
    std::istream& operator>>(std::istream& in, Truck& truck);
}

#endif // TRUCK_H
