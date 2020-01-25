#include "user.hh"

int UserIdCounter = 0;

User::User(string name, string pswd) {
    this->id = UserIdCounter++;
    this->name = name;
    this->pswd = pswd;
}

User::User() {
    this->id = UserIdCounter++;
    this->name = "John"[UserIdCounter];
    this->pswd = "password";
}

int User::getId() const { return this->id; }
