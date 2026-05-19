#include <iostream>
#include <string>
#include <bitset>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstdint>
#include "header_fucntion.h"
#include "header_bitgame.h"

using namespace std;

void BitGame::generate_round(int difficulty) {
    base_val = rand() % 256;
    final_val = base_val;
    
    // tell the compiler operation_step belongs to BitGame
    vector<BitGame::operation_step> pipeline;

    for (int i = 0; i < difficulty; i++) {
        uint8_t random_byte = rand() % 256; 
        int op = rand() % 6;

        switch (op) {
            case 0:
                final_val &= random_byte;
                pipeline.push_back({"AND", random_byte});
                break;
                cout << "[DEBUG] after NOT, final_val is: " << (int)final_val << endl;
            case 1:
                final_val |= random_byte;
                pipeline.push_back({"OR ", random_byte});
                break;
            case 2:
                final_val ^= random_byte;
                pipeline.push_back({"XOR", random_byte});
                break;
            case 3:
                final_val = ~final_val;
                pipeline.push_back({"NOT", 0});
                break;
            case 4:
                final_val = (final_val << 1) & 0xFF;
                pipeline.push_back({"LEFT SHIFT", 1});
                break;
            case 5:
                final_val = (final_val >> 1) & 0xFF;
                pipeline.push_back({"RIGHT SHIFT", 1});
                break;
        }
    }

    cout << endl << "--- Bitwise Operation Game (Level: " << difficulty <<", Score: " << score <<") ---" << endl;
    cout << bitset<8>(base_val) << endl;
    
    for (size_t i = 0; i < pipeline.size(); i++) {
        cout << pipeline[i].op_type << endl;

        // for case 3 - 5
        if (pipeline[i].op_type != "NOT" && 
            pipeline[i].op_type != "LEFT SHIFT" && 
            pipeline[i].op_type != "RIGHT SHIFT") {
            cout << bitset<8>(pipeline[i].byte_val) << endl;
        }
    }
}

BitGame::BitGame() : score(0) {
    srand(time(0));
}

void BitGame::start() {
    string input;
    while (true) {
        int current_difficulty = (score / 2) + 1;
        if (current_difficulty > 10) {
            current_difficulty = 10;
        }

        generate_round(current_difficulty);
        cout << "Enter the final integer result (or 'q' to quit): ";
        // cout << "debug: " << (int)final_val << endl; 
        cin >> input;

        if (input == "q") {
            break;
        }

        try {
            int user_guess = stoi(input);
            if (user_guess == (int)final_val) {
                cout << "Correct! +1 point.\n";
                score++;
                clearcls(1000, 0);
            } else {
                cout << "Wrong. The result was: " << (int)final_val << "\n";
                clearcls(1500, 0);
            }
        } catch (...) {
            cout << "Invalid input.\n";
            clearcls(1000, 0);
        }
    }
}
