#include <iostream>
#include <cmath>  // For round function

using namespace std;

int main() {
    double hoursInput;
    int minutesInput, secondsInput;
    cout << "Enter time as '<hours> <minutes> <seconds>': ";
    cin >> hoursInput >> minutesInput >> secondsInput;

    // Convert everything to total seconds
    double totalSeconds = hoursInput * 3600 + minutesInput * 60 + secondsInput;

    // Calculate the 12-hour format time components
    int totalHours = static_cast<int>(totalSeconds / 3600);
    totalSeconds -= totalHours * 3600;
    int totalMinutes = static_cast<int>(totalSeconds / 60);
    totalSeconds -= totalMinutes * 60;
    int totalHours12 = totalHours % 12;

    // Handle the case for 12-hour clock where 0 hour is shown as 12
    if (totalHours12 == 0) {
        totalHours12 = 12;
    }

    // Round the seconds to the nearest integer
    int roundedSeconds = round(totalSeconds);

    // Adjust minutes and hours if rounding seconds caused an overflow
    if (roundedSeconds == 60) {
        roundedSeconds = 0;
        totalMinutes += 1;
        if (totalMinutes == 60) {
            totalMinutes = 0;
            totalHours12 += 1;
            if (totalHours12 == 13) {
                totalHours12 = 1;
            }
        }
    }

    // Output the result
    cout << totalHours12 << ":" << totalMinutes << "." << roundedSeconds << " !" << endl;

    return 0;
}
