#include <chrono>
#include <ctime>  
#include "menu.h"

/*
city.h
-------------
Class City
City objectsx25
void viewCities() 
*/


/*
hotel.h
---------------------
Class Hotel
Hotel objectsx25
void viewAllHotels() C1Hotels etc... hotelchoiceannoying() 
*/

//Quick Brainstorm for hotel and city merger, we can have a map, 
//or we can keep the objects separate since im not storing the city in booking



//-------------------------visual separator for city class----------------------------------------------------------------------


class City {
public:
    string cityName;

    City(string city) : cityName(city) {}

    void viewCity() {
        cout << "City: " << cityName << endl;
    }
};

// 5 Ciies 5 obj

City C1("New York");
City C2("Paris");
City C3("London");
City C4("Tokyo");
City C5("Sydney");


void viewCities() { //small menu to show the cities, calls the subsequent hotel submenus
    cout << "1. New York" << endl;
    cout << "2. Paris" << endl;
    cout << "3. London" << endl;
    cout << "4. Tokyo" << endl;
    cout << "5. Sydney" << endl;
    cout << "6. Back to main menu" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";

    string choiceStr;
    getline(cin, choiceStr);

    if (all_of(choiceStr.begin(), choiceStr.end(), ::isdigit)) {
        int choice = stoi(choiceStr);
        if (choice >= 1 && choice <= 7) {
            if (choice == 1) {
                cout << "-----------------------" << endl;
                C1.viewCity();
                cout << "-----------------------" << endl;
                C1Hotels();
                //call the sub menu for the hotels in that city
            } else if (choice == 2) {
                cout << "-----------------------" << endl;
                C2.viewCity();
                cout << "-----------------------" << endl;
                C2Hotels();
            } else if (choice == 3) {
                cout << "-----------------------" << endl;
                C3.viewCity();
                cout << "-----------------------" << endl;
                C3Hotels();
            } else if (choice == 4) {
                cout << "-----------------------" << endl;
                C4.viewCity();
                cout << "-----------------------" << endl;
                C4Hotels();
            } else if (choice == 5) {
                cout << "-----------------------" << endl;
                C5.viewCity();
                cout << "-----------------------" << endl;
                C5Hotels();
            } else if (choice == 6) {
                menu();
            } else {
                exit(0);
            }
        } else {
            cout << "Invalid choice. Please enter a valid number between 1 and 7." << endl;
        }
    } else {
        cout << "Invalid choice. Please enter a valid number." << endl;
    }
}


//-------------------------visual separator for hotel class----------------------------------------------------------------------

class Hotel {
private:
    string hotelName;
    int pricePerNight;
    string roomType;

public:
    Hotel(string name, int price, string type) {
        hotelName = name;
        pricePerNight = price;
        roomType = type;
    }

    string getHotelName() {
        return hotelName;
    }

    int getPricePerNight() {
        return pricePerNight;
    }

    string getRoomType() {
        return roomType;
    }

    int calculateStayPrice(int stayDuration) {
        return pricePerNight * stayDuration;
    }


    bool wantToBook(){ //asks if you wanna book this hotel
        string choice;
        cout << "Do you wish to book this hotel?" << endl;
        cout << "1. Yes, book hotel" << endl;
        cout << "2. No, go back to main menu" << endl;
        cout << "3. Exit Program" << endl;
        cout << "Enter your choice: ";

        string choiceStr;
        getline(cin, choiceStr);

        if (all_of(choiceStr.begin(), choiceStr.end(), ::isdigit)) {
            int choice = stoi(choiceStr);
            if (choice >= 1 && choice <= 25) {
                if(choice == 1){
                    string fileName = "bookings.txt";
                    addBooking(fileName);
                    return true;
                }
                else if(choice == 2){
                    return false;
                }
                else if(choice == 3){
                    exit(0);
                } 
            } else {
                cout << "Invalid choice. Please enter a valid number between 1 and 25." << endl;
            } 
        } else {
            cout << "Invalid choice. Please enter a valid number." << endl;
        }

        return 0;
    }


