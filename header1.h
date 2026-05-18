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
#include <string>
#include <bitset>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstdint>

using namespace std;

class BitGame {
private:
    uint8_t base_val;
    uint8_t final_val;
    int score;

    // updated struct to reflect stacked byte operations
    struct operation_step {
        string op_type;
        uint8_t byte_val;
    };

    void generate_round(int difficulty) {
        base_val = rand() % 256;
        final_val = base_val;
        vector<operation_step> pipeline;

        for (int i = 0; i < difficulty; i++) {
            uint8_t random_byte = rand() % 256; 
            int op = rand() % 3; 
            
            if (op == 0) {
                final_val &= random_byte;
                pipeline.push_back({"AND", random_byte});
            } else if (op == 1) {
                final_val |= random_byte;
                pipeline.push_back({"OR ", random_byte});
            } else {
                final_val ^= random_byte;
                pipeline.push_back({"XOR", random_byte});
            }
        }

        cout << endl << "--- Bitwise Operation Game (Level: " << difficulty <<", Score: " << score <<") ---" << endl;
        // initian byte
        cout << bitset<8>(base_val) << endl;
        // " (" << (int)base_val << ")
        
        for (size_t i = 0; i < pipeline.size(); i++) {
            // loop for byte operation pipeline
            // operation
            cout << pipeline[i].op_type << endl;
            // byte layer
            cout << bitset<8>(pipeline[i].byte_val) << endl;
        }
    }

public:
    BitGame() : score(0) {
        srand(time(0));
    }

    void start() {
        string input;
        while (true) {
            int current_difficulty = (score / 2) + 1;
            if (current_difficulty > 10) {
                current_difficulty = 10;
            }

            generate_round(current_difficulty);
            cout << "Enter the final integer result (or 'q' to quit): ";
            cin >> input;

            if (input == "q") {
                break;
            }

            
            try {
                // if (input == "d") {
                //     cout << "debug";
                //     score++;
                    
                // }
                int user_guess = stoi(input);
                if (user_guess == (int)final_val) {
                    cout << "correct! +1 point.\n";
                    score++;
                } else {
                    cout << "Wrong. The result was: " << (int)final_val << "\n";
                }
            } catch (...) {
                cout << "Invalid input.\n";
            }
        }
    }
};

#endif