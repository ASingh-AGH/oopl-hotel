#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int menu();

//Declarations for City
void viewCities();  //view the list of cities, leads to view hotels menu
void C1Hotels();
void C2Hotels(); //YES I KNOW THIS IS REPETITIVE 
void C3Hotels();
void C4Hotels();
void C5Hotels();
void hotelchoiceannoying();

//Declarations for Hotel
void viewAllHotels(); // view the hotels
bool wantToBook(); // asks if the person wants to book the hotel, is causing some issues

//Declarations for Booking
struct Booking;
bool isValidDate(string date); //name is p explanatory, checks if date format is valid
int daysBetween(string checkIn, string checkOut); // days between the bookings
bool checkOutAfterCheckIn(string checkIn, string checkOut); // checks if the checkout is after the checkin date
void addBooking(string fileName); //adds a new booking, main section for code as well vvimp
void deleteBooking(string fileName); //deletes a booking has some work to be done its too harsh
void viewBookings(string fileName); // view the previous bookings



int menu(){
        string fileName = "bookings.txt";
    int choice;

    while (true) {
    cout << "-----------------------" << endl;
    cout << "----Booking Service----" << endl;
    cout << "-----------------------" << endl;
    cout << "1. Browse Cities" << endl;
    cout << "2. Browse Hotels" << endl;
    cout << "3. Add custom booking" << endl;
    cout << "4. View all bookings" << endl;
    cout << "5. Delete booking" << endl;
    cout << "6. Exit" << endl;
    cout << "-----------------------" << endl;
    cout << "Enter your choice: ";

    string choiceStr;
    getline(cin, choiceStr);

    if (all_of(choiceStr.begin(), choiceStr.end(), ::isdigit)) {
        int choice = stoi(choiceStr);
        if (choice >= 1 && choice <= 6) {
            if (choice == 1) {
                viewCities();//Browse cities
            } else if (choice == 2) {
                viewAllHotels();//Browse hotels
            } else if (choice == 3) {
                addBooking(fileName);//Add custom booking
            } else if (choice == 4) {
                viewBookings(fileName);//View booking    
            } else if (choice == 5) {
                viewBookings(fileName);//Delete booking
                deleteBooking(fileName);
            } else if (choice == 6){
                 cout << "Thank you for using Booking Service :) ";
                 exit;
            } else {
                break;
            }
        } else {
            cout << "Invalid choice. Please enter a valid number between 1 and 6." << endl;
        }
    } else {
        cout << "Invalid choice. Please enter a valid number." << endl;
    }
}
return 0;
}

