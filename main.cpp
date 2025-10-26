#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string name[], string color[]);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    list<Goat> trip;

    //test main menu
    cout << main_menu();
    add_goat(trip, names, colors);
    display_trip(trip);
    cout << select_goat(trip);
    delete_goat(trip);
    display_trip(trip);



    return 0;
}

int select_goat(list<Goat> trip) {
    int usr_choice;
    while (true) {
        display_trip(trip);
        cin >> usr_choice;
        if (usr_choice >= 1 && usr_choice <= trip.size()) {
            return usr_choice-1;
        }
        cout << "Not valid option" << endl;
    }
}
void delete_goat(list<Goat> &trip) {
    int goat_num = select_goat(trip);
    int ctr = 0;
    for(auto i = trip.begin(); i != trip.end(); i++) {
        if (ctr == goat_num) {
            trip.erase(i);
        }
        break;
    }
}

void add_goat(list<Goat> &trip, string name[], string color[]) {
    Goat * goat = new Goat(name[0], (int)(rand()) % (MAX_AGE+1), color[0]);
    trip.push_back(*goat);
    cout << name[0];
}
void display_trip(list<Goat> trip) {
    int ctr = 1;
    for(auto i = trip.begin(); i != trip.end(); i++){
        cout << "[" << ctr+1 << "] " << (*i).get_name() << " (" << (*i).get_age() << ", " << (*i).get_color() << ")" << endl;
        ctr++;
    }
}

int main_menu() {
    int input;
    while(true) {
        cout << "*** GOAT MANAGER 3001 ***\n[1] Add a goat\n[2] Delete a goat\n[3] List goats\n[4] Quit\nChoice --> " << endl;
        cin >> input;
        if (input > 0 && input < 5) {
            return input;
        }
        cout << "Invalid input" << endl;
    }
}