    void aboutHotel(){ //tells you about the hotel and then asks if you wanna book it
        cout << "-----------------------" << endl;
        cout << getHotelName() << endl;
        cout << "-----------------------" << endl;
        cout << "Price:" << getPricePerNight() << endl;
        cout << "Room Type:" << getRoomType() << endl;
        int choice = wantToBook();
        if(choice == 1){
            string fileName = "bookings.txt";
            addBooking(fileName);
        } else if (choice == 2){
            menu();
        }else {
            exit;
        }
    }
};


// 5 Cities 5 Hotels  25 obj

Hotel C1H1("The Grand Hotel", 100, "Deluxe");
Hotel C1H2("Evergrand Hotel", 30, "Basic");
Hotel C1H3("Barkeep Inn", 50, "Standard");
Hotel C1H4("Sunset Motel", 70, "Standard");
Hotel C1H5("Rising Sun Lodge", 70, "Basic");

Hotel C2H1("Seaside Resort", 200, "Ultra Deluxe");
Hotel C2H2("Beachside Inn", 40, "Basic");
Hotel C2H3("Duneview Hotel", 80, "Standard");
Hotel C2H4("Moonlight Motel", 60, "Standard");
Hotel C2H5("Twilight Lodge", 30, "Basic");

Hotel C3H1("Mountainpeak Retreat", 300, "Deluxe");
Hotel C3H2("Lakeside Lodge", 50, "Basic");
Hotel C3H3("Riverview Inn", 100, "Standard");
Hotel C3H4("Meadows Motel", 80, "Deluxe");
Hotel C3H5("Highland Haven", 90, "Basic");

Hotel C4H1("Garden Getaway", 400, "Ultra Deluxe");
Hotel C4H2("Forestside Inn", 60, "Basic");
Hotel C4H3("Riverside Resort", 90, "Standard");
Hotel C4H4("Valleyview Motel", 170, "Deluxe");
Hotel C4H5("Glenview Lodge", 25, "Basic");

Hotel C5H1("City Center Suites", 500, "Ultra Deluxe");
Hotel C5H2("Downtown Inn", 70, "Basic");
Hotel C5H3("Urbanview Hotel", 120, "Standard");
Hotel C5H4("Skyline Motel", 150, "Deluxe");
Hotel C5H5("Suburbia Haven", 45, "Basic");

void hotelchoiceannoying(){ //This annoying loop is used for all the hotel choice menu subsections 
    cout << "Enter your choice: ";

    string choiceStr;
    getline(cin, choiceStr);

    if (all_of(choiceStr.begin(), choiceStr.end(), ::isdigit)) {
        int choice = stoi(choiceStr);
        if (choice >= 1 && choice <= 27) {
            if (choice == 1) {
                C1H1.aboutHotel();
            } else if (choice == 2) {
                C1H2.aboutHotel();
            } else if (choice == 3) {
                C1H3.aboutHotel();
            } else if (choice == 4) {
                C1H4.aboutHotel();
            } else if (choice == 5) {
                C1H5.aboutHotel();
            } else if (choice == 6) {
                C2H1.aboutHotel();
            } else if (choice == 7) {
                C2H2.aboutHotel();
            } else if (choice == 8) {
                C2H3.aboutHotel();
            } else if (choice == 9) {
                C2H4.aboutHotel();
            } else if (choice == 10) {
                C2H5.aboutHotel();
            } else if (choice == 11) {
                C3H1.aboutHotel();
            } else if (choice == 12) {
                C3H2.aboutHotel();
            } else if (choice == 13) {
                C3H3.aboutHotel();
            } else if (choice == 14) {
                C3H4.aboutHotel();
            } else if (choice == 15) {
                C3H5.aboutHotel();
            } else if (choice == 16) {
                C4H1.aboutHotel();
            } else if (choice == 17) {
                C4H2.aboutHotel();
            } else if (choice == 18) {
                C4H3.aboutHotel();
            } else if (choice == 19) {
                C4H4.aboutHotel();
            } else if (choice == 20) {
                C4H5.aboutHotel();
            } else if (choice == 21) {
                C5H1.aboutHotel();
            } else if (choice == 22) {
                C5H2.aboutHotel();
            } else if (choice == 23) {
                viewCities();
            } else if (choice == 24) {
                viewCities();
            } else if (choice == 25) {
                viewCities();
            } else if (choice == 26) {
                menu();
            } else {
                exit(0);
            }
        } else {
            cout << "Invalid choice. Please enter a valid number between 1 and 27." << endl;
        }
    } else {
        cout << "Invalid choice. Please enter a valid number." << endl;
    }
}

