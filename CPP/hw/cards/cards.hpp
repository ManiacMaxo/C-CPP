#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Card {
    char value;  // 2,3,4,5,6,7,8,9,T,J,Q,K,A
    string suit;

   public:
    Card(char val, string s) {
        value = val;
        suit = s;
    }
    Card() {
        char suits[4][10] = {"club", "diamond", "spade", "heart"};
        char values[] = {'2', '3', '4', '5', '6', '7', '8',
                         '9', 'T', 'J', 'Q', 'K', 'A'};
        srand(time(NULL));
        value = values[rand() % 13];
        suit.assign(suits[rand() % 4]);
    }
    char get_value() { return value; }
    string get_suit() { return suit; }
};

bool operator!=(Card a, Card b) {
    if (a.get_value() != b.get_value() && a.get_suit() != b.get_suit()) {
        return 1;
    }
    return 0;
}

Card draw() {
    Card temp;
    return temp;
}

void face_up(struct vector<Card> deck) {
    for (auto i = deck.begin(); i != deck.end(); i++) {
        cout << i->get_value() << " " << i->get_suit() << endl;
    }
}

int hearts_count(struct vector<Card> cards) {
    int count = 0;
    for (auto i = cards.begin(); i != cards.end(); i++) {
        if (i->get_suit()[0] == 'h') {
            count++;
        }
    }
    return count;
}
