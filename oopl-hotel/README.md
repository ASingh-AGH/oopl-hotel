# OOPL Hotel

## Name and Roll
Apoorva Singh 

409428 

WEAiiB

----
<br>

## Project Supervisor 
Rafał Frączek <rafalfr@agh.edu.pl>

----
<br>

## Project Timeline

Due on 6pm 26th Jan 2023.

----
<br>


## Project Description 

Project 74: 

Design and implement classes for a hotel booking system where a user can search a
hotel in a given city and book it. 

https://dysk.agh.edu.pl/s/RaDxFLE2tjRFHkY?dir=undefined&path=%2Flab&openfile=4760621

----
<br>

## Project Rules
----

All projects mentioned below must meet the following guidelines and requirements:
1. Projects must be made individually.
2. In the project it is necessary to create at least one class with a constructor and
appropriate methods. It is also necessary to use at least one of the STL containers e.
g. vector, map or other.
3. If it makes any sense for the particular project, the program should also make use of
class inheritance, interfaces, exception handling, virtual functions and recurrence.
4. There should be at least minimal input values validation. For instance, when the
program expects that a user enters a digit, the program should check if the provided
string is actually a digit or not and let the user know when the wrong input was
provided. It is unacceptable that the project terminates or falls into an infinite loop
when the wrong input is provided.
5. There is no need to create the graphical user interface. It is enough that the project
runs in the terminal and text mode.
6. In the main menu, there should be an option that terminates the program. It should
also be possible to return to the main menu from any submenu.
7. The project can use external open source libraries, like for instance database server
sqlite etc.
8. All changes made during the program execution should be saved (e. g. in files) and
restored upon the program startup.
9. The project should be compiled with warnings set to level three. The source code
should be written in such a way that there should be no warnings during the
compilation. Only a few warnings are acceptable provided that they are difficult to
remove.
10. Do not use new and delete operators. Instead, if you need a pointer, use smart
pointers.
11. The source code should be well formatted and cleaned of all unused code. There
should be comments in the source code explaining the usage of all functions and
classes. Most variables (except for loop indexes) should have the names that are
meaningful.
1

<br>


## Project Planning 
----
<br>

### Menu Planning 
___________

Have a menu that gives the option of

    1) selecting a city
    2) checking current bookings
    3) quit program

If 1) is selected-- a sub menu is displayed with

    - a list of cities
    - an option to go back to the main menu
    - an option to quit the program

    When the user chooses a city another menu:
    - with a list of hotels for that partiqular city
    - an option to go back to the main menu
    - an option to quit the program

    If the user selects a hotel:
    - see the price 
    - room capacity (one bed/two bed)
    - booking option
    - an option to go back to the main menu
    - an option to quit the program




If the user checks option 3)

    And has a booking then: 
    - see all previous booking dates
    - see hotel name
    - cancel booking 
    - an option to go back to the main menu
    - an option to quit the program

    If the user has not booked anything:
    - display that nothing has been booked
    - an option to go back to the main menu
    - an option to quit the program


Remember to implement something to check if the input is a valid option: the menu should work with numbers only.

### Things to Research 
----------

All changes made during the program execution should be saved (e. g. in files) and
restored upon the program startup.
Remeber to implement this code as permanent features, meaning anytime the program is shut down and restarted, the user booking data is still present. 


<br>

### Class Planning 
-----------

implement menu by switch case or ifs, have the main menu call and exit be two separate classes called every time

have 5 cities -> every city having 3 hotels
use a Map?
city -> name, hotels 
hotel ->  price, room type
User booking-> yes | null
User booking-> date from, date to, hotel name