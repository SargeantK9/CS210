// Name: Joshua Nash Simmons (ID: 3663605)
// Date: 01/24/26
// Project 1 Functions File

#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

// This initializes the starting clock.
static int inputHours = 0;
static int inputMinutes = 0;
static int inputSeconds = 0;

// Change the text below if you want the clock titles to be different.
const string LABEL_TWELVE = "12-Hour Clock";
const string LABEL_TWENTY_FOUR = "24-Hour Clock";

// The below constants control the formatting of the display.
constexpr int CLOCK_WIDTH = 25;
constexpr int COLUMN_WIDTH = 1;
constexpr int CLOCK_PADDING = 6;
constexpr char CLOCK_FILLER = '*';
constexpr char PADDING_FILLER = ' ';

// The below constants set the menu options displayed to user.
const string OPTION_ONE = "1 - Add One Hour";
const string OPTION_TWO = "2 - Add One Minute";
const string OPTION_THREE = "3 - Add One Second";
const string OPTION_FOUR = "4 - Exit Program";

// The below constant control the input validation.
const string USER_INPUT_PROMPT = "Please select an option from the menu above: ";
const string USER_INPUT_INVALID_STATEMENT = "Your input was invalid. Please enter an integer between 1 and 4: ";
constexpr int INPUT_VALID_UPPER_LIMIT = 4;
constexpr int INPUT_VALID_LOWER_LIMIT = 1;

// This function allows main to "get" our time variables.
void getTimeVariables(int& h, int& m, int& s) {
    h = inputHours;
    m = inputMinutes;
    s = inputSeconds;
}

// The following functions allow us to "set" our time variables.
void addOneHour() {
    inputHours++;
    if (inputHours == 24) {
        inputHours = 0;
    }
}

void addOneMinute() {
    inputMinutes++;
    if (inputMinutes == 60) {
        addOneHour();
        inputMinutes = 0;
    }
}

void addOneSecond() {
    inputSeconds++;
    if (inputSeconds == 60) {
        addOneMinute();
        inputSeconds = 0;
    }
}

// No other functions directly interact with the time variables. All others call these functions.

int twelveHourConversion(const int h) {
    // The 12-hour clock only matches the 24-hour clock between 1 AM and 12 PM.
    return (h % 12 == 0) ? 12 : h % 12;
}

string addLeadingZero(const int num) {
    if (num < 10) {
        return "0" + to_string(num);
    }
    return to_string(num);
}

// The below function generates the string that will display the time.
// Setting isTwelve to true will generate a 12-hour format. Otherwise, the format is 24-hour.
string toClockFormat(const bool isTwelve, const int h, const int m, const int s) {

    // All clocks need the minutes and seconds in the same format.
    string displayMinutes = addLeadingZero(m);
    string displaySeconds = addLeadingZero(s);

    // We declare the displayHours variable then set it depending on if the format is 12 or 24.
    string displayHours;

    // The following code will only run if we want the 12-hour format.
    if (isTwelve) {
        // We run the 12-hour conversion inside the leading zero function to get the 12-hour display.
        displayHours = addLeadingZero(twelveHourConversion(h));
        string amPm = (h < 12) ? " AM" : " PM";
        return displayHours + ":" + displayMinutes + ":" + displaySeconds + amPm;
    }

    // If we set isTwelve to false, the below code will run.
    displayHours = addLeadingZero(h);
    return displayHours + ":" + displayMinutes + ":" + displaySeconds;
}

// A reusable tool for drawing UI elements
void printLine(int width, char filler, bool endLine = false) {
    cout << string(width, filler);
    if (endLine) cout << endl;
}

void printClockLine(int width, char filler, string text) {
    const int innerClockPadding = (width - text.length()) / 2;
    printLine(innerClockPadding, filler);
    cout << text;
    printLine(innerClockPadding, filler);
}

