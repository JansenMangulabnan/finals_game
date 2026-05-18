/*
plans: 
    need to answer the byte; binary to int
    need to answer the mask; binary to int
    add bit shifting
    
mechanic:
    
*/

#ifndef FINALS_GAME_HEADER1_H
#define FINALS_GAME_HEADER1_H

#include <iostream>
#include <bitset>
#include <ctime>
#include <cstdint>
using namespace std;

class BitGame {
private:
    uint8_t byte_val;
    uint8_t modifier;
    uint8_t final_val;
    int score;

    void generate_round() {
        byte_val = rand() % 256;
        modifier = rand() % 128; // mask for bitwise ops

        // choose operation: 0 = AND, 1 = OR
        if (rand() % 2 == 0) {
            final_val = byte_val & modifier;
            cout << "\noperation: (byte & mask)\n";
        } else {
            final_val = byte_val | modifier;
            cout << "\noperation: (byte | mask)\n";
        }

        cout << "byte: " << bitset<8>(byte_val) << "\n";
        cout << "mask: " << bitset<8>(modifier) << "\n";
    }

public:
    BitGame() : score(0) {
        srand(time(0));
    }

    void start() {
        string input;
        while (true) {
            generate_round();
            cout << "Enter the integer result (or 'q' to quit): ";
            cin >> input;

            if (input == "q") break;

            try {
                int user_guess = stoi(input);
                if (user_guess == (int)final_val) {
                    cout << "Correct! +1 point.\n";
                    score++;
                } else {
                    cout << "Wrong. The result was: " << (int)final_val << endl;
                }
            } catch (...) {
                cout << "Invalid input.\n";
            }
            cout << "Score: " << score << "\n";
        }
    }
};

#endif //FINALS_GAME_HEADER1_H