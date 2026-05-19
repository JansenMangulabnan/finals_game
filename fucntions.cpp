#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

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