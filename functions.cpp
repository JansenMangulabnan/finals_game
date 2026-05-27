#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <string>

using namespace std;  


void clear_cls(int wait_before, int wait_after) { // delay before clearing terminal
    #ifdef _WIN32
        this_thread::sleep_for(chrono::milliseconds(wait_before));
        system("cls");
        this_thread::sleep_for(chrono::milliseconds(wait_after));

    #else
        this_thread::sleep_for(chrono::milliseconds(wait_before));
        system("clear");
        this_thread::sleep_for(chrono::milliseconds(wait_after));
    #endif
}

// center relative to title
void to_center_msg(string width, int txt_length) {
    for (int i = 0; i <= (width.length()-1)/2 - txt_length/2; i++) {
        cout << " ";
    }   
}