void viewAllHotels() { //self explanatory: its the main display all hotels menu
    cout << "1. The Grand Hotel" << endl;
    cout << "2. Evergrand Hotel" << endl;
    cout << "3. Barkeep Inn" << endl;
    cout << "4. Sunset Motel" << endl;
    cout << "5. Rising Sun Lodge" << endl;

    cout << "6. Seaside Resort" << endl;
    cout << "7. Beachside Inn" << endl;
    cout << "8. Duneview Hotel" << endl;
    cout << "9. Moonlight Motel" << endl;
    cout << "10. Twilight Lodge" << endl;
    
    cout << "11. Mountainpeak Retreat" << endl;
    cout << "12. Lakeside Lodge" << endl;
    cout << "13. Riverview Inn" << endl;
    cout << "14. Meadows Motel" << endl;
    cout << "15. Highland Haven" << endl;

    cout << "16. Garden Getaway" << endl;
    cout << "17. Forestside Inn" << endl;
    cout << "18. Riverside Resort" << endl;
    cout << "19. Valleyview Motel" << endl;
    cout << "20. Glenview Lodge" << endl;

    cout << "21. City Center Suites" << endl;
    cout << "22. Downtown Inn" << endl;
    cout << "23. Urbanview Hotel" << endl;
    cout << "24. Skyline Motel" << endl;
    cout << "25. Suburbia Haven" << endl;

    cout << "26. Back to main menu" << endl;
    cout << "27. Exit" << endl;
    hotelchoiceannoying();
}

void C1Hotels() {

    cout << "1. The Grand Hotel" << endl;
    cout << "2. Evergrand Hotel" << endl;
    cout << "3. Barkeep Inn" << endl;
    cout << "4. Sunset Motel" << endl;
    cout << "5. Rising Sun Lodge" << endl;
    cout << "26. Back to main menu" << endl;
    cout << "27. Exit" << endl;
    hotelchoiceannoying();
}

void C2Hotels() {
    cout << "6. Seaside Resort" << endl;
    cout << "7. Beachside Inn" << endl;
    cout << "8. Duneview Hotel" << endl;
    cout << "9. Moonlight Motel" << endl;
    cout << "10. Twilight Lodge" << endl;
    cout << "26. Back to main menu" << endl;
    cout << "27. Exit" << endl;
    hotelchoiceannoying();
}

void C3Hotels() {
    
    cout << "11. Mountainpeak Retreat" << endl;
    cout << "12. Lakeside Lodge" << endl;
    cout << "13. Riverview Inn" << endl;
    cout << "14. Meadows Motel" << endl;
    cout << "15. Highland Haven" << endl;

    cout << "26. Back to main menu" << endl;
    cout << "27. Exit" << endl;hotelchoiceannoying();

}

void C4Hotels() {
    cout << "16. Garden Getaway" << endl;
    cout << "17. Forestside Inn" << endl;
    cout << "18. Riverside Resort" << endl;
    cout << "19. Valleyview Motel" << endl;
    cout << "20. Glenview Lodge" << endl;

    cout << "26. Back to main menu" << endl;
    cout << "27. Exit" << endl;
    hotelchoiceannoying();

}

void C5Hotels() {

    cout << "21. City Center Suites" << endl;
    cout << "22. Downtown Inn" << endl;
    cout << "23. Urbanview Hotel" << endl;
    cout << "24. Skyline Motel" << endl;
    cout << "25. Suburbia Haven" << endl;

    cout << "26. Back to main menu" << endl;
    cout << "27. Exit" << endl;

    hotelchoiceannoying();
}





//-------------------------visual separator end of doc----------------------------------------------------------------------