// This function handles every about creating the clock display.
// Including adjusting any of the numbers to display properly and the display itself.
void displayClockandMenu() {
    int h;
    int m;
    int s;

    getTimeVariables(h, m, s);

    const string twelveHourDisplay = toClockFormat(true, h, m, s);
    const string twentyFourHourDisplay = toClockFormat(false, h, m, s);

    // The below code builds the top border.
    printLine(COLUMN_WIDTH, CLOCK_FILLER);
    printLine(CLOCK_WIDTH, CLOCK_FILLER);
    printLine(COLUMN_WIDTH, CLOCK_FILLER);
    printLine(CLOCK_PADDING, PADDING_FILLER);
    printLine(COLUMN_WIDTH, CLOCK_FILLER);
    printLine(CLOCK_WIDTH, CLOCK_FILLER);
    printLine(COLUMN_WIDTH, CLOCK_FILLER, true);

    // Next inserts the clock labels.
    printLine(COLUMN_WIDTH, CLOCK_FILLER);
    printClockLine(CLOCK_WIDTH, PADDING_FILLER, LABEL_TWELVE);
    printLine(COLUMN_WIDTH, CLOCK_FILLER);
    printLine(CLOCK_PADDING, PADDING_FILLER);
    printLine(COLUMN_WIDTH, CLOCK_FILLER);
    printClockLine(CLOCK_WIDTH, PADDING_FILLER, LABEL_TWENTY_FOUR);
    printLine(COLUMN_WIDTH, CLOCK_FILLER, true);

    // Next the actual clocks displays.
    printLine(COLUMN_WIDTH, CLOCK_FILLER);
    printClockLine(CLOCK_WIDTH, PADDING_FILLER, twelveHourDisplay);
    printLine(COLUMN_WIDTH, CLOCK_FILLER);
    printLine(CLOCK_PADDING, PADDING_FILLER);
    printLine(COLUMN_WIDTH, CLOCK_FILLER);
    printClockLine(CLOCK_WIDTH, PADDING_FILLER, twentyFourHourDisplay);

    // I had trouble making the strings minimum width.
    cout << " ";
    printLine(COLUMN_WIDTH, CLOCK_FILLER, true);

    // Finally, the bottom border of the clocks.
    printLine(COLUMN_WIDTH, CLOCK_FILLER);
    printLine(CLOCK_WIDTH, CLOCK_FILLER);
    printLine(COLUMN_WIDTH, CLOCK_FILLER);
    printLine(CLOCK_PADDING, PADDING_FILLER);
    printLine(COLUMN_WIDTH, CLOCK_FILLER);
    printLine(CLOCK_WIDTH, CLOCK_FILLER);
    printLine(COLUMN_WIDTH, CLOCK_FILLER, true);

    vector<string> options = {OPTION_ONE, OPTION_TWO, OPTION_THREE, OPTION_FOUR};

    // The below code builds the top border.
    printLine(COLUMN_WIDTH, CLOCK_FILLER);
    printLine(CLOCK_WIDTH, CLOCK_FILLER);
    printLine(COLUMN_WIDTH, CLOCK_FILLER, true);

    // Then we print the menu by iterating through the string vector with our options.
    for (int i = 0; i < options.size(); i++) {
        printLine(COLUMN_WIDTH, CLOCK_FILLER);
        cout << " " + options[i];
        printLine(CLOCK_WIDTH - (options[i].length() + 1), PADDING_FILLER);
        printLine(COLUMN_WIDTH, CLOCK_FILLER, true);
    }

    // Last is the bottom border of the menu.
    printLine(COLUMN_WIDTH, CLOCK_FILLER);
    printLine(CLOCK_WIDTH, CLOCK_FILLER);
    printLine(COLUMN_WIDTH, CLOCK_FILLER, true);

}

// Eventually, I want to build this validation function so it can work with any input type.
// I haven't figured out how to have a parameter be expected input type to validate if (cin <<...).
// So, for now, it's very much only really usable for this project.
int getUserIntInput(const string &prompt, const string &ifInvalid, const int upperBounds, const int lowerBounds) {
    int inputFromUser;
    bool userInputValid = false;
    cout << prompt;
    // We need to ensure the user input is an integer and that it is 1 through 4.
    while (userInputValid == false) {
        if (cin >> inputFromUser && inputFromUser >= lowerBounds && inputFromUser <= upperBounds) {
            // Input is an int and in range
            userInputValid = true;
        }
        else {
            // Either not an int or out of range
            cout << ifInvalid;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return inputFromUser;
}

// Tried a few different methods to hide the input processing while allowing a "4" to break the main while loop.
// Settled on returning the user input.
int userDesiredChange() {
    const int input = getUserIntInput(USER_INPUT_PROMPT, USER_INPUT_INVALID_STATEMENT, INPUT_VALID_UPPER_LIMIT, INPUT_VALID_LOWER_LIMIT);
    if (input == 1) {
        addOneHour();
    }
    else if (input == 2) {
        addOneMinute();
    }
    else if (input == 3) {
        addOneSecond();
    }
    return input;
}


