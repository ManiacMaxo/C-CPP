#include <stdio.h>

struct card_t {
    char name[32];
    int dmg;
    int defence;
    int level;
    char mode;  // 'A' 'D'
};

struct yugi_t {
    struct card_t deck[50];
    struct card_t hand[50];
    struct card_t field[50];
    int health;
    int deck_index;
    int hand_count;
};

struct card_t drawCard(struct yugi_t player) {
    struct card_t result = player.deck[player.deck_index];
    player.deck_index++;
    player.hand[player.hand_count] = result;
    player.hand_count++;
    return result;
}

int main() {
    struct yugi_t player;
    return 0;
}
