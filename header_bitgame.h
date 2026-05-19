#ifndef FINALS_GAME_HEADER_BITGAME_H
#define FINALS_GAME_HEADER_BITGAME_H

#include <cstdint>
#include <string>

using namespace std;

void clearcls(int time);

class BitGame {
private:
    uint8_t base_val;
    uint8_t final_val;
    int score;

    struct operation_step {
        string op_type;
        uint8_t byte_val;
    };

    void generate_round(int difficulty);
public:
    BitGame();
    void start();
};

#endif