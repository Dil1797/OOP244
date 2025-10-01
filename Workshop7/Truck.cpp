// #include "Truck.h"
// #include <iomanip>

// namespace seneca {
//     Truck::Truck(const char* plate, int year, double cap, const char* addr)
//         : MotorVehicle(plate, year), capacity(cap), currentCargo(0) {
//         moveTo(addr);
//     }

//     bool Truck::addCargo(double cargo) {
//         if (currentCargo + cargo <= capacity) {
//             currentCargo += cargo;
//             return true;
//         }
//         return false;
//     }

//     bool Truck::unloadCargo() {
//         if (currentCargo > 0) {
//             currentCargo = 0;
//             return true;
//         }
//         return false;
//     }

//     std::ostream& Truck::write(std::ostream& os) const {
//         MotorVehicle::write(os) << " | " << currentCargo << "/" << capacity;
//         return os;
//     }

//     std::istream& Truck::read(std::istream& in) {
//         MotorVehicle::read(in);
//         std::cout << "Capacity: ";
//         in >> capacity;
//         std::cout << "Cargo: ";
//         in >> currentCargo;
//         return in;
//     }

//     std::ostream& operator<<(std::ostream& os, const Truck& truck) {
//         return truck.write(os);
//     }

//     std::istream& operator>>(std::istream& in, Truck& truck) {
//         return truck.read(in);
//     }
// }



// #include "Truck.h"
// #include <iostream>
// #include <cstring>

// namespace seneca {
//     Truck::Truck(const char* plate, int year, double cap, const char* addr)
//         : MotorVehicle(plate, year), capacity(cap), currentCargo(0) {
//         moveTo(addr);
//     }

//     bool Truck::addCargo(double cargo) {
//         if (currentCargo + cargo <= capacity) {
//             currentCargo += cargo;
//             return true;
//         }
//         return false;
//     }

//     bool Truck::unloadCargo() {
//         if (currentCargo > 0) {
//             currentCargo = 0;
//             return true;
//         }
//         return false;
//     }

//     std::ostream& Truck::write(std::ostream& os) const {
//         MotorVehicle::write(os) << " | " << currentCargo << "/" << capacity;
//         return os;
//     }

//     std::istream& Truck::read(std::istream& in) {
//         MotorVehicle::read(in);
//         std::cout << "Capacity: ";
//         in >> capacity;
//         std::cout << "Cargo: ";
//         in >> currentCargo;
//         return in;
//     }

//     std::ostream& operator<<(std::ostream& os, const Truck& truck) {
//         return truck.write(os);
//     }

//     std::istream& operator>>(std::istream& in, Truck& truck) {
//         return truck.read(in);
//     }
// }

#define _CRT_SECURE_NO_WARNINGS
#include "Truck.h"
#include <iostream>
#include <cstring>

namespace seneca {
    using namespace std;

    Truck::Truck(const char* plate, int year, double cap, const char* addr)
        : MotorVehicle(plate, year), capacity(cap), currentCargo(0) {
        moveTo(addr);
    }

    bool Truck::addCargo(double cargo) {
        if (currentCargo + cargo <= capacity) {
            currentCargo += cargo;
            return true;
        } else if (currentCargo < capacity) {
            currentCargo = capacity;
            return true;
        }
        return false;
    }

    bool Truck::unloadCargo() {
        if (currentCargo > 0) {
            currentCargo = 0;
            return true;
        }
        return false;
    }

    ostream& Truck::write(ostream& os) const {
        MotorVehicle::write(os) << " | " << currentCargo << "/" << capacity;
        return os;
    }

    istream& Truck::read(istream& in) {
        MotorVehicle::read(in);
        cout << "Capacity: ";
        in >> capacity;
        cout << "Cargo: ";
        in >> currentCargo;
        return in;
    }

    ostream& operator<<(ostream& os, const Truck& truck) {
        return truck.write(os);
    }

    istream& operator>>(istream& in, Truck& truck) {
        return truck.read(in);
    }
}
