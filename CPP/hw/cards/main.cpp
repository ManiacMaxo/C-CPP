#include "cards.hpp"

int main() {
    cout << "Hello" << endl;
    vector<Card> cards;
    // string spade = "spade";
    // I'm lazy
    Card ace_of_spades('A', string("spade"));
    do {
        cards.push_back(draw());
        // break on ace of spade
    } while (cards.back() != ace_of_spades);
    face_up(cards);
}
