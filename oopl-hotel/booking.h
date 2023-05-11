#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <chrono>
#include <ctime>  
using namespace std;

#include "CityHotel.h"

//see menu .h for the declarations 

struct Booking {
    string userName; //Name of the user making the booking custom
    string hotelName; //Name of the hotel being booked
    string checkIn; //Check in date in the format YYYY-MM-DD
    string checkOut; //Check out date in the format YYYY-MM-DD
    string stayDuration; //Number of days the user will stay at the hotel
    string stayPrice;  //Price of the booking totla
    string cpricePerNight;//custom price per night
};


bool isValidDate(string date) {
    int year, month, day;
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
        return false;
    }
    tm t = { 0 };
    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;

    time_t tt = mktime(&t);
    if (tt == -1) {
        return false;
    }
    return true;
}

int daysBetween(string checkIn, string checkOut) {
    int year1, month1, day1, year2, month2, day2;
    sscanf(checkIn.c_str(), "%d-%d-%d", &year1, &month1, &day1);
    sscanf(checkOut.c_str(), "%d-%d-%d", &year2, &month2, &day2);

    tm t1 = { 0 };
    t1.tm_year = year1 - 1900;
    t1.tm_mon = month1 - 1;
    t1.tm_mday = day1;
    tm t2 = { 0 };
    t2.tm_year = year2 - 1900;
    t2.tm_mon = month2 - 1;
    t2.tm_mday = day2;

    time_t tt1 = mktime(&t1);
    time_t tt2 = mktime(&t2);

    return (int)difftime(tt2, tt1) / (60 * 60 * 24);
}

bool checkOutAfterCheckIn(string checkIn, string checkOut) {
    int daysDiff = daysBetween(checkIn, checkOut);
    if (daysDiff > 0) {
        return true;
    } else {
        return false;
    }
}

void addBooking(string fileName) {
    Booking booking;

    cout << "Enter user name: ";
    getline(cin, booking.userName);

    cout << "Enter hotel name: ";
    getline(cin, booking.hotelName);

    while(true) {
        cout << "Enter check-in date (YYYY-MM-DD): ";
        getline(cin, booking.checkIn);

        if (isValidDate(booking.checkIn)) {
            break;
        } else {
            cout << "Invalid date. Please enter a valid date in the format YYYY-MM-DD." << endl;
        }
    }

    while(true) {
        cout << "Enter check-out date (YYYY-MM-DD): ";
        getline(cin, booking.checkOut);

        if (isValidDate(booking.checkOut) && checkOutAfterCheckIn(booking.checkIn, booking.checkOut)) {
            break;
        } else {
            cout << "Invalid date. Please enter a valid check-out date that is after the check-in date in the format YYYY-MM-DD." << endl;
        }
    }

    
    booking.stayDuration = to_string(daysBetween(booking.checkIn, booking.checkOut));
    cout << "That is " << booking.stayDuration << " days" << endl;

    cout << "Enter price: ";
    getline(cin, booking.cpricePerNight);
    booking.stayPrice = to_string(stoi(booking.cpricePerNight) * stoi(booking.stayDuration)); //Reminder that this is custom booking
    cout << "The price for stay is " << booking.stayPrice << endl;

    ofstream outFile(fileName, ios::app);
            outFile << "User: "<< booking.userName <<" || Hotel: "<< booking.hotelName <<" || Checkin: "<< booking.checkIn <<" || Checkout: "<< booking.checkOut <<" || Duration: "<< booking.stayDuration <<" days || Price: " << booking.stayPrice << endl;        
        outFile.close();

        cout << "Booking added!" << endl;
    }

//deleteBooking-- it still has room for improvement beause its savage in sensing any string similarity to delete rather than the exact match, check later
void deleteBooking(string fileName) {
    string userName;
    string hotelName;

    cout << "Enter user name: ";
    getline(cin, userName);

    bool entryFound = false;

    ifstream inFile(fileName);
    ofstream tempFile("temp.txt");

    string line;
    while (getline(inFile, line)) {
        if (line.find(userName) == string::npos) {
            tempFile << line << endl;
        }
        else {
            entryFound = true;
        }
    }

    inFile.close();
    tempFile.close();

    remove(fileName.c_str());
    rename("temp.txt", fileName.c_str());

    if (entryFound) {
        cout << "Booking deleted!" << endl;
    }
    else {
        cout << "No booking found with that user name. Please try again." << endl;
        deleteBooking(fileName);
    }
}

void viewBookings(string fileName) {
    ifstream inFile(fileName);
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}
