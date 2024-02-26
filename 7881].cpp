#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int year;
    int month;
    int day;

    // Check if using Julian calendar system
    if (n <= 1917) {
        year = n;
        if (year % 4 == 0) {
            // Leap year
            month = 9;
            day = 12;
        } else {
            // Not a leap year
            month = 9;
            day = 13;
        }
    } else if (n == 1918) {
        // Special case for transition year
        year = n;
        month = 9;
        day = 26;
    } else {
        // Using Gregorian calendar system
        year = n;
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            // Leap year
            month = 9;
            day = 12;
        } else {
            // Not a leap year
            month = 9;
            day = 13;
        }
    }

    // Print the result in the format "dd.mm.yyyy"
    printf("%02d.%02d.%04d", day, month, year);

    return 0;
}

