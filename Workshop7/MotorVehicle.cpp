// #include "MotorVehicle.h"
// #include <cstring>
// #include <iomanip>

// namespace seneca {
//     MotorVehicle::MotorVehicle(const char* plate, int yr) : year(yr) {
//         std::strncpy(licensePlate, plate, 9);
//         std::strncpy(address, "Factory", 64);
//     }

//     void MotorVehicle::moveTo(const char* addr) {
//         if (std::strcmp(address, addr) != 0) {
//             std::cout << '|' << std::setw(8) << std::right << licensePlate << '|' << ' ' << '|'
//                       << std::setw(20) << std::right << address << " ---> "
//                       << std::setw(20) << std::left << addr << '|' << std::endl;
//             std::strncpy(address, addr, 64);
//         }
//     }

//     std::ostream& MotorVehicle::write(std::ostream& os) const {
//         os << "| " << year << " | " << licensePlate << " | " << address;
//         return os;
//     }

//     std::istream& MotorVehicle::read(std::istream& in) {
//         char plate[9];
//         char addr[64];
//         std::cout << "Built year: ";
//         in >> year;
//         in.ignore();
//         std::cout << "License plate: ";
//         in.getline(plate, 9);
//         std::cout << "Current location: ";
//         in.getline(addr, 64);
//         std::strncpy(licensePlate, plate, 9);
//         std::strncpy(address, addr, 64);
//         return in;
//     }

//     std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle) {
//         return vehicle.write(os);
//     }

//     std::istream& operator>>(std::istream& in, MotorVehicle& vehicle) {
//         return vehicle.read(in);
//     }
// }


// #include "MotorVehicle.h"
// #include <cstring>
// #include <iostream>

// namespace seneca {
//     MotorVehicle::MotorVehicle(const char* plate, int yr) : year(yr) {
//         std::strncpy(licensePlate, plate, 9);
//         std::strncpy(address, "Factory", 64);
//     }

//     void MotorVehicle::moveTo(const char* addr) {
//         if (std::strcmp(address, addr) != 0) {
//             std::cout << '|'
//                       << std::string(8 - std::strlen(licensePlate), ' ') << licensePlate << "| |"
//                       << std::string(20 - std::strlen(address), ' ') << address << " ---> "
//                       << addr << std::string(20 - std::strlen(addr), ' ') << '|' << std::endl;

//             std::strncpy(address, addr, 64);
//         }
//     }

//     std::ostream& MotorVehicle::write(std::ostream& os) const {
//         os << "| " << year << " | " << licensePlate << " | " << address;
//         return os;
//     }

//     std::istream& MotorVehicle::read(std::istream& in) {
//         char plate[9];
//         char addr[64];
//         std::cout << "Built year: ";
//         in >> year;
//         in.ignore();
//         std::cout << "License plate: ";
//         in.getline(plate, 9);
//         std::cout << "Current location: ";
//         in.getline(addr, 64);
//         std::strncpy(licensePlate, plate, 9);
//         std::strncpy(address, addr, 64);
//         return in;
//     }

//     std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle) {
//         return vehicle.write(os);
//     }

//     std::istream& operator>>(std::istream& in, MotorVehicle& vehicle) {
//         return vehicle.read(in);
//     }
// }

#define _CRT_SECURE_NO_WARNINGS
#include "MotorVehicle.h"
#include <cstring>
#include <iostream>

namespace seneca {
    using namespace std;

    MotorVehicle::MotorVehicle(const char* plate, int yr) : year(yr) {
        strncpy(licensePlate, plate, 9);
        licensePlate[8] = '\0';  // Ensure null-termination
        strncpy(address, "Factory", 64);
        address[63] = '\0';  // Ensure null-termination
    }

    void MotorVehicle::moveTo(const char* addr) {
        if (strcmp(address, addr) != 0) {
            cout << "| "
                 << string(7 - strlen(licensePlate), ' ') << licensePlate << "| |"
                 << string(20 - strlen(address), ' ') << address << " ---> "
                 << addr << string(20 - strlen(addr), ' ') << '|' << endl;

            strncpy(address, addr, 64);
            address[63] = '\0';  // Ensure null-termination
        }
    }

    ostream& MotorVehicle::write(ostream& os) const {
        os << "| " << year << " | " << licensePlate << " | " << address;
        return os;
    }

    istream& MotorVehicle::read(istream& in) {
        char plate[9];
        char addr[64];
        cout << "Built year: ";
        in >> year;
        in.ignore();
        cout << "License plate: ";
        in.getline(plate, 9);
        cout << "Current location: ";
        in.getline(addr, 64);
        strncpy(licensePlate, plate, 9);
        licensePlate[8] = '\0';  // Ensure null-termination
        strncpy(address, addr, 64);
        address[63] = '\0';  // Ensure null-termination
        return in;
    }

    ostream& operator<<(ostream& os, const MotorVehicle& vehicle) {
        return vehicle.write(os);
    }

    istream& operator>>(istream& in, MotorVehicle& vehicle) {
        return vehicle.read(in);
    }
}
