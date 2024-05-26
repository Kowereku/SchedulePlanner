#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Calendar.h";

using namespace std;

void Calendar::displayWeek()
{
    vector<string> days = { "Poniedza³ek", "Wtorek", "Œroda", "Czwartek", "Pi¹tek", "Sobota", "Niedziela" };
    vector<string> events(7, "Brak wydarzeñ");

    cout << setw(15) << days[0] << setw(15) << days[1] << setw(15) << days[2] << setw(15) << days[3]
        << setw(15) << days[4] << setw(15) << days[5] << setw(15) << days[6] << "\n";
    cout << "-----------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < 7; ++i)
    {
        cout << setw(15) << events[i];
    }
    cout << "\n-----------------------------------------------------------------------------------------------------------\n";
    cout << "\nNaciœnij dowolny przycisk, aby wróciæ do menu...";
    cin.ignore();
    cin.get();
}