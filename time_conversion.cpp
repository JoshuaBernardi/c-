#include <iostream>
using namespace std;

int main() {
    int totalMinutes;
    cout << "Enter the number of minutes: ";
    cin >> totalMinutes;

    // Calculate hours and minutes
    int hours = (totalMinutes / 60) % 12; // Use modulo to keep hours between 0 and 11
    int minutes = totalMinutes % 60; // Minutes within an hour

    // Output the time in the format "hours:minutes !"
    cout << hours << ":" << minutes << " !" << endl;

    return 0;
}
