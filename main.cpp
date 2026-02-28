// Name: Joshua Nash Simmons (ID: 3663605)
// Date: 01/24/26
// Project 1 Main File

#include <iostream>
#include "functions.h"
using namespace std;

int main() {

    // We initialize userInput as -1 to kick off the while loop.
    bool exit = false;

    // All references to time variables are done internal to functions.

    // This while loop will continue to update and show the clocks and menu until user enters 4.
    while (!exit) {
        displayClockandMenu();
        if (userDesiredChange() == 4) {
            exit = true;
        }
    }

    // Once the user enters 4, we say goodbye.
    cout << "Thank you for using our clock!";

    return 0;
}