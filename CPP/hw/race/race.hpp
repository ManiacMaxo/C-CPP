#ifndef __RACE_H
#define __RACE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Race;

class Contestant {
    string name;
    int position;
    int speed;

   public:
    Contestant(string name, int position, int speed) {
        this->name = name;
        this->position = position;
        this->speed = speed;
    }
    string get_name() { return name; }
    void advance(Race* race);
};

class Race {
    int length;       // columns
    int contestants;  // rows

   public:
    vector<vector<Contestant*> > racetrack;
    Race(int contestants, int length) {
        for (int i = 0; i < contestants; i++) {
            vector<Contestant*> row;
            Contestant temp("Jerry " + to_string(i), i, rand() % 10);
            row.push_back(&temp);
            for (int j = 1; j < length; j++) {
                row.push_back(NULL);
            }
            racetrack.push_back(row);
        }
    }
    void conduct_race() {
        int count = 0;
        Contestant* pos[3];
        while (count != 3) {
            for (int i = 0; i < contestants; i++) {
                if (racetrack[length][i] != NULL) {
                    count++;
                    pos[count] = racetrack[length][i];
                    racetrack[length][i] = NULL;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            Contestant temp = *pos[i];
            cout << temp.get_name() << "finished " << i << endl;
        }
    }
    void add_contestant(Contestant contestant) {
        vector<Contestant*> row;
        row.push_back(&contestant);
        for (int i = 1; i < length; i++) {
            row.push_back(NULL);
        }
        racetrack.push_back(row);
    }
    int get_length() { return length; }
    int get_contestants() { return contestants; }
};

void Contestant::advance(Race* race) {
    int i = 0;
    while (i < race->get_length() || i != NULL) {
        i++;
    }
    Contestant* temp = race->racetrack[position][i];
    race->racetrack[position][i] = NULL;
    race->racetrack[position][i + speed] = temp;
    /* неясно беше как може да се движи за това всички отиват само на
    право */
    /* int dir = rand() % 3;
    switch (dir) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
    } */
}

#endif
