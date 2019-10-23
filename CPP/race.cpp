#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Contestant {
   private:
    string name;
    double distance;
    double speed;

   public:
    Contestant(string name, double speed) {
        name = name;
        speed = speed;
        distance = 0;
    }
    Contestant() {
        name = "";
        speed = 0;
        distance = 0;
    }
    string get_name();
    double get_speed();
    double get_distance();
    void calc_dist(int itterations);
    void reset_dist();
};

void Contestant::reset_dist() {
    distance = 0;
}

string Contestant::get_name() {
    return name;
}

double Contestant::get_speed() {
    return speed;
}

double Contestant::get_distance() {
    return distance;
}

void Contestant::calc_dist(int itterations) {
    distance = speed * itterations;
}

class Race {
   private:
    vector<Contestant> contestants;

   public:
    Race() {
        contestants[1];
    }
    Race(vector<Contestant> vect) {
        for (int i = 0; i < vect.size(); i++) {
            contestants.push_back(vect[i]);
        }
    }

    vector<Contestant> get_contestants();
    vector<Contestant> add_contestant(Contestant contestant);
    void reset_contestants();
    void simulate_race(int itterations);
};

vector<Contestant> Race::get_contestants() {
    return contestants;
}

vector<Contestant> Race::add_contestant(Contestant contestant) {
    contestants.push_back(contestant);
}

void Race::reset_contestants() {
    for (auto &contestant : contestants) {
        contestant.reset_dist();
    }
}

void Race::simulate_race(int itterations) {
    reset_contestants();
    for (int i = 0; i < itterations; i++) {
        for (auto &contestant : contestants) {
            contestant.calc_dist(itterations);
        }
        sort(contestants.begin(), contestants.end(), [](Contestant a, Contestant b) -> bool { return a->distance < b->distance; });
    }
}

int main() {
}
