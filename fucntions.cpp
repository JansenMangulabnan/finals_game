#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <string>

using namespace std;  


void clearcls(int wait_before, int wait_after) {
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

void to_center_msg(string width, int txt_length) {
    int spaceing = (width.length()-1)/2 - txt_length/2;
    for (int i = 0; i <= spaceing; i++) {
        cout << " ";
    }   
}