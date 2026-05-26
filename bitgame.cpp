#include <iostream>
#include <string>
#include <bitset>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstdint>
#include "header_functions.h"
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
                pipeline.push_back({"LSHF", 1});
                break;
            case 5:
                final_val = (final_val >> 1) & 0xFF;
                pipeline.push_back({"RSHF", 1});
                break;
        }
    }


    string title = "|================== Bitwise Operation Game (Level: " + to_string(difficulty) + ", Score: " + to_string(score) + ") ==================|";
    cout << endl << title << endl << endl;

    to_center_msg(title, 8); // initial val cout
    cout << bitset<8>(base_val) << endl;
    
    for (size_t i = 0; i < pipeline.size(); i++) {
        to_center_msg(title, pipeline[i].op_type.length()); // operation cout
        cout << pipeline[i].op_type << endl;

        // for case 3 - 5
        if (pipeline[i].op_type != "NOT" &&
            pipeline[i].op_type != "LSHF" &&
            pipeline[i].op_type != "RSHF") {
                to_center_msg(title, 8); // stacked val cout
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
        if (current_difficulty > 10) { // limiter of level
            current_difficulty = 10;
        }

        // generate round
        generate_round(current_difficulty);

        // cout << endl << "Debug: " << (int)final_val << endl;

        cout << "Enter the final integer result ([Q/q] to quit): ";
        cin >> input;

        if (input == "q" || input == "Q") {
            cout << endl << "Exiting the game." << endl;
            clear_cls(1000, 0);
            break;
        }

        try {
            int user_guess = stoi(input);
            if (user_guess == (int)final_val) {
                cout << endl << "Correct! +1 point.\n";
                score++;
                clear_cls(1000, 0);
            } else {
                cout << endl << "Wrong. The result was: " << (int)final_val << "\n";
                clear_cls(1500, 0);
            }
        } catch (...) { // error handling
            cout << endl << "Invalid input.\n";
            clear_cls(1000, 0);
        }
    }
}