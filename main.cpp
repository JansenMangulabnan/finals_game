#include <iostream>
#include "header1.h"

using namespace std;

int main() {
    BitGame game;
    int user_choice;
    cout << "++++++++++ Bitwise Operation Game ++++++++++" << endl;
    cout << "1. Play \n2. Exit \nEnter choice: ";
    cin >> user_choice;
    switch (user_choice) {
        case 1:
            game.start();
            break;
        case 2:
            cout << "Exiting the game." << endl;
            return 0;
    }
}